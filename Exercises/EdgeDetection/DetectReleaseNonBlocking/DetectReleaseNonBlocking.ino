// Change the code so that it only prints once when the button is released.
// Make sure your solution does not break the led code.
// The LED state should change
// immediately when the button state changes.
// You are not allowed to change the code inside
// the setup(), updateLed() and loop() functions.
// Hint:
// https://docs.arduino.cc/built-in-examples/digital/StateChangeDetection

const int BUTTON_PIN = 2;
const int LED_PIN = 5;

void setup()
{
  Serial.begin(9600);

  pinMode(BUTTON_PIN, INPUT);
  pinMode(LED_PIN, OUTPUT);
}

void updatePrintTask()
{
  bool buttonState = digitalRead(BUTTON_PIN);

  if (!buttonState)
  {
    Serial.println("Hello World!");
  }
}

void updateLed()
{
  digitalWrite(LED_PIN, digitalRead(BUTTON_PIN));
}

void loop()
{
  updatePrintTask();
  updateLed();
}
