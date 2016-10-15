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
#define DIR_INIT    1
#define DIR_STOP    1
#define DIR_FRONT   2
#define DIR_BACK    3
#define DIR_LEFT    4
#define DIR_RIGHT   5
#define MODE_REMOTE 25
#define MODE_AUTO   26
#define RADIX       10
#define RUNTIME     2400
#define TIMEOUT     30000

class HexapodBionicRobot
{
public:
    HexapodBionicRobot(IRrecv *ir_receiver, decode_results *ir_results);
    void avoidFrontObstacle(void);
    void handleInfraredInformation(void);
    void handleUltrasonicDistance(void);
    void moveRobotBody(uint8_t direction, uint8_t times);
    uint32_t getInfraredInformation(void);
    float getUltrasonicDistance(void);
private:
    int             mode_flag_;
    float           duration_;
    float           distance_;
    IRrecv         *ir_receiver_;
    decode_results *ir_results_;
};

#endif // HEXAPOD_BIONIC_ROBOT_H
