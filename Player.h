#ifndef EX2_Player_H
#define EX2_Player_H

#include <string>
#include "utilities.h"
using std::string;


class Player 
{
public:
    static const int MAX_LEVEL = 10;
    static const int MIN_HP = 0;
    static const int DEFAULT_MAX_HP = 100;
    /*
     * C'tor of Player class
     *
     * @param name - The name of the player.
     * @param maxHP - The maximum HP of the player (also its starting HP).
     * @param force - The initial force of the player.
     * @return
     *      A new instance of Player.
    */
    explicit Player(string name);


    /*
     * Copy C'tor of Player class
     *
     * @param player - The player instance to be copied.
     * @return
     *      A new instance of Player.
    */
    Player(const Player& player) = default;


    /*
     * D'tor of Player class
    */
    virtual ~Player() = default;


    /*
     * = operator of Player class
     *
     * @param player - The other player to be assigned to this player.
    */
    Player& operator=(const Player& player) = default;

    friend std::ostream& operator<<(std::ostream &os, const Player &player);
    /*
     * Prints info about the player like so:
     *
     * Player Details :
     * Name: <name>
     * Level: <level>
     * Force: <force>
     * HP: <HP>
     * Coins: <coins>
     * ------------------------
     * 
     * @return
     *      void
    */
    void printInfo(std::ostream &os) const;


    /*
     * Levels the player up by one level (unless they're already level 10)
     *
     * @return
     *      void
    */
    void levelUp();


    /*
     * Return the current level of the player
     *
     * @return
     *      The player's current level.
    */
    int getLevel() const;

    string getName() const;
    /*
     * Buffs the player's attack force by the given value.
     *
     * @param amount - The amount to buff the player by.
     * @return
     *      void
    */
    void buff(int amount);


    /*
     * Heals the player by the given value.
     *
     * @param amount - The amount to heal the player by.
     * @return
     *      void
    */
    virtual void heal(int amount);


    /*
     * Damages the player by the given value.
     *
     * @param amount - The amount to damage the player by.
     * @return
     *      void
    */
    void damage(int amount);


    /*
     * Checks if the player is knocked out.
     *
     * @return
     *      Whether the player is knocked out or not.
    */
    bool isKnockedOut() const;

    bool pay(int amount);


    /*
     * Gives the player an amount of coins determined by the given value.
     *
     * @param amount - The amount to give the player by.
     * @return
     *      void
    */
    virtual void addCoins(int amount);
    

     /*
     * Makes the player pay an amount of coins determined by the given value.
     *
     * @param amount - The amount to make the player pay.
     * @return
     *      Whether the payment was successful.
    bool pay(int amount);


     /*
     * Return the current attack force of the player
     *
     * @return
     *      The player's current attack force.
    */

     virtual int getAttackStrength() const;

    virtual string getJob() const= 0;

    int getCoins() const;

private:
    string m_name;
    int m_level;
    int m_force;
    int m_maxHP;
    int m_HP;
    int m_coins;
    static const int DEFAULT_FORCE = 5;
    static const int STARTING_LEVEL = 1;
    static const int STARTING_COINS = 0;
};


#endif //EX2_Player_H