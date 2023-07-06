// Fix the code so that the LED state changes
// immediately when the button state changes.
// You are not allowed to change the code inside
// the updateLed() and loop() functions.
// Hint:
// https://www.norwegiancreations.com/2017/09/arduino-tutorial-using-millis-instead-of-delay/

const int BUTTON_PIN = 2;
const int LED_PIN = 5;

void setup()
{
    Serial.begin(9600);

    pinMode(BUTTON_PIN, INPUT);
    pinMode(LED_PIN, OUTPUT);
}

void updateTimedTask()
{
    delay(3000);
    Serial.println("Timer 1: Elapsed Time: 3000");
}

void updateLed()
{
    digitalWrite(LED_PIN, digitalRead(BUTTON_PIN));
}

void loop()
{
    updateTimedTask();
    updateLed();
}
