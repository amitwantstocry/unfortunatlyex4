//
// Created by amito on 1/19/2023.
//

#include "Card.h"
#include "utilities.h"
#include "Player.h"


Card::Card(string name): m_name(std::move(name)){

}


void Card::printInfo(std::ostream &os) const{
    printCardDetails(os, m_name);
    printEndOfCardDetails(os);
}

std::ostream &operator<<(std::ostream &os, const Card &card) {
    card.printInfo(os);
    return os;
}

string Card::getName() const {
    return m_name;
}


