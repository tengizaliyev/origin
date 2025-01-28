#include <iostream>
#include <vector>
#include <memory>
#include <windows.h>
#include "Transport.h"
#include "LandTransport.h"
#include "AirTransport.h"
#include "Race.h"

void setupConsoleForRussian() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
}

void showMenu() {
    std::cout << "Добро пожаловать в гоночный симулятор!\n";
    std::cout << "1. Гонка для наземного транспорта\n";
    std::cout << "2. Гонка для воздушного транспорта\n";
    std::cout << "3. Гонка для наземного и воздушного транспорта\n";
    std::cout << "Выберите тип гонки: ";
}

void showRegisteredTransports(const std::vector<std::shared_ptr<Transport>>& participants) {
    std::cout << "Зарегистрированные транспортные средства: ";
    for (size_t i = 0; i < participants.size(); ++i) {
        std::cout << participants[i]->getName();
        if (i < participants.size() - 1) std::cout << ", ";
    }
    std::cout << "\n";
}

int main() {
    setupConsoleForRussian();

    while (true) {
        int raceTypeInput;
        showMenu();
        std::cin >> raceTypeInput;

        if (raceTypeInput < 1 || raceTypeInput > 3) {
            std::cout << "Неверный тип гонки. Завершение программы.\n";
            return 0;
        }

        double distance;
        std::cout << "Укажите длину дистанции (должна быть положительная): ";
        std::cin >> distance;

        Race race;
        std::vector<std::shared_ptr<Transport>> transports = {
            std::make_shared<LandTransport>("Верблюд", 10, 30, std::vector<double>{5, 8}),
            std::make_shared<LandTransport>("Верблюд-быстроход", 40, 10, std::vector<double>{5, 6.5, 8}),
            std::make_shared<LandTransport>("Кентавр", 15, 8, std::vector<double>{2}),
            std::make_shared<LandTransport>("Ботинки-вездеходы", 6, 60, std::vector<double>{10, 5}),
            std::make_shared<AirTransport>("Ковёр-самолёт", 10, 0.05),
            std::make_shared<AirTransport>("Орёл", 8, 0.06),
            std::make_shared<AirTransport>("Метла", 20, 0.01),
        };

        std::vector<std::shared_ptr<Transport>> filteredTransports;
        for (const auto& transport : transports) {
            if ((raceTypeInput == 1 && dynamic_cast<LandTransport*>(transport.get())) ||
                (raceTypeInput == 2 && dynamic_cast<AirTransport*>(transport.get())) ||
                (raceTypeInput == 3)) {
                filteredTransports.push_back(transport);
            }
        }

        while (true) {
            std::cout << "Выберите транспорт или 0 для окончания регистрации:\n";
            for (size_t i = 0; i < filteredTransports.size(); ++i) {
                std::cout << i + 1 << ". " << filteredTransports[i]->getName() << "\n";
            }
            std::cout << "0. Закончить регистрацию\n";

            int choice;
            std::cin >> choice;

            if (choice == 0) break;
            if (choice > 0 && choice <= filteredTransports.size()) {
                std::shared_ptr<Transport> selectedTransport = filteredTransports[choice - 1];

                bool alreadyRegistered = false;
                for (const auto& registered : race.getParticipants()) {
                    if (registered->getName() == selectedTransport->getName()) {
                        alreadyRegistered = true;
                        break;
                    }
                }

                if (!alreadyRegistered) {
                    race.registerTransport(selectedTransport);
                    std::cout << selectedTransport->getName() << " успешно зарегистрирован!\n";
                    showRegisteredTransports(race.getParticipants());
                }
                else {
                    std::cout << "Ошибка: " << selectedTransport->getName() << " уже зарегистрирован!\n";
                }
            }
            else {
                std::cout << "Неверный выбор. Попробуйте снова.\n";
            }
        }

        if (race.getParticipantsCount() < 2) {
            std::cout << "Для гонки необходимо минимум 2 участника. Начните регистрацию заново.\n";
            continue;
        }

        race.runRace(distance);
        race.printResults();

        std::cout << "1. Провести ещё одну гонку\n";
        std::cout << "2. Выйти\n";
        int action;
        std::cin >> action;

        if (action == 2) break;
    }

    return 0;
}
