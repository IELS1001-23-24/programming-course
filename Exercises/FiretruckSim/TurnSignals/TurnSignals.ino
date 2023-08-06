#include "FiretruckSim.h"

const int FLASH_LEFT_PICKER_PIN = 9;
const int FLASH_LEFT_PIN = 10;

const int FLASH_RIGHT_PICKER_PIN = 11;
const int FLASH_RIGHT_PIN = 12;

void setup()
{
    Serial.begin(9600);
}

void loop()
{
    Serial.println("Hello World!");
    delay(1000);
}
