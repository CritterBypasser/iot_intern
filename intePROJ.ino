void setup() {
  // put your setup code here, to run once:
pinMode(13,INPUT); //switch
pinMode(11,INPUT); // switch
pinMode(1,OUTPUT);//MOTOR
pinMode(0,OUTPUT);//LED
pinMode(2,OUTPUT);//led
pinMode(3,OUTPUT);//led
pinMode(4,OUTPUT);//led
pinMode(5,OUTPUT);//motor
}

void loop() {
  // put your main code here, to run repeatedly:
if(digitalRead(13)==HIGH and digitalRead(11)==HIGH)
  {
    digitalWrite(1,LOW);
    digitalWrite(5,LOW);
    digitalWrite(0,HIGH);
    delay(100);
    digitalWrite(0,LOW);
    delay(100);
    digitalWrite(2,HIGH);
    delay(100);
    digitalWrite(2,LOW);
    delay(100);
    digitalWrite(3,HIGH);
    delay(100);
    digitalWrite(3,LOW);
    delay(100);
    digitalWrite(4,HIGH);
    delay(100);
    digitalWrite(4,LOW);
    delay(100);
//    digitalWrite(5,HIGH);
//    delay(100);
//    digitalWrite(5,LOW);
//    delay(100);
  }
if(digitalRead(13)== LOW and digitalRead(11)==LOW)
  {
    digitalWrite(1,LOW);
    digitalWrite(5,LOW);
    digitalWrite(0,HIGH);
    //delay(100);
    digitalWrite(2,HIGH);
    //delay(100);
    digitalWrite(3,HIGH);
    //delay(100);
    digitalWrite(4,HIGH);
    delay(1000);
    digitalWrite(0,LOW);
    //delay(100);
    digitalWrite(2,LOW);
    //delay(100);
    digitalWrite(3,LOW);
    //delay(100);
    digitalWrite(4,LOW);
    delay(1000);
    
  }
if(digitalRead(13)==HIGH, digitalRead(11)==LOW)
  {
    digitalWrite(1,HIGH);
    digitalWrite(5,HIGH);
  }
if(digitalRead(11)==HIGH and digitalRead(13)==LOW)
  {
    digitalWrite(1,HIGH);
    digitalWrite(0,HIGH);
//    digitalWrite(5,LOW);
//    digitalWrite(2,LOW);
//    digitalWrite(3,LOW);
//    digitalWrite(4,LOW);
    
  } 
}
