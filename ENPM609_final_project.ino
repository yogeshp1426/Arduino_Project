// Author: Yogesh Patel, Project- ENPM609 Final Project Arduino code

#include <LiquidCrystal.h> // Using LiquidCrystal library to have an LCD object to interact with
#define echoPin 8 // attach pin D2 Arduino to pin Echo of HC-SR04
#define trigPin 7 //attach pin D3 Arduino to pin Trig of HC-SR04
#define buzzPin 2 // attach pin 2 to buzzer
// defining variables
long duration; // variable for the duration of sound wave travel time(which is twice the actual distance)
int distance; // variable for measuring the distance

LiquidCrystal lcd(4, 6, 10, 11, 12, 13);
void setup() {
  lcd.begin(16, 2);  // set up the LCD's number of columns and rows: 
  pinMode(buzzPin, OUTPUT); // Sets the buzzPin as OUTPUT
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an OUTPUT
  pinMode(echoPin, INPUT); // Sets the echoPin as an INPUT
  Serial.begin(9600); // // Serial Communication is starting with 9600 baudrate
  Serial.println("609 Project Test"); // printing some text in Serial Monitor
  Serial.println("with Arduino UNO R3");
}
void loop() {
  // Clears the trigPin condition
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  
  // Sets the trigPin HIGH (ACTIVE) for 10 microseconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);
  
  // Calculating the distance
  distance = duration * 0.034 / 2; // Speed of sound wave divided by 2 (as it accounted for going and coming back to sensor from obstacle)
  
  // Displays the distance on the Serial Monitor
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  lcd.setCursor(0,0); // To write on the first row of LCD 
  lcd.clear();
  lcd.print("Distance : "); // Printing Distance on first row of LCD
  lcd.print(distance);
  lcd.print(" cm");

  

  digitalWrite(buzzPin, LOW);
   
  if (distance <= 20) {
  // Buzz
  lcd.setCursor(0,1); // To write a warining message on second row of LCd
  lcd.print("Too close!"); 
  digitalWrite(buzzPin, HIGH); // To ring the buzzer
  }
  
}
