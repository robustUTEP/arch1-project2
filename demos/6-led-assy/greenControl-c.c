#include <msp430.h>
#include "led.h"

void greenOn(int on)
{
  if (on) {
    P1OUT |= LED_GREEN;
  } else {
    P1OUT &= ~LED_GREEN;
  }
}
