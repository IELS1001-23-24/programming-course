// Change the code so the message is only printed in one burst per button press.
// Making the message print exactly once will be in a later exercise.
// You are only allowed to change the code in the updatePrintFunction().
// Hint: You only have to add one line

const int BUTTON_PIN = 2;

bool buttonWasPressed = false;

// Is called by black magic in the arduino cpu when it detects
// a rising signal (from low to high) on the BUTTON_PIN.
void onButtonPress()
{
    buttonWasPressed = true;
}

void updatePrintFunction()
{
    if (buttonWasPressed)
    {
        Serial.println("Button was pressed!");
    }
}

void setup()
{
    Serial.begin(9600);

    pinMode(BUTTON_PIN, INPUT);

    // Register RISING signals on BUTTON_PIN to trigger a single call to the onButtonPress() function.
    attachInterrupt(digitalPinToInterrupt(BUTTON_PIN), onButtonPress, RISING);
}

void loop()
{
    updatePrintFunction();
}
