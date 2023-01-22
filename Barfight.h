//
// Created by amito on 1/19/2023.
//

#ifndef _BARFIGHT_H
#define _BARFIGHT_H

#include "Card.h"

class Barfight : public Card {
public:
    explicit Barfight();

    Barfight(const Barfight &barfight) = default;

    ~Barfight() = default;

    Barfight &operator=(const Barfight &barfight) = default;

    void applyEncounter(Player& player) const override;

private:
    static const int DAMAGE = 10;
};
#endif //BARFIGHT_H
