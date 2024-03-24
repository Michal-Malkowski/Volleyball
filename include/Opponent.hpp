#ifndef OPPONENT_HPP
#define OPPONENT_HPP

#include <SFML/Graphics.hpp>
#include "Define.hpp"

class Opponent
{
private:
    sf::Texture texture;
    sf::Sprite sprite;
    sf::Vector2f speed;
    bool down;
    float lastPosition;
    int reboundCounter;
public:
    Opponent();
    void moving();
    void draw(sf::RenderWindow&);
    sf::FloatRect getBounds();
    sf::Vector2f getPosition();
    sf::Vector2f getSpeed();
    void setReboundCounter(bool);
    int getReboundCounter();
    void setLastPosition();
};

#endif OPPONENT_HPP
