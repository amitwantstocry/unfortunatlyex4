//
// Created by amito on 1/19/2023.
//

#ifndef MTM_BATTLECARD_H
#define MTM_BATTLECARD_H
#include "Card.h"

class BattleCard : public Card {
public:
    explicit BattleCard(string name, int loot, int damage, int force);

    BattleCard(const BattleCard &battleCard) = default;

    ~BattleCard() override = default;

    BattleCard &operator=(const BattleCard &battleCard) = default;

    void applyEncounter(Player& player) const override;

    virtual void lostEncounter(Player& player) const;

    void printInfo(std::ostream &os) const override;
private:
    int m_loot;
    int m_damage;
    int m_force;
};
#endif //MTM_BATTLECARD_H
