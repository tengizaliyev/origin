#include "pch.h"
#include "Race.h"
#include <iostream>
#include <algorithm>

void Race::registerTransport(std::shared_ptr<Transport> transport) {
    for (const auto& participant : participants) {
        if (participant->getName() == transport->getName()) {
            std::cout << transport->getName() << " ��� ���������������!\n";
            return;
        }
    }
    participants.push_back(transport);
}

void Race::runRace(double distance) {
    for (auto& participant : participants) {
        // ��������� ������������ ����� ������ ���������
        double time = participant->calculateTime(distance);
        participant->setRaceTime(time); // ���������, ��� ����� setRaceTime ���� � ������ Transport
    }
}

void Race::printResults() const {
    std::vector<std::pair<std::string, double>> results;

    for (const auto& transport : participants) {
        results.emplace_back(transport->getName(), transport->getRaceTime()); // ���������, ��� getRaceTime ���� � ������ Transport
    }

    std::sort(results.begin(), results.end(), [](const auto& a, const auto& b) {
        return a.second < b.second;
        });

    for (size_t i = 0; i < results.size(); ++i) {
        std::cout << i + 1 << ". " << results[i].first << ". �����: " << results[i].second << "\n";
    }
}

// ���������� ������ ������
size_t Race::getParticipantsCount() const {
    return participants.size();
}
