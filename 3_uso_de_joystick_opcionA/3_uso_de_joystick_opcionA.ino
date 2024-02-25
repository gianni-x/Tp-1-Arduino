const int ledPin1 = 4;
const int VRy = A0;
const int VRx = A1;
const int SW = 2;
const int ledPin0 = 3;
const int ledPin2 = 5; 

 void setup() {
 Serial.begin(9600);
 pinMode(ledPin0, OUTPUT);
 pinMode(VRx, INPUT);
 pinMode(VRy, INPUT);
 pinMode(SW, INPUT_PULLUP);
 pinMode(ledPin1, OUTPUT);
 pinMode(ledPin2, OUTPUT);
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
 if(abs(mapX) == abs(mapY)){
 digitalWrite(ledPin0, 0);
 digitalWrite(ledPin1, 0);
 digitalWrite(ledPin2, 0); 
 } 
else if((-512+51.2<mapX<512-51.2) && (mapY >= 512-51.2)){
 digitalWrite(ledPin0, 0);
 digitalWrite(ledPin1,1);
 digitalWrite(ledPin2, 0);
 } 
 else if((-512+51.2<mapX<512-51.2) && (mapY <= -512+51.2)){
 digitalWrite(ledPin0, 1);
 digitalWrite(ledPin1,0);
 digitalWrite(ledPin2, 1);
 } 
 else if((-512+51.2<mapY<512-51.2) && (mapX <= -512+51.2)){
 digitalWrite(ledPin0, 1);
 digitalWrite(ledPin1,1);
 digitalWrite(ledPin2,0 );
 }
 else if((-512+51.2<mapY<512-51.2) && (mapX >= 512-51.2)){
digitalWrite(ledPin0, 0);
 digitalWrite(ledPin1,1);
 digitalWrite(ledPin2, 1);
 }
else { 
 digitalWrite(ledPin0, 0);
 digitalWrite(ledPin1, 0);
 digitalWrite(ledPin2, 0);
 }}