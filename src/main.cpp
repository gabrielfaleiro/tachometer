#include <Arduino.h>

const int interruptPin = D5;
const int LED=2; //On board blue LED 

// get clock ticks of 32bit register
static inline uint32_t asm_ccount(void) {
  /*
  ccount 32 bit register constantly count clock ticks
  */
  uint32_t r;

  asm volatile ("rsr %0, ccount" : "=r"(r));
  return r;
}

//This program get executed when interrupt is occures i.e.change of input state
IRAM_ATTR void gpio_change_handler() {
  uint32_t ticks = asm_ccount();
  Serial.print("Interrupt Detected. Ticks: ");
  Serial.println(ticks);
}

void setup() {
  Serial.begin(9600);
  pinMode(LED,OUTPUT); 
  pinMode(interruptPin, INPUT_PULLUP); 
  attachInterrupt(digitalPinToInterrupt(interruptPin), gpio_change_handler, CHANGE);
} 

void loop() { 
    digitalWrite(LED,HIGH); //LED off 
    delay(1000); 
    digitalWrite(LED,LOW); //LED on 
    delay(1000); 
} 

