// This sketch demonstrates that #define can be used
// to define "macros" that represent code. This shows how dangerous
// #define can be. If you continue to play with this example
// you will quickly realize how difficult it is to debug.

// This replaces the word "index" with the code "String(x)"
#define index String(x)

void setup()
{
    Serial.begin(9600);

    for (int i = 0; i < 5; i++)
    {
        // Comment out the line below to see what happens
        // Since "index" is replaced by the compiler with
        // "String(x)", the compiler will complain that
        // the variable "x" is not defined.
        int x = i;

        Serial.println("Printing index: " + index);

        // The code above is equivalent to the code below
        Serial.println("Printing index: " + String(x));
    }
}

void loop()
{
}
