int step = 0;
int num = 0;
String numSystem = "";
void setup()
{
    Serial.begin(9600);
    Serial.print("Enter number to be converted: ");
}

void loop()
{

    while (Serial.available())
    {
        String input = Serial.readString(); // read the incoming data as string

        // Handles input for number to be converted
        if (step == 0)
        {
            Serial.print(input + "\n");

            if (!isValidNumber(input))
            {
                Serial.println("Invalid input. Characters must be numeric");
                Serial.print("Enter number to be converted: ");
            }
            else
            {
                num = input.toInt();
                Serial.print("Enter number system: ");
                step++;
            }
        }
        // Handles input for number system
        else if (step == 1)
        {
            Serial.print(input + "\n");

            if (input.equals("binary"))
            {
                Serial.print("Binary: ");
            }
            else if (input.equals("octal"))
            {
                Serial.print("octal: ");
            }
            else if (input.equals("decimal"))
            {
                Serial.print("decimal: ");
            }
            else if (input.equals("hexadecimal"))
            {
                Serial.print("hexadecimal: ");
            }
            else
            {
                Serial.println("Invalid input. You must specify whether octal, decimal, hexadecimal, or binary");
                Serial.print("Enter number system:: ");
            }
        }
    }
}

boolean isValidNumber(String str)
{
    for (byte i = 0; i < str.length(); i++)
    {
        if (isDigit(str.charAt(i)))
            return true;
    }
    return false;
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

String ConvertDecimalToHex(long int n)
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
    return hex;
}