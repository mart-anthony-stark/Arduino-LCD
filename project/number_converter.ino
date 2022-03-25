int step = 0;
String num = "";
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
                num = input;
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
                Serial.println("\n<========== BINARY ==========>\n");
                int number = num.toInt();
                Serial.print(num + " to Binary conversion:");
                for (int i = 15; i >= 0; i--)
                {
                    Serial.print((number >> i & 1));
                }
                Serial.println();
            }
            else if (input.equals("octal"))
            {
                Serial.println("\n<========== OCTAL ==========>\n");
                int number = num.toInt();
                int octal = ConvertDecimalToBase(number, 8);
                Serial.println(num + " to Octal conversion: " + octal);
            }
            else if (input.equals("decimal"))
            {
                Serial.println("\n<========== DECIMAL ==========>\n");
                int number = num.toInt();
                Serial.println(num + " to Decimal conversion: " + number);
            }
            else if (input.equals("hexadecimal"))
            {
                Serial.println("\n<========== HEXADECIMAL ==========>\n");
                int number = num.toInt();
                String hex = ConvertDecimalToHex(number);
                Serial.println(num + " to Hexadecimal conversion: " + hex);
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

void continueProgram()
{
    Serial.print("\n\nDo you want to convert again? (Y/N): ");

    String input = Serial.readString();

    if (input.equalsIgnoreCase("y"))
    {
        // step = 0;
        // num = "";
        Serial.println("=====================================\n");
        Serial.print("Enter number to be converted: ");
    }
    else if (input.equalsIgnoreCase("n"))
    {
    }
}