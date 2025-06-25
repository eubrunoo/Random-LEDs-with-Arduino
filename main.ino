// C++ code
//
#define LED_PIN1 7
#define LED_PIN2 9
#define LED_PIN3 11

const int ledPins[3] = {LED_PIN1, LED_PIN2, LED_PIN3};

int randomPin;

void setup()
{
  randomSeed(analogRead(0));

  for (int i = 0; i < 3; i++) {
    pinMode(ledPins[i], OUTPUT);
  }
}

void loop()
{
  int randomTime = random(100, 500);
  int randomIndex = random(3);
  randomPin = ledPins[randomIndex];
  digitalWrite(randomPin, HIGH);
  delay(randomTime);
  digitalWrite(randomPin, LOW);
}