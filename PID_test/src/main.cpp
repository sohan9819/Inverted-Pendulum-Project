#include <PID_v1.h>
#include <Wire.h>
#include <NewPing.h>
#include <Encoder.h>

#define TRIGGER_PIN 5
#define ECHO_PIN 6
#define MAX_DISTANCE 80

NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);

// double setpoint = 800;
double setpoint = 0;
double input, output;
double Kp = 0.1, Ki = 0.0, Kd = 10.0;

PID pid(&input, &output, &setpoint, Kp, Ki, Kd, DIRECT);

// MOTOR CONTROL PINS
#define MOTOR_1A 9
#define MOTOR_1B 10

#define EncoderA 3
#define EncoderB 4

Encoder encoder(EncoderA, EncoderB);

// const double maxCartPosition = 80.0; // Maximum allowed cart position in cm

void setup()
{
  Serial.begin(9600);
  encoder.write(0);
  pid.SetMode(AUTOMATIC);
  pid.SetOutputLimits(-255, 255);
  pinMode(MOTOR_1A, OUTPUT);
  pinMode(MOTOR_1B, OUTPUT);
}

void setSpeed(double speed)
{
  if (speed > 0)
  {
    digitalWrite(MOTOR_1A, LOW);
    digitalWrite(MOTOR_1B, speed);
  }
  else if (speed < 0)
  {
    digitalWrite(MOTOR_1A, -speed);
    digitalWrite(MOTOR_1B, LOW);
  }
  else
  {
    digitalWrite(MOTOR_1A, LOW);
    digitalWrite(MOTOR_1B, LOW);
  }
}

void loop()
{
  // long currentPosition = sonar.ping_cm();
  // input = encoder.read();
  int angle = encoder.read() * 360 / 1600;
  input = angle % 360;
  pid.Compute();

  setSpeed(input);

  // Serial.print("Pos: ");
  // Serial.print(currentPosition);
  Serial.print("Input: ");
  Serial.print(input);
  Serial.print(", Angle: ");
  Serial.print(angle);
  Serial.print(", Output: ");
  Serial.println(output);
}