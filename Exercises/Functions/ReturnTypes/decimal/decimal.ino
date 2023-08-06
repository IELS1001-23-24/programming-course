// Find the correct return type for this function.
// Hint: Look at the output from the Serial Monitor. Is it the same as the number you expected?
// https://roboticsbackend.com/arduino-variable-types-complete-guide/

float getOnePointFive()
{
    return 1.5;
}

void setup()
{
    Serial.begin(9600);

    Serial.println(getOnePointFive());
}

void loop()
{
}
