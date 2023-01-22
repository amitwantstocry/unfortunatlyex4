//
// Created by amito on 1/19/2023.
//

#ifndef _DRAGON_H
#define _DRAGON_H
#include "BattleCard.h"

class Dragon : public BattleCard {
public:
    explicit Dragon();

    Dragon(const Dragon &dragon) = default;

    ~Dragon() = default;

    Dragon &operator=(const Dragon &dragon) = default;

private:
    static const int LOOT = 1000;
    static const int DAMAGE = Player::DEFAULT_MAX_HP;
    static const int FORCE = 25;
};
#endif //מתמ_שיט_DRAGON_H
