// Complete the code so the commandTimes
// updatePlayCommands() function waits the
// correct amount of time before running the
// next command (look for uses of the commandTimes[] array).
// Add new commands to toggle each LED on and off.

int pins[] = {
    2,
    3,
    4,
    5,
    6,
    7,
    8,
    9,
};

bool playing = false;
bool recording = false;

// Try to remove const and see what happens
const int maxCommands = 20;
int numCommands = 0;
char commands[maxCommands];

unsigned long commandTimer = 0;
// The time between each command
unsigned long commandTimes[maxCommands];

void setup()
{
    Serial.begin(9600);

    for (int pin : pins)
    {
        pinMode(pin, OUTPUT);
    }

    Serial.println("Commands:");
    Serial.println("p: Play recorded commands");
    Serial.println("r: Record commands");
    Serial.println("");
    Serial.println("a: Turn all LEDs on");
    Serial.println("b: Turn all LEDs off");
    Serial.println("c: Turn all LEDs on one by one");
    Serial.println("d: Turn all LEDs off one by one");
}

void runCommand(char command)
{
    switch (command)
    {
    case 'a':
        for (int pin : pins)
        {
            digitalWrite(pin, HIGH);
        }
        break;
    case 'b':
        for (int pin : pins)
        {
            digitalWrite(pin, LOW);
        }
        break;
    case 'c':
        for (int pin : pins)
        {
            digitalWrite(pin, HIGH);
            delay(100);
        }
        break;
    case 'd':
        for (int pin : pins)
        {
            digitalWrite(pin, LOW);
            delay(100);
        }
        break;
    }
}

void processCommand(char command)
{
    switch (command)
    {
    case 'p':
        playing = !playing;
        Serial.println(playing ? "Playing" : "Stopped playing");
        break;
    case 'r':
        recording = !recording;
        commandTimer = millis();
        Serial.println(recording ? "Recording" : "Stopped recording");
        if (recording)
            numCommands = 0;
        break;
    default:
        runCommand(command);
        if (recording)
        {
            if (numCommands < maxCommands)
            {
                unsigned long duration = millis() - commandTimer;

                Serial.print("[");
                Serial.print(numCommands + 1);
                Serial.print("/");
                Serial.print(maxCommands);
                Serial.print("/");
                Serial.print(duration);
                Serial.print("ms");
                Serial.print("]: ");
                Serial.println(command);

                commandTimes[numCommands] = duration;

                commands[numCommands] = command;
                commandTimer = millis();
                numCommands++;
            }
            if (numCommands >= maxCommands)
            {
                Serial.println("Max commands reached");
                processCommand('r');
            }
        }
        break;
    }
}

void updateSerial()
{
    while (Serial.available())
    {
        char command = Serial.read();

        if (command == '\n')
        {
            continue;
        }

        processCommand(command);
    }
}

void updatePlayCommands()
{
    if (playing)
    {
        Serial.println("Playing commands: ");
        for (int i = 0; i < numCommands; i++)
        {
            char command = commands[i];
            Serial.print(command);
            runCommand(command);
        }
        Serial.println("");
    }
}

void loop()
{
    updateSerial();
    updatePlayCommands();
}
