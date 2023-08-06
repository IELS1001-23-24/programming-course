// Find the correct return type for this function.
// Hint
// https://roboticsbackend.com/arduino-variable-types-complete-guide/

int getOne()
{
    return 1;
}

void setup()
{
    Serial.begin(9600);

    Serial.println(getOne());
}

void loop()
{
}
