//
// Created by amito on 1/19/2023.
//

#ifndef MTM_TREASURE_H
#define MTM_TREASURE_H
#include "Card.h"

class Treasure : public Card {
public:
    explicit Treasure();

    Treasure(const Treasure &treasure) = default;

    ~Treasure() = default;

    Treasure &operator=(const Treasure &treasure) = default;

    void applyEncounter(Player& player) const override;

private:
    static const int COINS = 10;
};
#endif //MTM_TREASURE_H
