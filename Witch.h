//
// Created by amito on 1/19/2023.
//

#ifndef MTM_WITCH_H
#define MTM_WITCH_H
#include "BattleCard.h"

class Witch : public BattleCard{
public:
    explicit Witch();

    Witch(const Witch& witch) = default;

    ~Witch() = default;

    Witch& operator=(const Witch& witch) = default;

    void lostEncounter(Player& player) const override;

private:
    static const int LOOT = 2;
    static const int DAMAGE = 10;
    static const int FORCE = 11;
    static const int FORCE_DAMAGE = -1;
};
#endif //MTM_WITCH_H
