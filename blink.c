#define F_CPU 1000000UL // for attiny2313 - 8MHz internal with prescaler of 8

#include <avr/io.h>
#include <util/delay.h>
#include <stdint.h>

#define SET_HIGH(PORT, PIN) PORT |= 1 << PIN
#define SET_LOW(PORT, PIN) PORT &= ~(1 << PIN)

#define LED_PORT PORTD
#define LED_PIN PD6

void delay_sec(uint8_t seconds) {
  while (seconds > 0) {
    for (uint8_t i = 0; i < 5; ++i) {
      _delay_ms(200);
    }
    --seconds;
  }
}


int main(void)
{
  // PB5 should be output, all else input
  // this is for atmega328p to run onboard arduino led -
  // attiny85 could be PB3
  DDRD = 1 << 5;

  while (1) {
    SET_HIGH(LED_PORT, LED_PIN);
    delay_sec(1);
    /* _delay_ms(200); */
    SET_LOW(LED_PORT, LED_PIN);
    delay_sec(1);
    /* _delay_ms(200); */
  }
}
