#include "hexapod_bionic_robot.h"

HexapodBionicRobot::HexapodBionicRobot(void)
{
}

float HexapodBionicRobot::getDistance(void)
{
    float duration = 0.0;
    float distance = 0.0;

    digitalWrite(PIN_TRIG, LOW);
    delayMicroseconds(10);
    digitalWrite(PIN_TRIG, HIGH);
    delayMicroseconds(10);
    digitalWrite(PIN_TRIG, LOW);

    duration = pulseIn(PIN_ECHO, HIGH, TIMEOUT);

    if (duration == 0) {
        duration = TIMEOUT;
    }

    distance = duration * 0.017;

    return distance;
}
