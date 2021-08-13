#include <Arduino.h>
#include "Wifi.h"

// const int interruptPin = D5;
const int LED=2; //On board blue LED 

Wifi test_wifi = Wifi();

void setup() {
  Serial.begin(9600);
  pinMode(LED,OUTPUT); 
  // pinMode(interruptPin, INPUT_PULLUP);

  // char ssid[32] = "testing_wifesp8266";
  // char pass[64] = "patata";
  // uint8_t channel = 1;
  // uint8_t max_connection = 1;
  // uint8_t local_ip[4] = {192,168,1,1};
  // uint8_t gateway[4] = {192,168,1,1};
  // uint8_t subnet[4] = {255,255,255,0};

  // Wifi soft_ap_wifi(ssid, pass, channel, max_connection, local_ip, gateway, subnet);
  // Wifi soft_ap_wifi();
  // soft_ap_wifi.StationNumGet();

} 

void loop() { 
  
  digitalWrite(LED,HIGH); //LED off 
  delay(1000); 
  digitalWrite(LED,LOW); //LED on 
  delay(1000); 
  Serial.print("local_ip: ");
  Serial.print(test_wifi.NetworkGet().local_ip[0]);
  Serial.print(".");
  Serial.print(test_wifi.NetworkGet().local_ip[1]);
  Serial.print(".");
  Serial.print(test_wifi.NetworkGet().local_ip[2]);
  Serial.print(".");
  Serial.print(test_wifi.NetworkGet().local_ip[3]);

  Serial.println("");

} 

