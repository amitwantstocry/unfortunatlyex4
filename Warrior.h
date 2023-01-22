//
// Created by amito on 1/19/2023.
//

#ifndef MTM_WARRIOR_H
#define MTM_WARRIOR_H
#include "Player.h"

class Warrior : public Player{
public:
    explicit Warrior(const string &name);

    Warrior(const Warrior& warrior) = default;

    ~Warrior() = default;

    Warrior& operator=(const Warrior& warrior) = default;

    string getJob() const override;

    int getAttackStrength() const override;
};
#endif //MTM_WARRIOR_H
