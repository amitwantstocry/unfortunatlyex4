//
// Created by amito on 1/19/2023.
//

#include "Treasure.h"

Treasure::Treasure(): Card("Treasure") {

}

void Treasure::applyEncounter(Player &player) const {
    player.addCoins(COINS);
    printTreasureMessage();
}
