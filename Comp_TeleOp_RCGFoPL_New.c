#pragma config(Hubs,  S1, HTMotor,  HTMotor,  HTMotor,  HTServo)
#pragma config(Sensor, S1,     ,               sensorI2CMuxController)
#pragma config(Sensor, S2,     Ultra,          sensorSONAR)
#pragma config(Sensor, S3,     Ultra2,         sensorSONAR)
#pragma config(Sensor, S4,     IR,             sensorHiTechnicIRSeeker600)
#pragma config(Motor,  motorA,           ,             tmotorNXT, openLoop)
#pragma config(Motor,  motorB,           ,             tmotorNXT, openLoop)
#pragma config(Motor,  motorC,           ,             tmotorNXT, openLoop)
#pragma config(Motor,  mtr_S1_C1_1,     Right,         tmotorTetrix, openLoop, reversed)
#pragma config(Motor,  mtr_S1_C1_2,     mFlag,         tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C2_1,     mHinge,        tmotorTetrix, openLoop, reversed)
#pragma config(Motor,  mtr_S1_C2_2,     Left,          tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C3_1,     mLift,         tmotorTetrix, openLoop, reversed)
#pragma config(Motor,  mtr_S1_C3_2,     mWrist,        tmotorTetrix, openLoop)
#pragma config(Servo,  srvo_S1_C4_1,    sHook,                tServoStandard)
#pragma config(Servo,  srvo_S1_C4_2,    AutoHook,             tServoStandard)
#pragma config(Servo,  srvo_S1_C4_3,    servo3,               tServoNone)
#pragma config(Servo,  srvo_S1_C4_4,    servo4,               tServoNone)
#pragma config(Servo,  srvo_S1_C4_5,    servo5,               tServoNone)
#pragma config(Servo,  srvo_S1_C4_6,    servo6,               tServoNone)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

#include "JoystickDriver.c"  //Include file to "handle" the Bluetooth messages.
#define max 100
#define min 0

bool sniper = false;
bool limit = false;

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
	if(joy1Btn(5) || joy2Btn(5))
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
	else
	{
		servo[AutoHook] += 0;
	}
}

void hinge() //moves the hinge of the dispenser up and down
{
	if(joy2Btn(6))
	{
		motor[mHinge] = 50;
	}
	else if(joy2Btn(8))
	{
		motor[mHinge] = -50;
	}
	else
	{
		motor[mHinge] = 0;
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

void lift() //lift method
{
	if(abs(joystick.joy2_y1)>10)
	{
		motor[mLift] = joystick.joy2_y1; //moves lift up or down based on joystick commands
	}
	else if(joy1Btn(6))
	{
		motor[mLift] = 100;
	}
	else if(joy1Btn(8))
	{
		motor[mLift] = -100;
	}
	else
	{
		motor[mLift] = 0;
	}
}

void liftLimit() //sets a limit for the lift; this prevents it from going past that point.
{
	if(joy2Btn(10))
	{
		limit = true;
		nMotorEncoder[mLift] = 0;
	}
	if(limit)
	{
		if(nMotorEncoder[mLift] < 0)
		{
			while(nMotorEncoder[mLift] < 0)
			{
				motor[mLift] = 90;
			}
			motor[mLift] = 0;
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

void newArm() //controls both parts of the arm at the same time
{
	if(joystick.joy2_y2 > 20)
	{
		motor[mWrist] = -10;
		motor[mHinge] = 40;
	}
	else if(joystick.joy2_y2 < -20)
	{
		motor[mWrist] = 30;
		motor[mHinge] = -20;
	}
	else
	{
		//motor[mWrist] = 0;
		motor[mHinge] = 0;
	}
}

task main()
{
	servo[sHook] = 127;
	servo[AutoHook] = 0;

	while(true)
	{
		getJoystickSettings(joystick);  // Update Buttons and Joysticks
		if(!bDisconnected)//makes  sure robot is still connected to Samantha
		{
			sniperCheck();
			drive();
			flag();
			lift();
			liftLimit();
			hook();
			wrist();
			hinge();
			//newArm();
			autoHook();
			//all of the above code runs the methods that control all the motorized parts of our robot.
			wait1Msec(10); //a wait to ensure that multiple signals do not stack and to prevent lag.
		}
		else
		{
			motor[Left] = 0;
			motor[Right] = 0;
			motor[mLift] = 0;
			motor[mFlag] = 0;
			motor[mWrist] = 0;
			motor[mHinge] = 0;
  		servo[sHook] = 127;
  		//sets everything to stop if bluetooth  is disconnected.
		}
	}
}
