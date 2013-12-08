#pragma config(Hubs,  S1, HTMotor,  HTMotor,  none,     none)
#pragma config(Sensor, S1,     ,               sensorI2CMuxController)
#pragma config(Motor,  mtr_S1_C1_1,     mLeft1,        tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C1_2,     mLeft2,        tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C2_1,     mRight1,       tmotorTetrix, openLoop, reversed)
#pragma config(Motor,  mtr_S1_C2_2,     mRight2,       tmotorTetrix, openLoop, reversed)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

#include "yoloswag.h"
#include "JoystickDriver.c"

int thresh(int x)
{
	return abs(x) < 10 ? 0 : x;
}

task main()
{
	waitForStart();

	while (true) {
		getJoystickSettings(joystick);

		left(thresh(joystick.joy1_y1 * 100 / 128));
		right(thresh(joystick.joy1_y2 * 100 / 128));

		if (bDisconnected) {
			left(right(0));
		}

		wait10Msec(1);
	}
}
