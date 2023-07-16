const int LED_PIN = 5;

unsigned long loopTimer = 0;

void setup()
{
    Serial.begin(9600);

    pinMode(LED_PIN, OUTPUT);
}

void updateLed()
{
    for (int iUp = 0; iUp <= 255; iUp += 5)
    {
        analogWrite(LED_PIN, iUp);
        Serial.println("iUp: " + String(iUp));
        delay(100);
    }

    for (int iDown = 255; iDown >= 0; iDown -= 5)
    {
        analogWrite(LED_PIN, iDown);
        Serial.println("iDown: " + String(iDown));
        delay(100);
    }
}

void loop()
{
    loopTimer = micros();
    updateLed();
    Serial.println("Loop time: " + String(micros() - loopTimer) + " microseconds");

    // Pause the program so the loop time is readable
    delay(10000);
}
