void setup()
{
    Serial.begin(9600);

    bool value = true;
    String message = value ? "The value is true" : "The value is false";
    Serial.println(message);

    int otherValue = 1;
    Serial.println(otherValue == 1 ? "The other value is 1" : "The other value is not 1");
}

void loop()
{
}
