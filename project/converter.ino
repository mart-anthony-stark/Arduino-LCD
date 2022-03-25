/*
  LiquidCrystal Library - Hello World

 Demonstrates the use a 16x2 LCD display.  The LiquidCrystal
 library works with all LCD displays that are compatible with the
 Hitachi HD44780 driver. There are many of them out there, and you
 can usually tell them by the 16-pin interface.

 This sketch prints "Hello World!" to the LCD
 and shows the time.

  The circuit:
 * LCD RS pin to digital pin 5
 * LCD Enable pin to digital pin 4
 * LCD D4 pin to digital pin 3
 * LCD D5 pin to digital pin 2
 * LCD D6 pin to digital pin A4
 * LCD D7 pin to digital pin A5
 * LCD R/W pin to ground
 * LCD VSS pin to ground
 * LCD VCC pin to 5V
 * 10K resistor:
 * ends to +5V and ground
 * wiper to LCD VO pin (pin 3)

 This example code is in the public domain.

 http://www.arduino.cc/en/Tutorial/LiquidCrystal
 */

// include the library code:
#include <Keypad.h>
#include <LiquidCrystal.h>

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(5, 4, 3, 2, A4, A5);

int NumberToBeDisplayed = 0;
int TempNum = 0;

// Mapping byte keys
const byte ROWS = 4; // four rows
const byte COLS = 4; // three columns
char keys[ROWS][COLS] = {
    {'1', '2', '3', 'A'},
    {'4', '5', '6', 'B'},
    {'7', '8', '9', 'C'},
    {'*', '0', '#', 'D'}};
byte rowPins[ROWS] = {A0, A1, 11, 10}; // connect to the row pinouts of the keypad
byte colPins[COLS] = {9, 8, 7, 6};     // connect to the column pinouts of the keypad
int LCDCol = 0;
int LCDRow = 0;

Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

void setup()
{
    // set up the LCD's number of columns and rows:
    Serial.begin(9600);
    lcd.begin(16, 2);
    lcd.setCursor(LCDCol, LCDRow);
}

void loop()
{
    char key = keypad.getKey();

    if (key == '1')
    {
        lcd.print("1");
        delay(50);
        NumberToBeDisplayed = (NumberToBeDisplayed * 10) + 1;
    }
    else if (key == '2')
    {
        lcd.print("2");
        delay(50);
        NumberToBeDisplayed = (NumberToBeDisplayed * 10) + 2;
    }
    Serial.println(NumberToBeDisplayed);
}
