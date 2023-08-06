#include <Arduino.h>
#include <ArduinoJson.h>

// All the pinMode payloads that have
// been sent to the simulator will be stored here.
// If the simulator is reset, it will request the pinModes
// and this string will be used.
String pinModes = "";

byte pinValues[100];

void syncPinsWithSim()
{
    while (Serial.available() > 0)
    {
        DynamicJsonDocument jsonDoc(500);
        DeserializationError error = deserializeJson(jsonDoc, Serial);

        if (error != DeserializationError::Ok)
        {
            Serial.print("deserializeJson() failed: ");
            Serial.println(error.c_str());
            return;
        }

        if (jsonDoc.containsKey("p"))
        {
            int pin = jsonDoc["p"].as<int>();
            int value = jsonDoc["v"].as<int>();
            pinValues[pin] = value;
        }

        if (jsonDoc.containsKey("init"))
        {
            // Send the pinModes to the simulator
            Serial.print(pinModes);

            // Parse all the json messages in the pinModes string
            // and send the pin values for all outputs
            // to the simulator.

            String buffer = pinModes;
            while (buffer.length() > 0)
            {
                DynamicJsonDocument jsonDoc(50);
                DeserializationError error = deserializeJson(jsonDoc, buffer);

                // Remove the json message from the buffer
                buffer = buffer.substring(buffer.indexOf("}") + 1);

                if (error != DeserializationError::Ok)
                {
                    Serial.print("deserializeJson() failed: ");
                    Serial.println(error.c_str());
                    continue;
                }

                if (jsonDoc.containsKey("m"))
                {
                    int pin = jsonDoc["p"].as<int>();
                    String mode = jsonDoc["m"].as<String>();

                    if (mode == "o")
                    {
                        // Send the pin value to the simulator
                        DynamicJsonDocument jsonDoc(100);
                        jsonDoc["p"] = pin;
                        jsonDoc["v"] = pinValues[pin];
                        serializeJson(jsonDoc, Serial);
                    }
                }
            }
        }
    }
}

int digitalReadSim(uint8_t pin)
{
    syncPinsWithSim();
    return pinValues[pin];
}

int analogReadSim(uint8_t pin)
{
    syncPinsWithSim();
    return pinValues[pin];
}

void analogWriteSim(uint8_t pin, int val)
{
    syncPinsWithSim();

    if (val == pinValues[pin])
    {
        return;
    }

    pinValues[pin] = val;

    DynamicJsonDocument jsonDoc(50);

    jsonDoc["p"] = pin;
    jsonDoc["v"] = val;

    serializeJson(jsonDoc, Serial);
    syncPinsWithSim();
}

void digitalWriteSim(uint8_t pin, uint8_t val)
{
    analogWriteSim(pin, val);
}

void pinModeSim(uint8_t pin, uint8_t mode)
{
    syncPinsWithSim();

    DynamicJsonDocument jsonDoc(50);

    jsonDoc["m"] = (mode == OUTPUT) ? "o" : "i";
    jsonDoc["p"] = pin;

    serializeJson(jsonDoc, Serial);

    // Store the payload in a string for later use
    serializeJson(jsonDoc, pinModes);

    syncPinsWithSim();
}

#define digitalRead digitalReadSim
#define analogRead analogReadSim
#define digitalWrite digitalWriteSim
#define analogWrite analogWriteSim

#define pinMode pinModeSim

size_t printSim(const String &s)
{
    syncPinsWithSim();

    DynamicJsonDocument jsonDoc(500);
    jsonDoc["print"] = s;

    serializeJson(jsonDoc, Serial);
}

size_t printlnSim(const String &s)
{
    return printSim(s + '\n');
}

class HardwareSerialSim
{
public:
    void begin(unsigned long baudrate)
    {
        Serial.begin(baudrate);
    }

    size_t print(const String &s)
    {
        syncPinsWithSim();

        DynamicJsonDocument jsonDoc(500);
        jsonDoc["print"] = s;

        return serializeJson(jsonDoc, Serial);
    }

    size_t print(int &s)
    {
        return print(String(s));
    }

    size_t println(const String &s)
    {
        return print(s + '\n');
    }

    size_t println(int &s)
    {
        return println(String(s));
    }
};

HardwareSerialSim SerialSim;

#define Serial SerialSim
