// Run the code to see the output.
//
// Try to prefix each "true" and "false" with the logical
// NOT operator (!) to see what happens.
//
// When you understand what is going on, try to unlock
// the message using the method above.
//
// When you get the message, undo what you did to the variables,
// and instead use the NOT operator on the same variables in their respective print.
//
// Can you get the output 111111 without changing the variables?
//
// Can you get the output 000000 without changing the variables?
//
// Undo the file to its original state, and unlock the message
// by inverting the variables directly in the if statement.
//
// https://www.arduino.cc/reference/en/language/structure/boolean-operators/logicalnot/

void setup()
{
    Serial.begin(9600);

    bool a = false;
    bool b = true;
    bool c = false;
    bool d = true;
    bool e = false;
    bool f = true;

    Serial.print(a);
    Serial.print(b);
    Serial.print(c);
    Serial.print(d);
    Serial.print(e);
    Serial.print(f);
    Serial.println();

    if (!a && b && !c && d && !e && f)
    {
        Serial.println("You got it!");
    }
}

void loop()
{
}
