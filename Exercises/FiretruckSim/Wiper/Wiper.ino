#include "FiretruckSim.h"

const int WIPER_PICKER_PIN = 13;
const int WIPER_PIN = 14;

void setup()
{
    Serial.begin(9600);
}

void loop()
{
    Serial.println("Hello World!");
    delay(1000);
}
