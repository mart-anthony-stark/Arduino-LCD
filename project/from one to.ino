int step = 0;
String num = "";
String system1 = "";

void setup()
{
    Serial.begin(9600);
    Serial.println("========= Number System Converter =========");
    Serial.println("Enter number system you want to convert: ");
    Serial.println("\t* decimal");
    Serial.println("\t* octal");
    Serial.println("\t* hexadecimal");
    Serial.println("\t* binary");
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
                step = 1;
            }
            else if (input.equals("decimal"))
            {
                system1 = "decimal";
                Serial.print("Enter number to be converted: ");
                step = 1;
            }
            else if (input.equals("hexadecimal"))
            {
                system1 = "hexadecimal";
                Serial.print("Enter number to be converted: ");
                step = 1;
            }
            else if (input.equals("octal"))
            {
                system1 = "octal";
                Serial.print("Enter number to be converted: ");
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

        // Handles input for 2nd number system and convert it
        else if (step == 2)
        {
            Serial.print(input + "\n");
            // HANDLE DECIMAL TO BLANK CONVERSION
            if (system1.equals("decimal"))
            {
                if (input.equals("binary"))
                {
                    int number = num.toInt();
                    printBinary(number);
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
                    String hex = ConvertDecimalToHex(number);
                    printConverted(system1, "hexadecimal", String(hex));
                }
                else
                {
                    printErrorNSys();
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
                else if (input.equals("hexadecimal"))
                {
                    long number = convertBinaryToDecimal(num.toInt());
                    String hex = ConvertDecimalToHex(number);
                    printConverted(system1, "hexadecimal", String(hex));
                }
                else if (input.equals("octal"))
                {
                    long number = convertBinaryToDecimal(num.toInt());
                    printConverted(system1, "octal", String(number, 8));
                }
                else
                {
                    printErrorNSys();
                }
            }
            // HANDLE OCTAL TO BLANK CONVERSION
            else if (system1.equals("octal"))
            {
                if (input.equals("octal"))
                {
                    printConverted(system1, "octal", num);
                }
                else if (input.equals("decimal"))
                {
                    int number = num.toInt();
                    int decimal = octalToDecimal(number);
                    printConverted(system1, "decimal", String(decimal));
                }
                else if (input.equals("hexadecimal"))
                {
                    int number = num.toInt();
                    int decimal = octalToDecimal(number);
                    String hex = ConvertDecimalToHex(decimal);
                    printConverted(system1, "hexadecimal", String(hex));
                }
                else if (input.equals("binary"))
                {
                    int number = num.toInt();
                    int decimal = octalToDecimal(number);
                    printBinary(decimal);
                }
                else
                {
                    printErrorNSys();
                }
            }

            // HANDLE HEX TO BLANK CONVERSION
            else if (system1.equals("hexadecimal"))
            {
                if (input.equals("hexadecimal"))
                {
                    printConverted(system1, "hexadecimal", num);
                }
                else if (input.equals("decimal"))
                {
                    int str_len = num.length() + 1;
                    char char_array[str_len];
                    num.toCharArray(char_array, str_len);
                    int decimal = HexToDecimal(char_array);
                    printConverted(system1, "decimal", String(decimal));
                }
                else if (input.equals("octal"))
                {
                    int str_len = num.length() + 1;
                    char char_array[str_len];
                    num.toCharArray(char_array, str_len);
                    int decimal = HexToDecimal(char_array);
                    printConverted(system1, "octal", String(decimal, 8));
                }
                else if (input.equals("binary"))
                {
                    int str_len = num.length() + 1;
                    char char_array[str_len];
                    num.toCharArray(char_array, str_len);
                    int decimal = HexToDecimal(char_array);
                    printBinary(decimal);
                }
                else
                {
                    printErrorNSys();
                }
            }
        }
    }
}

// Method for converting hexadecimal to decimal
long HexToDecimal(char hex[])
{
    long long decimal, place;
    int i = 0, val, len;

    decimal = 0;
    place = 1;

    /* Find the length of total number of hex digit */
    len = strlen(hex);
    len--;

    /*
     * Iterate over each hex digit
     */
    for (i = 0; hex[i] != '\0'; i++)
    {

        /* Find the decimal representation of hex[i] */
        if (hex[i] >= '0' && hex[i] <= '9')
        {
            val = hex[i] - 48;
        }
        else if (hex[i] >= 'a' && hex[i] <= 'f')
        {
            val = hex[i] - 97 + 10;
        }
        else if (hex[i] >= 'A' && hex[i] <= 'F')
        {
            val = hex[i] - 65 + 10;
        }

        decimal += val * pow(16, len);
        len--;
    }
    return decimal + 1;
}

// Function for printing binary numbers, accepts decimal int parameter
void printBinary(int number)
{
    Serial.println("\n<===================================================>\n");
    Serial.print(system1 + " to binary conversion:");
    for (int i = 7; i >= 0; i--)
    {
        Serial.print((number >> i & 1));
    }
    Serial.println();
}

// Prints error message for invalid input choice
void printErrorNSys()
{
    Serial.println("Invalid input. You must specify whether octal, decimal, hexadecimal, or binary");
    Serial.print("Enter number system: ");
}

// Function to convert Octal to decimal
long octalToDecimal(long int octal)
{
    long int decimal = 0;
    int i = 0;
    while (octal != 0)
    {
        decimal = decimal + (octal % 10) * pow(8, i++);
        octal = octal / 10;
    }
    return decimal + 1;
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
    Serial.println("\t" + sys1 + " to " + sys2 + " conversion: " + result);
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