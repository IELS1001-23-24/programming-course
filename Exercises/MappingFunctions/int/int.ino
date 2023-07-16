// Complete the getType() mapping function

String getType(int value)
{
    if (value < 0)
    {
        return "Negative";
    }

    if (value < 10)
    {
        return "Small";
    }

    // TODO: Return "Medium" if value is less than 100

    return "Large";
}

void setup()
{
    Serial.begin(9600);
    Serial.println("Enter a number:");
}

void updateSerial()
{
    if (Serial.available() > 0)
    {
        int value = Serial.parseInt(SKIP_WHITESPACE, '\n');

        String type = getType(value);

        Serial.print("The number ");
        Serial.print(value);
        Serial.print(" is ");
        Serial.println(type);
    }
}

void loop()
{
    updateSerial();
}
