int ledPin = 2; //LED terhubung dg pin D2
void setup()
{
  pinMode(ledPin, OUTPUT); //pin D2 sebagai output
}
void loop()
{
  digitalWrite(ledPin, HIGH); //pin D2=HIGH (LED ON)
  delay(500);  //delay 500 ms
  digitalWrite(ledPin, LOW); //pin D2=LOW (LED OFF)
  delay(500);  //delay 500 ms
}
