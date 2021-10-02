void setup() {

   pinMode(A0, INPUT);
   pinMode(9, OUTPUT);
  
}

void loop() {
  
  
   int poten = 0;
  poten = analogRead(A0);
  analogWrite(9, poten/4);
}
 