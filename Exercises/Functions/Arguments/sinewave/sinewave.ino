// Find the correct parameter for these functions.
// Open the Serial Plotter to see the signal.
// Hint: You can tell what parameters are missing
// by looking at the arguments passed to them when they are called,
// looking at the Javadoc comments, and by compiling the code
// as-is and look at the compiler errors.
// https://www.baeldung.com/javadoc

// https://www.wikihow.com/Convert-Degrees-to-Radians
double degreesToRadians(double degrees)
{
    return (degrees * PI) / 180.0;
}

/**
 * Generates a sine wave centered around the center value
 * with a max=centerValue+amplitude and min=centerValue-amplitude
 * The offset argument lets you add or remove time, and is
 * useful if you need multiple sinewaves working together
 * In 3 phase AC power for example there are 3 sine waves
 * working at a 120 degree offset.
 * https://en.wikipedia.org/wiki/Three-phase_electric_power#/media/File:3_phase_AC_waveform.svg
 * https://www.google.com/search?q=generate+sine+wave+with+arduino
 * Example: https://www.tinkercad.com/things/8wqREUCNY4p
 *
 * @param amplitude The maximum value of the wave.
 * @param frequency The frequency of the wave in Hz (Hertz).
 * @param centerValue The center value of the wave.
 * @param offset The offset of the wave in ms (milliseconds).
 * @return A sine wave with the given frequency and maximum value.
 */
double getSineWave(double amplitude, double frequency, double centerValue, double offset)
{
    // Creating a variable for the current moment in time
    // given in seconds. Using double as the datatype because
    // it can store massive numbers as decimals. The datatype
    // for the sin() function argument is also double.
    // https://reference.arduino.cc/reference/en/language/variables/data-types/double/
    double t = millis() / 1000.0;

    // How to use the sin() function: https://reference.arduino.cc/reference/tr/language/functions/trigonometry/sin/
    // The formula for a sine wave: https://en.wikipedia.org/wiki/Sine_wave
    return (amplitude * sin((2.0 * PI * frequency * t) + degreesToRadians(offset))) + centerValue;
}

void setup()
{
    Serial.begin(9600);
}

void loop()
{
    Serial.print(getSineWave(50, 0.1, 150, 0));
    Serial.print(",");
    Serial.print(getSineWave(50, 0.1, 150, 120));
    Serial.print(",");
    Serial.print(getSineWave(50, 0.1, 150, 240));
    Serial.println("");
}
