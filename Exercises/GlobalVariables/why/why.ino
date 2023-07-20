// Global variables are variables that are
// declared outside of any function.
// They only loose their value when the program restarts.
int globalVariable = 0;

void setup()
{
    Serial.begin(9600);
}

void printGlobalVariable()
{
    // Because the global variable is declared outside
    // of any function, it is available in
    // all functions in the program.
    Serial.print("Global variable from function: ");
    Serial.println(globalVariable);
}

void loop()
{
    // Local variables are variables that are
    // declared inside a function.
    // They are only available inside the function.
    // and reset when the function is done executing.
    int localVariable = 0;

    localVariable++;
    Serial.print("Local variable: ");
    Serial.println(localVariable);

    delay(1000);

    globalVariable++;
    Serial.print("Global variable: ");
    Serial.println(globalVariable);

    delay(1000);

    printGlobalVariable();
    delay(1000);
}
