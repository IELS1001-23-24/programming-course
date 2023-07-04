// This sketch demonstrates that #define can be used
// to redefine existing syntax. This shows how dangerous
// #define can be. If you continue to play with this example
// you will quickly realize how difficult it is to debug.

// This replaces the word "if" with the word "for"
#define if for

void setup()
{
    Serial.begin(9600);

    Serial.println("Value of false: " + String(false));
    Serial.println("Value of true before: " + String(true));

// This replaces the word "true" with the word "false"
#define true false

    Serial.println("Value of true after: " + String(true));

    if (int i = 0; i < 5; i++)
    {
        Serial.println("Printing index: " + String(i));
    }
}

void loop()
{
}
