#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

int redled = 7;
int greenled = 6;
float time =0;
float dist = 0;
int trigger = 10;
int echo = 13;
float temp1 = 0;
float temp2 = 0;
float temp3 = 0;
float tempmed = 0;
int avisoled = 8;
int som = 9;

void setup() {
  lcd.begin(16, 2);
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  pinMode(A2, INPUT);
  pinMode(redled, OUTPUT);
  pinMode(greenled, OUTPUT);
  pinMode(trigger, OUTPUT);
  pinMode(echo, INPUT);
  pinMode(avisoled, OUTPUT);
  digitalWrite(redled, LOW);
  digitalWrite(greenled, LOW);
  digitalWrite(avisoled, LOW);
  digitalWrite(greenled, HIGH);
  lcd.print("Proximo");
}

void loop() {  
   lcd.setCursor(0, 1);
  //Ativa o sonar
  digitalWrite(trigger, LOW); 
  delayMicroseconds(2);
  digitalWrite(trigger, HIGH);
  delayMicroseconds(10);
  //calcula a distancia de acordo com o tempo
  time = pulseIn(echo, HIGH);
  dist = time/1000000*170;
  dist = dist*100;

  if(dist <= 100 && dist > 0){
    lcd.clear();
    digitalWrite(greenled, LOW);
    digitalWrite(redled, HIGH);
   
    lcd.print("Aguarde a");
    lcd.setCursor(1,1);
    lcd.print("medicao");
    lcd.setCursor(0, 1);
    //Faz as medições de temperatura com os 3 sensores
  	temp1 = (analogRead(A0) - 102) * 0.488;
    delay(800);
    temp2 = (analogRead(A1) - 102) * 0.488;
	delay(800);
    temp3 = (analogRead(A2) - 102) * 0.488;
	delay(800);
    tempmed = (temp1 + temp2 + temp3)/3;
    lcd.clear();
    //lcd.print(temp1);
    //lcd.print(temp3);
    //lcd.print(temp2);
    if(tempmed > 38){
    digitalWrite(avisoled, HIGH);
    analogWrite(som, 150);
    }
    lcd.print("Temperatura de");
    lcd.setCursor(1,1);
    lcd.print(tempmed);
    lcd.print("C");
    delay(6000);
    lcd.clear();
			
  
  } else {
    lcd.setCursor(0, 1);
    digitalWrite(redled, LOW);
    digitalWrite(greenled, HIGH);
    lcd.print("Proximo");
  
  }
  
  digitalWrite(avisoled, LOW);
  lcd.setCursor(0, 1);
  lcd.clear();
  lcd.print("Proximo");

}
 