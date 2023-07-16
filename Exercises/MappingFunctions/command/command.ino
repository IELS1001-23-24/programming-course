// Complete the stringFrom() mapping function

enum class LedMode
{
    OFF,
    ON
};

const int LED_PIN = 5;

LedMode ledMode = LedMode::OFF;

LedMode ledModeFrom(char command)
{
    switch (command)
    {
    case '0':
        return LedMode::OFF;
    case '1':
        return LedMode::ON;
    default:
        return LedMode::OFF;
    }
}

String stringFrom(LedMode ledMode)
{
    // TODO: Delete this and implement the correct logic
    return "ON";
}

String messageFrom(LedMode newLedMode, LedMode oldLedMode)
{
    String mode = stringFrom(newLedMode);

    if (oldLedMode == newLedMode)
    {
        return "The LED is already " + mode;
    }

    return "Switching LED " + mode;
}

void updateSerial()
{
    if (Serial.available() > 0)
    {
        int value = Serial.read();

        if (value != '\n')
        {
            LedMode newLedMode = ledModeFrom(value);
            Serial.println(messageFrom(newLedMode, ledMode));
            ledMode = newLedMode;
        }
    }
}

void updateLed()
{
    switch (ledMode)
    {
    case LedMode::OFF:
        digitalWrite(LED_PIN, LOW);
        break;
    case LedMode::ON:
        digitalWrite(LED_PIN, HIGH);
        break;
    }
}

void setup()
{
    Serial.begin(9600);

    pinMode(LED_PIN, OUTPUT);

    Serial.println("Enter the number '1' or '0':");
}

void loop()
{
    updateSerial();
    updateLed();
}
