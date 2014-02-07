 #pragma config(Hubs,  S1, HTMotor,  HTMotor,  HTMotor,  HTServo)
#pragma config(Sensor, S1,     ,               sensorI2CMuxController)
#pragma config(Sensor, S2,     Ultra,          sensorSONAR)
#pragma config(Sensor, S3,     Ultra2,         sensorSONAR)
#pragma config(Sensor, S4,     IR,             sensorHiTechnicIRSeeker600)
#pragma config(Motor,  motorA,           ,             tmotorNXT, openLoop)
#pragma config(Motor,  motorB,           ,             tmotorNXT, openLoop)
#pragma config(Motor,  motorC,           ,             tmotorNXT, openLoop)
#pragma config(Motor,  mtr_S1_C1_1,     mLift2,        tmotorTetrix, openLoop, reversed)
#pragma config(Motor,  mtr_S1_C1_2,     Right,         tmotorTetrix, openLoop, reversed)
#pragma config(Motor,  mtr_S1_C2_1,     mLift1,        tmotorTetrix, openLoop, reversed)
#pragma config(Motor,  mtr_S1_C2_2,     mFlag,         tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C3_1,     Left,          tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C3_2,     mWrist,        tmotorTetrix, openLoop)
#pragma config(Servo,  srvo_S1_C4_1,    AutoHook,             tServoStandard)
#pragma config(Servo,  srvo_S1_C4_2,    sHook,                tServoStandard)
#pragma config(Servo,  srvo_S1_C4_3,    servo3,               tServoNone)
#pragma config(Servo,  srvo_S1_C4_4,    servo4,               tServoNone)
#pragma config(Servo,  srvo_S1_C4_5,    servo5,               tServoNone)
#pragma config(Servo,  srvo_S1_C4_6,    servo6,               tServoNone)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

// Include file to handle the Bluetooth messages.
#include "JoystickDriver.c"
// the max motor value
#define max 100
// the min motor value
#define min 0
// the maximum lift power
#define lift_max 100
// the minimum lift power
#define lift_min 0
// the threshold of when the lift is considered down
#define thresh 4700

// whether sniper mode is currently enabled
// Sniper mode allows the drivers to slow down the robot for more precise movements.
bool sniper = false;
// whether the slide limit function is enabled
bool limit = false;
// whether the slide is all the way down
bool bottom = false;
// whether slide is completely extended
bool extended = false;
// whether the slide toggle button is currently down
bool clicked = false;
// whether the slide toggle button was previously down
// This is used to prevent double-triggering the toggle function.
bool prevClicked = false;

/*------------------------------------------------|
|Motor A1 is Right; Motor A2 is mDispenser.				|
|Motor C1 is mLift; Motor C2 is mWrist.						|
|Motor B1 is mHinge;Motor B2 is Left.							|
|servo1 is sHook; servo2 is AutoDispenser.				|
|Motors run on a scale of -100(max backwards) to  |
|100 (max forwards), with no power being 0.				|
|Servos run on a scale of 0 (max backwards) to 		|
|256(max forwards), with 127 being no power.			|
|-------------------------------------------------*/


void sniperCheck() //checks to see if the robot should go in "sniper"/slow mode.
{
	if(joy1Btn(5))
	{
		sniper = true;
	}
	else
	{sniper = false;}
}

void drive() //moving method
{
	if(!sniper)
	{
		if(abs(joystick.joy1_y2)>10) //prevents idle movement from small values
		{
			if(joystick.joy1_y2>0)
			{
				motor[Left] = pow(joystick.joy1_y2, 2)/100;//(joystick.joy1_y2*100)/128; //moves left side forward/backward on the motor's scale
			}
			else
			{
				motor[Left] = -pow(joystick.joy1_y2, 2)/100;//(joystick.joy1_y2*100)/128; //moves left side forward/backward on the motor's scale
			}
		}
		else
		{
			motor[Left] = 0; //stops movement of the left side
		}

		if(abs(joystick.joy1_y1)>10)
		{
			if(joystick.joy1_y1>0)
			{
				motor[Right] = pow(joystick.joy1_y1, 2)/100; //(joystick.joy1_y1*100)/128; //moves right side forward/backward on the motor's scale
			}
			else
			{
				motor[Right] = -pow(joystick.joy1_y1, 2)/100; //(joystick.joy1_y1*100)/128; //moves right side forward/backward on the motor's scale
			}
		}
		else
		{
			motor[Right] = 0; //stops movement of the right side
		}
	}
	else
	{
		if(abs(joystick.joy1_y2)>10) //prevents idle movement from small values
		{
			if(joystick.joy1_y2>0)
			{
				motor[Left] = pow(joystick.joy1_y2, 2)/400;//(joystick.joy1_y2*100)/128; //moves left side forward/backward on the motor's scale
			}
			else
			{
				motor[Left] = -pow(joystick.joy1_y2, 2)/400;//(joystick.joy1_y2*100)/128; //moves left side forward/backward on the motor's scale
			}
		}
		else
		{
			motor[Left] = 0;
		}

		if(abs(joystick.joy1_y1)>10)
		{
			if(joystick.joy1_y1>0)
			{
				motor[Right] = pow(joystick.joy1_y1, 2)/400; //(joystick.joy1_y1*100)/128; //moves right side forward/backward on the motor's scale
			}
			else
			{
				motor[Right] = -pow(joystick.joy1_y1, 2)/400; //(joystick.joy1_y1*100)/128; //moves right side forward/backward on the motor's scale
			}
		}
		else
		{
			motor[Right] = 0; //stops movement of the right side
		}
	}


}


void newLift()
{
	if(!clicked)
	{
		motor[motorA] = 0;
		if(nMotorEncoder[mLift1] >= thresh)
		{
			extended = true;
			bottom = false;
		}
		else if(nMotorEncoder[mLift1] <= 200)
		{
			bottom = true;
			extended = false;
		}
		if(joystick.joy2_y1 > 10)
		{
			if(bottom)
			{
				motor[mLift1] = joystick.joy2_y1;
				motor[mLift2] = 0;
			}
			else if(extended)
			{
				motor[mLift2] = joystick.joy2_y1;
				motor[mLift1] = 0;
			}
		}
		else if(joystick.joy2_y1 < 10)
		{
			if(bottom)
			{
				motor[mLift1] = 0;
				motor[mLift2] = joystick.joy2_y1;
			}
			else
			{
				motor[mLift2] = 0;
				motor[mLift1] = joystick.joy2_y1;
			}
		}
	}
	else
	{
		motor[motorA] = 100;
		if(joystick.joy2_TopHat == 0)
		{
			motor[mLift1] = 100;
		}
		else if(joystick.joy2_TopHat == 4)
		{
			motor[mLift1] = -100;
		}
		else if(joy2Btn(5))
		{
			motor[mLift2] = 100;
		}
		else if(joy2Btn(7))
		{
			motor[mLift2] = -100;
		}
		else
		{
			motor[mLift2] = 0;
			motor[mLift1] = 0;
		}
	}
}

void isClicked()
{
	if(joy2Btn(11))
	{
		if(!prevClicked)
		{
			clicked = !clicked;
			prevClicked = true;
		}

	}
	else
	{
		prevClicked = false;
	}
}

void lift()
{
	if(joystick.joy2_y1 > 20)
	{
		motor[mLift1] = joystick.joy2_y1;
	}
	else if(joystick.joy2_y1 < 20)
	{
		motor[mLift1] = joystick.joy2_y1;
	}
	else
	{
		motor[mLift1] = 0;
	}
}

void lift2()
{

	if(joy2Btn(5) || joy1Btn(5))
	{
		motor[mLift2] = 100;
	}
	else if(joy2Btn(7) || joy1Btn(7))
	{
		motor[mLift2] = -100;
	}
	else
	{
		motor[mLift2] = 0;
	}
}

void autoHook()
{
	if(joy1Btn(4))
	{
		servo[AutoHook] -= 5;
	}
	if(joy1Btn(2))
	{
		servo[AutoHook] += 5;
	}
}



void wrist() //moves the wrist part of the dispenser up and down
{
	if(abs(joystick.joy2_y2) > 10)
	{
		motor[mWrist] = joystick.joy2_y2/4;
	}
	else
	{
		motor[mWrist] = 0;
	}
}

void flag() //flag method
{
	if(!sniper)
	{
		if(joystick.joy2_TopHat == 2)
			motor[mFlag]= 100; //moves flag attachment clockwise
		else if(joystick.joy2_TopHat == 6 )
			motor[mFlag]= -100; //moves flag attachment counterclockwise
		else
			motor[mFlag] = 0; //stops moving flag attachment
	}
	else
	{
		if(joystick.joy2_TopHat == 2)
			motor[mFlag]= 50; //moves flag attachment clockwise
		else if(joystick.joy2_TopHat == 6 )
			motor[mFlag]= -50; //moves flag attachment counterclockwise
		else
			motor[mFlag] = 0; //stops moving flag attachment
	}
}
void liftLimit() //sets a limit for the lift; this prevents it from going past that point.
{
	if(joy2Btn(10))
	{
		limit = true;
		nMotorEncoder[mLift1] = 0;
	}
	if(limit)
	{
		if(nMotorEncoder[mLift1] < 0)
		{
			while(nMotorEncoder[mLift1] < 0)
			{
				motor[mLift1] = 90;
			}
			motor[mLift1] = 0;
		}
		if (joy2Btn(9))
		{
			limit = false;
		}
	}
}

void hook() //controls the hook's side-to-side movement.
{
	if(joy2Btn(4))
	{
		servo[sHook] += 5;
	}
	else if(joy2Btn(2))
	{
		servo[sHook] -= 5;
	}
}

task main()
{
	nMotorEncoder[mLift1] = 0;

	servo[sHook] = 0;
	servo[AutoHook] = 0;
	motor[Left] = 0;
	motor[Right] = 0;
	motor[mLift1] = 0;
	motor[mLift2] = 0;
	motor[mFlag] = 0;
	motor[mWrist] = 0;

	while(true)
	{
		getJoystickSettings(joystick);  // Update Buttons and Joysticks
		if(!bDisconnected)//makes  sure robot is still connected to Samantha
		{
			sniperCheck();
			drive();
			flag();
			newLift();
			isClicked();
			liftLimit();
			hook();
			wrist();
			autoHook();
			//all of the above code runs the methods that control all the motorized parts of our robot.
			wait1Msec(10); //a wait to ensure that multiple signals do not stack and to prevent lag.
		}
		else
		{
			motor[Left] = 0;
			motor[Right] = 0;
			motor[mLift1] = 0;
			motor[mLift2] = 0;
			motor[mFlag] = 0;
			motor[mWrist] = 0;
			//sets everything to stop if bluetooth  is disconnected.
		}
	}
}
