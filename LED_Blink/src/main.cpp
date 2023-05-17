#include <Arduino.h>

#define LED_BUILTIN 2

String data;
char dl;

double kp = 0, ki = 0, kd = 0;

void setup()
{
  // put your setup code here, to run once:

  Serial.begin(9600);
  Serial.println("Hello world");
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop()
{

  if (Serial.available())
  {
    data = Serial.readString();
    dl = data.charAt(0);

    switch (dl)
    {
    case 'A':
      digitalWrite(LED_BUILTIN, HIGH);
      break;
    case 'a':
      digitalWrite(LED_BUILTIN, LOW);
      break;
    case 'P':
      kp = data.substring(1).toDouble();
      break;
    case 'I':
      ki = data.substring(1).toDouble();
      break;
    case 'D':
      kd = data.substring(1).toDouble();
      break;

    default:
      Serial.print("Invalid Data");
      Serial.println(data);
      break;
    }
  }

  // Serial.println(analogRead(A0));
  Serial.print("P");
  Serial.println(kp);
  Serial.print("I");
  Serial.println(ki);
  Serial.print("D");
  Serial.println(kd);
}