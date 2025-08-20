#include "Archer.h"
#include "Monster.h"
#include <iostream>
using namespace std;

Archer::Archer(string nickname) : Player(nickname) {
    job_name = "궁수";
    HP = 110;
    MP = 70;
    power = 20;
    defence = 8;
    accuracy = 25;
    speed = 18;
}

void Archer::attack() {
    cout << "[궁수] " << nickname << "이(가) 연발 사격을 시전합니다!" << endl;
}

void Archer::attack(Monster* monster) {
    int damage = power - monster->getDefence();
    if (damage <= 0) damage = 1;

    int per_hit = damage / 3;
    if (per_hit <= 0) per_hit = 1;

    for (int i = 0; i < 3 && monster->getHP() > 0; i++) {
        cout << "[궁수] " << nickname << "이(가) " << monster->getName()
            << "에게 화살로 " << per_hit << "의 피해를 입혔다!" << endl;

        bool alive = monster->setHP(monster->getHP() - per_hit);
        if (!alive) {
            cout << monster->getName() << "의 남은 HP: " << monster->getHP() << endl;
            cout << nickname << "의 승리!" << endl;
            return;
        }
    }
    cout << monster->getName() << "의 남은 HP: " << monster->getHP() << endl;
}
