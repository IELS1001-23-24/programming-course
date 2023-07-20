// Always use capital first letter for struct names
struct Led
{
    int pin = 0;
    bool state = false;

    void on()
    {
        state = true;
        digitalWrite(pin, HIGH);
    }

    void off()
    {
        state = false;
        digitalWrite(pin, LOW);
    }

    void toggle()
    {
        state = !state;
        digitalWrite(pin, state);
    }

    void setup()
    {
        pinMode(pin, OUTPUT);
    }
};

// Global variable with datatype "Led" and name "led"
// Always use non-capital first letter for variable names
Led led;

void setup()
{
    Serial.begin(9600);

    // Give the variable "pin" inside the variable "led" the value 5
    led.pin = 5;

    // Call the function "setup" inside the variable "led"
    led.setup();

    led.on();
    delay(1000);

    led.off();
    delay(1000);
}

void loop()
{
    led.toggle();
    delay(1000);
}
