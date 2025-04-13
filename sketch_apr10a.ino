#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
#include <SD.h>

LiquidCrystal_I2C lcd(0x27, 16, 2); // I2C address 0x27

String lastStatus = "";
int lastValue = -1;  // To track last sensor value displayed

const int RELAY_PIN = 2;
const int SOIL_SENSOR_PIN = A0;
const int SD_CS_PIN = 9;  // SD card module CS pin

File logFile;

void setup() {
  //this part of the code was provided by Abdul Moiz
  Serial.begin(9600);
  lcd.init();
  lcd.backlight();
  lcd.clear();

  pinMode(RELAY_PIN, OUTPUT);
  digitalWrite(RELAY_PIN, HIGH);  // Pump off (relay is active-low)

  lcd.setCursor(0, 0);
  lcd.print(F("IRRIGATION"));
  lcd.setCursor(0, 1);
  lcd.print(F("SYSTEM IS ON"));
  delay(3000);
  lcd.clear();

  // Initialize SD card
  //this part of the code was provided by Haider
  if (!SD.begin(SD_CS_PIN)) {
    Serial.println("SD card init failed!");
    lcd.setCursor(0, 0);
    lcd.print("SD init failed!");
    delay(3000);
  } else {
    Serial.println("SD card ready.");
    lcd.setCursor(0, 0);
    lcd.print("SD card ready");
    delay(2000);
  }

  lcd.clear();
}

void loop() {
  //this part of the code was provided by Abdul Moiz
  int value = analogRead(SOIL_SENSOR_PIN);
  Serial.print(F("Soil sensor value: "));
  Serial.println(value);

  String status;

  if (value > 700) {
    status = "Dry";
    digitalWrite(RELAY_PIN, LOW);  // Pump ON
  } else {
    status = "Wet";
    digitalWrite(RELAY_PIN, HIGH); // Pump OFF
  }
  
  // Only update display & log if value or status changed
  // this part of the code was provided by haider
  if (value != lastValue || status != lastStatus) {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Soil: ");
    lcd.print(value);

    lcd.setCursor(0, 1);
    if (status == "Dry") {
      lcd.print("Pump ON (Dry)");
    } else {
      lcd.print("Pump OFF (Wet)");
    }

    // Log to SD card
    //this part of the code was provided by haider
    logFile = SD.open("log.txt", FILE_WRITE);
    if (logFile) {
      logFile.print("Soil: ");
      logFile.print(value);
      logFile.print(" - ");
      logFile.println(status);
      logFile.close();
      Serial.println("Logged to SD");
    } else {
      Serial.println("Failed to open log file");
    }

    lastValue = value;
    lastStatus = status;
  }

  delay(1000);
}
