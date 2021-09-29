//Alternate LEDs from Off, Green, and Red
#include <msp430.h>
#include "libTimer.h"
#include "led.h"

int main(void) {
  P1DIR |= LEDS;
  P1OUT &= ~LED_GREEN;
  P1OUT |= LED_RED;

  configureClocks();		/* setup master oscillator, CPU & peripheral clocks */
  enableWDTInterrupts();	/* enable periodic interrupt */
  
  or_sr(0x18);		/* CPU off, GIE on */
}






int blinkLimit = 5;   //  state var representing reciprocal of duty cycle 
int blinkCount = 0; // state var representing blink state
int secondCount = 0; // state variable representing repeating time 0…1s

void
__interrupt_vec(WDT_VECTOR) WDT()	/* 250 interrupts/sec */
{
  // handle blinking   
  blinkCount ++;
  if (blinkCount >= blinkLimit) {
    blinkCount = 0;
    P1OUT |= LED_GREEN;
  } else
    P1OUT &= ~LED_GREEN;
  // measure a second
  secondCount ++;
  if (secondCount >= 250) { // once each second
    secondCount = 0;
    blinkLimit ++;  // reduce duty cycle
    if (blinkLimit >= 8)  // but don't let duty cycle go below 1/7.
      blinkLimit = 0;
  }
} 

