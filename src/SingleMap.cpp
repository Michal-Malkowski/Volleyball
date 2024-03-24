#include "SingleMap.hpp"

SingleMap::SingleMap()
    :collCounter(3),counter(0)
{
    textureBackground.loadFromFile("images/background.png");
    spriteBackground.setTexture(textureBackground);
    net.setPosition(sf::Vector2f(627,545));
    net.setSize(sf::Vector2f(25,365));
}

void SingleMap::run(sf::RenderWindow& window,int maxSets,int maxPoints)
{
    player.moving();
    opponent.moving();
    if(!ball.isHolding())
        ball.moving();

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
        ball.setHolding(false);

    if(net.getGlobalBounds().intersects(player.getBounds())||player.getPosition().x<PLAYER_RADIUS)
        player.setLastPosition();
    if(net.getGlobalBounds().intersects(opponent.getBounds())||opponent.getPosition().x>SCREENX-PLAYER_RADIUS)
        opponent.setLastPosition();
    if(net.getGlobalBounds().intersects(ball.getBounds())&&collCounter>2)
    {
        ///kolizja pilki z siatka
        collCounter=0;
        int collisionState;
        if(ball.getPosition().y>SCREENY-net.getSize().y+BALL_RADIUS)
            collisionState=1;
        else if(ball.getPosition().y>net.getPosition().x-15&&ball.getPosition().y<net.getPosition().x+net.getSize().x+15)
            collisionState=2;
        else if(ball.getPosition().x<net.getPosition().x+15)
            collisionState=3;
        else collisionState=4;

        ball.netCollision(collisionState);
    }

    sf::Vector2f offset=sf::Vector2f(ball.getPosition().x-player.getPosition().x,ball.getPosition().y-player.getPosition().y);
    float distance=sqrt(offset.x*offset.x+offset.y*offset.y);

    ///kolizja z graczem
    if(distance<=BALL_RADIUS+PLAYER_RADIUS&&collCounter>5)
    {
        collCounter=0;
        ball.collision(offset,player.getSpeed(),player.getPosition());
        player.setReboundCounter(true);
        opponent.setReboundCounter(false);
    }

    offset=sf::Vector2f(ball.getPosition().x-opponent.getPosition().x,ball.getPosition().y-opponent.getPosition().y);
    distance=sqrt(offset.x*offset.x+offset.y*offset.y);

    if(distance<=BALL_RADIUS+PLAYER_RADIUS&&collCounter>5)
    {
        collCounter=0;
        ball.collision(offset,opponent.getSpeed(),opponent.getPosition());
        opponent.setReboundCounter(true);
        player.setReboundCounter(false);
    }

    if(player.getReboundCounter()>3||opponent.getReboundCounter()>3)
        ball.ballLoss(ball.getPosition().x);

    ///zdobycie punktu
    if(ball.point())
    {
        if(counter==0)
        {
            if(ball.point()==1)
                stats.update(false,maxSets,maxPoints);
            else
                stats.update(true,maxSets,maxPoints);
        }
        counter++;
        if(counter>150)
        {
            ball.setHolding(true);
            ball.hold();
            counter=0;
        }
    }

    collCounter++;

    draw(window);
    if(ball.isHolding())
    {
        player.setReboundCounter(false);
        opponent.setReboundCounter(false);
        stats.drawSpace(window);
    }
}

void SingleMap::draw(sf::RenderWindow& window)
{
    window.clear();
    window.draw(spriteBackground);
    player.draw(window);
    opponent.draw(window);
    ball.draw(window);
    stats.draw(window);
}
