# Random LEDs with Variable Timing on Arduino

This project demonstrates a simple Arduino application where three LEDs are randomly illuminated for a variable duration, creating an unpredictable and dynamic "blinking" or "sequence" effect. The circuit is straightforward to assemble, and the code is direct, making it ideal for beginners in electronics and Arduino programming.

## Features

* Randomly lights up one of three LEDs.
* The duration for which the LED stays lit is also random, varying between 100 and 500 milliseconds.
* Utilizes Arduino's `random()` function to ensure randomness in both LED selection and illumination duration.
* Simple and modular design, easy to understand and expand upon.

## Components Required

To replicate this project, you will need the following components:

* **1x Arduino Board** (Uno, Nano, Mega, etc.)
* **3x LEDs** (colors of your preference)
* **3x 220 Ohm Resistors** (for LED protection)
* **1x Breadboard**
* **Jumper Wires**

## Circuit Diagram

Connect the components as per the diagram below:

| Component       | Arduino Connection | Notes                                                                                                                                                                                                     |
| :-------------- | :----------------- | :-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| LED 1 (anode)   | Digital Pin 7      | Connect the 220 Ohm resistor to the anode (longer leg) of the LED, and the other end of the resistor to Pin 7. The cathode (shorter leg) of the LED should go to GND.                                          |
| LED 2 (anode)   | Digital Pin 9      | Similar connection to LED 1, but to Pin 9.                                                                                                                                                                |
| LED 3 (anode)   | Digital Pin 11     | Similar connection to LED 1, but to Pin 11.                                                                                                                                                               |
| GND (LED cathodes) | GND Pin            | All LED cathodes should be connected to an Arduino GND pin.                                                                                                                                             |

<br>
<p align="center">
  **Basic Connection Scheme:**
  <br>
  LED Anode (long leg) -> Resistor -> Arduino Digital Pin
  <br>
  LED Cathode (short leg) -> Arduino GND
</p>

## Code

The source code for this project is included in this repository. You can copy it directly into the Arduino IDE.

```cpp
// C++ code
//
#define LED_PIN1 7
#define LED_PIN2 9
#define LED_PIN3 11

const int ledPins[3] = {LED_PIN1, LED_PIN2, LED_PIN3};

int randomPin;

void setup()
{
  randomSeed(analogRead(0)); // Initializes the random number generator based on an analog reading

  for (int i = 0; i < 3; i++) {
    pinMode(ledPins[i], OUTPUT); // Configures the LED pins as output
  }
}

void loop()
{
  int randomTime = random(100, 500); // Generates a random time between 100 and 499 milliseconds
  int randomIndex = random(3);       // Generates a random index between 0, 1, and 2
  randomPin = ledPins[randomIndex];  // Selects the LED pin corresponding to the index

  digitalWrite(randomPin, HIGH); // Turns the selected LED ON
  delay(randomTime);             // Waits for the random duration
  digitalWrite(randomPin, LOW);  // Turns the LED OFF
}
