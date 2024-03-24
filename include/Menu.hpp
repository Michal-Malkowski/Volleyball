#ifndef MENU_HPP
#define MENU_HPP

#include <SFML/Graphics.hpp>
#include <iostream>
#include <sstream>
#include "Define.hpp"

class Menu
{
private:
    sf::Font font;
    sf::Text text[5];
    sf::Text numbers[6];
    int state;
    int choosenSets;
    int choosenPoints;
    bool gameStart;
public:
    Menu();
    void run(sf::RenderWindow&);
    bool game();
    void draw(sf::RenderWindow&);
    int getSets();
    int getPoints();
};

#endif MENU_HPP
