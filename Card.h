//
// Created by Daniel_Meents on 07/04/2022.
//
#ifndef EX2_Card_H
#define EX2_Card_H

#include <string>
#include "Players/Player.h"
#include "utilities.h"


class Card {
public:
    /*
     * C'tor of Card class
     *
     * @param type - The type of the card.
     * @param stats - The numeral stats of the card.
     * @return
     *      A new instance of Card.
    */
    explicit Card(string name);


    /*
     * Handling the player's applyEncounter with the card:
     *
     * @param player - The player.
     * @return
     *      void
    */
    virtual void applyEncounter(Player& player) const = 0;


    /*
     * Prints the card info:
     *
     * @return
     *      void
    */
    virtual void printInfo(std::ostream &os) const;


    /*
     * Here we are explicitly telling the compiler to use the default methods
    */
    Card(const Card&) = default;

    virtual ~Card() = default;

    Card& operator=(const Card& other) = default;

    friend std::ostream& operator<<(std::ostream &os, const Card &card);
protected:
    string getName() const;
private:
    string m_name;
};


#endif //EX2_Card_H