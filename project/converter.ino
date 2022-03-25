/*
  circuit connection:
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

 */

#include <Keypad.h>
#include <LiquidCrystal.h>

// initialize the lcd
LiquidCrystal lcd(5, 4, 3, 2, A4, A5);

String numberDisplay = "";
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
        numberDisplay += "1";
    }
    else if (key == '2')
    {
        lcd.print("2");
        delay(50);
        numberDisplay += "2";
    }
    else if (key == '3')
    {
        lcd.print("3");
        delay(50);
        numberDisplay += "3";
    }
    else if (key == '4')
    {
        lcd.print("4");
        delay(50);
        numberDisplay += "4";
    }
    else if (key == '5')
    {
        lcd.print("5");
        delay(50);
        numberDisplay += "5";
    }
    else if (key == '6')
    {
        lcd.print("6");
        delay(50);
        numberDisplay += "6";
    }
    else if (key == '7')
    {
        lcd.print("7");
        delay(50);
        numberDisplay += "7";
    }
    else if (key == '8')
    {
        lcd.print("8");
        delay(50);
        numberDisplay += "8";
    }
    else if (key == '9')
    {
        lcd.print("9");
        delay(50);
        numberDisplay += "9";
    }
    else if (key == '0')
    {
        lcd.print("0");
        delay(50);
        numberDisplay += "0";
    }
    else if (key == 'A')
    {
        lcd.clear();
        lcd.print("<< OCTAL >>");
        lcd.setCursor(0, 1);
        int num = numberDisplay.toInt();
        TempNum = ConvertDecimalToBase(num, 8);
        Serial.println(num);
        lcd.print(TempNum);
    }
    else if (key == 'B')
    {
        lcd.clear();
        lcd.print("<< BINARY >>");
        lcd.setCursor(0, 1);
        int num = numberDisplay.toInt();
        for (int i = 15; i >= 0; i--)
        {
            lcd.print((num >> i & 1));
        }
        Serial.println(num);
    }
    else if (key == 'C')
    {
        delay(50);
        lcd.clear();
        lcd.print("<<HEXADECIMAL>>");
        lcd.setCursor(0, 1);
        int num = numberDisplay.toInt();
        ConvertDecimalToHex(num);
        Serial.println(num);
    }
    else if (key == 'D')
    {
        lcd.clear();
        lcd.print("<< DECIMAL >>");
        lcd.setCursor(0, 1);
        lcd.print(numberDisplay);
        delay(1000);
    }
    else if (key == 42)
    {
        numberDisplay = "";
        delay(50);
        lcd.clear();
        lcd.setCursor(0, 1);
        lcd.print("Enter number");
        lcd.setCursor(0, 0);
    }

    // Serial.println(key==42);
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

void ConvertDecimalToHex(long int n)
{
    String hex = "";
    long int rem[50], i = 0, length = 0;
    while (n > 0)
    {
        rem[i] = n % 16;
        n = n / 16;
        i++;
        length++;
    }
    for (i = length - 1; i >= 0; i--)
    {
        switch (rem[i])
        {
        case 10:
            hex += "A";
            break;
        case 11:
            hex += "B";
            break;
        case 12:
            hex += "C";
            break;
        case 13:
            hex += "D";
            break;
        case 14:
            hex += "E";
            break;
        case 15:
            hex += "F";
            break;
        default:
            hex += rem[i];
        }
    }
    lcd.print(hex);
}
