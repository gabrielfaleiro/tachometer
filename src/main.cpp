#include <Arduino.h>
#include "Wifi.h"

// const int interruptPin = D5;
const int LED=2; //On board blue LED 


void setup() {
  Serial.begin(9600);
  pinMode(LED,OUTPUT); 
  // pinMode(interruptPin, INPUT_PULLUP); 
  Wifi soft_ap_wifi("testing_wifi_esp8266", "patata", 1, 1, [192,168,1,1], [192,168,1,1], [255,255,255,0]);
  soft_ap_wifi.StationNumGet();
} 

void loop() { 
    digitalWrite(LED,HIGH); //LED off 
    delay(1000); 
    digitalWrite(LED,LOW); //LED on 
    delay(1000); 
} 

