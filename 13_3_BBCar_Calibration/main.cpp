#include "mbed.h"
#include "bbcar.h"

Ticker servo_ticker;
PwmOut pin10(D10), pin11(D11);

BBCar car(pin10, pin11, servo_ticker);

int main()
{
	// please contruct you own calibration table with each servo
	double pwm_table0[] = {-150, -120, -90, -60, -30, 0, 30, 60, 90, 120, 150};
	double speed_table0[] = {-16.030, -15.711, -14.833, -12.281, -6.699, 0.000, 4.865, 11.005, 14.275, 15.471, 15.950};
	double pwm_table1[] = {-150, -120, -90, -60, -30, 0, 30, 60, 90, 120, 150};
	double speed_table1[] = {-16.269, -15.950, -14.754, -11.564, -5.503, 0.000, 6.380, 12.202, 14.913, 15.950, 16.269};

	// first and fourth argument : length of table
	car.setCalibTable(11, pwm_table0, speed_table0, 11, pwm_table1, speed_table1);

	while (1)
	{
		car.goStraightCalib(5);
		wait(5);
		car.stop();
		wait(5);
	}
}