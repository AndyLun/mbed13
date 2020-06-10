#include "mbed.h"
#include "bbcar.h"

DigitalOut led1(LED1);
PwmOut pin10(D10), pin11(D11);
DigitalInOut pin9(D9);
Ticker servo_ticker;

BBCar car(pin10, pin11, servo_ticker);

int main()
{
	parallax_ping ping1(pin9);

	car.goStraight(100);
	while (1)
	{
		if ((float)ping1 > 10)
			led1 = 1;
		else
		{
			led1 = 0;
			car.stop();
			break;
		}
		wait(.01);
	}
}