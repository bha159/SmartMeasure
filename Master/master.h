#define desired 2.25
#define kp 1
#define ki 0.01;
#define kd 0.3;
#define imin 0.01;
#define imax 0.1;

double PID(double error);

void motor(double duty);

void send(char *dat);
