//
// Created by amito on 1/19/2023.
//

#include "Warrior.h"

Warrior::Warrior(const string &name): Player(name){

}

string Warrior::getJob() const {
    return "Warrior";
}

int Warrior::getAttackStrength() const {
    return (2 * Player::getAttackStrength() - Player::getLevel());
}
