#include <iostream>
#include "Player.h"
#include "Warrior.h"
#include "Magician.h"
#include "Thief.h"
#include "Archer.h"
#include "Monster.h"
using namespace std;

int main() {
    string jobs[] = { "����", "������", "����", "�ü�" };
    int job_choice = 0;
    string nickname;

    Player* player = nullptr;

    cout << "* �г����� �Է����ּ���: ";
    cin >> nickname;

    cout << "<���� �ý���>" << endl;
    cout << nickname << "��, ȯ���մϴ�!" << endl;
    cout << "* ���Ͻô� ������ �������ּ���." << endl;

    for (int i = 0; i < 4; i++) {
        cout << (i + 1) << ". " << jobs[i] << endl;
    }

    cout << "����: ";
    cin >> job_choice;

    switch (job_choice) {
    case 1:
        player = new Warrior(nickname);
        cout << nickname << "���� ����� �����Ͽ����ϴ�!" << endl;
        break;
    case 2:
        player = new Magician(nickname);
        cout << nickname << "���� ������� �����Ͽ����ϴ�!" << endl;
        break;
    case 3:
        player = new Thief(nickname);
        cout << nickname << "���� �������� �����Ͽ����ϴ�!" << endl;
        break;
    case 4:
        player = new Archer(nickname);
        cout << nickname << "���� �ü��� �����Ͽ����ϴ�!" << endl;
        break;
    default:
        cout << "�߸��� �Է��Դϴ�." << endl;
        return 1;
    }

    player->printPlayerStatus();

    Monster slime("������");
    cout << "\n*** ���� ����! ***" << endl;

    while (player->getHP() > 0 && slime.getHP() > 0) {
        player->attack(&slime);
        if (slime.getHP() <= 0) break;

        slime.attack(player);
        if (player->getHP() <= 0) break;
    }

    delete player;
    return 0;
}
