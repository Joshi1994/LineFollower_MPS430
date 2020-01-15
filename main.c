//--------------final_motor----------------------------------

#include <msp430.h>
#include <stdint.h>
#include "port.h"
#include "timer.h"


int main(void) {

    WDTCTL = WDTPW | WDTHOLD;   // Stop watchdog timer

    P2DIR |= (BIT2);   // motor port   pin as output
    P2SEL |= (BIT2);  // Motor port  pin as timer





    P2SEL &=~ BIT4;         // CONFIGURED AS GPIO
    P2DIR |= BIT4;              // CONFIGURED AS OUTPUT
    P2SEL &=~ BIT5;         // CONFIGURED AS GPIO
    P2DIR |= BIT5;              // CONFIGURED AS OUTPUT


    P1SEL &=~ BIT6;         // CONFIGURED AS GPIO
    P1DIR |= BIT6;              // CONFIGURED AS OUTPUT

    P2OUT |= BIT5;

   timer_motorA();
    //timer_motorB();


// TIMER FOR MOTOR B


// TIMER FOR MOTOR A





    __enable_interrupt();


    while(1)
    {
        without_timer();
    }


}


#pragma vector=TIMER0_A1_VECTOR
__interrupt void TIMER()
{
         P2OUT ^= BIT4;      //left motor B
         TACTL&=~(TAIFG);
}
