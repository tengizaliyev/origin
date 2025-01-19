#ifndef AIRTRANSPORT_H
#define AIRTRANSPORT_H

#include "Transport.h"

class RACELIBRARY_API AirTransport : public Transport {
    double reductionCoefficient;

public:
    AirTransport(const std::string& name, double speed, double reductionCoefficient)
        : Transport(name, speed), reductionCoefficient(reductionCoefficient) {}

    double calculateTime(double distance) const override;
};

#endif // AIRTRANSPORT_H
