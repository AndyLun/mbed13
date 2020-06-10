#include "mbed.h"
#include "bbcar.h"

Ticker servo_ticker;
PwmOut pin11(D11), pin10(D10);
BBCar car(pin10, pin11, servo_ticker);

int main()
{
	while (1)
	{
		car.goStraight(100);
		wait(1);
		car.stop();
		wait(1);
	}
}