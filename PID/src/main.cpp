#include <PID_v1.h>
#include <Wire.h>
#include <NewPing.h>
#include <Encoder.h>

#define TRIGGER_PIN 5
#define ECHO_PIN 6
#define TRACK_DISTANCE 120

#define MAX_DISTANCE 75
#define MIN_DISTANCE 15

double setpoint = 0;
double input, output;
double Kp = 10, Ki = 0.0, Kd = 0.0; // Order of calibrating values kp => kd => ki

PID pid(&input, &output, &setpoint, Kp, Ki, Kd, DIRECT);

// MOTOR CONTROL PINS
#define MOTOR_1A 9
#define MOTOR_1B 10

#define EncoderA 3
#define EncoderB 4

// Initialize the Distance Sensor
NewPing sonar(TRIGGER_PIN, ECHO_PIN, TRACK_DISTANCE);

//  Initialize the encoder
Encoder encoder(EncoderA, EncoderB);

// Default motor speed
int MotorSpeed = 0;
int position;

void setup()
{
  Serial.begin(9600);
  encoder.write(0);
  pid.SetMode(AUTOMATIC);
  pid.SetOutputLimits(-255, 255);
  pinMode(MOTOR_1A, OUTPUT);
  pinMode(MOTOR_1B, OUTPUT);
}

void setSpeed(int speed)
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

void moveToCentre(int speed)
{
  position = sonar.ping_cm();

  while (position <= MIN_DISTANCE || position >= MAX_DISTANCE)
  {
    position = sonar.ping_cm();
    setSpeed(speed);
    Serial.println("Repositioning to center...");
    Serial.print(", Position: ");
    Serial.println(position);
  }
}

void checkPosition()
{
  position = sonar.ping_cm();

  if (position <= MIN_DISTANCE)
  {
    // delay(1000);
    moveToCentre(200);
    Serial.println("Entered Check Position");
  }
  else if (position >= MAX_DISTANCE)
  {
    // delay(1000);
    moveToCentre(-200);
    Serial.println("Entered Check Position");
  }
}

void loop()
{
  checkPosition();
  int angle = encoder.read() * 360 / 1600;
  angle = angle % 360;

  if ((angle >= 3 && angle <= 110) || (angle >= -357 && angle <= -250))
  {
    if (angle > 0)
    {
      MotorSpeed = map(angle, 3, 110, -225, -150);
    }
    else if (angle < 0)
    {
      MotorSpeed = map(angle, -357, -250, -225, -150);
    }
    Serial.print("Motor Speed : ");
    Serial.print(MotorSpeed);
    setSpeed(MotorSpeed);
  }
  else if ((angle <= -3 && angle >= -110) || (angle <= 357 && angle >= 250))
  {
    if (angle > 0)
    {
      MotorSpeed = map(angle, 357, 250, 225, 150);
    }
    else if (angle < 0)
    {
      MotorSpeed = map(angle, -3, -110, 225, 150);
    }
    Serial.print("Motor Speed : ");
    Serial.print(MotorSpeed);
    setSpeed(MotorSpeed);
  }
  else if ((angle >= 135 && angle <= 225) || (angle <= -135 && angle >= -225))
  {
    if (angle > 0)
    {
      input = map(angle, 225, 135, 45, -45);
    }
    else if (angle < 0)
    {
      input = map(angle, -135, -225, 45, -45);
    }
    pid.Compute();
    setSpeed(int(output));
  }
  else
  {
    setSpeed(0);
  }

  Serial.print("Input: ");
  Serial.print(input);
  Serial.print(", Angle: ");
  Serial.print(angle);
  Serial.print(", Output: ");
  Serial.print(output);
  Serial.print(", Position: ");
  Serial.println(position);
}