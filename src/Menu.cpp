#include "Menu.hpp"

Menu::Menu()
    :state(0),gameStart(false),choosenSets(0),choosenPoints(3)
{
    font.loadFromFile("arial.ttf");
    for(int i=0; i<5; i++) text[i].setFont(font);
    for(int i=0; i<6; i++)
    {
        numbers[i].setFont(font);
        numbers[i].setCharacterSize(SCREENY/20);
    }

    numbers[0].setString("1");
    numbers[1].setString("2");
    numbers[2].setString("3");
    numbers[3].setString("10");
    numbers[4].setString("15");
    numbers[5].setString("25");

    numbers[choosenSets].setFillColor(sf::Color::Red);
    numbers[choosenPoints].setFillColor(sf::Color::Red);
}

void Menu::run(sf::RenderWindow& window)
{
    for(int i=0; i<6; i++)
        numbers[i].setPosition(sf::Vector2f(-1000,-1000));

    switch(state)
    {
    case 0:
        for(int i=0; i<5; i++)
        {
            text[i].setCharacterSize(SCREENY/10);
            text[i].setPosition(sf::Vector2f(0,SCREENY/5*i));
        }
        text[0].setPosition(sf::Vector2f(SCREENX/2-text[0].getGlobalBounds().width/2,text[0].getPosition().y));
        text[0].setString("Volleyball");
        text[1].setString("Play");
        text[2].setString("Options");
        text[3].setString("Credits");
        text[4].setString("Quit");

        for(int i=1; i<5; i++)
        {
            if(text[i].getGlobalBounds().left<sf::Mouse::getPosition(window).x&&text[i].getGlobalBounds().left+text[i].getGlobalBounds().width>sf::Mouse::getPosition(window).x&&text[i].getGlobalBounds().top<sf::Mouse::getPosition(window).y&&text[i].getGlobalBounds().top+text[i].getGlobalBounds().height>sf::Mouse::getPosition(window).y)
            {
                text[i].setFillColor(sf::Color::Red);
                text[i].setScale(sf::Vector2f(1.1,1.1));
                if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
                    state=i;
            }
            else
            {
                text[i].setFillColor(sf::Color::White);
                text[i].setScale(sf::Vector2f(1,1));
            }
        }
        break;
    case 1:
        gameStart=true;
        break;
    case 2:
        text[0].setString("Options:");
        text[1].setString("Sets\n\n\nPoints");
        text[1].setCharacterSize(SCREENY/15);
        text[1].setPosition(sf::Vector2f(SCREENX/4,text[1].getPosition().y));

        for(int i=0; i<6; i++)
        {
            numbers[i].setPosition(sf::Vector2f(text[1].getPosition().x+text[1].getGlobalBounds().width+50+i%3*100,
                                                text[1].getPosition().y+text[1].getGlobalBounds().height/32));
            if(i>=3)
                numbers[i].setPosition(sf::Vector2f(numbers[i].getPosition().x,
                                                    numbers[i].getPosition().y+text[1].getGlobalBounds().height*5/6));
        }

        text[4].setString("Back");
        text[4].setPosition(sf::Vector2f(SCREENX-text[4].getGlobalBounds().width-100,text[4].getPosition().y));

        for(int i=2; i<=3; i++)
            text[i].setPosition(sf::Vector2f(-1000,-1000));

        if(text[4].getGlobalBounds().left<sf::Mouse::getPosition(window).x&&text[4].getGlobalBounds().left+text[4].getGlobalBounds().width>sf::Mouse::getPosition(window).x&&text[4].getGlobalBounds().top<sf::Mouse::getPosition(window).y&&text[4].getGlobalBounds().top+text[4].getGlobalBounds().height>sf::Mouse::getPosition(window).y)
        {
            text[4].setFillColor(sf::Color::Red);
            text[4].setScale(sf::Vector2f(1.1,1.1));
            if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
                state=0;
        }
        else
        {
            text[4].setFillColor(sf::Color::White);
            text[4].setScale(sf::Vector2f(1,1));
        }

        for(int i=0; i<6; i++)
        {
            if(numbers[i].getGlobalBounds().left<sf::Mouse::getPosition(window).x&&numbers[i].getGlobalBounds().left+numbers[i].getGlobalBounds().width>sf::Mouse::getPosition(window).x&&numbers[i].getGlobalBounds().top<sf::Mouse::getPosition(window).y&&numbers[i].getGlobalBounds().top+numbers[i].getGlobalBounds().height>sf::Mouse::getPosition(window).y)
            {
                numbers[i].setFillColor(sf::Color::Red);
                numbers[i].setScale(sf::Vector2f(1.1,1.1));
                if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
                {
                    if(i<3) choosenSets=i;
                    else choosenPoints=i;
                }
            }
            else
            {
                if(i!=choosenSets&&i!=choosenPoints)
                    numbers[i].setFillColor(sf::Color::White);
                numbers[i].setScale(sf::Vector2f(1,1));
            }
        }
        break;
    case 3:
        text[0].setString("Credits:");
        text[1].setString("Michal Malkowski");
        text[1].setPosition(sf::Vector2f(SCREENX/2-text[1].getGlobalBounds().width/2,SCREENY/2-text[1].getGlobalBounds().height));
        text[4].setString("Back");
        text[4].setPosition(sf::Vector2f(SCREENX-text[4].getGlobalBounds().width-100,text[4].getPosition().y));
        for(int i=2; i<=3; i++)
            text[i].setPosition(sf::Vector2f(-1000,-1000));
        if(text[4].getGlobalBounds().left<sf::Mouse::getPosition(window).x&&text[4].getGlobalBounds().left+text[4].getGlobalBounds().width>sf::Mouse::getPosition(window).x&&text[4].getGlobalBounds().top<sf::Mouse::getPosition(window).y&&text[4].getGlobalBounds().top+text[4].getGlobalBounds().height>sf::Mouse::getPosition(window).y)
        {
            text[4].setFillColor(sf::Color::Red);
            text[4].setScale(sf::Vector2f(1.1,1.1));
            if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
                state=0;
        }
        else
        {
            text[4].setFillColor(sf::Color::White);
            text[4].setScale(sf::Vector2f(1,1));
        }
        break;
    case 4:
        window.close();
        break;
    }
    draw(window);
}

bool Menu::game()
{
    if(gameStart)
        return true;
    return false;
}

void Menu::draw(sf::RenderWindow& window)
{
    window.clear();
    for(int i=0; i<5; i++) window.draw(text[i]);
    for(int i=0; i<6; i++) window.draw(numbers[i]);
}

int Menu::getSets()
{
    if(choosenSets==0)
        return 1;
    else if(choosenSets==1)
        return 2;
    else if(choosenSets==2)
        return 3;
}

int Menu::getPoints()
{
    if(choosenPoints==3)
        return 10;
    else if(choosenPoints==4)
        return 15;
    else if(choosenPoints==5)
        return 25;
}
