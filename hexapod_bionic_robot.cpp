#include "hexapod_bionic_robot.h"

// IRrecv         g_ir_recv(PIN_IR);
// decode_results g_decode_results;

HexapodBionicRobot::HexapodBionicRobot(IRrecv *ir_recviver,
                                       decode_results *ir_results)
    : ir_receiver_(ir_recviver),
      ir_results_(ir_results)
{
    pinMode(PIN_LED, OUTPUT);
    pinMode(PIN_TRIG, OUTPUT);
    pinMode(PIN_ECHO, INPUT);

    // g_ir_recv.enableIRIn();

    duration_ = 0.0;
    distance_ = 0.0;
}

void HexapodBionicRobot::handleUltrasonicDistance(void)
{
    float distance = getUltrasonicDistance();

    if (distance == false) {
        Serial.println("No data for ultrasonic sensor!!!");
    }
    else if (distance <= 5.0) {
        digitalWrite(PIN_LED, HIGH);
        Serial.println("Warning! Distance is too close!!!");
    }
    else {
        digitalWrite(PIN_LED, LOW);
    }

    Serial.print("Distance: ");
    Serial.print(distance);
    Serial.println("cm");
    delay(100);
}

void HexapodBionicRobot::handleInfraredInformation(void)
{
    uint32_t ir_results = getInfraredInformation();

    if (ir_results == false) {
        return ;
    }
    else {
        Serial.print("Infrared code: ");
        Serial.println(ir_results, HEX);
        if (ir_results == 0XFF22DD) {
            digitalWrite(PIN_LED, HIGH);
        }
        else if (ir_results == 0XFFA25D) {
            digitalWrite(PIN_LED, LOW);
        }
    }
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
