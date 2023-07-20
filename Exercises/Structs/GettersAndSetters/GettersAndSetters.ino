struct Counter
{
    // The default value for all
    // variables of type "Counter" is now 10.
    int value = 10;

    void up()
    {
        value++;
    }

    void down()
    {
        value--;
    }

    int getValue()
    {
        return value;
    }

    // Notice the argument is called "newValue"
    // instead of "value". This is because the
    // argument is a local variable, and it
    // "hides" the member variable "value"
    // if it has the same name.
    void setValue(int newValue)
    {
        value = newValue;
    }
};

Counter counter;

void setup()
{
    Serial.begin(9600);

    // Without the setter
    counter.value = 5;
    // Without the getter
    Serial.println(counter.value);

    // With the setter
    counter.setValue(10);
    // With the getter
    Serial.println(counter.getValue());
}

void loop()
{
    counter.up();

    Serial.println(counter.getValue());
    
    delay(1000);
}
