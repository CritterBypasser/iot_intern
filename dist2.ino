#include <LiquidCrystal_I2C.h>

#include <Wire.h>


LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
   //Initialize the LCD
  lcd.init();
  lcd.begin(16,2);
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("Distance: ");
 
  pinMode(7, OUTPUT); // changed pin 1 to pin 7 for the LED
  pinMode(5, OUTPUT); // LED
  pinMode(6, OUTPUT); // LED
  pinMode(4, OUTPUT); // Buzzer
  pinMode(2, INPUT);  // Echo
  pinMode(3, OUTPUT); // Trigger
  Serial.begin(9600);
}

void loop() {
 
  digitalWrite(3, LOW);
  delayMicroseconds(2);
  digitalWrite(3, HIGH);
  delayMicroseconds(10);
  digitalWrite(3, LOW);
 
  // Read the echo pin
  long duration = pulseIn(2, HIGH);
  long inches = duration / 74 / 2;  // Convert time to distance in inches
  long cm = duration * 0.017;       // Convert time to distance in cm
 
  Serial.print(inches);
  Serial.println(" inches");  
  Serial.print(cm);
  Serial.println(" cm");      
  Serial.println();        

  // Update the LCD
  lcd.setCursor(0, 1);
  lcd.print("                ");
  lcd.setCursor(0, 1);
  lcd.print(cm);
  lcd.print(" cm");

 
  if (cm <= 10) 
  {
    digitalWrite(7, HIGH);  
    digitalWrite(4, HIGH);  
    digitalWrite(5, LOW);  
    digitalWrite(6, LOW);  
  } else if (cm <= 50) 
  {
    digitalWrite(5, HIGH);  
    digitalWrite(7, LOW);  
    digitalWrite(6, LOW); 
    digitalWrite(4, LOW);  
  } else if (cm <= 100) 
  {
    digitalWrite(6, HIGH);  
    digitalWrite(5, LOW);  
    digitalWrite(7, LOW); 
    digitalWrite(4, LOW);  
  } else 
  {
    digitalWrite(7, LOW);
    digitalWrite(5, LOW);  
    digitalWrite(6, LOW);  
    digitalWrite(4, LOW);  
  }

  delay(100); // Avoid sudden switching
}
