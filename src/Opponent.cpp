#include "Opponent.hpp"

Opponent::Opponent()
    :speed(0,0),down(true),reboundCounter(0)
{
    texture.loadFromFile("images/player2.png");
    sprite.setTexture(texture);
    sprite.setOrigin(PLAYER_RADIUS,PLAYER_RADIUS);
    sprite.setPosition(sf::Vector2f(SCREENX-PLAYER_RADIUS,SCREENY-PLAYER_RADIUS));
}

void Opponent::moving()
{
    lastPosition=sprite.getPosition().x;

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        speed.x=-8;
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        speed.x=8;
    else speed.x=0;
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)&&down)
        speed.y=-PLAYER_JUMP;

    sprite.move(speed);
    speed.y+=GRAVITATION;
    down=false;
    if(sprite.getPosition().y+PLAYER_RADIUS>=SCREENY)
    {
        down=true;
        speed.y=0;
        sprite.setPosition(sf::Vector2f(sprite.getPosition().x,SCREENY-PLAYER_RADIUS));
    }
}

void Opponent::draw(sf::RenderWindow& window)
{
    window.draw(sprite);
}

sf::FloatRect Opponent::getBounds()
{
    return sprite.getGlobalBounds();
}

sf::Vector2f Opponent::getPosition()
{
    return sprite.getPosition();
}

sf::Vector2f Opponent::getSpeed()
{
    return speed;
}

void Opponent::setReboundCounter(bool x)
{
    if(x)
        reboundCounter++;
    else
        reboundCounter=0;
}

int Opponent::getReboundCounter()
{
    return reboundCounter;
}

void Opponent::setLastPosition()
{
    sprite.setPosition(sf::Vector2f(lastPosition,sprite.getPosition().y));
}
