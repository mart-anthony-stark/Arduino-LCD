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