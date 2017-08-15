sbit  rs485_rxtx_pin at RC2_bit;
sbit  rs485_rxtx_pin_direction at TRISC2_bit;

char txt1[]="";
char txt[]="";
char dat[10];

void interrupt()
{
 RS485Slave_Receive(dat);
}

void main()
{
  ADCON0 = 0x00;
  ADCON1 = 0x00;

  PORTB = 0;
  PORTD = 0;
  PORTA = 0;
  TRISB = 0;
  TRISD = 0;
  TRISA = 0;

  UART1_Init(9600);
  Delay_ms(100);
  RS485Slave_Init(160);

  RCIE_bit = 1;
  TXIE_bit = 0;
  PEIE_bit = 1;
  GIE_bit = 1;

  while(1)
  {
   if(dat[4])
   {
    strncat(txt,dat,1);
    dat[4]=0;
   }
  }

  sim808_snd(txt);
}
