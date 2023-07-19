// The "onComplete" argument is a function
// that will be called with the argument 2
// after the print is done. This is known
// as a callback function.
function printSomething(onComplete) {
    console.log("Something");
    onComplete(2);
}

// This function just prints the first argument
function printNumber(number) {
    console.log(number);
}

// The printSomething function is called,
// and the printNumber function is passed
// as an argument
// This means printNumber() gets called after
// running console.log("Something")
printSomething(printNumber);

// Here the printNumber function is replaced by
// an anonymous function.
// It is an anonymous function because it has no name.
// The function takes an argument "number" and
// prints it after adding 2 to it.
printSomething(
    (number) => console.log(number + 2)
)

// Get the button from the website
const button = document.getElementById("trigger")

// Global variable
let counter = 0

// Add an event listener to the button
button.addEventListener("click",
    // Create an anonymous function as the event handler
    // to handle the click event
    () => {
        counter += 1
        console.log("Button clicked", counter, "times")
    }
)
