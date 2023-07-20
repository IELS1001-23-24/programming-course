// Add a third dog and an "owner" field

struct Dog
{
    // Each variable of type Dog has a unique version
    // of the variables below.
    // Variables inside a struct are called "fields" or "member variables".
    String name;
    int age;

    // Each variable of type Dog has a unique version
    // of the function below.
    // Functions inside a struct are called "methods" or "member functions".
    void bark()
    {
        // For functions inside a struct, the variables
        // name and dog behave like global variables.
        Serial.print("My name is ");
        Serial.print(name);
        Serial.print(" and I am ");
        Serial.print(age);
        Serial.println(" years old.");
    }
};

Dog scooby;
Dog pluto;

void setup()
{
    Serial.begin(9600);
    
    // Set values for the variables in scooby
    scooby.name = "Scooby";
    scooby.age = 7;

    // Set values for the variables in pluto
    pluto.name = "Pluto";
    pluto.age = 5;

    // Print the name variable stored in scooby
    Serial.println(scooby.name);
    // Print the age variable stored in scooby
    Serial.println(scooby.age);

    // Print the name variable stored in pluto
    Serial.println(pluto.name);
    // Print the age variable stored in pluto
    Serial.println(pluto.age);

    // Call the bark() function stored in scooby
    scooby.bark();

    // Call the bark() function stored in pluto
    pluto.bark();
}

void loop()
{
}
