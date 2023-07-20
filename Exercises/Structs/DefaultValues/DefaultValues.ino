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
};

Counter counter;

void setup()
{
    Serial.begin(9600);
    
    // Because the value has not been changed,
    // the default value is printed.
    Serial.println(counter.value);

    // Set the value to 5. The default value
    // is now overwritten.
    counter.value = 5;

    // Because the value has been changed,
    // the new value is printed.
    Serial.println(counter.value);
}

void loop()
{
    // Increases the value by 1
    counter.up();

    // Prints the new value
    Serial.println(counter.value);
    
    delay(1000);
}
