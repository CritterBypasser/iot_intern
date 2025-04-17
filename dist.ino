void setup() {
pinMode(1,OUTPUT);//led
pinMode(5,OUTPUT);//led
pinMode(6,OUTPUT);//led
pinMode(4,OUTPUT);//buzzer
pinMode(2,INPUT);//echo
pinMode(3,OUTPUT);//trigger
Serial.begin(9600);
}

void loop() {
  digitalWrite(3, LOW);
  delay(4);
  digitalWrite(3, HIGH);
  delay(10);
  digitalWrite(3, LOW);
//  tone(4, 1000); 
//  delay(100);   
//  noTone(4);     
//  delay(100);
  long t = pulseIn(2, HIGH);//input pulse and save it
  //long inches = t /37; //time convert distance
  long cm = t *0.017; //time convert distance
  String inch = " inches t";
  String CM = " cm";
  //Serial.print(inches +inch);//print serial monitor inches
  Serial.println(cm +CM);//print serial monitor cm
  Serial.println();//print space
  delay(100);//delay
if(cm<=10)
  {
    digitalWrite(1, HIGH);
    digitalWrite(4, HIGH);
  }
else if(cm<=50)
  {
    digitalWrite(5, HIGH);
    digitalWrite(4, LOW);
    digitalWrite(1, LOW);
    digitalWrite(6, LOW);
  }
else if(cm<=100)
  {
    digitalWrite(6, HIGH);
    digitalWrite(5, LOW);
    digitalWrite(1, LOW);
  }
}
