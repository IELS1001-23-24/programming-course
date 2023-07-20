// A bunch of functions that control an LED
// Run the code and see what happens

int ledPin = 5;
bool ledState = false;

void ledOn()
{
    ledState = true;
    digitalWrite(ledPin, HIGH);
}

void ledOff()
{
    ledState = false;
    digitalWrite(ledPin, LOW);
}

void ledToggle()
{
    ledState = !ledState;
    digitalWrite(ledPin, ledState);
}

void ledSetup()
{
    pinMode(ledPin, OUTPUT);
}

void setup()
{
    Serial.begin(9600);

    ledSetup();

    ledOn();
    delay(1000);

    ledOff();
    delay(1000);
}

void loop()
{
    ledToggle();
    delay(1000);
}
