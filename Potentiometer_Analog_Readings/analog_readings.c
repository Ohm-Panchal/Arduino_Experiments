// C++ code
//
int x = 0;
void setup()
{
  pinMode(8, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  
  Serial.begin(9600);
}

void loop()
{
  digitalWrite(LED_BUILTIN, HIGH);
  delay(1000); // Wait for 1000 millisecond(s)
  digitalWrite(LED_BUILTIN, LOW);
  delay(1000); // Wait for 1000 millisecond(s)
  x = analogRead(A0);
  float voltage = (x/1023.00)*5;
  Serial.println(voltage);
  
  if(voltage>=0.10 && voltage<=2.00){
  	digitalWrite(8, HIGH);
  }
  else{
  	digitalWrite(8, LOW);
    digitalWrite(10, LOW);
    digitalWrite(11, LOW);
  }
  
  if(voltage>=2.01 && voltage<=3.50){
  	digitalWrite(8, HIGH);
    digitalWrite(10, HIGH);
  }
  else{
    digitalWrite(10, LOW);
  }
  
  if(voltage>=3.51 && voltage<=5.00){
  	digitalWrite(8, HIGH);
    digitalWrite(10, HIGH);
    digitalWrite(11, HIGH);
  }
  else{
    digitalWrite(11, LOW);
  }
}