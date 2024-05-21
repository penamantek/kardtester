/*

*/
#include <stdio.h>

int numPin = 0;

void setup() {
    Serial.begin(9600);
}

void loop() {
  Serial.println("Starting...");
  delay(5000);
  for(int i=0; i<14; i++) {
    numPin = i;
    pinMode(numPin, OUTPUT);
    digitalWrite(numPin, LOW);
    Serial.print("Pin: ");
    Serial.println(numPin);
    digitalWrite(numPin, HIGH);
    delay(1000);
    digitalWrite(numPin, LOW);
    Serial.println("Move to next pin pls");
    delay(1000);
  }

  // lol this is prob a little inefficient but oh well
  activateAnalog(A0);
  activateAnalog(A1);
  activateAnalog(A2);
  activateAnalog(A3);
  activateAnalog(A4);
  activateAnalog(A5);
}

void activateAnalog(int pin) {
  pinMode(pin, OUTPUT);
  Serial.print("Pin: ");
  Serial.println(pin);
  analogWrite(pin, 255);
  delay(1000);
  analogWrite(pin, 0);
  Serial.println("Move to next pin pls");
  delay(1000);
}
