// C++ code
//
void setup()
{
  Serial.begin(9600);
}
const unsigned int MAX_MESSAGE_LENGTH = 20;
void loop() {
  static char message[MAX_MESSAGE_LENGTH];
  static unsigned int message_pos = 0;
  
}