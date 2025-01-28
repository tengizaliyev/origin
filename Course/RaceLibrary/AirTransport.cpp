#include "pch.h"
#include "AirTransport.h"

double AirTransport::calculateTime(double distance) const {
    double effectiveDistance = distance * (1.0 - (static_cast<int>(distance / 1000) * reductionCoefficient));
    return effectiveDistance / speed;
}
