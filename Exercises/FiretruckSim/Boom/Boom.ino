#include "FiretruckSim.h"

const int BOOM_UP_PICKER_PIN = 15;
const int BOOM_DOWN_PICKER_PIN = 16;
const int BOOM_ELEVATION_PIN = 18;

const int BOOM_LEFT_PICKER_PIN = 19;
const int BOOM_RIGHT_PICKER_PIN = 20;
const int BOOM_ROTATION_PIN = 22;

const int BOOM_ELBOW_OUT_PICKER_PIN = 23;
const int BOOM_ELBOW_IN_PICKER_PIN = 24;
const int BOOM_ELBOW_PIN = 25;

const int BOOM_WRIST_PIN = 28;

void setup()
{
    Serial.begin(9600);
}

void loop()
{
    Serial.println("Hello World!");
    delay(1000);
}
