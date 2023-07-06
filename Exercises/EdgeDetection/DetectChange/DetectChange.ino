// Change the code so that it only prints once when the button state changes.
// Hint:
// https://docs.arduino.cc/built-in-examples/digital/StateChangeDetection

const int BUTTON_PIN = 2;

void setup()
{
  Serial.begin(9600);

  pinMode(BUTTON_PIN, INPUT);
}

void loop()
{
  bool buttonState = digitalRead(BUTTON_PIN);

  if (buttonState)
  {
    Serial.println("Hello World!");
  }
}
