// Recreate this codes functionality using a while loop instead of a for loop.

const int LED_PIN = 5;

void setup()
{
    Serial.begin(9600);

    pinMode(LED_PIN, OUTPUT);
}

void updateLed()
{
    for (int i = 0; i <= 255; i++)
    {
        analogWrite(LED_PIN, i);
        delay(10);
    }
}

void loop()
{
    updateLed();
}
