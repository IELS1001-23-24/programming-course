int state = 0;

void updateStateMachine()
{
    switch (state)
    {
    case 0:
        Serial.println("Running 1");
        state += 1;
        break;
    case 1:
        Serial.println("Running 2");
        state += 1;
        break;
    case 2:
        Serial.println("Running 3");
        state += 1;
        break;
    case 3:
        Serial.println("Running 4");
        state += 1;
        break;
    case 4:
        Serial.println("Running 5");
        state += 1;
        break;
    case 5:
        Serial.println("Running 6");
        state = 0;
        break;
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
