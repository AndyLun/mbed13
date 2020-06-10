#include "mbed.h"
#include "bbcar.h"

Ticker servo_ticker;
Ticker encoder_ticker;
PwmOut pin10(D10), pin11(D11);
DigitalIn pin3(D3);

BBCar car(pin10, pin11, servo_ticker);

int main()
{
	parallax_encoder encoder0(pin3, encoder_ticker);
	encoder0.reset();

	car.goStraight(100);
	while (encoder0.get_cm() < 30)
		wait_ms(50);
	car.stop();
}