#include <iostream>
#include <memory>
#include "../RaceLibrary/race_simulator.h"

using namespace std;

int main() {
    cout << "Добро пожаловать в гоночный симулятор!" << endl;

    double distance;
    cout << "Введите дистанцию для гонки: ";
    cin >> distance;

    Race race(distance);

    cout << "Выберите транспорт для гонки:" << endl;
    cout << "1. Верблюд\n2. Быстроходный верблюд\n3. Кентавр\n4. Ботинки-вездеходы\n";
    cout << "5. Ковёр-самолёт\n6. Орёл\n7. Метла\n";
    cout << "0. Закончить регистрацию" << endl;

    int choice;
    while (true) {
        cout << "Выбор: ";
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
        default: cout << "Неверный выбор!" << endl;
        }
    }

    cout << "Гонка началась!" << endl;
    race.startRace();

    return 0;
}
