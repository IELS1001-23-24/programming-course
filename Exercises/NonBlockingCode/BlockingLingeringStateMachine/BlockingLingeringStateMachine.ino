void updateStateMachine()
{
    Serial.println("Running 1");
    
    while (true)
    {
        Serial.println("Running 2");

        // Send the character "1" into the serial monitor to
        // continue to the next state.
        if (Serial.read() == '1')
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
