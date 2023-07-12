// Recreate this codes functionality using if-statements instead of while-loops.

const int BUTTON_PIN = 2;

void setup()
{
    Serial.begin(9600);

    pinMode(BUTTON_PIN, INPUT);
}

void loop()
{
    while (digitalRead(BUTTON_PIN))
    {
        Serial.println("1");
    }
    while (!digitalRead(BUTTON_PIN))
    {
        Serial.println("0");
    }
}
