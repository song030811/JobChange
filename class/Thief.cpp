#include "Thief.h"
#include "Monster.h"
#include <iostream>
using namespace std;

Thief::Thief(string nickname) : Player(nickname) {
    job_name = "도적";
    HP = 120;
    MP = 80;
    power = 18;
    defence = 10;
    accuracy = 20;
    speed = 25;
}

void Thief::attack() {
    cout << "[도적] " << nickname << "이(가) 암살을 사용합니다!" << endl;
}

void Thief::attack(Monster* monster) {
    int damage = power - monster->getDefence();
    if (damage <= 0) damage = 1;

    int per_hit = damage / 5;
    if (per_hit <= 0) per_hit = 1;

    for (int i = 0; i < 5 && monster->getHP() > 0; i++) {
        cout << "[도적] " << nickname << "이(가) " << monster->getName()
            << "에게 단검으로 " << per_hit << "의 피해를 입혔다!" << endl;

        bool alive = monster->setHP(monster->getHP() - per_hit);
        if (!alive) {
            cout << monster->getName() << "의 남은 HP: " << monster->getHP() << endl;
            cout << nickname << "의 승리!" << endl;
            return;
        }
    }
    cout << monster->getName() << "의 남은 HP: " << monster->getHP() << endl;
}
