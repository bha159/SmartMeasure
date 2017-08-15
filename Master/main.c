#include<master.h>
int count = 0;
double ierror;
double derror;
double iTerm;
double dTerm;
char dat[]="";
char std[10];

sbit  rs485_rxtx_pin  at RC2_bit;
sbit  rs485_rxtx_pin_direction at TRISC2_bit;

void interrupt()
{
  RS485Master_Receive(dat);
}

void main()
{
  int i = 0;
  long cnt = 0;

  RCIE_bit = 1;
  TXIE_bit = 0;
  PEIE_bit = 1;
  GIE_bit = 1;
  ADCON0 = 0xC1;        //Setting up the ADC of PIC MCU
  ADCON1 = 0x04;
  PORTA = 0xFF;
  TRISA = 0x03;
  PWM1_Init(2000);        //Initializing the PWM1 module at 1kHz
  PWM2_Init(2000);

  PORTB  = 0;
  PORTD  = 0;
  TRISB  = 0;
  TRISD  = 0;
  double error;
  double input;
  double output;
  double duty;
        
  ADC_Init();
  while(1)
  {
   output = ADC_Read(1);
   error = output - desired;
   duty = PID(abs(error));
   motor(duty);
   UART1_Init(9600);
   Delay_ms(200);

   dat=output;
   send(dat);
  }
}
