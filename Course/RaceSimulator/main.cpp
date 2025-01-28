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
    std::cout << "����� ���������� � �������� ���������!\n";
    std::cout << "1. ����� ��� ��������� ����������\n";
    std::cout << "2. ����� ��� ���������� ����������\n";
    std::cout << "3. ����� ��� ��������� � ���������� ����������\n";
    std::cout << "�������� ��� �����: ";
}

void showRegisteredTransports(const std::vector<std::shared_ptr<Transport>>& participants) {
    std::cout << "������������������ ������������ ��������: ";
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
            std::cout << "�������� ��� �����. ���������� ���������.\n";
            return 0;
        }

        double distance;
        std::cout << "������� ����� ��������� (������ ���� �������������): ";
        std::cin >> distance;

        Race race;
        std::vector<std::shared_ptr<Transport>> transports = {
            std::make_shared<LandTransport>("�������", 10, 30, std::vector<double>{5, 8}),
            std::make_shared<LandTransport>("�������-���������", 40, 10, std::vector<double>{5, 6.5, 8}),
            std::make_shared<LandTransport>("�������", 15, 8, std::vector<double>{2}),
            std::make_shared<LandTransport>("�������-���������", 6, 60, std::vector<double>{10, 5}),
            std::make_shared<AirTransport>("����-������", 10, 0.05),
            std::make_shared<AirTransport>("���", 8, 0.06),
            std::make_shared<AirTransport>("�����", 20, 0.01),
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
            std::cout << "�������� ��������� ��� 0 ��� ��������� �����������:\n";
            for (size_t i = 0; i < filteredTransports.size(); ++i) {
                std::cout << i + 1 << ". " << filteredTransports[i]->getName() << "\n";
            }
            std::cout << "0. ��������� �����������\n";

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
                    std::cout << selectedTransport->getName() << " ������� ���������������!\n";
                    showRegisteredTransports(race.getParticipants());
                }
                else {
                    std::cout << "������: " << selectedTransport->getName() << " ��� ���������������!\n";
                }
            }
            else {
                std::cout << "�������� �����. ���������� �����.\n";
            }
        }

        if (race.getParticipantsCount() < 2) {
            std::cout << "��� ����� ���������� ������� 2 ���������. ������� ����������� ������.\n";
            continue;
        }

        race.runRace(distance);
        race.printResults();

        std::cout << "1. �������� ��� ���� �����\n";
        std::cout << "2. �����\n";
        int action;
        std::cin >> action;

        if (action == 2) break;
    }

    return 0;
}
