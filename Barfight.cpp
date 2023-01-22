//
// Created by amito on 1/19/2023.
//
#include "Barfight.h"

Barfight::Barfight(): Card("Barfight") {

}

void Barfight::applyEncounter(Player &player) const {
    if(player.getJob() != "Warrior"){
        printBarfightMessage(false);
        player.damage(DAMAGE);
    }
    else{
        printBarfightMessage(true);
    }
}

