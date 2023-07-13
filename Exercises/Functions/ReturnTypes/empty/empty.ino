// Find the correct return type for this function.
// Hint
// https://roboticsbackend.com/arduino-variable-types-complete-guide/

String printHello()
{
    Serial.print("Hello World!");
}

void setup()
{
    Serial.begin(9600);

    printHello();
}

void loop()
{
}
