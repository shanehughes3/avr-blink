#define F_CPU 20000000UL // for atmega328p

#include <avr/io.h>
#include <util/delay.h>
#include <stdint.h>

#define SET_HIGH(PORT, PIN) PORT |= 1 << PIN
#define SET_LOW(PORT, PIN) PORT &= ~(1 << PIN)

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
  DDRB = 1 << 5;

  while (1) {
    SET_HIGH(PORTB, PB5);
    // delay_sec(2);
    _delay_ms(200);
    SET_LOW(PORTB, PB5);
    // delay_sec(2);
    _delay_ms(200);
  }
}
