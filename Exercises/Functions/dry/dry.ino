// Make this code less repetitive by creating
// a function to print a single number

void printNumbers()
{
    Serial.print("Here is a number: ");
    Serial.println(1);

    Serial.print("Here is a number: ");
    Serial.println(2);

    Serial.print("Here is a number: ");
    Serial.println(3);

    Serial.print("Here is a number: ");
    Serial.println(4);

    Serial.print("Here is a number: ");
    Serial.println(5);

    Serial.print("Here is a number: ");
    Serial.println(6);

    Serial.print("Here is a number: ");
    Serial.println(7);

    Serial.print("Here is a number: ");
    Serial.println(8);

    Serial.print("Here is a number: ");
    Serial.println(9);

    Serial.print("Here is a number: ");
    Serial.println(10);
}

void setup()
{
    Serial.begin(9600);

    printNumbers();
}

void loop()
{
}
