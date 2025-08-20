#pragma once
#include "Player.h"

class Thief : public Player {
public:
    Thief(string nickname);
    void attack() override;
    void attack(Monster* monster) override;
};
