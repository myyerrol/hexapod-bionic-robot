#include <SoftwareSerial.h>
#include "hexapod_bionic_robot.h"

HexapodBionicRobot::HexapodBionicRobot(IRrecv *ir_recviver,
                                       decode_results *ir_results)
    : ir_receiver_(ir_recviver),
      ir_results_(ir_results)
{
    pinMode(PIN_LED, OUTPUT);
    pinMode(PIN_TRIG, OUTPUT);
    pinMode(PIN_ECHO, INPUT);

    mode_flag_ = MODE_REMOTE;

    duration_ = 0.0;
    distance_ = 0.0;
}

void HexapodBionicRobot::handleUltrasonicDistance(void)
{
    float distance = getUltrasonicDistance();

    if (distance == false) {
        return ;
    }
    else if (distance <= 5.0) {
        digitalWrite(PIN_LED, HIGH);
#if DEBUG
        Serial.println("Warning! Distance is too close!!!");
#endif
    }
    else {
        digitalWrite(PIN_LED, LOW);
    }
#if DEBUG
    Serial.print("Distance: ");
    Serial.print(distance);
    Serial.println("cm");
#endif
    delay(100);
}

void HexapodBionicRobot::handleInfraredInformation(void)
{
    float distance = 0.0;
    uint32_t ir_results = getInfraredInformation();

    if (ir_results == false) {
        return ;
    }
    else {
#if DEBUG
        Serial.print("Infrared code: ");
        Serial.println(ir_results, HEX);
#endif
        if (ir_results == 0XFF629D) {
            mode_flag_ = MODE_REMOTE;
        }
        else if (ir_results == 0XFFE21D) {
            mode_flag_ = MODE_AUTO;
        }

        if (mode_flag_ == MODE_REMOTE) {
            digitalWrite(PIN_LED, LOW);
            if (ir_results == 0xFF02FD) {
                moveRobotBody(DIR_FRONT, 1);
            }
            else if (ir_results == 0xFF9867) {
                moveRobotBody(DIR_BACK, 1);
            }
            else if (ir_results == 0xFFE01F) {
                moveRobotBody(DIR_LEFT, 1);
            }
            else if (ir_results == 0xFF906f) {
                moveRobotBody(DIR_RIGHT, 1);
            }
            else if (ir_results == 0xFFA857) {
                moveRobotBody(DIR_STOP, 1);
            }

        }
        else if (mode_flag_ == MODE_AUTO) {
            digitalWrite(PIN_LED, HIGH);
            while (ir_results != 0XFF629D) {
                ir_results = getInfraredInformation();
                moveRobotBody(DIR_FRONT, 1);
                delay(2000);
            }
            mode_flag_ = MODE_REMOTE;
        }
    }
}

void HexapodBionicRobot::moveRobotBody(uint8_t direction, uint8_t times)
{
    char string_direction[5];
    char string_times[5];

    itoa(direction, string_direction, RADIX);
    itoa(times, string_times, RADIX);

    Serial.print("#");
    Serial.print(string_direction);
    Serial.print("G");
    Serial.print(string_times);
    Serial.println("C");
}

uint32_t HexapodBionicRobot::getInfraredInformation(void)
{
    if (ir_receiver_->decode(ir_results_)) {
        ir_receiver_->resume();
        return ir_results_->value;
    }
    else {
        return false;
    }
}

float HexapodBionicRobot::getUltrasonicDistance(void)
{
    duration_ = 0.0;
    distance_ = 0.0;

    digitalWrite(PIN_TRIG, LOW);
    delayMicroseconds(10);
    digitalWrite(PIN_TRIG, HIGH);
    delayMicroseconds(10);
    digitalWrite(PIN_TRIG, LOW);

    duration_ = pulseIn(PIN_ECHO, HIGH, TIMEOUT);

    if (duration_ == 0.0) {
        return false;
    }
    else {
        distance_ = duration_ * 0.017;
        return distance_;
    }
}
