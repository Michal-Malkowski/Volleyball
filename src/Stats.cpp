#include "Stats.hpp"

Stats::Stats()
    :playerSets(0),opponentSets(0),playerPoints(0),opponentPoints(0)
{
    font.loadFromFile("arial.ttf");
    textSpace.setFont(font);
    textSpace.setCharacterSize(96);
    textSpace.setString("Press Spacebar");
    textSpace.setPosition(sf::Vector2f(SCREENX/2-textSpace.getGlobalBounds().width/2,SCREENY/2-textSpace.getGlobalBounds().height));
    textSpace.setFillColor(sf::Color::Black);

    textPlayerPoints.setFont(font);
    textPlayerPoints.setCharacterSize(96);
    conversion(playerPoints);
    textPlayerPoints.setString(str);
    textPlayerPoints.setPosition(sf::Vector2f(SCREENX*2/5,20));

    textOpponentPoints.setFont(font);
    textOpponentPoints.setCharacterSize(96);
    conversion(opponentPoints);
    textOpponentPoints.setString(str);
    textOpponentPoints.setPosition(sf::Vector2f(SCREENX*3/5-textOpponentPoints.getGlobalBounds().width,20));

    textPlayerSets.setFont(font);
    textPlayerSets.setCharacterSize(48);
    conversion(playerSets);
    textPlayerSets.setString(str);
    textPlayerSets.setPosition(sf::Vector2f(textPlayerPoints.getPosition().x-textPlayerPoints.getGlobalBounds().width-textPlayerSets.getGlobalBounds().width,20));

    textOpponentSets.setFont(font);
    textOpponentSets.setCharacterSize(48);
    conversion(opponentSets);
    textOpponentSets.setString(str);
    textOpponentSets.setPosition(sf::Vector2f(textOpponentPoints.getPosition().x+2*textOpponentPoints.getGlobalBounds().width,20));
}

void Stats::update(bool player,int maxSets,int maxPoints)
{
    if(player)
    {
        playerPoints++;
        conversion(playerPoints);
        textPlayerPoints.setString(str);
    }
    else
    {
        opponentPoints++;
        conversion(opponentPoints);
        textOpponentPoints.setString(str);
    }

    if(playerPoints>=maxPoints&&playerPoints-1>opponentPoints)
    {
        playerPoints=0;
        opponentPoints=0;
        playerSets++;
        conversion(playerSets);
        textPlayerSets.setString(str);
        conversion(playerPoints);
        textPlayerPoints.setString(str);
        conversion(opponentPoints);
        textOpponentPoints.setString(str);
    }
    else if(opponentPoints>=maxPoints&&opponentPoints-1>playerPoints)
    {
        playerPoints=0;
        opponentPoints=0;
        opponentSets++;
        conversion(opponentSets);
        textOpponentSets.setString(str);
        conversion(playerPoints);
        textPlayerPoints.setString(str);
        conversion(opponentPoints);
        textOpponentPoints.setString(str);
    }
    if(playerSets>=maxSets)
    {

    }
    else if(opponentSets>=maxSets)
    {

    }

    textPlayerPoints.setPosition(sf::Vector2f(SCREENX*2/5,20));

    textOpponentPoints.setPosition(sf::Vector2f(SCREENX*3/5-textOpponentPoints.getGlobalBounds().width,20));

    textPlayerSets.setPosition(sf::Vector2f(textPlayerPoints.getPosition().x-textPlayerPoints.getGlobalBounds().width-textPlayerSets.getGlobalBounds().width,20));

    textOpponentSets.setPosition(sf::Vector2f(textOpponentPoints.getPosition().x+2*textOpponentPoints.getGlobalBounds().width,20));
}

void Stats::conversion(int x)
{
    str="";
    std::ostringstream ss;

    ss<<x;
    str+=ss.str()+" ";
    ss.str("");
}

void Stats::draw(sf::RenderWindow& window)
{
    window.draw(textPlayerPoints);
    window.draw(textOpponentPoints);
    window.draw(textPlayerSets);
    window.draw(textOpponentSets);
}

void Stats::drawSpace(sf::RenderWindow& window)
{
    window.draw(textSpace);
}
