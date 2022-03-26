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
                int number = num.toInt();
                String hex = ConvertDecimalToHex(number);
                printConverted(system1, "HEXADECIMAL", String(number, HEX));
            }
            else
            {
                Serial.println("Invalid input. You must specify whether octal, decimal, hexadecimal, or binary");
                Serial.print("Enter number system: ");
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