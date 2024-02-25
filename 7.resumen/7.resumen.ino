// SERVO
#include <Servo.h>
Servo servo1;
const int servoPin = 10;
// SENSOR ULTRASÓNICO
const int pingPin = 7;
const int echoPin = 6;
// INTERRUPCIÓN
const byte interruptPin = 2;
volatile byte button = 0;
// LEDS
const int ledPin0 = 3;
const int ledPin1 = 4;
const int ledPin2 = 5;
// JOYSTICK
const int VRy = A0;
const int VRx = A1;
const int SW = 2;

void setup() {
  // SERVO
  servo1.attach(servoPin);
  //SENSOR ULTRASÓNICO
  Serial.begin(9600);
  pinMode(pingPin, OUTPUT);
  pinMode(echoPin, INPUT);
  // INTERRUPCIÓN
  pinMode(interruptPin, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(interruptPin), click, RISING);
  // LEDS
  pinMode(ledPin0, OUTPUT);
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  // JOYSTICK
  pinMode(VRx, INPUT);
  pinMode(VRy, INPUT);
  pinMode(SW, INPUT_PULLUP);
}

void loop() {  
  // JOYSTICK
  int xPosition = analogRead(VRx);
  int yPosition = analogRead(VRy);
  int SW_state = digitalRead(SW);

  // SENSOR ULTRASÓNICO
  long duration, cm;
  digitalWrite(pingPin, LOW);
  delayMicroseconds(2);
  digitalWrite(pingPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(pingPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  cm = microsecondsToCentimeters(duration);
  Serial.print(cm);
  Serial.print("cm");
  Serial.println();
  delay(100);

  // INTERRUPCIÓN (SERVO Y LEDS)
  if(button) {
    int angulo1 = map(yPosition, 0, 1023, 0, 180);
    servo1.write(angulo1);
    int mapX = map(xPosition, 0, 1023, -600, 600);
      if(mapX > 0 && mapX <= 200) {
      digitalWrite(ledPin0, 1);
      digitalWrite(ledPin1, 0);
      digitalWrite(ledPin2, 0);
    } else if(mapX > 200  && mapX <= 400) {
      digitalWrite(ledPin0, 1);
      digitalWrite(ledPin1, 1);
      digitalWrite(ledPin2, 0);
    } else if(mapX > 400 && mapX <= 600) {
      digitalWrite(ledPin0, 1);
      digitalWrite(ledPin1, 1);
      digitalWrite(ledPin2, 1);
    } else if(mapX < 0 && mapX >= -200) {
      digitalWrite(ledPin0, 0);
      digitalWrite(ledPin1, 0);
      digitalWrite(ledPin2, 1);
    } else if(mapX <-200 && mapX >= -400) {
      digitalWrite(ledPin0, 0);
      digitalWrite(ledPin1, 1);
      digitalWrite(ledPin2, 1);
    } else if(mapX < -400 && mapX >= -600) {
      digitalWrite(ledPin0, 1);
      digitalWrite(ledPin1, 1);
      digitalWrite(ledPin2, 1);
    } else {
      digitalWrite(ledPin0, 0);
      digitalWrite(ledPin1, 0);
      digitalWrite(ledPin2, 0);
      }
  } else {
    int angulo1 = map(xPosition, 0, 1023, 0, 180);
    servo1.write(angulo1);
    int mapY = map(yPosition, 0, 1023, -600, 600);
    if(mapY > 10 && mapY <= 200) {
      digitalWrite(ledPin0, 1);
      digitalWrite(ledPin1, 0);
      digitalWrite(ledPin2, 0);
    } else if(mapY > 200  && mapY <= 400) {
      digitalWrite(ledPin0, 1);
      digitalWrite(ledPin1, 1);
      digitalWrite(ledPin2, 0);
    } else if(mapY > 400 && mapY <= 600) {
      digitalWrite(ledPin0, 1);
      digitalWrite(ledPin1, 1);
      digitalWrite(ledPin2, 1);
    } else if(mapY < 0 && mapY >= -200) {
      digitalWrite(ledPin0, 0);
      digitalWrite(ledPin1, 0);
      digitalWrite(ledPin2, 1);
    } else if(mapY <-200 && mapY >= -400) {
      digitalWrite(ledPin0, 0);
      digitalWrite(ledPin1, 1);
      digitalWrite(ledPin2, 1);
    } else if(mapY < -400 && mapY >= -600) {
      digitalWrite(ledPin0, 1);
      digitalWrite(ledPin1, 1);
      digitalWrite(ledPin2, 1);
    } else {
      digitalWrite(ledPin0, 0);
      digitalWrite(ledPin1, 0);
      digitalWrite(ledPin2, 0);
    }
  }
}

void click(){
  delayMicroseconds(100);
  if( button == 0) {
    button = 1;
  } else {
    button = 0;
  }
  delayMicroseconds(100);
}

long microsecondsToCentimeters(long microseconds) {
  return microseconds / 29 / 2;
}

