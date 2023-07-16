// Replace the for-loops with equivalent non-blocking
// When done correctly (and with only the loop time print),
// the loop time should be about 16 microseconds.

const int LED_PIN = 5;

unsigned long loopTimer = 0;

int step = 0;

int iUp = 0;
int iDown = 0;

void setup()
{
    Serial.begin(9600);

    pinMode(LED_PIN, OUTPUT);
}

void updateLed()
{
    switch (step)
    {
    case 0:
        Serial.println("Step 1");
        // Hint: Set iUp to 0
        step++;
        break;
    case 1:
        Serial.println("Step 2");
        for (iUp = 0; iUp <= 255; iUp += 5)
        {
            analogWrite(LED_PIN, iUp);
            Serial.println("iUp: " + String(iUp));
            delay(100);
        }
        step++;
        break;
    case 2:
        Serial.println("Step 3");
        // Hint: Set iDown to 255 here
        step++;
        break;
    case 3:
        Serial.println("Step 4");
        for (iDown = 255; iDown >= 0; iDown -= 5)
        {
            analogWrite(LED_PIN, iDown);
            Serial.println("iDown: " + String(iDown));
            delay(100);
        }
        step++;
        break;
    case 4:
        Serial.println("Step 5");
        step = 0;
        break;
    default:
        Serial.println("Invalid step!");
        break;
    }
}

void loop()
{
    loopTimer = micros();
    updateLed();
    Serial.println("Loop time: " + String(micros() - loopTimer) + " microseconds");

    // Pause the program so the loop time is readable
    // Reduce this to 100 ms after you have made the code non-blocking
    delay(3000);
}
