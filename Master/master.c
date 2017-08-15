double PID(double error)
{
        count++;
        iTerm = 0;
        dTerm = 0;
        ierror = ierror + error;
        if(ierror > imax)
        {
                ierror = imax;
        }
        else
        {
                if(ierror < imin)
                {
                        ierror = imin;
                }
        }
        if(count%10 == 0)
        {
                ki += 0.1;
        }
        iTerm = ki * ierror;
        dTerm = kd * (derror - ADC_Read(0));
        derror = dTerm;
        return iTerm + (kd * dTerm) + (kp * error);
}

void motor(double duty)
{
        TRISC=0;
        PWM1_Start();
        PWM1_Set_Duty(Duty);
        delay_ms(1000);
        PWM1_Stop();
        if(duty == 0)
        {
                PORTC=0;
                delay_ms(1000);
        }
}

void send(char *dat)
{
   RS485Master_Init();
   for (i=0;i<=strlen(dat);i++)
   {
     std[0]=dat[i];
     std[4]=0;
     RS485Master_Send(std,1,160);
     Delay_ms(1);
   }
}
