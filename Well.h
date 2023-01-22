//
// Created by amito on 1/19/2023.
//

#ifndef MTM_WELL_H
#define MTM_WELL_H
#include "Card.h"

class Well : public Card {
public:
    explicit Well();

    Well(const Well &well) = default;

    ~Well() = default;

    Well &operator=(const Well &well) = default;

    void applyEncounter(Player& player) const override;

private:
    static const int DAMAGE = 10;
};
#endif //MTM_WELL_H
