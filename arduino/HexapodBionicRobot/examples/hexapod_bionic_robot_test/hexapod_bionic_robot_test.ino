#include <IRremote.h>
#include <hexapod_bionic_robot.h>

IRrecv         g_ir_receiver(PIN_IR);
decode_results g_ir_results;

void setup()
{
    Serial.begin(115200);
    Serial.println("#1G2C");
    g_ir_receiver.enableIRIn();
}

void loop()
{
    HexapodBionicRobot hexapod_bionic_robot(&g_ir_receiver, &g_ir_results);
    hexapod_bionic_robot.handleInfraredInformation();
}
