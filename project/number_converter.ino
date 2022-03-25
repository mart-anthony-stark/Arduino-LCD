void setup()
{

    Serial.begin(9600);
}

void loop()
{

    while (Serial.available())
    {

        String a = Serial.readString(); // read the incoming data as string

        Serial.println(a);
    }
}