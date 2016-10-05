#ifndef HEXAPOD_BIONIC_ROBOT_H
#define HEXAPOD_BIONIC_ROBOT_H

#include <Arduino.h>

#define TIMEOUT  30000
#define PIN_LED  13
#define PIN_TRIG 5
#define PIN_ECHO 6

class HexapodBionicRobot
{
public:
    HexapodBionicRobot(void);
    float getDistance(void);
private:
};

#endif // HEXAPOD_BIONIC_ROBOT_H