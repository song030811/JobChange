#include "Warrior.h"
#include "Monster.h"
#include <iostream>
using namespace std;

Warrior::Warrior(string nickname) : Player(nickname) {
    job_name = "����";
    HP = 200;
    MP = 40;
    power = 25;
    defence = 20;
    accuracy = 10;
    speed = 7;
}

void Warrior::attack() {
    cout << "[����] " << nickname << "��(��) ����� �ֵθ��ϴ�!" << endl;
}

void Warrior::attack(Monster* monster) {
    int damage = power - monster->getDefence();
    if (damage <= 0) damage = 1;

    cout << "[����] " << nickname << "��(��) " << monster->getName()
        << "���� ������ " << damage << "�� ���ظ� ������!" << endl;

    bool alive = monster->setHP(monster->getHP() - damage);
    if (alive) {
        cout << monster->getName() << "�� ���� HP: " << monster->getHP() << endl;
    }
    else {
        cout << monster->getName() << "�� ���� HP: " << monster->getHP() << endl;
        cout << nickname << "�� �¸�!" << endl;
    }
}
