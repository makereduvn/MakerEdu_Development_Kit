// Include library
// Cai dat thu vien

#include "LiquidCrystal_I2C.h"

// Define connected pin
// Dat ten chan cong ket noi
#define LDR_PIN         A3
#define LED_STREET_PIN  A1
#define LED_RED_PIN     9
#define LED_YELLOW_PIN  10
#define LED_GREEN_PIN   11

// Set the LCD address to 0x27 for a 16 chars and 2 line display
// Thiet lap dia chi LCD 0x27 de hien thi 16 ky tu tren hai dong
LiquidCrystal_I2C LCD(0x27, 16, 2);

void setup() {
  // Initialize LCD 1602 to display
  // Khoi tao LCD 1602 de hien thi
  LCD.init();
  // Turn on LCD backlight
  // Bat den nen LCD 1602
  LCD.backlight();
  // Set LED as Output pin
  // Thiet lap LED o trang thai OUTPUT
  pinMode(LED_RED_PIN, OUTPUT);
  pinMode(LED_YELLOW_PIN, OUTPUT);
  pinMode(LED_GREEN_PIN, OUTPUT);
  pinMode(LED_STREET_PIN, OUTPUT);
}

void loop() {
  LCD.setCursor(0, 0);
  LCD.print("TRAFFIC");
  LCD.setCursor(8, 0);
  LCD.print("|");
  LCD.setCursor(10, 0);
  LCD.print("STREET");
  // Turn on Green Light and countdown 7 seconds
  // Dem nguoc den xanh 7 giay
  digitalWrite(LED_GREEN_PIN, HIGH);
  digitalWrite(LED_YELLOW_PIN, LOW);
  digitalWrite(LED_RED_PIN, LOW);
  for (int i = 7; i > 0; i--) {
    LCD.setCursor(0, 1);
    LCD.print(i);
    LCD.print("  ");
    LCD.setCursor(8, 1);
    LCD.print("|");
    LCD.setCursor(10, 1);
    LCD.print(analogRead(LDR_PIN));
    LCD.print(("  "));
    // If LRD>110 turn on the street light
    // Nếu cam bien anh sang > 110 bat den đuong
    if (analogRead(LDR_PIN) > 110) {
      digitalWrite(LED_STREET_PIN, HIGH);
    } else {
      digitalWrite(LED_STREET_PIN, LOW);
    }
    delay(1000);
  }
  // Turn on Yellow Light and countdown 3 seconds
  // Dem nguoc den vang 3 giay
  digitalWrite(LED_GREEN_PIN, LOW);
  digitalWrite(LED_YELLOW_PIN, HIGH);
  digitalWrite(LED_RED_PIN, LOW);
  for (int i = 3; i > 0 ; i--) {
    LCD.setCursor(0, 1);
    LCD.print(i);
    LCD.print("  ");
    LCD.setCursor(8, 1);
    LCD.print("|");
    LCD.setCursor(10, 1);
    LCD.print(analogRead(LDR_PIN));
    LCD.print(("  "));
    // If LRD>110 turn on the street light
    // Nếu cam bien anh sang > 110 bat den đuong
    if (analogRead(LDR_PIN) > 110) {
      digitalWrite(LED_STREET_PIN, HIGH);
    } else {
      digitalWrite(LED_STREET_PIN, LOW);
    }
    delay(1000);
  }
  // Turn on Red Light and countdown 10 seconds
  // Dem nguoc den do 10 giay
  digitalWrite(LED_GREEN_PIN, LOW);
  digitalWrite(LED_YELLOW_PIN, LOW);
  digitalWrite(LED_RED_PIN, HIGH);
  for (int i = 10; i > 0; i--) {
    LCD.setCursor(0, 1);
    LCD.print(i);
    LCD.print("  ");
    LCD.setCursor(8, 1);
    LCD.print("| ");
    LCD.setCursor(10, 1);
    LCD.print(analogRead(LDR_PIN));
    LCD.print(("  "));
    // If LRD>110 turn on the street light
    // Nếu cam bien anh sang > 110 bat den đuong
    if (analogRead(LDR_PIN) > 110) {
      digitalWrite(LED_STREET_PIN, HIGH);
    } else {
      digitalWrite(LED_STREET_PIN, LOW);
    }
    delay(1000);
  }
}
