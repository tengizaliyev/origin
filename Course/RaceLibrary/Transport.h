#ifndef TRANSPORT_H
#define TRANSPORT_H

#include <string>

#ifdef RACELIBRARY_EXPORTS
#define RACELIBRARY_API __declspec(dllexport)
#else
#define RACELIBRARY_API __declspec(dllimport)
#endif

class RACELIBRARY_API Transport {
protected:
    std::string name;
    double speed;
    double raceTime; // Сохраняем время гонки
public:
    Transport(const std::string& name, double speed);
    virtual ~Transport() = default;

    virtual double calculateTime(double distance) const = 0;
    std::string getName() const { return name; }
    double getSpeed() const { return speed; }
    void setRaceTime(double time) { raceTime = time; }
    double getRaceTime() const { return raceTime; }
};

#endif // TRANSPORT_H
