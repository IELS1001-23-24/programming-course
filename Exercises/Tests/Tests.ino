// Uncomment to see debug info
#define DEBUG

// Uncomment to add test code
// #define RUN_TESTS

#ifdef RUN_TESTS
#define DEBUG
bool testMode = false;
#endif

const int SWITCH_PIN_1 = 7;
const int SWITCH_PIN_2 = 6;
const int SWITCH_PIN_3 = 5;
const int SWITCH_PIN_4 = 4;
const int SWITCH_PIN_5 = 3;
const int SWITCH_PIN_6 = 2;
const int SWITCH_PIN_7 = 14;
const int SWITCH_PIN_8 = 15;

const int SEGMENT_PIN_A = 17;
const int SEGMENT_PIN_B = 16;
const int SEGMENT_PIN_C = 10;
const int SEGMENT_PIN_D = 12;
const int SEGMENT_PIN_E = 13;
const int SEGMENT_PIN_F = 18;
const int SEGMENT_PIN_G = 19;

int getSwitchValue(
    bool sw1,
    bool sw2,
    bool sw3,
    bool sw4,
    bool sw5,
    bool sw6,
    bool sw7,
    bool sw8)
{

#ifdef DEBUG
#ifdef RUN_TESTS
    if (!testMode)
    {
#endif
        Serial.print("Switch values: ");
        Serial.print(sw1);
        Serial.print(sw2);
        Serial.print(sw3);
        Serial.print(sw4);
        Serial.print(sw5);
        Serial.print(sw6);
        Serial.print(sw7);
        Serial.print(sw8);
#ifdef RUN_TESTS
    }
#endif
#endif

    if (sw1 && !sw2 && !sw3 && !sw4 && !sw5 && !sw6 && !sw7 && !sw8)
    {
        return 1;
    }

    if (!sw1 && sw2 && !sw3 && !sw4 && !sw5 && !sw6 && !sw7 && !sw8)
    {
        return 2;
    }

    if (!sw1 && !sw2 && sw3 && !sw4 && !sw5 && !sw6 && !sw7 && !sw8)
    {
        return 3;
    }

    return 0;
}

/**
 * @brief Sets the value of the seven segment display.
 *
 * https://docs.wokwi.com/parts/wokwi-7segment
 *
 * @param value The value to set the seven segment display to (0-3).
 */
void setSevenSegmentValue(int value)
{
    bool a = value == 0 || value == 2 || value == 3;
    bool b = value == 0 || value == 1 || value == 2 || value == 3;
    bool c = value == 0 || value == 1 || value == 3;
    bool d = value == 0 || value == 2 || value == 3;
    bool e = value == 0 || value == 2;
    bool f = value == 0;
    bool g = value == 2 || value == 3;

    digitalWrite(SEGMENT_PIN_A, a);
    digitalWrite(SEGMENT_PIN_B, b);
    digitalWrite(SEGMENT_PIN_C, c);
    digitalWrite(SEGMENT_PIN_D, d);
    digitalWrite(SEGMENT_PIN_E, e);
    digitalWrite(SEGMENT_PIN_F, f);
    digitalWrite(SEGMENT_PIN_G, g);
}

void setupSwitch()
{
    pinMode(SWITCH_PIN_1, INPUT_PULLUP);
    pinMode(SWITCH_PIN_2, INPUT_PULLUP);
    pinMode(SWITCH_PIN_3, INPUT_PULLUP);
    pinMode(SWITCH_PIN_4, INPUT_PULLUP);
    pinMode(SWITCH_PIN_5, INPUT_PULLUP);
    pinMode(SWITCH_PIN_6, INPUT_PULLUP);
    pinMode(SWITCH_PIN_7, INPUT_PULLUP);
    pinMode(SWITCH_PIN_8, INPUT_PULLUP);
}

void setupSevenSegment()
{
    pinMode(SEGMENT_PIN_A, OUTPUT);
    pinMode(SEGMENT_PIN_B, OUTPUT);
    pinMode(SEGMENT_PIN_C, OUTPUT);
    pinMode(SEGMENT_PIN_D, OUTPUT);
    pinMode(SEGMENT_PIN_E, OUTPUT);
    pinMode(SEGMENT_PIN_F, OUTPUT);
    pinMode(SEGMENT_PIN_G, OUTPUT);
}

#ifdef RUN_TESTS
/**
 * @brief Checks if the values are the same.
 *
 * @param testName The name of the test.
 * @param value1 The first value to compare.
 * @param value2 The second value to compare.
 *
 * @return true if the values are the same, false otherwise.
 */
bool expectEqual(String testName, int value1, int value2)
{
    if (value1 == value2)
    {
        return true;
    }

    Serial.print("Test ");
    Serial.print(testName);
    Serial.print(" failed: ");
    Serial.print("Expected ");
    Serial.print(value1);
    Serial.print(" but got ");
    Serial.println(value2);

    return false;
}
#endif

#ifdef RUN_TESTS
// Runs all the tests and pauses the program if any of them fail.
void runTests()
{
    testMode = true;

    bool results[] = {
        expectEqual("getSwitchValue", 0, getSwitchValue(0, 0, 0, 0, 0, 0, 0, 0)),
        expectEqual("getSwitchValue", 1, getSwitchValue(1, 0, 0, 0, 0, 0, 0, 0)),
        expectEqual("getSwitchValue", 2, getSwitchValue(0, 1, 0, 0, 0, 0, 0, 0)),
        expectEqual("getSwitchValue", 3, getSwitchValue(0, 0, 1, 0, 0, 0, 0, 0)),
        expectEqual("getSwitchValue", 4, getSwitchValue(0, 0, 0, 1, 0, 0, 0, 0)),
        expectEqual("getSwitchValue", 5, getSwitchValue(0, 0, 0, 0, 1, 0, 0, 0)),
        expectEqual("getSwitchValue", 6, getSwitchValue(0, 0, 0, 0, 0, 1, 0, 0)),
        expectEqual("getSwitchValue", 7, getSwitchValue(0, 0, 0, 0, 0, 0, 1, 0)),
        expectEqual("getSwitchValue", 8, getSwitchValue(0, 0, 0, 0, 0, 0, 0, 1)),
    };

    for (bool result : results)
    {
        // If any test fails, blink the A segment forever.
        if (!result)
        {
            Serial.println("Tests failed!");
            Serial.println("Halting program");
            while (true)
            {
                digitalWrite(SEGMENT_PIN_A, HIGH);
                delay(500);
                digitalWrite(SEGMENT_PIN_A, LOW);
                delay(500);
            }
        }
    }

    testMode = false;
}
#endif

void setup()
{
    Serial.begin(9600);

    setupSwitch();
    setupSevenSegment();

#ifdef RUN_TESTS
    runTests();
#endif
}

void loop()
{
    // Because the inputs have internal pullup resistors,
    // all the values are inverted here.
    int switchValue = getSwitchValue(
        !digitalRead(SWITCH_PIN_1),
        !digitalRead(SWITCH_PIN_2),
        !digitalRead(SWITCH_PIN_3),
        !digitalRead(SWITCH_PIN_4),
        !digitalRead(SWITCH_PIN_5),
        !digitalRead(SWITCH_PIN_6),
        !digitalRead(SWITCH_PIN_7),
        !digitalRead(SWITCH_PIN_8));

#ifdef DEBUG
    Serial.print(", Switch value: ");
    Serial.print(switchValue);
#endif

    setSevenSegmentValue(switchValue);

#ifdef DEBUG
    Serial.println("");
#endif
}
