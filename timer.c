#include <msp430.h>

    int i;
void timer_motorB()
{

        TACTL = 0| (TASSEL_2 | ID_1);
        TACTL |= MC_1;
        TACTL |= TAIE;
        TACCR0 = 10;

}


void timer_motorA()
{

    TA1CCR0 |= 1000 - 1;
    TA1CCTL1 |= OUTMOD_7;
    TA1CCR1 = 100;
    TA1CTL |= TASSEL_2 + MC_1;
}

void without_timer()
{

    P2OUT |= BIT4;
    P1OUT |= BIT6;
    __delay_cycles(4);
    P2OUT &=~ BIT4;
    P1OUT &=~ BIT6;
    __delay_cycles(100);
}
