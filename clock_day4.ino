#include <RTClib.h>
#include <RTCDS1307.h>

#include <Wire.h> //to communicate with i2c from board
#include <DS1307RTC.h> // Include the RTC library, adjust if using a different library
#include <LiquidCrystal_I2C.h> // Include if using an LCD
RTCDS1307 rtc;
// Pins for the 4-switch module
const int switch1Pin = 8; // Example pin numbers, adjust as per your wiring
const int switch2Pin = 9;
const int switch3Pin = 10;
const int switch4Pin = 11;

// Pin for the buzzer
const int buzzerPin = 12;

// Initialize RTC instance


// Variables for storing time and alarm
int alarmHour = 0;
int alarmMinute = 0;
bool alarmEnabled = false;

LiquidCrystal_I2C lcd(0x27,16,2);


void setup() {
  lcd.init();
 // lcd.init();
  lcd.begin(16,2);
  // Initialize Serial communication for debugging
  Serial.begin(9600);

  // Initialize RTC
  Wire.begin();
  if (!rtc.begin()) {
    Serial.println("Couldn't find RTC");
    while (1);
  }

  // Check if RTC is running and set the time if not
  if (!rtc.isrunning()) {
    Serial.println("RTC is NOT running!");
    // Set the RTC to the date & time this sketch was compiled
    rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
  }

  // Set up switch module pins as inputs
  pinMode(switch1Pin, INPUT);
  pinMode(switch2Pin, INPUT);
  pinMode(switch3Pin, INPUT);
  pinMode(switch4Pin, INPUT);

  // Set up buzzer pin as output
  pinMode(buzzerPin, OUTPUT);
}

void loop() {
  // Read switches and set alarm time accordingly
  readSwitches();

  // Get current time from RTC
  DateTime now = rtc.now();
  int currentHour = now.hour();
  int currentMinute = now.minute();

  // Check if alarm time matches current time and alarm is enabled
  if (alarmEnabled && alarmHour == currentHour && alarmMinute == currentMinute) {
    // Trigger the alarm
    activateAlarm();
    // Disable alarm to avoid continuous triggering
    alarmEnabled = false;
  }

  // Display current time and alarm time (for debugging, you can use an LCD for actual display)
  Serial.print("Current Time: ");
  printDigits(currentHour);
  Serial.print(":");
  printDigits(currentMinute);
  Serial.println();

  Serial.print("Alarm Time: ");
  printDigits(alarmHour);
  Serial.print(":");
  printDigits(alarmMinute);
  Serial.println();

  lcd.setCursor(0,1);
lcd.print("Time: ");
lcd.print(currentHour);
lcd.setCursor(1,0);
lcd.print("Time: ");
lcd.print(currentMinute);
  delay(1000); // Update every second
}

// Function to read switches and set alarm time
void readSwitches() {
  if (digitalRead(switch1Pin) == HIGH) {
    alarmHour++;
    if (alarmHour > 23) alarmHour = 0;
    delay(200); // Debounce delay
  }
  if (digitalRead(switch2Pin) == HIGH) {
    alarmMinute++;
    if (alarmMinute > 59) alarmMinute = 0;
    delay(200); // Debounce delay
  }
  if (digitalRead(switch3Pin) == HIGH) {
    alarmEnabled = !alarmEnabled;
    delay(200); // Debounce delay
  }
  if (digitalRead(switch4Pin) == HIGH) {
    // Additional function, if needed
    delay(200); // Debounce delay
  }
}

// Function to activate the alarm (turn on buzzer)
void activateAlarm() {
  digitalWrite(buzzerPin, HIGH); // Sound the buzzer
  delay(1000); // Buzzer ON time
  digitalWrite(buzzerPin, LOW); // Silence the buzzer
  delay(1000); // Buzzer OFF time
}

// Function to print digits with leading zero if necessary
void printDigits(int digits) {
  if (digits < 10) {
    Serial.print('0');
  }
  Serial.print(digits);
}
