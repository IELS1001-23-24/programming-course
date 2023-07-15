// Complete the code so the seven segment display supports all the switches.
// Hint:
// https://docs.wokwi.com/parts/wokwi-7segment

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
    Serial.print("Switch values: ");
    Serial.print(sw1);
    Serial.print(sw2);
    Serial.print(sw3);
    Serial.print(sw4);
    Serial.print(sw5);
    Serial.print(sw6);
    Serial.print(sw7);
    Serial.print(sw8);

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

void setup()
{
    Serial.begin(9600);

    setupSwitch();
    setupSevenSegment();
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

    Serial.print(", Switch value: ");
    Serial.print(switchValue);

    setSevenSegmentValue(switchValue);

    Serial.println("");
}
