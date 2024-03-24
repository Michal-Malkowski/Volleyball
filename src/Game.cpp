#include "Game.hpp"

Game::Game()
    :window(sf::VideoMode(SCREENX,SCREENY), "Volleyball"),state(false)
{
    window.setFramerateLimit(FRAMELIMIT);
}

void Game::run()
{
    srand(time(0));

    while(window.isOpen())
    {
        while(window.pollEvent(event))
            if(event.type==sf::Event::Closed)
                window.close();

                if(menu.game())
                    state=true;

                switch(state)
                {
                case 0:
                    menu.run(window);
                    break;
                case 1:
                    singleMap.run(window,menu.getSets(),menu.getPoints());
                    break;
                }
                window.display();
    }
}
