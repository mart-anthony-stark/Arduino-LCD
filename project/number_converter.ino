int step = 0;
int num = 0;
int temp = 0;
void setup()
{
    Serial.begin(9600);
    Serial.print("Enter number to be converted: ");
}

void loop()
{

    while (Serial.available())
    {
        String a = Serial.readString(); // read the incoming data as string

        // Handles input for number to be converted
        if (step == 0)
        {
            Serial.print(a + "\n");
            num = a.toInt();
            Serial.print("Enter number system: ");
            step++;
        }
        // Handles input for number system
        else if (step == 1)
        {
            Serial.print(a + "\n");
            step++;
        }
    }
}