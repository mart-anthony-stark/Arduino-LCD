// C++ code
//
void setup()
{
  Serial.begin(9600);
}

void loop() {
  String readSerial;
  char input = Serial.read();
  if(Serial.available() > 0){
    readSerial = Serial.readString();
    Serial.println(readSerial);
  }
  
}