// Make this code less repetitive by creating
// a function to print a single number

void printNumber(int number)
{
    Serial.print("Here is a number: ");
    Serial.println(number);
}

void printNumbers()
{
    printNumber(1);
    printNumber(2);
    printNumber(3);
    printNumber(4);
    printNumber(5);
    printNumber(6);
    printNumber(7);
    printNumber(8);
    printNumber(9);
    printNumber(10);
}

void setup()
{
    Serial.begin(9600);

    printNumbers();
}

void loop()
{
}
