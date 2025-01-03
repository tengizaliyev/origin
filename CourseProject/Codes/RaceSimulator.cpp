#include <iostream>
#include <memory>
#include "../RaceLibrary/race_simulator.h"

using namespace std;

int main() {
    cout << "����� ���������� � �������� ���������!" << endl;

    double distance;
    cout << "������� ��������� ��� �����: ";
    cin >> distance;

    Race race(distance);

    cout << "�������� ��������� ��� �����:" << endl;
    cout << "1. �������\n2. ������������ �������\n3. �������\n4. �������-���������\n";
    cout << "5. ����-������\n6. ���\n7. �����\n";
    cout << "0. ��������� �����������" << endl;

    int choice;
    while (true) {
        cout << "�����: ";
        cin >> choice;

        if (choice == 0) break;
        switch (choice) {
        case 1: race.addParticipant(make_shared<Camel>()); break;
        case 2: race.addParticipant(make_shared<FastCamel>()); break;
        case 3: race.addParticipant(make_shared<Centaur>()); break;
        case 4: race.addParticipant(make_shared<Boots>()); break;
        case 5: race.addParticipant(make_shared<Carpet>()); break;
        case 6: race.addParticipant(make_shared<Eagle>()); break;
        case 7: race.addParticipant(make_shared<Broom>()); break;
        default: cout << "�������� �����!" << endl;
        }
    }

    cout << "����� ��������!" << endl;
    race.startRace();

    return 0;
}
