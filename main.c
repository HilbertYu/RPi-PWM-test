#include <stdio.h>
#include <wiringPi.h>



int main(int argc, const char * argv[])
{
    wiringPiSetupGpio();
//    wiringPiSetup();
    pinMode(18, OUTPUT);
    digitalWrite(18, 0);
   // delay(3000);

    pinMode(18, PWM_OUTPUT);
    pwmSetMode(PWM_MODE_MS);
  //  pwmSetMode(PWM_MODE_BAL);
    pwmSetClock(1920); //10Khz
    pwmSetRange(100); //10Hz

    while (1)
    {

        pwmWrite(18, 1);
        delay(1);

    }


    pwmWrite(18, 500);
    delay(1000);
//    pwmWrite(18, 200);

    pinMode(18, OUTPUT);

    return 0;
}
