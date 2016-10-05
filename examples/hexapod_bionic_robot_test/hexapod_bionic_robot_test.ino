#include <hexapod_bionic_robot.h>

char               g_char = 0;
HexapodBionicRobot g_hexapod_bionic_robot;

void setup()
{
    Serial.begin(9600);
    pinMode(13, OUTPUT);
}

void loop()
{
    // float distance = g_hexapod_bionic_robot.getDistance();

    // if (distance <= 5.0) {
    //     digitalWrite(13, HIGH);
    // }
    // else {
    //     digitalWrite(13, LOW);
    // }

    // Serial.print("Distance: ");
    // Serial.println(g_hexapod_bionic_robot.getDistance());
    // Serial.print("cm");

    if (Serial.available()) {
        g_char = Serial.read();
        if (g_char == 'a') {
            digitalWrite(13, HIGH);
            Serial.println("Pin On!");
        }
        else if (g_char == 'b') {
            digitalWrite(13, LOW);
            Serial.println("Pin Off!");
        }
    }
}
