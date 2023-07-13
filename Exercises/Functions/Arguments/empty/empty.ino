// Find the correct parameter for this function.

void printMessage()
{
    Serial.print("I need no arguments, but i will still print: ");
    Serial.println("Hello World!");
}

void setup()
{
    Serial.begin(9600);

    printMessage();
}

void loop()
{
}
