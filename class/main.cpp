#include <iostream>
#include "Player.h"
#include "Warrior.h"
#include "Magician.h"
#include "Thief.h"
#include "Archer.h"
#include "Monster.h"
using namespace std;

int main() {
    string jobs[] = { "전사", "마법사", "도적", "궁수" };
    int job_choice = 0;
    string nickname;

    Player* player = nullptr;

    cout << "* 닉네임을 입력해주세요: ";
    cin >> nickname;

    cout << "<전직 시스템>" << endl;
    cout << nickname << "님, 환영합니다!" << endl;
    cout << "* 원하시는 직업을 선택해주세요." << endl;

    for (int i = 0; i < 4; i++) {
        cout << (i + 1) << ". " << jobs[i] << endl;
    }

    cout << "선택: ";
    cin >> job_choice;

    switch (job_choice) {
    case 1:
        player = new Warrior(nickname);
        cout << nickname << "님은 전사로 전직하였습니다!" << endl;
        break;
    case 2:
        player = new Magician(nickname);
        cout << nickname << "님은 마법사로 전직하였습니다!" << endl;
        break;
    case 3:
        player = new Thief(nickname);
        cout << nickname << "님은 도적으로 전직하였습니다!" << endl;
        break;
    case 4:
        player = new Archer(nickname);
        cout << nickname << "님은 궁수로 전직하였습니다!" << endl;
        break;
    default:
        cout << "잘못된 입력입니다." << endl;
        return 1;
    }

    player->printPlayerStatus();

    Monster slime("슬라임");
    cout << "\n*** 전투 개시! ***" << endl;

    while (player->getHP() > 0 && slime.getHP() > 0) {
        player->attack(&slime);
        if (slime.getHP() <= 0) break;

        slime.attack(player);
        if (player->getHP() <= 0) break;
    }

    delete player;
    return 0;
}
