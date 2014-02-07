#pragma config(Hubs,  S1, HTMotor,  HTMotor,  HTMotor,  HTServo)
#pragma config(Sensor, S1,     ,               sensorI2CMuxController)
#pragma config(Sensor, S2,     Ultra,          sensorSONAR)
#pragma config(Sensor, S3,     Ultra2,         sensorSONAR)
#pragma config(Sensor, S4,     IR,             sensorHiTechnicIRSeeker600)
#pragma config(Motor,  motorA,           ,             tmotorNXT, openLoop)
#pragma config(Motor,  motorB,           ,             tmotorNXT, openLoop)
#pragma config(Motor,  motorC,           ,             tmotorNXT, openLoop)
#pragma config(Motor,  mtr_S1_C1_1,     mLift2,        tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C1_2,     Left,          tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C2_1,     mLift1,        tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C2_2,     mFlag,         tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C3_1,     Right,         tmotorTetrix, openLoop, reversed)
#pragma config(Motor,  mtr_S1_C3_2,     mWrist,        tmotorTetrix, openLoop)
#pragma config(Servo,  srvo_S1_C4_1,    AutoHook,             tServoStandard)
#pragma config(Servo,  srvo_S1_C4_2,    sHook,                tServoStandard)
#pragma config(Servo,  srvo_S1_C4_3,    servo3,               tServoNone)
#pragma config(Servo,  srvo_S1_C4_4,    servo4,               tServoNone)
#pragma config(Servo,  srvo_S1_C4_5,    servo5,               tServoNone)
#pragma config(Servo,  srvo_S1_C4_6,    servo6,               tServoNone)


#include "JoystickDriver.c"  //Include file to "handle" the Bluetooth messages.

bool sniper = false;

void sniperCheck() //checks to see if the robot should go in "sniper"/slow mode.
{
	if(joystick.joy1_TopHat==3 || joystick.joy2_TopHat == 3)
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


task main()
{
	while(true)
	{
		getJoystickSettings(joystick);
		sniperCheck();
		drive();
		lift();
	}
}
