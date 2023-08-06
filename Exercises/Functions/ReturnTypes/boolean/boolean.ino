// Find the correct return type for this function.
// Hint
// https://roboticsbackend.com/arduino-variable-types-complete-guide/

bool getTrue()
{
    return true;
}

void setup()
{
    Serial.begin(9600);

    if (getTrue())
    {
        Serial.println("true");
    }
    else
    {
        Serial.println("false");
    }
}

void loop()
{
}
