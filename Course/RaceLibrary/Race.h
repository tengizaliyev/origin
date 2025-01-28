#ifndef RACE_H
#define RACE_H

#include <vector>
#include <memory>
#include "Transport.h"

class RACELIBRARY_API Race {
private:
    std::vector<std::shared_ptr<Transport>> participants;

public:
    void registerTransport(std::shared_ptr<Transport> transport);
    void runRace(double distance);
    void printResults() const;

    size_t getParticipantsCount() const;
    void showRegisteredTransports() const;


    const std::vector<std::shared_ptr<Transport>>& getParticipants() const;
};

#endif // RACE_H
