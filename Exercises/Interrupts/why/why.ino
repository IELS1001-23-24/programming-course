// Compare the number of times the message is printed with how
// many times the count increases in the serial monitor.
// Because Serial.print() is a slow function, the interrupt
// triggers multiple times during its execution,
// while the updateManualCount() function only gets to run once
// between every print.

const int BUTTON_PIN = 2;

volatile byte interruptCount = 0;
int manualCount = 0;

bool buttonWasPressed = false;

// Is called by black magic in the arduino cpu when it detects
// a rising signal (from low to high) on the BUTTON_PIN.
void onButtonPress()
{
    interruptCount++;
}

void updateManualCount()
{
    bool buttonIsPressed = digitalRead(BUTTON_PIN);
    if (buttonIsPressed && !buttonWasPressed)
    {
        manualCount++;
    }
    buttonWasPressed = buttonIsPressed;
}

void updatePrintFunction()
{
    unsigned long printTimer = millis();
    Serial.print("Manual Count: ");
    Serial.print(manualCount);
    Serial.print(", ");
    Serial.print("Interrupt Count: ");
    Serial.print(interruptCount);
    Serial.print(", ");
    Serial.print("Print time: ");
    Serial.print(millis() - printTimer);
    Serial.println(" ms");
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
    updateManualCount();
    updatePrintFunction();
}
