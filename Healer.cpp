//
// Created by amito on 1/19/2023.
//

#include "Healer.h"


    Healer::Healer(const string &name): Player(name){

    }

    string Healer::getJob() const {
        return "Healer";
    }

void Healer::heal(int amount) {
    Player::heal(2 * amount);
}

