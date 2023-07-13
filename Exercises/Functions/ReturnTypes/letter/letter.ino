// Find the correct return type for this function.
// Hint: Look at the output from the Serial Monitor. Is it the same as you expected?
// https://www.asciitable.com/
// https://roboticsbackend.com/arduino-variable-types-complete-guide/

int getLetter()
{
    return 'a';
}

void setup()
{
    Serial.begin(9600);

    Serial.println(getLetter());
}

void loop()
{
}
