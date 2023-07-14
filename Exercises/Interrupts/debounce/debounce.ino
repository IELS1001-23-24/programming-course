// Button bounce was disabled in the previous simulation.
// Run the sketch and watch each button press trigger multiple messages.
// Fix the program using non-blocking debouncing so only one message is printed per button press.
// You can only add global variables and change the code in the updatePrintFunction().

const int BUTTON_PIN = 2;

bool buttonWasPressed = false;

void onButtonPress()
{
    buttonWasPressed = true;
}

void updatePrintFunction()
{
    if (buttonWasPressed)
    {
        Serial.println("Button was pressed!");
        buttonWasPressed = false;
    }
}

void setup()
{
    Serial.begin(9600);

    pinMode(BUTTON_PIN, INPUT);
    attachInterrupt(digitalPinToInterrupt(BUTTON_PIN), onButtonPress, RISING);
}

void loop()
{
    updatePrintFunction();
}
