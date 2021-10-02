


void setup() {
  pinMode(2, OUTPUT);  
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(13, INPUT);
}

void loop() {
  
   int botao = 0;
 int pedRed = 8;
 int pedGreen = 9;
 int carRed = 2;
 int carYellow = 3;
 int carGreen = 4;
 int pot = analogRead(1);
int i = 0;

  botao = digitalRead(13);
  
digitalWrite(pedRed, HIGH);
digitalWrite(carGreen, HIGH);

  if (botao == HIGH) {
    digitalWrite(carGreen, LOW);
    digitalWrite(carYellow, HIGH);
   
    delay(2000);
    
    digitalWrite(carYellow, LOW);
    digitalWrite(carRed, HIGH);
    digitalWrite(pedGreen, HIGH);
    digitalWrite(pedRed, LOW);
    
    delay(5000);
    digitalWrite(pedGreen, LOW);
    while( i != 3 ){
    digitalWrite(pedRed, HIGH);
    delay(pot);
    digitalWrite(pedRed, LOW);
    delay(pot);
    i++;
    }
	digitalWrite(pedRed, HIGH);
    digitalWrite(carGreen, HIGH);
    digitalWrite(carRed, LOW);


    
  } else {

  
  	}
  
  
}
