#include "pch.h"
#include "Race.h"
#include <iostream>
#include <algorithm>

void Race::registerTransport(std::shared_ptr<Transport> transport) {
    for (const auto& participant : participants) {
        if (participant->getName() == transport->getName()) {
            std::cout << transport->getName() << " уже зарегистрирован!\n";
            return;
        }
    }
    participants.push_back(transport);
}

void Race::runRace(double distance) {
    for (auto& participant : participants) {
        double time = participant->calculateTime(distance);
        participant->setRaceTime(time);
    }
}

void Race::printResults() const {
    std::vector<std::pair<std::string, double>> results;

    for (const auto& transport : participants) {
        results.emplace_back(transport->getName(), transport->getRaceTime());
    }

    std::sort(results.begin(), results.end(), [](const auto& a, const auto& b) {
        return a.second < b.second;
        });

    for (size_t i = 0; i < results.size(); ++i) {
        std::cout << i + 1 << ". " << results[i].first << ". Время: " << results[i].second << "\n";
    }
}

size_t Race::getParticipantsCount() const {
    return participants.size();
}

void Race::showRegisteredTransports() const {
    std::cout << "Зарегистрированные транспортные средства: ";
    for (size_t i = 0; i < participants.size(); ++i) {
        std::cout << participants[i]->getName();
        if (i < participants.size() - 1) std::cout << ", ";
    }
    std::cout << "\n";
}

// Реализация метода getParticipants()
const std::vector<std::shared_ptr<Transport>>& Race::getParticipants() const {
    return participants;
}
