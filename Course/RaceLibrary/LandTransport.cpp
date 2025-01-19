#include "pch.h"
#include "LandTransport.h"

double LandTransport::calculateTime(double distance) const {
    double time = 0.0;
    double remainingDistance = distance;
    int restCount = 0;

    while (remainingDistance > 0) {
        if (remainingDistance <= speed * timeBeforeRest) {
            time += remainingDistance / speed;
            remainingDistance = 0;
        }
        else {
            time += timeBeforeRest;
            remainingDistance -= speed * timeBeforeRest;
            if (restCount < restDurations.size()) {
                time += restDurations[restCount++];
            }
            else {
                time += restDurations.back();
            }
        }
    }

    return time;
}
