// Fix the code so the while loop runs for 5 seconds every time.
// Hint: Does the time difference start with a different value
// the second time the sequence runs compared to the first?

unsigned long timer = 0;

void updateStateMachine()
{
    Serial.println("Running 1");

    while (true)
    {
        unsigned long timeDifference = millis() - timer;

        Serial.println("Running 2: " + String(timeDifference / 1000.0) + " sec");

        if (timeDifference >= 5000)
        {
            break;
        }

        delay(1000);
    }

    Serial.println("Running 3");
    Serial.println("Running 4");
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
