// This sketch demonstrates that not only is #define
// not a constant, but it can also be used to redefine
// a variable to a different datatype. This is not
// possible with const, where you must also specify a datatype.
// Imagine what happens in a 1000+ line program, possibly with
// several files. This is intended behaviour, which is why
// this should only be used when you have a technical
// reason to do so.

#define LED_PIN 13

void setup()
{
    Serial.begin(9600);

    Serial.println("Original value: " + String(LED_PIN));
#define LED_PIN 12
    Serial.println("Changed value: " + String(LED_PIN));
#define LED_PIN String("Hello World")
    Serial.println("Different datatype: " + LED_PIN);
}

void loop()
{
}
