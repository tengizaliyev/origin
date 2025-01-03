#pragma once
#ifndef RACE_SIMULATOR_H
#define RACE_SIMULATOR_H

#include <string>
#include <vector>
#include <memory>
#include <algorithm>
#include <iostream>

// Базовый класс для всех ТС
class Transport {
protected:
    std::string name;
    double speed;
public:
    Transport(std::string name, double speed) : name(name), speed(speed) {}
    virtual ~Transport() = default;

    std::string getName() const { return name; }
    virtual double calculateTime(double distance) const = 0;
};

// Наземный транспорт
class LandTransport : public Transport {
protected:
    double moveTime;
    double restTime;
    int firstRest;
    int secondRest;
public:
    LandTransport(std::string name, double speed, double moveTime, double restTime, int firstRest, int secondRest)
        : Transport(name, speed), moveTime(moveTime), restTime(restTime), firstRest(firstRest), secondRest(secondRest) {}

    double calculateTime(double distance) const override {
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
};

// Воздушный транспорт
class AirTransport : public Transport {
protected:
    double reductionCoefficient;
public:
    AirTransport(std::string name, double speed, double reductionCoefficient)
        : Transport(name, speed), reductionCoefficient(reductionCoefficient) {}

    double calculateTime(double distance) const override {
        double effectiveDistance = distance * (1 - reductionCoefficient);
        return effectiveDistance / speed;
    }
};

// Классы конкретных ТС
class Camel : public LandTransport {
public:
    Camel() : LandTransport("Верблюд", 10, 30, 0, 5, 8) {}
};

class FastCamel : public LandTransport {
public:
    FastCamel() : LandTransport("Верблюд-быстроход", 40, 10, 0, 5, 6) {}
};

class Centaur : public LandTransport {
public:
    Centaur() : LandTransport("Кентавр", 15, 8, 0, 2, 2) {}
};

class Boots : public LandTransport {
public:
    Boots() : LandTransport("Ботинки-вездеходы", 6, 60, 0, 10, 5) {}
};

class Carpet : public AirTransport {
public:
    Carpet() : AirTransport("Ковёр-самолёт", 10, 0.05) {}
};

class Eagle : public AirTransport {
public:
    Eagle() : AirTransport("Орёл", 8, 0.06) {}
};

class Broom : public AirTransport {
public:
    Broom() : AirTransport("Метла", 20, 0.01) {}
};

// Класс гонки
class Race {
private:
    double distance;
    std::vector<std::shared_ptr<Transport>> participants;
public:
    Race(double distance) : distance(distance) {}

    void addParticipant(std::shared_ptr<Transport> transport) {
        participants.push_back(transport);
    }

    void startRace() {
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
};

#endif // RACE_SIMULATOR_H
