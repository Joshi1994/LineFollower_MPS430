#include <msp430.h>




void port_init()
{
          P2SEL &=~ BIT1;
          P2SEL &=~BIT2;            // Motor A PWM
          P2SEL&=~BIT4;             //Motor B PWM
          P2SEL &=~BIT5;
          P1SEL|= (BIT6|BIT0);



          P1DIR|=BIT6; //Set P1.6 as output pin
          P1DIR|=BIT0;

          P2DIR|=BIT1; //motor A
          P2DIR|=BIT2;

          P2DIR|=BIT4; //Motor B
          P2DIR|=BIT5;
}
void motorA_Dir()
{

              P2DIR|=BIT1; //motor A
              P2DIR|=BIT2;

}

void motorB_Dir()
{
                P2DIR|=BIT4; //Motor B
                P2DIR|=BIT5;

}

void right_motor()
{

    P2OUT^=BIT2; // Motor A
}

void left_motor()
{
    P2OUT^=BIT4;  //Motor B

}
