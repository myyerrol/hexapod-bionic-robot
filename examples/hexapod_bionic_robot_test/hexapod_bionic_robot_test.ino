#include <hexapod_bionic_robot.h>

float              g_distance = 0.0;
HexapodBionicRobot g_hexapod_bionic_robot;

void setup()
{
    Serial.begin(9600);
}

void loop()
{
    g_distance = g_hexapod_bionic_robot.getDistance();

    if (g_distance <= 5.0) {
        digitalWrite(PIN_LED, HIGH);
        Serial.println("Warning, Distance is too close!!!");
    }
    else {
        digitalWrite(PIN_LED, LOW);
    }

    Serial.print(g_distance);
    Serial.println("cm");
    delay(100);
}
