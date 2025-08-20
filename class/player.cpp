#include "Player.h"

Player::Player(string nickname) {
    this->nickname = nickname;
    this->level = 1;
    this->HP = 100;
    this->MP = 50;
    this->power = 10;
    this->defence = 5;
    this->accuracy = 5;
    this->speed = 5;
}

void Player::printPlayerStatus() {
    cout << "------------------------------------" << endl;
    cout << "* ���� �ɷ�ġ" << endl;
    cout << "�г���: " << nickname << endl;
    cout << "����: " << job_name << endl;
    cout << "Lv. " << level << endl;
    cout << "HP: " << HP << endl;
    cout << "MP: " << MP << endl;
    cout << "���ݷ�: " << power << endl;
    cout << "����: " << defence << endl;
    cout << "��Ȯ��: " << accuracy << endl;
    cout << "�ӵ�: " << speed << endl;
    cout << "------------------------------------" << endl;
}

string Player::getJobName() { return job_name; }
string Player::getNickname() { return nickname; }
int Player::getLevel() { return level; }
int Player::getHP() { return HP; }
int Player::getMP() { return MP; }
int Player::getPower() { return power; }
int Player::getDefence() { return defence; }
int Player::getAccuracy() { return accuracy; }
int Player::getSpeed() { return speed; }

void Player::setNickname(string nickname) { this->nickname = nickname; }
bool Player::setHP(int HP) {
    if (HP > 0) { this->HP = HP; return true; }
    this->HP = 0;
    return false;
}
bool Player::setMP(int MP) {
    if (MP >= 0) { this->MP = MP; return true; }
    return false;
}
void Player::setPower(int power) { this->power = power; }
void Player::setDefence(int defence) { this->defence = defence; }
void Player::setAccuracy(int accuracy) { this->accuracy = accuracy; }
void Player::setSpeed(int speed) { this->speed = speed; }
