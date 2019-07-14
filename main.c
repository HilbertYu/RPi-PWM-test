#include <stdio.h>
#include <stdlib.h>
#include <wiringPi.h>

const int pin = 18;

void init(void)
{
    if (wiringPiSetup() < 0)
    {
        fprintf(stderr, "init fail\n");
        exit(1);
    }

    if (wiringPiSetupGpio() < 0)
    {
        fprintf(stderr, "init fail\n");
        exit(1);
    }

}


int main(int argc, const char * argv[])
{

    init();
    printf("init - done\n");

    //pinMode(pin, INPUT);
    pinMode(pin, OUTPUT);
    digitalWrite(pin, 0);

    if (argc > 1)
    {
        pinMode(pin, PWM_OUTPUT);
        pwmWrite(pin, 0);
        delay(1000);
        printf("finish!\n");
        return 0;

    }

    pinMode(pin, PWM_OUTPUT);


    pwmSetMode(PWM_MODE_MS);
  //  pwmSetMode(PWM_MODE_BAL);
    //19.2 M = 19200 K


    const int mul = 20*3*8;

    const int dc = 1920*2/mul;
    const int rng = 100*mul;

    pwmSetClock(dc);
    pwmSetRange(rng);

    const double C = 19.20*1000*1000;
    printf("pwm c = %.2lf Hz\n", (double)C/(dc*rng));

    if (1920*2 % mul != 0)
    {
        printf("!!\n");
    }

    {
        const int wt = 5;

        pwmWrite(pin, 0);
        int i = 0;
        for (i = 0; i < wt; ++i)
        {
            printf("(0) i = %d\n", i);
            delay(1000);
        }

        {
            printf("to mid\n");
            getchar();
            pwmWrite(pin, 5.5*mul);
            int i = 0;
            for (i = 0; i < wt; ++i)
            {
                printf("(mid) i = %d\n", i);
                delay(1000);
            }

            printf("to zero\n");
            getchar();
            pwmWrite(pin, 3.5*mul);
            for (i = 0; i < wt+ 5; ++i)
            {
                printf("(0) i = %d\n", i);
                delay(1000);
            }
            return 0;
        }
        {
#if 0
            double r = 0;
            for (; r < 45; r += 1)
            {
            //    printf("(3) i = %d\n", i);
                //pwmWrite(pin, 3*mul);
             //   r += 0.05;
                printf("r(%.2lf, %.2lf)\n", r*mul, r);
                pwmWrite(pin, (r)*mul);

                delay(100);
            }

            for (; r > 1; r -= 1)
            {
             //   printf("(3) i = %d\n", i);
                //pwmWrite(pin, 3*mul);
             //   r += 0.05;
                printf("r(%.2lf, %.2lf)\n", r*mul, r);
                pwmWrite(pin, (r)*mul);

                delay(100);
            }
#endif
        pwmWrite(pin, 3*mul);

#if 1
            for (i = 0; i < wt+10; ++i)
            {
                printf("(3) i = %d\n", i);
                //pwmWrite(pin, 3*mul);
                /* r += 0.05; */
                /* printf("r(%.2lf, %.2lf)\n", r*mul, r); */
                pwmWrite(pin, 3*mul);

                delay(1000);
            }
#endif
        }

        pwmWrite(pin, 0);
        i = 0;
        for (i = 0; i < wt + 2; ++i)
        {
            printf("(0) i = %d\n", i);
            delay(1000);
        }

    }

//    return 0;

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
