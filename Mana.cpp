//
// Created by amito on 1/19/2023.
//
#include "Mana.h"

Mana::Mana(): Card("Mana") {

}

void Mana::applyEncounter(Player &player) const {
    if(player.getJob() != "Healer"){
        printManaMessage(false);
    }
    else{
        printManaMessage(true);
        player.heal(HEAL);
    }
}

