// Creating a global variable
int value = 0;

void setup()
{
    Serial.begin(9600);
}

void doSomething()
{
    value++;
    Serial.print("Global in doSomething: ");
    Serial.println(value);
    delay(1000);

    // Creating a local variable unique to this function
    // with the same name as the
    // global variable.
    // We can no longer access the
    // global variable in this function
    //  because the local variable has priority.
    int value = 10;
    Serial.print("Local in doSomething: ");
    Serial.println(value);
    delay(1000);

    // The local variable gets deleted when the function
    // is done executing.
}

void loop()
{
    value++;
    Serial.print("Global in loop: ");
    Serial.println(value);
    delay(1000);

    // Creating a local variable unique to this function
    // with the same name as the
    // global variable.
    // We can no longer access the
    // global variable in this function
    //  because the local variable has priority.
    int value = 5;
    Serial.print("Local in loop: ");
    Serial.println(value);
    delay(1000);

    // Because the local variables belongs to this
    // function, it does not transfer to doSomething()
    // and therefor the global variable is
    // available inside the function doSomething().
    doSomething();

    // The local variable gets deleted when the function
    // is done executing.
}
