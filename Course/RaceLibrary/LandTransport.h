#ifndef LANDTRANSPORT_H
#define LANDTRANSPORT_H

#include "Transport.h"
#include <vector>

class RACELIBRARY_API LandTransport : public Transport {
    double timeBeforeRest;
    std::vector<double> restDurations;

public:
    LandTransport(const std::string& name, double speed, double timeBeforeRest, const std::vector<double>& restDurations)
        : Transport(name, speed), timeBeforeRest(timeBeforeRest), restDurations(restDurations) {}

    double calculateTime(double distance) const override;
};

#endif // LANDTRANSPORT_H
