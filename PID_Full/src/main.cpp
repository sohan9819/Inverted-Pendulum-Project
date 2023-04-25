#include <Arduino.h>
#include <Encoder.h>
#include <NewPing.h>

// LIMIT SWITCH PINS
#define MicroSwitch_Right 8
#define MicroSwitch_Left 9

// Define the rotary encoder pins
#define ENCODER_A_PIN 3
#define ENCODER_B_PIN 4

// MOTOR CONTROL PINS
#define MOTOR_1A 9
#define MOTOR_1B 10

// Ultrasonic Sensor PINS
#define TRIGGER_PIN 5
#define ECHO_PIN 6
#define MAX_DISTANCE 80
#define MIN_DISTANCE 10

// Create the sonar object
NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);

// Create the encoder object
Encoder encoder(ENCODER_A_PIN, ENCODER_B_PIN);

int Motor_Speed = 0;

void setup()
{
  // put your setup code here, to run once:

  Serial.begin(9600);
  while (!Serial)
    ;
  Serial.println("Serial Port Started");
  encoder.write(0);
  pinMode(MOTOR_1A, OUTPUT);
  pinMode(MOTOR_1B, OUTPUT);
}

void loop()
{
  long currentPosition = sonar.ping_cm();
  int angle = encoder.read() * 360 / 1600;
  angle = angle % 360;
  // Serial.println(angle);

  // if (currentPosition <= 10)
  // {
  //   while (currentPosition <= 40)
  //   {
  //     digitalWrite(MOTOR_1A, LOW);
  //     analogWrite(MOTOR_1B, 150);
  //     currentPosition = sonar.ping_cm();
  //   }
  //   digitalWrite(MOTOR_1A, LOW);
  //   digitalWrite(MOTOR_1B, LOW);
  // }
  // else if (currentPosition >= 75)
  // {
  //   while (currentPosition >= 40)
  //   {
  //     analogWrite(MOTOR_1A, 150);
  //     digitalWrite(MOTOR_1B, LOW);
  //     currentPosition = sonar.ping_cm();
  //   }
  //   digitalWrite(MOTOR_1A, LOW);
  //   digitalWrite(MOTOR_1B, LOW);
  // }

  if ((angle > 3 && angle < 140) || (angle < -220 && angle > -358))
  {
    Motor_Speed = map(angle, 5, 360, 255, 150);
    Motor_Speed = constrain(Motor_Speed, 50, 200);
    // Motors.setMotorB(255, 0);
    // digitalWrite(MOTOR_1A, LOW);
    // analogWrite(MOTOR_1B, Motor_Speed);

    // For making Upwards
    analogWrite(MOTOR_1A, Motor_Speed);
    digitalWrite(MOTOR_1B, LOW);
  }
  else if ((angle < -3 && angle > -140) || (angle > 220 && angle < 358))
  {
    Motor_Speed = map(angle, -5, -360, 255, 150);
    Motor_Speed = constrain(Motor_Speed, 50, 200);
    // Motors.setMotorB(255, 1);
    // analogWrite(MOTOR_1A, Motor_Speed);
    // digitalWrite(MOTOR_1B, LOW);

    // For making Upwards
    digitalWrite(MOTOR_1A, LOW);
    analogWrite(MOTOR_1B, Motor_Speed);
  }
  else if ((angle < -140 && angle > -180) || (angle > 180 && angle < 220))
  {
    // analogWrite(MOTOR_1A, 255);
    // digitalWrite(MOTOR_1B, LOW);
    if (angle < 0)
    {
      Motor_Speed = map(angle, -180, -140, 150, 255);
    }
    else if (angle > 0)
    {
      Motor_Speed = map(angle, 180, 220, 150, 255);
    }

    analogWrite(MOTOR_1A, Motor_Speed);
    digitalWrite(MOTOR_1B, LOW);
  }
  else if ((angle < -180 && angle > -220) || (angle > 140 && angle < 180))
  {
    // digitalWrite(MOTOR_1A, LOW);
    // analogWrite(MOTOR_1B, 255);

    if (angle < 0)
    {
      Motor_Speed = map(angle, -180, -140, 150, 255);
    }
    else if (angle > 0)
    {
      Motor_Speed = map(angle, 180, 140, 150, 255);
    }

    digitalWrite(MOTOR_1A, LOW);
    analogWrite(MOTOR_1B, Motor_Speed);
  }
  else
  {
    digitalWrite(MOTOR_1A, LOW);
    digitalWrite(MOTOR_1B, LOW);
  }

  // int encoderValue = encoder.read();

  Serial.print("Angle: ");
  Serial.print(angle);
  Serial.print(", Position: ");
  Serial.println(currentPosition);
  // Serial.println(encoderValue);
}
