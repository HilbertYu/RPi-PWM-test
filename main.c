#include <stdio.h>
#include <wiringPi.h>

const int pin = 18;


int main(int argc, const char * argv[])
{
    /* int ret = wiringPiSetupGpio(); */
    /* printf("ret = %d\n", ret); */
    wiringPiSetupGpio();

    printf("ok\n");

    pinMode(18, OUTPUT);
/*     pinMode(18, OUTPUT); */
/*  //   pinMode(18, INPUT); */
/*     digitalWrite(18, 1); */
/*     delay(1000); */
/*     return 0; */
    /* digitalWrite(18, 0); */
    /* delay(3000); */
    /* return 0; */

    pinMode(pin, PWM_OUTPUT);
    pwmSetMode(PWM_MODE_MS);
  //  pwmSetMode(PWM_MODE_BAL);
    //19.2 M = 19200 K
    pwmSetClock(1920*2); //10Khz
    pwmSetRange(100); //10Hz

    while (1)
    {

        pwmWrite(pin, 10);
        //delay(10*1000);

    }

    return 0;

    pwmWrite(18, 500);
    delay(1000);
//    pwmWrite(18, 200);

    pinMode(18, OUTPUT);

    return 0;
}
