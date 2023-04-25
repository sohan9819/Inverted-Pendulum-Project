#include <Arduino.h>
#include <AccelStepper.h>
#include <Encoder.h>

#define STEPPER_DIR 5
#define STEPPER_PULSE 6

// Define the rotary encoder pins
#define ENCODER_A_PIN 3
#define ENCODER_B_PIN 4

// LIMIT SWITCH PINS
#define MicroSwitch 2

// STEPPER PINS
// stepper(mode , pulse  , dir)
AccelStepper stepper(1, STEPPER_PULSE, STEPPER_DIR);

// Create the encoder object
Encoder encoder(ENCODER_A_PIN, ENCODER_B_PIN);

#define MAX_SPEED 5000

void setup()
{
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("Serial Port Started");
  encoder.write(0);

  pinMode(MicroSwitch, INPUT);

  // stepper.setAcceleration(MAX_SPEED * 2);
  // stepper.moveTo(1000);

  // while (true)
  // {
  //   stepper.setMaxSpeed(MAX_SPEED);
  //   stepper.setMaxSpeed(MAX_SPEED);
  //   stepper.setAcceleration(MAX_SPEED * 2);
  //   stepper.moveTo(1000);
  //   if (digitalRead(MicroSwitch))
  //   {
  //     /* code */
  //     Serial.print(F("Limit Switch : "));
  //     Serial.println(digitalRead(MicroSwitch));
  //     stepper.setMaxSpeed(0);
  //     stepper.setSpeed(0);
  //     stepper.moveTo(0);
  //     stepper.stop();
  //     stepper.setCurrentPosition(0);
  //     break;
  //   }
  //   Serial.println("Setting motor to initial Position");
  //   stepper.run();
  // }

  stepper.setMaxSpeed(MAX_SPEED);
  stepper.setAcceleration(MAX_SPEED * 2);
  stepper.setCurrentPosition(0);
}

void loop()
{
  // double angle = encoder.read() * 360.0 / 1600.0;

  // Serial.print(F("Angle : "));
  // Serial.println(encoder.read());
  stepper.moveTo(-6000);
  stepper.runToPosition();
  delay(3000);

  stepper.moveTo(6000);
  stepper.runToPosition();
  delay(3000);
  // Serial.println("Moving cart to center");
  // Serial.print("Stepper Motor Position");
  Serial.println(stepper.currentPosition());
}
