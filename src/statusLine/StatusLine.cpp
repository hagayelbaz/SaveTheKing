#include "StatusLine.h"

//=====================================		PUBLIC		==================================

#include "Thief.h"
StatusLineGui StatusLine::show(std::map<PlayersName, std::shared_ptr<Player>>& players, const Time time, sf::Vector2f position, sf::Vector2f size)
{
    StatusLineGui status(position,size);
    std::string toWrite; 
    bool hasKey = false;

    for (auto& player : players)
        if (player.first == PlayersName::Thief)
        {
            hasKey = ((Thief*)player.second.get())->hasKey();
            toWrite = hasKey ? "You have a key  !!!!" : "You don't have a key  !!!";
        }
    toWrite += "\t\t\t\t";
    status.WriteLine(toWrite);
    status.append("|  " + time.getTime(':') + "  |", hasKey ? sf::Color::Green : sf::Color::Red);

    return status;
}
