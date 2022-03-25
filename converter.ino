#include <LiquidCrystal.h>
/*Connected RS of LCD to A0 EN to A1 D4 to D7 to A2 to A5 Respectively*/
LiquidCrystal lcd(A0, A1, A2, A3, A4, A5);
int NumberToBeDisplayed = 0;
int TempNum = 0;
/*Rows of keypad connected to D6-D9 of Arduino*/
int r1 = 6;
int r2 = 7;
int r3 = 8;
int r4 = 9;
/*Colums of keypad connected to D10-D13 of Arduino*/
int c1 = 10;
int c2 = 11;
int c3 = 12;
int c4 = 13;
/*Declared four variable to read colums status*/
int col1;
int col2;
int col3;
int col4;
void setup()
{
    /*Declared Row pins as OUTPUT*/
    pinMode(r1, OUTPUT);
    pinMode(r2, OUTPUT);
    pinMode(r3, OUTPUT);
    pinMode(r4, OUTPUT);
    /*Declared Column pins as OUTPUT*/
    pinMode(c1, INPUT);
    pinMode(c2, INPUT);
    pinMode(c3, INPUT);
    pinMode(c4, INPUT);
    digitalWrite(c1, HIGH);
    digitalWrite(c2, HIGH);
    digitalWrite(c3, HIGH);
    digitalWrite(c4, HIGH);
    pinMode(4, OUTPUT);
    /*lcd brightness terminal connected*/
    digitalWrite(4, 0);
    lcd.begin(16, 2);
    lcd.setCursor(0, 0);
    lcd.print(“A
              : Oct B
              : Binary”);
    lcd.setCursor(0, 1);
    lcd.print(“C
              : Hex D
              : Decimal”);
    lcd.setCursor(0, 1);
    delay(2000);
    lcd.clear();
    lcd.setCursor(0, 1);
}
void loop()
{
    digitalWrite(r1, LOW);
    digitalWrite(r2, HIGH);
    digitalWrite(r3, HIGH);
    digitalWrite(r4, HIGH);
    col1 = digitalRead(c1);
    col2 = digitalRead(c2);
    col3 = digitalRead(c3);
    col4 = digitalRead(c4);
    if (col1 == LOW)
    {
        lcd.print(“1”);
        delay(50);
        NumberToBeDisplayed = (NumberToBeDisplayed * 10) + 1;
        while (digitalRead(c1) == LOW)
            ;
    }
    else if (col2 == LOW)
    {
        lcd.print(“2”);
        delay(50);
        NumberToBeDisplayed = (NumberToBeDisplayed * 10) + 2;
        while (digitalRead(c2) == LOW)
            ;
    }
    else if (col3 == LOW)
    {
        lcd.print(“3”);
        delay(50);
        NumberToBeDisplayed = (NumberToBeDisplayed * 10) + 3;
        while (digitalRead(c3) == LOW)
            ;
    }
    else if (col4 == 0)
    {
        lcd.clear();
        lcd.print(“—- OCTAL —–“);
        lcd.setCursor(0, 1);
        TempNum = ConvertDecimalToBase(NumberToBeDisplayed, 8);
        lcd.print(TempNum);
        while (digitalRead(c4) == LOW)
            ;
    }
    digitalWrite(r1, HIGH);
    digitalWrite(r2, LOW);
    digitalWrite(r3, HIGH);
    digitalWrite(r4, HIGH);
    col1 = digitalRead(c1);
    col2 = digitalRead(c2);
    col3 = digitalRead(c3);
    col4 = digitalRead(c4);
    if (col1 == LOW)
    {
        lcd.print(“4”);
        delay(50);
        NumberToBeDisplayed = (NumberToBeDisplayed * 10) + 4;
        while (digitalRead(c1) == LOW)
            ;
    }
    else if (col2 == LOW)
    {
        lcd.print(“5”);
        delay(50);
        NumberToBeDisplayed = (NumberToBeDisplayed * 10) + 5;
        while (digitalRead(c2) == LOW)
            ;
    }
    else if (col3 == LOW)
    {
        lcd.print(“6”);
        delay(50);
        NumberToBeDisplayed = (NumberToBeDisplayed * 10) + 6;
        while (digitalRead(c3) == LOW)
            ;
    }
    else if (col4 == LOW)
    {
        delay(50);
        lcd.clear();
        lcd.print(“—- BINARY —-“);
        lcd.setCursor(0, 1);
        for (int i = 15; i >= 0; i–)
        {
            lcd.print((NumberToBeDisplayed >> i & 1));
        }
        while (digitalRead(c4) == LOW)
            ;
    }
    digitalWrite(r1, HIGH);
    digitalWrite(r2, HIGH);
    digitalWrite(r3, LOW);
    digitalWrite(r4, HIGH);
    col1 = digitalRead(c1);
    col2 = digitalRead(c2);
    col3 = digitalRead(c3);
    col4 = digitalRead(c4);
    if (col1 == LOW)
    {
        lcd.print(“7”);
        delay(50);
        NumberToBeDisplayed = (NumberToBeDisplayed * 10) + 7;
        while (digitalRead(c1) == LOW)
            ;
    }
    else if (col2 == LOW)
    {
        lcd.print(“8”);
        delay(50);
        NumberToBeDisplayed = (NumberToBeDisplayed * 10) + 8;
        while (digitalRead(c2) == LOW)
            ;
    }
    else if (col3 == LOW)
    {
        lcd.print(“9”);
        delay(50);
        NumberToBeDisplayed = (NumberToBeDisplayed * 10) + 9;
        while (digitalRead(c3) == LOW)
            ;
    }
    else if (col4 == LOW)
    {
        delay(50);
        lcd.clear();
        lcd.print(“- HEXADECIMAL –“);
        lcd.setCursor(0, 1);
        TempNum = NumberToBeDisplayed;
        ConvertDecimalToHex(TempNum);
        while (digitalRead(c4) == LOW)
            ;
    }
    digitalWrite(r1, HIGH);
    digitalWrite(r2, HIGH);
    digitalWrite(r3, HIGH);
    digitalWrite(r4, LOW);
    col1 = digitalRead(c1);
    col2 = digitalRead(c2);
    col3 = digitalRead(c3);
    col4 = digitalRead(c4);
    if (col1 == LOW)
    {
        delay(50);
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print(“A
                  : Oct B
                  : Binary”);
        lcd.setCursor(0, 1);
        lcd.print(“C
                  : Hex D
                  : Decimal”);
        lcd.setCursor(0, 1);
        delay(2000);
        lcd.clear();
        NumberToBeDisplayed = 0;
        while (digitalRead(c2) == LOW)
            ;
    }
    else if (col2 == LOW)
    {
        lcd.print(“0”);
        delay(50);
        NumberToBeDisplayed = (NumberToBeDisplayed * 10) + 0;
        while (digitalRead(c2) == LOW)
            ;
    }
    else if (col3 == LOW)
    {
        delay(50);
        lcd.clear();
        lcd.print(“—- OCTAL —–“);
        lcd.setCursor(0, 1);
        TempNum = ConvertDecimalToBase(NumberToBeDisplayed, 8);
        lcd.print(TempNum);
        delay(1000);
        lcd.clear();
        lcd.print(“—- BINARY —-“);
        lcd.setCursor(0, 1);
        for (int i = 15; i >= 0; i–)
        {
            lcd.print((NumberToBeDisplayed >> i & 1));
        }
        delay(1000);
        lcd.clear();
        lcd.print(“- HEXADECIMAL –“);
        lcd.setCursor(0, 1);
        TempNum = NumberToBeDisplayed;
        ConvertDecimalToHex(TempNum);
        delay(1000);
        lcd.clear();
        lcd.print(“— DECIMAL —-“);
        lcd.setCursor(0, 1);
        lcd.print(NumberToBeDisplayed);
        delay(1000);
        lcd.clear();
        NumberToBeDisplayed = 0;
        lcd.setCursor(0, 0);
        lcd.print(“A
                  : Oct B
                  : Binary”);
        lcd.setCursor(0, 1);
        lcd.print(“C
                  : Hex D
                  : Decimal”);
        lcd.setCursor(0, 1);
        delay(2000);
        lcd.clear();
        lcd.setCursor(0, 1);
        while (digitalRead(c3) == LOW)
            ;
    }
    else if (col4 == LOW)
    {
        delay(50);
        lcd.clear();
        lcd.print(“— DECIMAL —-“);
        lcd.setCursor(0, 1);
        lcd.print(NumberToBeDisplayed);
        while (digitalRead(c4) == LOW)
            ;
    }
}
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
    for (i = length - 1; i >= 0; i–)
    {
        switch (rem[i])
        {
        case 10:
            lcd.print(“A”);
            break;
        case 11:
            lcd.print(“B”);
            break;
        case 12:
            lcd.print(“C”);
            break;
        case 13:
            lcd.print(“D”);
            break;
        case 14:
            lcd.print(“E”);
            break;
        case 15:
            lcd.print(“F”);
            break;
        default:
            lcd.print(rem[i]);
        }
    }
}