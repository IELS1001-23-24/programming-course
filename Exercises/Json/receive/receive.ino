// Complete the code.
// You are only allowed to only change the code inside processReceivedJson().
// Hint:
// https://arduinojson.org/

#include <ArduinoJson.h>

const int LED_PIN = 13;

int servoPosition = 0;

void processReceivedJson(DynamicJsonDocument &jsonDoc)
{
    Serial.println("Received data:");
    serializeJson(jsonDoc, Serial);
    Serial.println("");

    // TODO: If the field "topic" contains the value "servo/status",
    // write the value to the global variable servoPosition,
    // so it can be used by other parts of the program.
}

void setup()
{
    Serial.begin(115200);
    Serial1.begin(115200);

    pinMode(LED_PIN, OUTPUT);

    Serial1.print("{\"topic\": \"servo/init\"}");
}

void readSerial()
{
    // Is there data on the serial port?
    if (Serial1.available() > 0)
    {
        // Create a variable of the data type DynamicJsonDocument that has a
        // capacity of 500 bytes (probably enough for our purposes)
        DynamicJsonDocument jsonDoc(500);

        // Read the string coming from the "Serial" port, find the variables
        // and save them in the jsonDoc variable
        DeserializationError error = deserializeJson(jsonDoc, Serial1);

        // If there is an error, print it out
        // and return from (stop running) the function
        if (error != DeserializationError::Ok)
        {
            Serial.print(F("deserializeJson() failed with the error message: "));
            Serial.println(error.c_str());
            return;
        }

        processReceivedJson(jsonDoc);
    }
}

void updateLed()
{
    // Write the servo position to an LED for now
    // to visually test the code.
    analogWrite(LED_PIN, servoPosition);
}

void loop()
{
    readSerial();
    updateLed();
}
