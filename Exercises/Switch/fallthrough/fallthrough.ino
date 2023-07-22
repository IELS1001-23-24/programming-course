// Fix the code so only one letter is printed per number.
// 3, 4 and 5 should print the letter D once.
// Hint:
// https://www.w3schools.com/js/js_switch.asp
// https://stackoverflow.com/questions/8146106/does-case-switch-work-like-this

void printValue(int value)
{
    Serial.print(value);
    Serial.print(": ");
    
    switch (value)
    {
    case 0:
        Serial.print("A");
    case 1:
        Serial.print("B");
    case 2:
        Serial.print("C");
        break;
    case 3:
    case 4:
    case 5:
        Serial.print("D");
    default:
        Serial.print("E");
    }

    Serial.println("");
}

void setup()
{
    Serial.begin(9600);

    printValue(0);
    delay(1000);

    printValue(1);
    delay(1000);

    printValue(2);
    delay(1000);

    printValue(3);
    delay(1000);

    printValue(4);
    delay(1000);

    printValue(5);
    delay(1000);

    printValue(6);
    delay(1000);
}

void loop()
{
}
