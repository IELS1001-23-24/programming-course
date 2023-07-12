// Find out why the variable does not change.
// Hint: You only have to add 1 symbol to the code.
// https://www.w3schools.com/cpp/cpp_function_reference.asp
// https://www.w3schools.com/cpp/cpp_references.asp

void add(int variable, int value)
{
  variable += value;
}

void setup()
{
  Serial.begin(9600);

  int someNumber = 0;

  Serial.println("Old Value: " + String(someNumber));

  add(someNumber, 5);

  Serial.println("New Value: " + String(someNumber));
}

void loop()
{
}
