#include <Arduino.h>

int led = 5;

int button1 = A0;
int brightness = 0;  
int led1 = 0 ;
//#define debug

void setup() {
  pinMode(led, OUTPUT);
  pinMode(button1, INPUT);
  analogWrite(led, 0);
  #ifdef debug 
  Serial.begin(9600);
  #endif

}


void loop() {
   
  
  if (led1 == 1 && brightness < 5) {
    for (brightness=0; brightness < 256; brightness++){
    analogWrite(led, brightness);
    // Warte 5 Millisekunden
    delay(5);
    #ifdef debug
    Serial.println(brightness);
    #endif
    }
   }
   

  if (led1 == 0 && brightness > 5) {
    for (brightness=255; brightness > -1; brightness--){
    analogWrite(led, brightness);
    // Warte 5 Millisekunden
    delay(5);
    #ifdef debug
    Serial.println(brightness);
    #endif
    }
   }

  if (digitalRead(button1) == HIGH) {
    if (led1 == 1){
        led1 = 0;
      }
      else{
        led1 = 1;
      }
      
    while (digitalRead(button1) == HIGH)
      {
        /* code */
      }
    delay(100);
     #ifdef debug
     Serial.print(digitalRead(button1)); 
     Serial.print("   "); 
     Serial.println(digitalRead(led1));
     #endif
  }
  delay(100);

}

