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
            Serial.println(isValidNumber(input));

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
                Serial.println("Invalid input. You must specify whether octal, decimal, hexadecimal, or bonary");
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