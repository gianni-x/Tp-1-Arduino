const int pingPin = 7;
const int echoPin = 6;

const int ledPin0 = 3;
const int ledPin1 = 4;
const int ledPin2 = 5;


void setup() {
  Serial.begin(9600);
  pinMode(pingPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(ledPin0, OUTPUT);
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
}

void loop() {
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

  if(cm >= 5 && cm <= 10){
    digitalWrite(ledPin0, 1);
    digitalWrite(ledPin1, 1);
    digitalWrite(ledPin2, 1);
  } else {
    digitalWrite(ledPin0, 0);
    digitalWrite(ledPin1, 0);
    digitalWrite(ledPin2, 0);
  }
}

long microsecondsToCentimeters(long microseconds) {
  return microseconds / 29 / 2;
}
