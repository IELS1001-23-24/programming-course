// Find the correct parameter for this function.

void printValue()
{
    Serial.print("The value of my first and only argument is: ");
    Serial.println(value);
}

void setup()
{
    Serial.begin(9600);

    printValue("Hello World!");
}

void loop()
{
}
