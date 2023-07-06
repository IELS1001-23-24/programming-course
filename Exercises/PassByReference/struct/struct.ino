// Find out why the name does not change.
// Hint: You only have to add 1 symbol to the code.
// https://www.w3schools.com/cpp/cpp_function_reference.asp
// https://www.w3schools.com/cpp/cpp_references.asp

struct Data
{
  String name = "John Wick";
  int age = 0;
};

void setName(Data data, String name)
{
  data.name = name;
}

void setup()
{
  Serial.begin(9600);

  Data data;

  Serial.println("Old Name: " + data.name);

  setName(data, "Baba Yaga");

  Serial.println("New Name: " + data.name);
}

void loop()
{
}
