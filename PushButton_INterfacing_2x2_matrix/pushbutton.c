#define row1 9
#define row2 8
#define col1 10
#define col2 11

void setup() {
  // put your setup code here, to run once:
  pinMode(row1, OUTPUT);
  pinMode(row2, OUTPUT);
  pinMode(col1, INPUT_PULLUP);
  pinMode(col2, INPUT_PULLUP);

  digitalWrite(row1, HIGH);
  digitalWrite(row2, HIGH);
  Serial.begin(9600);
}
int key_press(){
  digitalWrite(row1, LOW);
  if(digitalRead(col1) == LOW){
    delay(50); //debouncing
    if(digitalRead(col1) == LOW){
      digitalWrite(row1, HIGH);
      return 5;
    }
  }
  if(digitalRead(col2) == LOW){
    delay(50); //debouncing
    if(digitalRead(col2) == LOW){
      digitalWrite(row1, HIGH);
      return 4;
    }
  }
  digitalWrite(row1, HIGH);
  digitalWrite(row2, LOW);
  if(digitalRead(col1) == LOW){
    delay(50); //debouncing
    if(digitalRead(col1) == LOW){
      digitalWrite(row2, HIGH);
      return 3;
    }
  }
  if(digitalRead(col2) == LOW){
    delay(50); //debouncing
    if(digitalRead(col2) == LOW){
      digitalWrite(row2, HIGH);
      return 2;
    }
  }
  digitalWrite(row2, HIGH);
  return 0;
}
void loop() {
  // put your main code here, to run repeatedly:
  int key = key_press();
  if(key != 0){
    digitalWrite(key, HIGH);
  }
  else{
    digitalWrite(5, LOW);
    digitalWrite(4, LOW);
    digitalWrite(3, LOW);
    digitalWrite(2, LOW);
  }
  Serial.println(key);
}
