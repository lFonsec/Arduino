void setup()
{
  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(4, OUTPUT);
}

void loop()
{
	int i,j;
  	j=1; 
  	i=13;
  
  while(j<10){
    for(i; i>=4; i--){
    digitalWrite(i, HIGH);
      delay(50);
    digitalWrite(i, LOW);
    }
    
    for(i; i<=13-j; i++){
    digitalWrite(i, HIGH);
      delay(50);
    digitalWrite(i, LOW);
    }
  
  j++;
}

}
//Lucas da Fonseca Costa RA:221150154