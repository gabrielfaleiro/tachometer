#include "Timing.h"

// ccount 32 bit register constantly count clock ticks
static inline uint32_t AsmCcount(void) {
  uint32_t r;

  asm volatile ("rsr %0, ccount" : "=r"(r));
  return r;
}

//This program get executed when interrupt is occures i.e.change of input state
IRAM_ATTR void gpio_change_handler() {
  uint32_t ticks = AsmCcount();
  Serial.print("Interrupt Detected. Ticks: ");
  Serial.println(ticks);
}

attachInterrupt(digitalPinToInterrupt(interruptPin), gpio_change_handler, RISING);
