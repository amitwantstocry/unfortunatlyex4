//
// Created by amito on 1/19/2023.
//

#ifndef _GREMLIN_H
#define _GREMLIN_H
#include "BattleCard.h"

class Gremlin : public BattleCard {
public:
    explicit Gremlin();

    Gremlin(const Gremlin &gremlin) = default;

    ~Gremlin() = default;

    Gremlin &operator=(const Gremlin &gremlin) = default;

private:
    static const int LOOT = 2;
    static const int DAMAGE = 10;
    static const int FORCE = 5;
};
#endif 
