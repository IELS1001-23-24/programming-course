// Always use capital first letter for struct names
struct Led
{
    int ledPin = 0;
    bool ledState = false;

    void on()
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
};

// Global variable with datatype "Led" and name "led"
// Always use non-capital first letter for variable names
Led led;

void setup()
{
    Serial.begin(9600);

    // Give the variable "ledPin" inside the variable "led" the value 5
    led.ledPin = 5;

    // Call the function "ledSetup" inside the variable "led"
    led.ledSetup();

    led.on();
    delay(1000);

    led.ledOff();
    delay(1000);
}

void loop()
{
    led.ledToggle();
    delay(1000);
}
