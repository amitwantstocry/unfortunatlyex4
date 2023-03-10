#ifndef MTMCHKIN_H_
#define MTMCHKIN_H_


#include "Players/Player.h"
#include "Players/Healer.h"
#include "Players/Ninja.h"
#include "Players/Warrior.h"
#include "Cards/Card.h"
#include "Cards/Barfight.h"
#include "Cards/BattleCard.h"
#include "Cards/Dragon.h"
#include "Cards/Gremlin.h"
#include "Cards/Mana.h"
#include "Cards/Merchant.h"
#include "Cards/Treasure.h"
#include "Cards/Well.h"
#include "Cards/Witch.h"
#include "Exception.h"

#include <memory>
#include <queue>


class Mtmchkin{

public:

    /**
    * C'tor of Mtmchkin class
    *
    * @param filename - a file which contains the cards of the deck.
    * @return
    *      A new instance of Mtmchkin.
    */
    explicit Mtmchkin(std::string fileName);

    /**
    * Play the next Round of the game - according to the instruction in the exercise document.
    *
    * @return
    *      void
    */
    void playRound();

    /**
    * Prints the leaderBoard of the game at a given stage of the game - according to the instruction in the exercise document.
    *
    * @return
    *      void
    */
    void printLeaderBoard() const;

    /**
    *  Checks if the game ended:
    *
    *  @return
    *          True if the game ended
    *          False otherwise
    */
    bool isGameOver() const;

    /**
    *  Returns the number of rounds played.
    *
    *  @return
    *          int - number of rounds played
    */
    int getNumberOfRounds() const;


private:
    int m_numOfRounds;
    std::deque<std::unique_ptr<Player>> m_players;
    std::deque<std::unique_ptr<Card>> m_cards;
    std::deque<std::unique_ptr<Player>> m_winners;
    std::deque<std::unique_ptr<Player>> m_losers;
};


template<class T>
std::unique_ptr<Card> createCard()
{
    return std::unique_ptr<Card>(new T);
}

template<class T>
std::unique_ptr<Player> createPlayer(const std::string& playerName)
{
    return std::unique_ptr<Player>(new T(playerName));
}

template<class T>
std::unique_ptr<BattleCard> createBattleCard()
{
    return std::unique_ptr<BattleCard>(new T);
}

/**
 *
 * checks if the card name entered is one of the game cards names
 * @return
 *      boolean, true/false boolean function
 */
bool cardNameExist(std::string& cardName);

/**
 *
 * receives the card names of the game and creates the right object for each card
 * @return
 *      void
 */
void receiveCards(std::deque<std::unique_ptr<Card>>& deck, const std::string& fileNam);

/**
 *
 * receives the players of the game with the job of each player
 * @return
 *     void
 */
void receivePlayers(std::deque<std::unique_ptr<Player>>& queue);

#endif /* MTMCHKIN_H_ */