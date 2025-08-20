#include "Magician.h"
#include "Monster.h"
#include <iostream>
using namespace std;

Magician::Magician(string nickname) : Player(nickname) {
    job_name = "������";
    HP = 90;
    MP = 200;
    power = 30;
    defence = 5;
    accuracy = 18;
    speed = 10;
}

void Magician::attack() {
    cout << "[������] " << nickname << "��(��) ������ ��Ʈ�� �����մϴ�!" << endl;
}

void Magician::attack(Monster* monster) {
    int damage = power - monster->getDefence();
    if (damage <= 0) damage = 1;

    cout << "[������] " << nickname << "��(��) " << monster->getName()
        << "���� ������ ��Ʈ�� " << damage << "�� ���ظ� ������!" << endl;

    bool alive = monster->setHP(monster->getHP() - damage);
    if (alive) {
        cout << monster->getName() << "�� ���� HP: " << monster->getHP() << endl;
    }
    else {
        cout << monster->getName() << "�� ���� HP: " << monster->getHP() << endl;
        cout << nickname << "�� �¸�!" << endl;
    }
}
