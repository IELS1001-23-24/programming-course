const int LED_PIN = 5;
const int BUTTON_PIN = 2;

bool buttonDebouncedState = false;
bool buttonPreviousState = false;
bool buttonRisingEdge = false;
bool buttonFallingEdge = false;
unsigned long buttonDebounceDuration = 50;
unsigned long buttonDebounceTimer = 0;

unsigned long ledPulseDuration = 0;
unsigned long ledTimer = 0;

// Returns true if the duration has passed
bool buttonDebounceTimerIsFinished(unsigned long duration)
{
    return (millis() - buttonDebounceTimer) >= duration;
}

void buttonDebounceTimerReset()
{
    buttonDebounceTimer = millis();
}

void buttonUpdateDebouncedState()
{
    // Prevent this function from running until
    // the debounce timer has finished
    if (!buttonDebounceTimerIsFinished(buttonDebounceDuration))
    {
        return;
    }

    bool newButtonState = digitalRead(BUTTON_PIN);

    if (buttonDebouncedState != newButtonState)
    {
        buttonDebounceTimerReset();
    }

    buttonDebouncedState = newButtonState;
}

void buttonUpdateEdgeDetection()
{
    buttonRisingEdge = buttonDebouncedState && !buttonPreviousState;
    buttonFallingEdge = !buttonDebouncedState && buttonPreviousState;
    buttonPreviousState = buttonDebouncedState;
}

void buttonUpdate()
{
    buttonUpdateDebouncedState();
    buttonUpdateEdgeDetection();
}

void buttonSetup()
{
    pinMode(BUTTON_PIN, INPUT);
}

// Returns true if the duration has passed
bool ledTimerIsFinished(unsigned long duration)
{
    if ((millis() - ledTimer) >= duration)
    {
        return true;
    }

    return false;
}

void ledTimerReset()
{
    ledTimer = millis();
}

void ledOn()
{
    digitalWrite(LED_PIN, HIGH);
}

void ledOff()
{
    digitalWrite(LED_PIN, LOW);
}

void ledPulse(int duration)
{
    ledPulseDuration = duration;
    ledOn();
    ledTimerReset();
}

void ledUpdate()
{
    if (ledTimerIsFinished(ledPulseDuration))
    {
        ledOff();
    }
}

void ledSetup()
{
    pinMode(LED_PIN, OUTPUT);
}

void updateLedControls()
{
    // Pulse the LED for 100ms when the button is pressed
    if (buttonRisingEdge)
    {
        ledPulse(100);
    }

    // Pulse the LED for 1s when the button is released
    if (buttonFallingEdge)
    {
        ledPulse(1000);
    }
}

void setup()
{
    Serial.begin(9600);

    buttonSetup();
    ledSetup();
}

void loop()
{
    buttonUpdate();
    updateLedControls();
    ledUpdate();
}
