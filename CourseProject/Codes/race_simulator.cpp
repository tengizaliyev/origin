#include "race_simulator.h"
#include "pch.h"
#include <vector>
#include <algorithm>
#include <memory>
#include <iostream>
#include <string>

// Реализация методов LandTransport
double LandTransport::calculateTime(double distance) const {
    double time = 0;
    double traveled = 0;
    int rests = 0;
    while (traveled < distance) {
        if (traveled + moveTime * speed >= distance) {
            time += (distance - traveled) / speed;
            break;
        }
        traveled += moveTime * speed;
        time += moveTime;
        rests++;
        if (rests == 1) time += firstRest;
        else time += secondRest;
    }
    return time;
}

// Реализация методов AirTransport
double AirTransport::calculateTime(double distance) const {
    double effectiveDistance = distance * (1 - reductionCoefficient);
    return effectiveDistance / speed;
}

// Реализация методов Race
void Race::addParticipant(std::shared_ptr<Transport> transport) {
    participants.push_back(transport);
}

void Race::startRace() {
    std::vector<std::pair<std::string, double>> results;
    for (auto& participant : participants) {
        double time = participant->calculateTime(distance);
        results.emplace_back(participant->getName(), time);
    }
    std::sort(results.begin(), results.end(), [](const auto& a, const auto& b) {
        return a.second < b.second;
        });

    std::cout << "Результаты гонки:" << std::endl;
    for (const auto& result : results) {
        std::cout << result.first << ": " << result.second << " ч." << std::endl;
    }
}
