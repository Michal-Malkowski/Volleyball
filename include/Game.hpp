#ifndef GAME_HPP
#define GAME_HPP

#include "Menu.hpp"
#include "SingleMap.hpp"

class Game
{
private:
    sf::RenderWindow window;
    sf::Event event;
    bool state;
    Menu menu;
    SingleMap singleMap;
public:
    Game();
    void run();
};

#endif GAME_HPP
