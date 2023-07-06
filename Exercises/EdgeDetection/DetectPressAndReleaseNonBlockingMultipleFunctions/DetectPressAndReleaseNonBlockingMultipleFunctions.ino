// Change the code so that it only prints once when the button is pressed,
// and so the LED changes states with the button.
// You are only allowed to add global variables and change the
// code inside the updateButtonStates() function.
// Hint:
// https://docs.arduino.cc/built-in-examples/digital/StateChangeDetection

const int BUTTON_PIN = 2;
const int LED_PIN = 5;

bool buttonPressed = false;
bool buttonReleased = false;

void setup()
{
  Serial.begin(9600);

  pinMode(BUTTON_PIN, INPUT);
  pinMode(LED_PIN, OUTPUT);
}

void updateButtonStates()
{
  bool buttonState = digitalRead(BUTTON_PIN);
}

void updatePrint()
{
  if (buttonPressed)
  {
    Serial.println("Hello World!");
  }
}

void updateLed()
{
  if (buttonPressed)
  {
    digitalWrite(LED_PIN, HIGH);
  }

  if (buttonReleased)
  {
    digitalWrite(LED_PIN, LOW);
  }
}

void loop()
{
  updateButtonStates();
  updatePrint();
  updateLed();
}
