#include <Arduino.h>
#include <Encoder.h>

// Define the rotary encoder pins
#define ENCODER_A_PIN 3
#define ENCODER_B_PIN 4

// Create the encoder object
Encoder encoder(ENCODER_A_PIN, ENCODER_B_PIN);

void setup()
{
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("Serial Port Started");
  encoder.write(0);
}

void loop()
{
  // put your main code here, to run repeatedly:
  double angle = encoder.read() * 360.0 / 1600.0;
  Serial.println(angle);
}