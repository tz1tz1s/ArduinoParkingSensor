const int trigPin = 2;    // Arduino Nano digital pin 2
const int echoPin = 3;    // Arduino Nano digital pin 3
const int greenLed = 5;   // Arduino Nano digital pin 5
const int orangeLed = 6;  // Arduino Nano digital pin 6
const int redLed = 7;     // Arduino Nano digital pin 7
const int buzzerPin = 8;  // Arduino Nano digital pin 8

const int distanceThreshold1 = 70; // Distance threshold for green LED
const int distanceThreshold2 = 50;  // Distance threshold for orange LED
const int distanceThreshold3 = 30;  // Distance threshold for red LED
const int distanceThreshold4 = 10;

int buzNear = 100;     //declare buzzing time for very close proximity;
int buzHigh = 200;     //declare buzzing time for close proximity;
int buzMid  =300;     //declare buzzing time for mid proximity;


void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(greenLed, OUTPUT);
  pinMode(orangeLed, OUTPUT);
  pinMode(redLed, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
  analogWrite(buzzerPin, LOW);
  Serial.begin(9600);
}

void loop() {
  
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  long duration = pulseIn(echoPin, HIGH);

  int distance = duration * 0.034 / 2;

  Serial.print("Distance: ");
  Serial.println(distance);

  //control the buzzer and the leds
  
  if (distance > distanceThreshold1) {
    digitalWrite(buzzerPin, HIGH);
  }
  
 if (distance <= distanceThreshold1 && distance >= distanceThreshold2) {
    digitalWrite(greenLed, HIGH);
    digitalWrite(buzzerPin,LOW);
    delay(buzMid);
    digitalWrite(buzzerPin,HIGH);
    delay(buzMid);
  }
  else{
    digitalWrite(buzzerPin,HIGH);
    digitalWrite(greenLed, LOW);
  }
 
  if (distance < distanceThreshold2 && distance >= distanceThreshold3) {
    digitalWrite(orangeLed, HIGH);
    digitalWrite(greenLed, HIGH);
    digitalWrite(buzzerPin,LOW);
    delay(buzHigh);
    digitalWrite(buzzerPin,HIGH);
    delay(buzHigh);
  }
  else{
    digitalWrite(orangeLed, LOW);
    digitalWrite(greenLed, LOW);
    digitalWrite(buzzerPin,HIGH);
  }
  
 if (distance < distanceThreshold3 && distance >= distanceThreshold4) {
    digitalWrite(redLed, HIGH);
    digitalWrite(orangeLed, HIGH);
    digitalWrite(greenLed, HIGH);
    digitalWrite(buzzerPin,LOW);
    delay(buzNear);
    digitalWrite(buzzerPin,HIGH);
    delay(buzNear);
  }
  else{
    digitalWrite(redLed, LOW);
    digitalWrite(orangeLed, LOW);
    digitalWrite(greenLed, LOW);
    digitalWrite(buzzerPin,HIGH);
  }
  
 if (distance >= 0 && distance < distanceThreshold4) {
    digitalWrite(buzzerPin,LOW);
    digitalWrite(redLed, HIGH);
    digitalWrite(orangeLed, HIGH);
    digitalWrite(greenLed, HIGH);
    delay(500);
    digitalWrite(redLed, LOW);
    digitalWrite(orangeLed, LOW);
    digitalWrite(greenLed, LOW);
    delay(500);
  }
  else{
    digitalWrite(buzzerPin,HIGH);
    digitalWrite(redLed, LOW);
    digitalWrite(orangeLed, LOW);
    digitalWrite(greenLed, LOW);
  }
 
}
