const int ledPin0 = 4;
const int VRy = A0;
const int VRx = A1;
const int SW = 2;

void setup() {
  Serial.begin(9600);
  pinMode(ledPin0, OUTPUT);
  pinMode(VRx, INPUT);
  pinMode(VRy, INPUT);
  pinMode(SW, INPUT_PULLUP);
}

void loop() {
  int xPosition = analogRead(VRx);
  int yPosition = analogRead(VRy);
  int SW_state = digitalRead(SW);

  int mapX = map(xPosition, 0, 1023, -512, 512);
  int mapY = map(yPosition, 0, 1023, -512, 512);

  Serial.println(mapX);
  Serial.println(mapY);
  Serial.println(SW_state);

  digitalWrite(ledPin0, SW_state);
  delay(10);
}
