//
// Created by amito on 1/19/2023.
//

#ifndef MTM_NINJA_H
#define MTM_NINJA_H

#include "Player.h"

class Ninja : public Player {
public:
    explicit Ninja(const string &name);

    Ninja(const Ninja &ninja) = default;

    ~Ninja() = default;

    Ninja &operator=(const Ninja &ninja) = default;

    string getJob() const override;

    void addCoins(int amount) override;
};
#endif //MTM_NINJA_H
