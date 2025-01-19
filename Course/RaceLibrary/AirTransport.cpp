#include "pch.h"
#include "AirTransport.h"

double AirTransport::calculateTime(double distance) const {
    double effectiveDistance = distance * (1.0 - reductionCoefficient);
    return effectiveDistance / speed;
}
