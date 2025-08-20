#include "Magician.h"
#include "Monster.h"
#include <iostream>
using namespace std;

Magician::Magician(string nickname) : Player(nickname) {
    job_name = "마법사";
    HP = 90;
    MP = 200;
    power = 30;
    defence = 5;
    accuracy = 18;
    speed = 10;
}

void Magician::attack() {
    cout << "[마법사] " << nickname << "이(가) 에너지 볼트를 시전합니다!" << endl;
}

void Magician::attack(Monster* monster) {
    int damage = power - monster->getDefence();
    if (damage <= 0) damage = 1;

    cout << "[마법사] " << nickname << "이(가) " << monster->getName()
        << "에게 에너지 볼트로 " << damage << "의 피해를 입혔다!" << endl;

    bool alive = monster->setHP(monster->getHP() - damage);
    if (alive) {
        cout << monster->getName() << "의 남은 HP: " << monster->getHP() << endl;
    }
    else {
        cout << monster->getName() << "의 남은 HP: " << monster->getHP() << endl;
        cout << nickname << "의 승리!" << endl;
    }
}
