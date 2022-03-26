int step = 0;
String num = "";
String system1 = "";

void setup()
{
    Serial.begin(9600);
    Serial.print("Enter number system you want to convert: ");
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
            if (input.equals("binary"))
            {
                system1 = "binary";
                Serial.print("Enter number to be converted: ");
                // delay(100);
                step = 1;
            }
            else if (input.equals("decimal"))
            {
                system1 = "decimal";
                Serial.print("Enter number to be converted: ");
                // delay(100);
                step = 1;
            }
            else if (input.equals("hexadeximal"))
            {
                system1 = "hexadeximal";
                Serial.print("Enter number to be converted: ");
                // delay(100);
                step = 1;
            }
            else if (input.equals("octal"))
            {
                system1 = "octal";
                Serial.print("Enter number to be converted: ");
                // delay(100);
                step = 1;
            }
            else
            {
                Serial.println("Invalid input. You must specify whether octal, decimal, hexadecimal, or binary");
                Serial.print("Enter number system to be converted: ");
            }
        }

        // Handle input for number to be converted
        else if (step == 1)
        {
            Serial.print(input + "\n");

            if (!isValidNumber(input))
            {
                Serial.println("Invalid input. Characters must be numeric");
                Serial.print("Enter number to be converted: ");
            }
            else
            {
                num = input;
                Serial.print("Enter number system: ");
                step++;
            }
        }

        // Handles input for number system
        else if (step == 2)
        {
            Serial.print(input + "\n");
            // HANDLE DECIMAL TO BLANK CONVERSION
            if (system1.equals("decimal"))
            {
                if (input.equals("binary"))
                {
                    Serial.println("\n<===================================================>\n");
                    int number = num.toInt();
                    Serial.print(system1 + " to binary conversion:");
                    for (int i = 7; i >= 0; i--)
                    {
                        Serial.print((number >> i & 1));
                    }
                    Serial.println();
                }
                else if (input.equals("octal"))
                {
                    int number = num.toInt();
                    printConverted(system1, "octal", String(number, 8));
                }
                else if (input.equals("decimal"))
                {
                    int number = num.toInt();
                    printConverted(system1, "decimal", String(number));
                }
                else if (input.equals("hexadecimal"))
                {
                    int number = num.toInt();
                    printConverted(system1, "hexadecimal", String(number, HEX));
                }
                else
                {
                    Serial.println("Invalid input. You must specify whether octal, decimal, hexadecimal, or binary");
                    Serial.print("Enter number system: ");
                }
            }

            // HANDLE BINARY TO BLANK CONVERSION
            else if (system1.equals("binary"))
            {
                if (input.equals("binary"))
                {
                    printConverted(system1, "binary", num);
                }
                else if (input.equals("decimal"))
                {
                    long number = convertBinaryToDecimal(num.toInt());
                    printConverted(system1, "decimal", String(number));
                }
            }
        }
    }
}

// Function to convert Binary to Decimal
long convertBinaryToDecimal(long binary)
{

    long number = binary;
    long decimalVal = 0;
    long baseVal = 1;
    long tempVal = number;
    long previousDigit;

    while (tempVal)
    {

        // Converts Binary to Decimal
        previousDigit = tempVal % 10;
        tempVal = tempVal / 10;
        decimalVal += previousDigit * baseVal;
        baseVal = baseVal * 2;
    }

    // Returns the Decimal number
    return decimalVal;
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

// Method for printing converted
void printConverted(String sys1, String sys2, String result)
{
    Serial.println("\n<===================================================>\n");
    Serial.println(sys1 + " to " + sys2 + " conversion: " + result);
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