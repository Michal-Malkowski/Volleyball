#ifndef BALL_HPP
#define BALL_HPP

#include <SFML/Graphics.hpp>
#include "Define.hpp"
#include <ctime>
#include <cstdlib>
#include <cmath>

class Ball
{
private:
    sf::Texture texture;
    sf::Sprite sprite;
    sf::Vector2f speed;
    int collCounter;
    int ifFalled;
    bool holding;
    int rebound;
public:
    Ball();
    void moving();
    void netCollision(int);
    void collision(sf::Vector2f,sf::Vector2f,sf::Vector2f);
    void ballLoss(float);
    void hold();
    void setHolding(bool);
    bool isHolding();
    sf::FloatRect getBounds();
    sf::Vector2f getPosition();
    int point();
    void draw(sf::RenderWindow&);
};

#endif BALL_HPP
