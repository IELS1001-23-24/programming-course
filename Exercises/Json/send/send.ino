// Complete the code.
// When the code is complete the chip will respond with {"position":50,"topic":"servo/status"}
// You are only allowed to only change the code inside getServoInitCommand().
// Hint:
// https://arduinojson.org/
// https://github.com/IELS1001-23-24/wokwi-json-chip/blob/main/src/lib.rs

#include <ArduinoJson.h>

DynamicJsonDocument getServoInitCommend()
{
    DynamicJsonDocument jsonDoc(500);
    
    // TODO: Add the field "topic" with the value "servo/init"

    return jsonDoc;
}

void sendJson(DynamicJsonDocument jsonDoc)
{
    // Send debug text in the serial monitor
    String jsonText;
    serializeJson(jsonDoc, jsonText);
    Serial.print("Sending: ");
    Serial.println(jsonText);

    // Send the json to the serial1 port
    serializeJson(jsonDoc, Serial1);
}

void setup()
{
    Serial.begin(115200);
    Serial1.begin(115200);

    // Send command
    sendJson(getServoInitCommend());
}

void readSerial()
{
    // Is there data on the serial1 port?
    if (Serial1.available() > 0)
    {
        Serial.print((char)Serial1.read());
    }
}

void loop()
{
    readSerial();
}
