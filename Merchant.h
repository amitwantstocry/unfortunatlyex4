//
// Created by amito on 1/19/2023.
//

#ifndef MTM_MERCHANT_H
#define MTM_MERCHANT_H

#include "Card.h"

class Merchant : public Card {
public:
    explicit Merchant();

    Merchant(const Merchant &merchant) = default;

    ~Merchant() = default;

    Merchant &operator=(const Merchant &merchant) = default;

    void applyEncounter(Player& player) const override;

private:
    string HEAL_POTION = "1";
    string FORCE_BOOST = "2";
    string EXIT = "0";
    static const int BOOST_PRICE = 10;
    static const int POTION_PRICE = 5;
    static const int FORCE_BUFF = 1;
    static const int HEAL_POINTS = 1;
};

#endif //MTM_MERCHANT_H
