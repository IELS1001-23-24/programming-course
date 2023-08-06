#include "FiretruckSim.h"

const int HEADLIGHTS_PICKER_PIN = 7;
const int HEADLIGHTS_PIN = 8;

void setup()
{
    Serial.begin(9600);
}

void loop()
{
    Serial.println("Hello World!");
    delay(1000);
}
