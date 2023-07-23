int pins[] = {
    2,
    3,
    4,
    5,
    6,
    7,
    8,
    9,
};

void setup()
{
    Serial.begin(9600);

    // This is considered non-blocking code because
    // it is very fast (the for-loop takes milliseconds to run)
    for (int pin : pins)
    {
        pinMode(pin, OUTPUT);
    }
}

void loop()
{
    // This is considered blocking code because it is slow
    // (the for-loop takes seconds to run)
    for (int pin : pins)
    {
        digitalWrite(pin, HIGH);
        delay(100);
    }

    for (int pin : pins)
    {
        digitalWrite(pin, LOW);
        delay(100);
    }
}
