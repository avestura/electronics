#include <LiquidCrystal_I2C.h>
#define trigPin 10
#define echoPin 13

LiquidCrystal_I2C lcd(0x3F, 16, 2);

void setup() {
  Serial.begin (9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
}

void loop() {
  float duration, distance;
  digitalWrite(trigPin, LOW); 
  delayMicroseconds(2);
 
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  duration = pulseIn(echoPin, HIGH);
  distance = (duration / 2) * 0.0344;
  
  if (distance >= 400 || distance <= 2){
    Serial.print("Distance = ");
    Serial.println("Out of range");
    lcd.setCursor(0, 0);
    lcd.print("distance: ");
    lcd.setCursor(0, 1);
    lcd.print("Out of range");
    delay(100);
  }
  else {
    Serial.print("Distance = ");
    Serial.print(distance);
    Serial.println(" cm");
    lcd.setCursor(0, 0);
    lcd.print("distance: ");
    lcd.setCursor(0, 1);
    lcd.print(distance);
    lcd.print(" cm");
    delay(500);
  }
  delay(500);
  lcd.clear();
}
