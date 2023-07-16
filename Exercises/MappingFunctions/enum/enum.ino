// Add the size MEDIUM for values between 10 and 100.

enum class Size
{
    Negative,
    Small,
    Large
};

Size sizeFrom(int value)
{
    if (value < 0)
    {
        return Size::Negative;
    }

    if (value < 10)
    {
        return Size::Small;
    }

    return Size::Large;
}

String labelFrom(Size value)
{
    switch (value)
    {
    case Size::Negative:
        return "Negative";
    case Size::Small:
        return "Small";
    case Size::Large:
        return "Large";
    }
}

void setup()
{
    Serial.begin(9600);
    Serial.println("Enter a number:");
}

void updateSerial()
{
    if (Serial.available() > 0)
    {
        int value = Serial.parseInt(SKIP_WHITESPACE, '\n');

        Size size = sizeFrom(value);

        String label = labelFrom(size);

        Serial.print("The number ");
        Serial.print(value);
        Serial.print(" is ");
        Serial.println(label);
    }
}

void loop()
{
    updateSerial();
}
