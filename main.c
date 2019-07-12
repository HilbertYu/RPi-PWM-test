#include <stdio.h>
#include <wiringPi.h>

const int pin = 18;


int main(int argc, const char * argv[])
{
    /* int ret = wiringPiSetupGpio(); */
    /* printf("ret = %d\n", ret); */
    wiringPiSetup();
    wiringPiSetupGpio();

    printf("ok\n");

    pinMode(18, OUTPUT);

    pinMode(pin, PWM_OUTPUT);
    pwmSetMode(PWM_MODE_MS);
  //  pwmSetMode(PWM_MODE_BAL);
    //19.2 M = 19200 K
    pwmSetClock(1920*2); //10Khz
    pwmSetRange(100); //10Hz


    {
        pwmWrite(pin, 0);
        int i = 0;
        for (i = 0; i < 10; ++i)
        {
            printf("(0) i = %d\n", i);
            delay(1000);
        }

        pwmWrite(pin, 3);
        for (i = 0; i < 10; ++i)
        {
            printf("(3) i = %d\n", i);
            delay(1000);
        }
    }

    double i = 4;
    while (1)
    {
        while (i < 10)
        {
            printf("i1 = %.2lf\n", i);
            pwmWrite(pin, i);
            delay(50);
            i += 0.2;
        }

        while (i > 4)
        {
            printf("i2 = %.2lf\n", i);
            pwmWrite(pin, i);
            delay(50);
            i -= 0.5;
        }
        //delay(10*1000);

    }

    return 0;

    pwmWrite(18, 500);
    delay(1000);
//    pwmWrite(18, 200);

    pinMode(18, OUTPUT);

    return 0;
}
