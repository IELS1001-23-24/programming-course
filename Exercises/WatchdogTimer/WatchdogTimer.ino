// https://www.electronicwings.com/arduino/watchdog-in-arduino

#include <avr/wdt.h>

const int BUTTON_PIN = 2;

void setup()
{
    Serial.begin(9600);
    pinMode(BUTTON_PIN, INPUT);

    Serial.println("---------------------------");
    Serial.println("Startup done!");
    Serial.println("---------------------------");

    // Start the watchdog timer with a 2 second timeout.
    // If the watchdog timer is not reset within 2 seconds,
    // the arduino will restart.
    wdt_enable(WDTO_2S);
}

void possiblyLongTask()
{
    Serial.println("Waiting for button press ...");

    while (!digitalRead(BUTTON_PIN))
    {
        // Wait for press
    }

    Serial.println("Button was pressed!");

    while (digitalRead(BUTTON_PIN))
    {
        // Wait for release
    }
}

// MUST be run at least once every 2 seconds or people DIE!
void criticalTask()
{
    Serial.println("Critical task complete!");

    // Restart the watchdog timer countdown.
    wdt_reset();
}

void loop()
{
    criticalTask();
    possiblyLongTask();
}
