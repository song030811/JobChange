#include "Warrior.h"
#include "Monster.h"
#include <iostream>
using namespace std;

Warrior::Warrior(string nickname) : Player(nickname) {
    job_name = "전사";
    HP = 200;
    MP = 40;
    power = 25;
    defence = 20;
    accuracy = 10;
    speed = 7;
}

void Warrior::attack() {
    cout << "[전사] " << nickname << "이(가) 장검을 휘두릅니다!" << endl;
}

void Warrior::attack(Monster* monster) {
    int damage = power - monster->getDefence();
    if (damage <= 0) damage = 1;

    cout << "[전사] " << nickname << "이(가) " << monster->getName()
        << "에게 검으로 " << damage << "의 피해를 입혔다!" << endl;

    bool alive = monster->setHP(monster->getHP() - damage);
    if (alive) {
        cout << monster->getName() << "의 남은 HP: " << monster->getHP() << endl;
    }
    else {
        cout << monster->getName() << "의 남은 HP: " << monster->getHP() << endl;
        cout << nickname << "의 승리!" << endl;
    }
}
