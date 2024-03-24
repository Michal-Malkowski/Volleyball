#ifndef STATS_HPP
#define STATS_HPP

#include <SFML/Graphics.hpp>
#include "Define.hpp"
#include <sstream>
#include <iostream>

class Stats
{
private:
    sf::Font font;
    sf::Text textSpace;
    sf::Text textPlayerPoints;
    sf::Text textOpponentPoints;
    sf::Text textPlayerSets;
    sf::Text textOpponentSets;
    int playerPoints;
    int opponentPoints;
    int playerSets;
    int opponentSets;
    std::string str;
public:
    Stats();
    void update(bool,int,int);
    void conversion(int);
    void draw(sf::RenderWindow&);
    void drawSpace(sf::RenderWindow&);
};

#endif STATS_HPP
