// Find a way to make the code run while still
// creating the variable x inside case 0.
// Hint:
// https://www.fayewilliams.com/2011/10/26/declaring-variables-in-switch-statements/

void setup()
{
    Serial.begin(9600);
}

void updateSwitch()
{
    Serial.println("Switch start");
    switch (1)
    {
    case 0:
        // Comment out the next line to fix the code.
        int x = 0;
        Serial.println("A");
        break;
    case 1:
        Serial.println("B");
        break;
    }
    Serial.println("Switch end");
}

void loop()
{
    updateSwitch();
    delay(1000);
}
