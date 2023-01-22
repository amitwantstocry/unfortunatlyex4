//
// Created by amito on 1/19/2023.
//

#include <iostream>
#include <string>
#include <fstream>
#include <map>
#include <queue>

#include "Mtmchkin.h"
#include "utilities.h"
#include "Exception.h"

using std::ifstream;
using std::string;
using std::cerr;
using std::cout;
using std::endl;
using std::cin;
using std::unique_ptr;
using std::getline;

int const MAX_NAME_LENGTH = 15;
int const MIN_CARDS_SIZE = 5;
int const MAX_LEVEL = 10;
char const MAX_TEAM_SIZE = '6';
char const MIN_TEAM_SIZE = '2';

Mtmchkin::Mtmchkin(const std::string fileName)
{
    printStartGameMessage();
    receiveCards(m_cards, fileName);
    receivePlayers(m_players);
    m_numOfRounds = 0;
}

void Mtmchkin::playRound()
{
    m_numOfRounds++;

    printRoundStartMessage(getNumberOfRounds());

    int size = int(m_players.size());
    for(int i=0; i < size; i++)
    {
        printTurnStartMessage((m_players.front())->getName());
        m_cards.front()->applyEncounter(*m_players.front());

        m_cards.push_back(std::move(m_cards.front()));
        m_cards.pop_front();

        if((m_players.front())->getLevel() == MAX_LEVEL)
        {
            m_winners.push_back(std::move(m_players.front()));
        }
        else if(m_players.front()->isKnockedOut())
        {
            m_losers.push_front(std::move(m_players.front()));
        }
        else //the player is still in the game
        {
            m_players.push_back(std::move(m_players.front()));
        }
        m_players.pop_front();
    }

    if(isGameOver())
    {
        printGameEndMessage();
    }
}


bool Mtmchkin::isGameOver() const
{
    return m_players.empty();
}


int Mtmchkin::getNumberOfRounds() const
{
    return m_numOfRounds;
}

bool cardNameExist(string& cardName)
{
    if(cardName == "Gremlin" ||cardName == "Witch" || cardName == "Dragon" ||
       cardName == "Barfight" || cardName == "Treasure" || cardName == "Merchant" || cardName == "Well"||
       cardName == "Mana")
    {
        return true;
    }
    return false;
}


void receiveCards(std::deque<unique_ptr<Card>>& deck, const string& fileName)
{
    ifstream source(fileName);
    if(!source)
    {
        throw DeckFileNotFound();
    }

    std::string inputName;
    std::map <string, unique_ptr<Card>(*)()> Map;

    Map["Mana"] = createCard<Mana>;
    Map["Gremlin"] = createCard<Gremlin>;
    Map["Dragon"] = createCard<Dragon>;
    Map["Merchant"] = createCard<Merchant>;
    Map["Well"] = createCard<Well>;
    Map["Witch"] = createCard<Witch>;
    Map["Treasure"] = createCard<Treasure>;
    Map["Barfight"] = createCard<Barfight>;

    std::map<string, unique_ptr<BattleCard>(*)()> mapBattleCard;

    mapBattleCard["Witch"] = createBattleCard<Witch>;
    mapBattleCard["Gremlin"] = createBattleCard<Gremlin>;
    mapBattleCard["Dragon"] = createBattleCard<Dragon>;

    int line = 1;
    std::deque<std::unique_ptr<BattleCard>> gang;

    if(deck.size() < MIN_CARDS_SIZE)
    {
        throw DeckFileInvalidSize();
    }
}

bool invalidName(string name)
{
    if(name.size() > MAX_NAME_LENGTH)
    {
        return true;
    }
    for (int i = 0; i < int(name.size()); i++)
    {
        if ((name[i] >= 'A' && name[i] <= 'Z') || (name[i] >= 'a' && name[i] <= 'z'))
        {
            continue;
        }
        else
        {
            return true;
        }
    }
    return false;
}

void receivePlayers(std::deque<unique_ptr<Player>>& playersQueue)
{
    string buffer;
    printEnterTeamSizeMessage();
    getline(cin, buffer);
    while (buffer.size() != 1 || buffer[0] < MIN_TEAM_SIZE || buffer[0] > MAX_TEAM_SIZE)
    {
        printInvalidTeamSize();
        printEnterTeamSizeMessage();
        getline(cin, buffer);
    }
    int teamSize = std::stoi(buffer);

    std::map <string, unique_ptr<Player>(*)(const std::string&)> Map;
    Map["Ninja"] = createPlayer<Ninja>;
    Map["Warrior"] = createPlayer<Warrior>;
    Map["Healer"] = createPlayer<Healer>;

    buffer = "";
    for(int i=0; i < teamSize;  i++)
    {
        string playerName, playerJob;

        printInsertPlayerMessage();
        getline(cin, buffer);

        while(true)
        {
            for(int j = 0; buffer[j] != ' '; j++)
            {
                playerName += buffer[j];
            }
            for(int j = int(playerName.size()) + 1; j < int(buffer.size()); j++)
            {
                playerJob += buffer[j];
            }
            if(invalidName(playerName))
            {
                printInvalidName();
            }
            else if(playerJob != "Healer" && playerJob != "Warrior" && playerJob != "Ninja")
            {
                printInvalidClass();
            }
            else
            {
                break;
            }
            playerJob = "";
            playerName = "";
            getline(cin, buffer);
        }
        playersQueue.push_back(Map[playerJob](playerName));
    }
}


void Mtmchkin::printLeaderBoard() const
{
    printLeaderBoardStartMessage();

    for(int i=0; i < int(m_winners.size()); i++)
    {
        printPlayerLeaderBoard(i+1, *m_winners[i]);
    }
    for(int t=0; t < int(m_players.size()); t++)
    {
        printPlayerLeaderBoard(t+int(m_winners.size())+1, *m_players[t]);
    }
    for(int j=0; j < int(m_losers.size()); j++)
    {
        printPlayerLeaderBoard(j+int(m_winners.size())+int(m_players.size())+1, *m_losers[j]);
    }
}