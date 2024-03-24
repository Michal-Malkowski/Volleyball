#include "Player.hpp"

Player::Player()
    :speed(0,0),down(true),reboundCounter(0)
{
    texture.loadFromFile("images/player.png");
    sprite.setTexture(texture);
    sprite.setOrigin(PLAYER_RADIUS,PLAYER_RADIUS);
    sprite.setPosition(sf::Vector2f(PLAYER_RADIUS*4,SCREENY-PLAYER_RADIUS));
}

void Player::moving()
{
    lastPosition=sprite.getPosition().x;

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        speed.x=-8;
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        speed.x=8;
    else speed.x=0;
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::W)&&down)
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

void Player::draw(sf::RenderWindow& window)
{
    window.draw(sprite);
}

sf::FloatRect Player::getBounds()
{
    return sprite.getGlobalBounds();
}

sf::Vector2f Player::getPosition()
{
    return sprite.getPosition();
}

sf::Vector2f Player::getSpeed()
{
    return speed;
}

void Player::setReboundCounter(bool x)
{
    if(x)
        reboundCounter++;
    else
        reboundCounter=0;
}

int Player::getReboundCounter()
{
    return reboundCounter;
}

void Player::setLastPosition()
{
    sprite.setPosition(sf::Vector2f(lastPosition,sprite.getPosition().y));
}
