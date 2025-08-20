#include "Archer.h"
#include "Monster.h"
#include <iostream>
using namespace std;

Archer::Archer(string nickname) : Player(nickname) {
    job_name = "�ü�";
    HP = 110;
    MP = 70;
    power = 20;
    defence = 8;
    accuracy = 25;
    speed = 18;
}

void Archer::attack() {
    cout << "[�ü�] " << nickname << "��(��) ���� ����� �����մϴ�!" << endl;
}

void Archer::attack(Monster* monster) {
    int damage = power - monster->getDefence();
    if (damage <= 0) damage = 1;

    int per_hit = damage / 3;
    if (per_hit <= 0) per_hit = 1;

    for (int i = 0; i < 3 && monster->getHP() > 0; i++) {
        cout << "[�ü�] " << nickname << "��(��) " << monster->getName()
            << "���� ȭ��� " << per_hit << "�� ���ظ� ������!" << endl;

        bool alive = monster->setHP(monster->getHP() - per_hit);
        if (!alive) {
            cout << monster->getName() << "�� ���� HP: " << monster->getHP() << endl;
            cout << nickname << "�� �¸�!" << endl;
            return;
        }
    }
    cout << monster->getName() << "�� ���� HP: " << monster->getHP() << endl;
}
