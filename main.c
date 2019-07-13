#include <stdio.h>
#include <wiringPi.h>

const int pin = 18;


int main(int argc, const char * argv[])
{
    /* int ret = wiringPiSetupGpio(); */
    /* printf("ret = %d\n", ret); */
    wiringPiSetup();
    wiringPiSetupGpio();

    printf("init\n");

    pinMode(pin, OUTPUT);

    pinMode(pin, PWM_OUTPUT);
    pwmSetMode(PWM_MODE_MS);
  //  pwmSetMode(PWM_MODE_BAL);
    //19.2 M = 19200 K


    const int mul = 20*3*8;

    const int dc = 1920*2/mul;
    const int rng = 100*mul;

    pwmSetClock(dc);
    pwmSetRange(rng);


    const double C = 1920*1000;
    printf("pwm c = %.2lf Hz\n", (double)C/(dc*rng));

    if (1920*2 % mul != 0)
    {
        printf("!!\n");

    }



    {
        const int wt = 1;

        pwmWrite(pin, 0);
        int i = 0;
        for (i = 0; i < wt; ++i)
        {
            printf("(0) i = %d\n", i);
            delay(1000);
        }

        pwmWrite(pin, 3*mul);
        for (i = 0; i < wt; ++i)
        {
            printf("(3) i = %d\n", i);
            delay(1000);
        }
    }

    while (1)
    {
        double i = 4 * mul;

        while (i < 10 * mul)
        {
            printf("i1 = %.2lf, %.2lf\n", i, i/mul);
            pwmWrite(pin, i);
            delay(50);
            i += (0.02 * mul);
        }

        while (i > 4 * mul)
        {
            printf("i2 = %.2lf, %.2lf\n", i, i/mul);
            pwmWrite(pin, i);
            delay(50);
            i -= (0.05 * mul);
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
