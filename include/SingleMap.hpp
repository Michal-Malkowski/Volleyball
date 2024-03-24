#ifndef SINGLEMAP_HPP
#define SINGLEMAP_HPP

#include "Player.hpp"
#include "Opponent.hpp"
#include "Ball.hpp"
#include "Stats.hpp"

class SingleMap
{
private:
    sf::Texture textureBackground;
    sf::Sprite spriteBackground;
    sf::RectangleShape net;
    Player player;
    Opponent opponent;
    Ball ball;
    Stats stats;
    int collCounter;
    int counter;
public:
    SingleMap();
    void run(sf::RenderWindow&,int,int);
    void draw(sf::RenderWindow&);
};

#endif SINGLEMAP_HPP
