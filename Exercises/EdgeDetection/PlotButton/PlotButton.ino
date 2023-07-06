// Make sure the counter only increases by 1 every button press and release
// Hint:
// https://docs.arduino.cc/built-in-examples/digital/Debounce

const int BUTTON_PIN = 2;

void setup()
{
  Serial.begin(9600);

  pinMode(BUTTON_PIN, INPUT);
}

void loop()
{
  bool buttonState = digitalRead(BUTTON_PIN);

  Serial.println(buttonState);
}
