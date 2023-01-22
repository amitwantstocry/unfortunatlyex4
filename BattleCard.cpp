//
// Created by amito on 1/19/2023.
//

#include "BattleCard.h"

BattleCard::BattleCard(string name, int loot, int damage, int force): Card(std::move(name)),
m_loot(loot),
m_damage(damage),
m_force(force)
{

}

void BattleCard::applyEncounter(Player& player) const {
    if (player.getAttackStrength() >= m_force) {
        player.levelUp();
        player.addCoins(m_loot);
        printWinBattle(player.getName(), getName());
    } else {
        lostEncounter(player);
        printLossBattle(player.getName(), getName());
    }
}


void BattleCard::printInfo(std::ostream &os) const {
    printCardDetails(os, getName());
    printMonsterDetails(os, m_force, m_damage, m_loot, m_damage == Player::DEFAULT_MAX_HP);
    printEndOfCardDetails(os);
}

void BattleCard::lostEncounter(Player &player) const {
    player.damage(m_damage);
}
