// Find the correct parameter for this function.

void printValue(bool value)
{
    Serial.print("The value of my first and only argument is: ");

    if (value)
    {
        Serial.println("true");
    }
    else
    {
        Serial.println("false");
    }
}

void setup()
{
    Serial.begin(9600);

    printValue(true);
}

void loop()
{
}
