//
// Created by amito on 1/19/2023.
//

#include "Ninja.h"
#include "Player.h"

Ninja::Ninja(const string &name): Player(name){

}

string Ninja::getJob() const {
    return "Ninja";
}

void Ninja::addCoins(int amount) {
    Player::addCoins(2 * amount);
}


