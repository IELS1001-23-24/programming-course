void setup()
{
    Serial.begin(9600);

    String characters[] = {
        "Tony Stark",
        "Groot",
        "Thanos",
    };

    String quotes[] = {
        "I am Ironman",
        "I am Groot",
        "I am inevitable",
    };

    Serial.print(characters[0]);
    Serial.print(": ");
    Serial.println(quotes[0]);

    Serial.print(characters[1]);
    Serial.print(": ");
    Serial.println(quotes[1]);

    Serial.print(characters[2]);
    Serial.print(": ");
    Serial.println(quotes[2]);
}

void loop()
{
}