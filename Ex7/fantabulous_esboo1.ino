void setup()
{
	pinMode(6, OUTPUT); 
	pinMode(5, INPUT); 
 	pinMode(12, OUTPUT); 
	pinMode(13, INPUT); 
	pinMode(7, OUTPUT);
  	pinMode(8, OUTPUT);
  pinMode(3, OUTPUT);
 Serial.begin(9600);
  
  
}

void loop()
{
 	
  float time =0;
  float dist = 0;
  int trigger = 6;
  int echo = 5;
  int som = 3;
  int LedAma = 7;
  int LedRed= 8;
  int trig2 = 12;
  int echo2 = 13;
  float dist2 = 0;
  float time2 = 0;
  int i=0;

  	digitalWrite(LedAma, LOW);
  	digitalWrite(LedRed, LOW);
  
    digitalWrite(trigger, LOW); 
	delayMicroseconds(2);
	digitalWrite(trigger, HIGH);
	delayMicroseconds(10);
  
    time = pulseIn(echo, HIGH);
  dist = time/1000000*170;
  
  	digitalWrite(trig2, LOW); 
	delayMicroseconds(2);
	digitalWrite(trig2, HIGH);
	delayMicroseconds(10);
  
   time2 = pulseIn(echo2, HIGH);
  dist2 = time2/1000000*170;
  

  
 
  Serial.println(dist*100);
  Serial.println(dist2*100);
  
  dist = dist*100;
  dist2 = dist2*100;
  
  if(dist <= 100 && dist > 0){
  analogWrite(som, 255);
    while (i < 10){
  digitalWrite(LedRed, HIGH);
      delay(300);
   digitalWrite(LedRed, LOW);
   digitalWrite(LedAma, HIGH);
      delay(300);
   digitalWrite(LedAma, LOW);
   digitalWrite(LedRed, HIGH);
      i++;

    }
  }else if (dist2 <= 100 && dist2 > 0){
  
  analogWrite(som, 255);
    while (i < 10){
  digitalWrite(LedRed, HIGH);
      delay(300);
   digitalWrite(LedRed, LOW);
   digitalWrite(LedAma, HIGH);
      delay(300);
   digitalWrite(LedAma, LOW);
   digitalWrite(LedRed, HIGH);
      i++;

    }
  
  }else{
    analogWrite(som,0);
	digitalWrite(LedRed,LOW);
    digitalWrite(LedAma,LOW);
  }
      analogWrite(som,0);
	digitalWrite(LedRed,LOW);
    digitalWrite(LedAma,LOW);
  delay(60);

	
 
}
