// Fix the code so "case 1:" runs for 5 seconds every time.
// Hint: Does the time difference start with a different value
// the second time the sequence runs compared to the first?

unsigned long timer = 0;

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
    {
        unsigned long timeDifference = millis() - timer;

        Serial.println("Running 2: " + String(timeDifference / 1000.0) + " sec");

        if (timeDifference >= 5000)
        {
            state += 1;
        }
        break;
    }
    case 2:
        Serial.println("Running 3");
        state += 1;
        break;
    case 3:
        Serial.println("Running 4");
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
