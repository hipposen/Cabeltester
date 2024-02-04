#include <Arduino.h>

// put function declarations here:
int myFunction(int, int);

void setup() {

  Serial.begin(57600);
  pinMode(LED_BUILTIN, OUTPUT);
  //int result = myFunction(2, 3);
  
  pinMode(2, INPUT_PULLUP);
  pinMode(3, INPUT_PULLUP);
  pinMode(4, INPUT_PULLUP);
  pinMode(6, INPUT_PULLUP);

  pinMode(12, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(9, OUTPUT);

  digitalWrite(12,LOW);
  digitalWrite(11,LOW);
  digitalWrite(10,LOW);
  digitalWrite(9,LOW);

  digitalWrite(LED_BUILTIN, LOW);
  Serial.println("Ende  setup");     
}

void loop() {
  //Serial.println("Start Loop");
  digitalWrite(LED_BUILTIN, HIGH);  // turn the LED on (HIGH is the voltage level)       
  delay(1000);
// put your main code here, to run repeatedly:
 
  int valVBUS = digitalRead(2);
  int valDataneg = digitalRead(3);
  int valDatapos = digitalRead(4);
  int valGND = digitalRead(6);


  if (valVBUS == LOW ) {
    Serial.println("#####################################");
    Serial.println((String)"VBUS   : verbunden");
  } 
  
  if (valDataneg == LOW) {
    Serial.println((String)"Data - : verbunden");
  } 

 if (valDatapos == LOW) {
    Serial.println((String)"Data+  : verbunden");
  } 

 if (valGND == LOW) {
    Serial.println((String)"  GND  : verbunden");
  } 


  //Serial.println("End Loop");     
  digitalWrite(LED_BUILTIN, LOW);  // turn the LED off (HIGH is the voltage level)
  delay(2000);
}

// put function definitions here:
int myFunction(int x, int y) {
  return x + y;
}