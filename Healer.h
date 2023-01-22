//
// Created by amito on 1/19/2023.
//

#ifndef MTM_HEALER_H
#define MTM_HEALER_H
#include "Player.h"

class Healer : public Player{
public:
    explicit Healer(const string &name);

    Healer(const Healer& healer) = default;

    ~Healer() = default;

    Healer& operator=(const Healer& healer) = default;

    string getJob() const override;

    void heal(int amount) override;

};
#endif //MTM_HEALER_H
