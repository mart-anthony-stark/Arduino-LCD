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

String NumberToBeDisplayed = "";
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
        NumberToBeDisplayed += "1";
    }
    else if (key == '2')
    {
        lcd.print("2");
        delay(50);
        NumberToBeDisplayed += "2";
    }
    else if (key == '3')
    {
        lcd.print("3");
        delay(50);
        NumberToBeDisplayed += "3";
    }
    else if (key == '4')
    {
        lcd.print("4");
        delay(50);
        NumberToBeDisplayed += "4";
    }
    else if (key == '5')
    {
        lcd.print("5");
        delay(50);
        NumberToBeDisplayed += "5";
    }
    else if (key == '6')
    {
        lcd.print("6");
        delay(50);
        NumberToBeDisplayed += "6";
    }
    else if (key == '7')
    {
        lcd.print("7");
        delay(50);
        NumberToBeDisplayed += "7";
    }
    else if (key == '8')
    {
        lcd.print("8");
        delay(50);
        NumberToBeDisplayed += "8";
    }
    else if (key == '9')
    {
        lcd.print("9");
        delay(50);
        NumberToBeDisplayed += "9";
    }
    else if (key == '0')
    {
        lcd.print("0");
        delay(50);
        NumberToBeDisplayed += "0";
    }
    else if (key == 'A')
    {
        lcd.clear();
        lcd.print("-- OCTAL --");
        lcd.setCursor(0, 1);
        int num = NumberToBeDisplayed.toInt();
        TempNum = ConvertDecimalToBase(num, 8);
        Serial.println(num);
        lcd.print(TempNum);
    }

    // Serial.println(NumberToBeDisplayed);
}

// Method for converting to with specified base
int ConvertDecimalToBase(int n, int b)
{
    int r = 0, digitPos = 1;
    while (n)
    {
        r += (n % b) * digitPos;
        n /= b;
        digitPos *= 10;
    }
    return r;
}

void ConvertDecimalToHex(long int num)
{
    long int rem[50], i = 0, length = 0;
    while (num > 0)
    {
        rem[i] = num % 16;
        num = num / 16;
        i++;
        length++;
    }
    for (i = length - 1; i >= 0; i--)
    {
        switch (rem[i])
        {
        case 10:
            lcd.print("A");
            break;
        case 11:
            lcd.print("B");
            break;
        case 12:
            lcd.print("C");
            break;
        case 13:
            lcd.print("D");
            break;
        case 14:
            lcd.print("E");
            break;
        case 15:
            lcd.print("F");
            break;
        default:
            lcd.print(rem[i]);
        }
    }
}
