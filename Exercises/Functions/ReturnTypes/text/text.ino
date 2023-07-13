// Find the correct return type for this function.
// Hint
// https://roboticsbackend.com/arduino-variable-types-complete-guide/

void getHello()
{
    return "Hello World!";
}

void setup()
{
    Serial.begin(9600);

    String hello = getHello();
    Serial.println(hello);
}

void loop()
{
}
