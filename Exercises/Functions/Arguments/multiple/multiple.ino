// Find the correct parameters for this function.

void printValue(char letter, int number, float decimal)
{
    Serial.print("Here is a letter: ");
    Serial.println(letter);

    Serial.print("Here is a number: ");
    Serial.println(number);

    Serial.print("Here is a decimal number: ");
    Serial.println(decimal);
}

void setup()
{
    Serial.begin(9600);

    printValue('a', 1, 1.5);
}

void loop()
{
}
