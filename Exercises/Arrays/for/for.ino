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

    for (int i = 0; i < 3; i++)
    {
        Serial.print(characters[i]);
        Serial.print(": ");
        Serial.println(quotes[i]);
    }
}

void loop()
{
}
