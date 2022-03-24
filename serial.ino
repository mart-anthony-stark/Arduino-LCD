// C++ code
//
void setup()
{
  Serial.begin(9600);
}
const unsigned int MAX_MESSAGE_LENGTH = 20;
void loop() {
  // Check if available serial receive buffer
  while(Serial.available() > 0){
    static char message[MAX_MESSAGE_LENGTH];
    static unsigned int message_pos = 0;
    
    //Read next byte
    char inByte = Serial.read();
  }
}