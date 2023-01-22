//
// Created by amito on 1/19/2023.
//

#include "Witch.h"

Witch::Witch(): BattleCard("Witch", LOOT, DAMAGE, FORCE) {

}

void Witch::lostEncounter(Player &player) const {
    BattleCard::lostEncounter(player);
    player.buff(FORCE_DAMAGE);
}
