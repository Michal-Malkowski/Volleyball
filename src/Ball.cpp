#include "Ball.hpp"

Ball::Ball()
    :speed(0,0),collCounter(3),ifFalled(0),holding(true),rebound(100)
{
    texture.loadFromFile("images/ball.png");
    sprite.setTexture(texture);
    sprite.setOrigin(sf::Vector2f(BALL_RADIUS,BALL_RADIUS));
    sprite.setPosition(sf::Vector2f(SCREENX/6,BALL_RADIUS));
}

void Ball::moving()
{
    if(rebound<5)
        speed.y+=PLAYER_JUMP/5;
else
    speed.y+=(float)GRAVITATION/3;
rebound++;

    if(speed.x>0) speed.x-=0.02;
    else if(speed.x<0) speed.x+=0.02;

    ///kolizja ze scianami
    if(sprite.getPosition().x<BALL_RADIUS||sprite.getPosition().x>SCREENX-BALL_RADIUS&&collCounter>2)
    {
        if(sprite.getPosition().x<BALL_RADIUS)
            sprite.setPosition(sf::Vector2f(BALL_RADIUS,sprite.getPosition().y));
        else
            sprite.setPosition(sf::Vector2f(SCREENX-BALL_RADIUS,sprite.getPosition().y));
        collCounter=0;
        speed.x=-speed.x;
    }
    ///kolizja z podloga
    if(sprite.getPosition().y>SCREENY-BALL_RADIUS&&collCounter>2)
    {
        ballLoss(sprite.getPosition().x);
        sprite.setPosition(sf::Vector2f(sprite.getPosition().x,SCREENY-BALL_RADIUS));
        collCounter=0;
        speed.y=-speed.y/1.5;
    }
    collCounter++;

    sprite.move(speed);
}

void Ball::netCollision(int state)
{
    switch(state)
    {
    case 1:
        ///uderzenie w bok siatki
        speed.x=-speed.x;
        break;
    case 2:
        ///uderzenie w gore siatki
        speed.y=-speed.y;
        break;
    case 3:
        ///uderzenie w lewy kant siatki
        if(speed.x<0)
            speed.y=-speed.y/2;
        else if(speed.x>0)
        {
            speed.x-=(rand()%150+150)/100.0;
            if(speed.x*1.5<15)
                speed.y=-speed.x*1.5;
            else speed.y=-15;
        }
        break;
    case 4:
        ///uderzenie w prawy kant siatki
        if(speed.x<0)
        {
            speed.x+=(rand()%150+150)/100.0;
            if(speed.x*1.5>-15)
                speed.y=speed.x*1.5;
            else speed.y=-15;
        }
        else if(speed.x>0)
            speed.y=-speed.y/2;
        break;
    }
}

void Ball::collision(sf::Vector2f offset,sf::Vector2f playerSpeed,sf::Vector2f playerPosition)
{
    rebound=0;
    sprite.setPosition(sf::Vector2f(playerPosition.x+offset.x,playerPosition.y+offset.y-10));
    speed.x=offset.x/3+playerSpeed.x/2.5;
    speed.y=offset.y/4+playerSpeed.y/3.5;
    speed.y-=PLAYER_JUMP;
}

void Ball::ballLoss(float pos)
{
    if(ifFalled==0)
    {
        if(pos<SCREENX/2)
            ifFalled=1;
        else ifFalled=2;
    }
}

void Ball::hold()
{
    if(ifFalled==1)
        sprite.setPosition(sf::Vector2f(SCREENX/6*5,BALL_RADIUS));
    else
        sprite.setPosition(sf::Vector2f(SCREENX/6,BALL_RADIUS));
    speed=sf::Vector2f(0,0);
    ifFalled=0;
    rebound=100;
}

void Ball::setHolding(bool x)
{
    holding=x;
}

bool Ball::isHolding()
{
    return holding;
}

sf::FloatRect Ball::getBounds()
{
    return sprite.getGlobalBounds();
}

sf::Vector2f Ball::getPosition()
{
    return sprite.getPosition();
}

int Ball::point()
{
    return ifFalled;
}

void Ball::draw(sf::RenderWindow &window)
{
    window.draw(sprite);
}
