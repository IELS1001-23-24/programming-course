void updateStateMachine()
{
    Serial.println("Running 1");
    delay(1000);
    Serial.println("Running 2");
    delay(1000);
    Serial.println("Running 3");
    delay(1000);
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
}
