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

Led led1;
Led led2;

void setup()
{
    Serial.begin(9600);

    led1.pin = 5;
    led1.setup();

    led2.pin = 10;
    led2.setup();
}

void loop()
{
    led1.toggle();
    delay(1000);

    led2.toggle();
    delay(1000);
}
