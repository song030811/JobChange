#include "Monster.h"
#include "Player.h"

Monster::Monster(string name) {
    this->name = name;
    this->HP = 30;
    this->power = 30;
    this->defence = 10;
    this->speed = 10;
}

void Monster::attack(Player* player) {
    int damage = power - player->getDefence();
    if (damage <= 0) damage = 1;

    cout << "* " << name << "이(가) " << player->getNickname()
        << "에게 " << damage << "의 피해를 입혔다!" << endl;

    bool alive = player->setHP(player->getHP() - damage);
    if (alive) {
        cout << player->getNickname() << "의 남은 HP: " << player->getHP() << endl;
    }
    else {
        cout << player->getNickname() << "의 남은 HP: " << player->getHP() << endl;
        cout << name << "의 승리!" << endl;
    }
}

string Monster::getName() { return name; }
int Monster::getHP() { return HP; }
int Monster::getPower() { return power; }
int Monster::getDefence() { return defence; }
int Monster::getSpeed() { return speed; }

void Monster::setName(string name) { this->name = name; }
bool Monster::setHP(int HP) {
    if (HP > 0) {
        this->HP = HP;
        return true;
    }
    else {
        this->HP = 0;
        return false;
    }
}
void Monster::setPower(int power) { this->power = power; }
void Monster::setDefence(int defence) { this->defence = defence; }
void Monster::setSpeed(int speed) { this->speed = speed; }
