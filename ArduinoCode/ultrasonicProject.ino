int Pin_echo   = 13; 
int Pin_trig   = 12; 
int Pin_red    = 11;
int Pin_yellow = 10;
int Pin_green  = 9;
 
void setup() { 
  Serial.begin (9600); 
  pinMode(Pin_trig, OUTPUT); 
  pinMode(Pin_echo, INPUT); 
  pinMode(Pin_red, OUTPUT); 
  pinMode(Pin_yellow, OUTPUT); 
  pinMode(Pin_green, OUTPUT); 
}
 
void loop() { 
  int pulso, cm; 
  digitalWrite(Pin_trig, LOW); 
  delayMicroseconds(2); 
  digitalWrite(Pin_trig, HIGH); 
  delayMicroseconds(10); 
  digitalWrite(Pin_trig, LOW); 
  pulso = pulseIn(Pin_echo, HIGH); //Medición del pulso por el pin Echo
  cm = pulso / 29 / 2;  // Conversion a cm
 
  Serial.print("Distancia:"); 
  Serial.print(cm); 
  Serial.println(" cm"); 
  
  digitalWrite(Pin_green, LOW); 
  digitalWrite(Pin_red, LOW); 
  digitalWrite(Pin_yellow, LOW); 
  
  if(cm>5){
    digitalWrite(Pin_green, HIGH); 
  }
  if(cm>15){
    digitalWrite(Pin_yellow, HIGH); 
  }
  if(cm>30){
    digitalWrite(Pin_red, HIGH); 
  }
  
  delay(200); 
}
