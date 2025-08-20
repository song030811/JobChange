#include "Thief.h"
#include "Monster.h"
#include <iostream>
using namespace std;

Thief::Thief(string nickname) : Player(nickname) {
    job_name = "����";
    HP = 120;
    MP = 80;
    power = 18;
    defence = 10;
    accuracy = 20;
    speed = 25;
}

void Thief::attack() {
    cout << "[����] " << nickname << "��(��) �ϻ��� ����մϴ�!" << endl;
}

void Thief::attack(Monster* monster) {
    int damage = power - monster->getDefence();
    if (damage <= 0) damage = 1;

    int per_hit = damage / 5;
    if (per_hit <= 0) per_hit = 1;

    for (int i = 0; i < 5 && monster->getHP() > 0; i++) {
        cout << "[����] " << nickname << "��(��) " << monster->getName()
            << "���� �ܰ����� " << per_hit << "�� ���ظ� ������!" << endl;

        bool alive = monster->setHP(monster->getHP() - per_hit);
        if (!alive) {
            cout << monster->getName() << "�� ���� HP: " << monster->getHP() << endl;
            cout << nickname << "�� �¸�!" << endl;
            return;
        }
    }
    cout << monster->getName() << "�� ���� HP: " << monster->getHP() << endl;
}
