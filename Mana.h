//
// Created by amito on 1/19/2023.
//

#ifndef MTM_MANA_H
#define MTM_MANA_H

#include "Card.h"

class Mana : public Card {
public:
    explicit Mana();

    Mana(const Mana &mana) = default;

    ~Mana() = default;

    Mana &operator=(const Mana &mana) = default;

    void applyEncounter(Player& player) const override;

private:
    static const int HEAL = 10;
};
#endif //MTM_MANA_H
