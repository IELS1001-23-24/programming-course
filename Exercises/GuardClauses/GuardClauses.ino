// Use guard clauses to make the canMotorStart() function more readable.
// Hint:
// https://youtu.be/CFRhGnuXG-4
// https://wiki.c2.com/?GuardClause
// https://en.wikipedia.org/wiki/Guard_(computer_science)

bool motorIsRunning = false;
bool motorIsOverheating = false;
bool motorIsDamaged = false;
bool peopleAreInDangerZone = false;

const int LED_PIN = 5;

void setup()
{
    Serial.begin(9600);

    pinMode(LED_PIN, OUTPUT);

    Serial.println("Commands:");
    Serial.println("start;");
    Serial.println("stop;");
    Serial.println("walk in;");
    Serial.println("walk out;");
    Serial.println("overheat;");
    Serial.println("cool down;");
    Serial.println("damage;");
    Serial.println("repair;");
}

// Returns true if the motor can start, and false if it can not start.
bool canMotorStart()
{
    if (!motorIsOverheating)
    {
        if (!motorIsDamaged)
        {
            if (!peopleAreInDangerZone)
            {
                return true;
            }
            else
            {
                Serial.println("Motor can not start because people are in the danger zone.");
                return false;
            }
        }
        else
        {
            Serial.println("Motor can not start because it is damaged.");
            return false;
        }
    }
    else
    {
        Serial.println("Motor can not start because it is overheating.");
        return false;
    }
}

void updateSerialCommands()
{
    if (Serial.available() > 0)
    {
        String command = Serial.readStringUntil(';');

        if (command == "start")
        {
            motorIsRunning = canMotorStart();
        }

        if (command == "stop")
        {
            motorIsRunning = false;
        }

        if (command == "walk in")
        {
            motorIsRunning = false;
            peopleAreInDangerZone = true;
        }

        if (command == "walk out")
        {
            peopleAreInDangerZone = false;
        }

        if (command == "overheat")
        {
            motorIsRunning = false;
            motorIsOverheating = true;
        }

        if (command == "cool down")
        {
            motorIsOverheating = false;
        }

        if (command == "damage")
        {
            motorIsRunning = false;
            motorIsDamaged = true;
        }

        if (command == "repair")
        {
            motorIsDamaged = false;
        }
    }
}

void updateMotor()
{
    if (motorIsRunning)
    {
        digitalWrite(LED_PIN, HIGH);
    }
    else
    {
        digitalWrite(LED_PIN, LOW);
    }
}

void loop()
{
    updateSerialCommands();
    updateMotor();
}
