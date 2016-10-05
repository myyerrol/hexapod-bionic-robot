#ifndef HEXAPOD_BIONIC_ROBOT_H
#define HEXAPOD_BIONIC_ROBOT_H

#include <Arduino.h>
#include <IRremote.h>

#define PIN_IR      2
#define PIN_TX      3
#define PIN_RX      4
#define PIN_TRIG    5
#define PIN_ECHO    6
#define PIN_LED     13
#define DIR_FORWARD 20
#define DIR_BACK    21
#define DIR_LEFT    22
#define DIR_RIGHT   23
#define DIR_STOP    24
#define TIMEOUT  30000

class HexapodBionicRobot
{
public:
    HexapodBionicRobot(IRrecv *ir_receiver, decode_results *ir_results);
    void handleInfraredInformation(void);
    void handleUltrasonicDistance(void);
    void moveRobotBody(uint8_t direction);
    uint32_t getInfraredInformation(void);
    float getUltrasonicDistance(void);
private:
    float           duration_;
    float           distance_;
    IRrecv         *ir_receiver_;
    decode_results *ir_results_;
};

#endif // HEXAPOD_BIONIC_ROBOT_H
