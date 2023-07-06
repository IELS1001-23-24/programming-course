// Find out why the timers are not working as expected.
// Hint: You only have to add 1 symbol to the code.
// https://www.w3schools.com/cpp/cpp_function_reference.asp
// https://www.w3schools.com/cpp/cpp_references.asp

unsigned long timer1 = 0;
unsigned long timer2 = 0;

// Resets the timer
void resetTimer(unsigned long timer)
{
  timer = millis();
}

// Returns true when the duration has passed since the timer was reset.
bool timerIsFinished(unsigned long timer, unsigned long duration)
{
  unsigned long timeSinceReset = millis() - timer;
  return timeSinceReset >= duration;
}

void setup()
{
  Serial.begin(9600);
}

void loop()
{
  if (timerIsFinished(timer1, 1000))
  {
    Serial.println("Timer 1: 1 second has passed");
    resetTimer(timer1);
  }

  if (timerIsFinished(timer2, 2000))
  {
    Serial.println("Timer 2: 2 seconds have passed");
    resetTimer(timer2);
  }
}
