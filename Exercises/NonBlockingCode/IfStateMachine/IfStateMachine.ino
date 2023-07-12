int state = 0;

void updateStateMachine()
{
    if (state == 0)
    {
        Serial.println("Running 1");
        state = 1;
    }
    else if (state == 1)
    {
        Serial.println("Running 2");
        state = 2;
    }
    else if (state == 2)
    {
        Serial.println("Running 3");
        state = 0;
    }
}

void setup()
{
    Serial.begin(9600);
}

void loop()
{
    Serial.println("Loop Start");
    delay(500);
    updateStateMachine();
    delay(1000);
}
