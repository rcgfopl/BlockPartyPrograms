#pragma config(Hubs,  S1, HTMotor,  HTMotor,  HTMotor,  HTServo)
#pragma config(Sensor, S2,     Ultra,          sensorSONAR)
#pragma config(Sensor, S3,     Ultra2,         sensorSONAR)
#pragma config(Sensor, S4,     IR,             sensorHiTechnicIRSeeker600)
#pragma config(Motor,  motorA,           ,             tmotorNXT, openLoop)
#pragma config(Motor,  motorB,           ,             tmotorNXT, openLoop)
#pragma config(Motor,  motorC,           ,             tmotorNXT, openLoop)
#pragma config(Motor,  mtr_S1_C1_1,     Right,         tmotorTetrix, openLoop, reversed)
#pragma config(Motor,  mtr_S1_C1_2,     mFlag,         tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C2_1,     mLift,         tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C2_2,     Left,          tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C3_1,     mWinch1,       tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C3_2,     mWinch2,       tmotorTetrix, openLoop)
#pragma config(Servo,  srvo_S1_C4_1,    sCubes,               tServoContinuousRotation)
#pragma config(Servo,  srvo_S1_C4_2,    servo2,               tServoNone)
#pragma config(Servo,  srvo_S1_C4_3,    servo3,               tServoNone)
#pragma config(Servo,  srvo_S1_C4_4,    servo4,               tServoNone)
#pragma config(Servo,  srvo_S1_C4_5,    servo5,               tServoNone)
#pragma config(Servo,  srvo_S1_C4_6,    servo6,               tServoNone)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

#include "JoystickDriver.c"  //Include file to "handle" the Bluetooth messages.
#include "FunctionLibrary.c"
#define max 100
#define min 0

bool sniper = false;
bool limit = false;
/*------------------------------------------------|
|Motor A1 is Right; Motor A2 is mDispenser.				|
|Motor C1 is Left; Motor C2 is mLift.							|
|Motor B1 is mIntake;   Motor B2 is mFlag.				|
|Motors run on a scale of -100(max backwards) to  |
|100 (max forwards), with no power being 0.				|
|Servos run on a scale of 0 (max backwards) to 		|
|256(max forwards), with 127 being no power.			|
|------------------------------------	------------*/

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

void flag() //flag method
{
	if(!sniper)
	{
		if(joystick.joy2_TopHat == 2 || joystick.joy1_TopHat == 2)
			motor[mFlag]= 100; //moves flag attachment clockwise
		else if(joystick.joy2_TopHat == 6 || joystick.joy1_TopHat == 6)
			motor[mFlag]= -100; //moves flag attachment counterclockwise
	else
			motor[mFlag] = 0; //stops moving flag attachment
	}
	else
	{
		if(joystick.joy2_TopHat == 2 || joystick.joy1_TopHat == 2)
			motor[mFlag]= 50; //moves flag attachment clockwise
		else if(joystick.joy2_TopHat == 6 || joystick.joy1_TopHat == 2)
			motor[mFlag]= -50; //moves flag attachment counterclockwise
		else
			motor[mFlag] = 0; //stops moving flag attachment
	}
}

void lift() //lift method
{
	//if(!sniper)
  //{
		if(abs(joystick.joy2_y1)>10)
		{
			motor[mLift] = joystick.joy2_y1; //moves lift up
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
	//}
	//else
	//{
	//	if(abs(joystick.joy2_y1)>10)
	//	{
	//		motor[mLift] = joystick.joy2_y1/2; //moves lift up
	//	}
	//	else if(joy1Btn(6))
	//	{
	//		motor[mLift] = 50;
	//	}
	//	else if(joy1Btn(8))
	//	{
	//		motor[mLift] = -50;
	//	}
	//	else
	//	{
	//		motor[mLift] = 0;
	//	}
	//}
}

void dispenser()//dispenser method
{
	if(joy1Btn(1) || joy2Btn(1))
	{
		servo[sCubes] = 0; //pushes dispenser forward and dispenses blocks
	}
	else if(joy1Btn(3) || joy2Btn(3))
	{
		servo[sCubes] = 255; //brings dispenser back
	}
	else
	{
		servo[sCubes] = 127; //dispenser stops moving
	}
}

void liftLimit()
{
	if(joy2Btn(10) || joy1Btn(10))
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

void winch()
{
	if (joy2Btn(11)||joy1Btn(11)) {
		motor[mWinch1] = motor[mWinch2] = 100;
	} else if (joy2Btn(12)||joy1Btn(12)) {
		motor[mWinch1] = motor[mWinch2] = -100;
	} else {
		motor[mWinch1] = motor[mWinch2] = 0;
	}
}

task main()
{
	servo[sCubes] = 127;
	waitForStart();

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
			winch();
			dispenser();
			//all of the above code runs the methods that control all the motorized parts of our robot.
			wait1Msec(10); //a wait to ensure that multiple signals do not stack and to prevent lag.
		}
		else
		{
			motor[Left] = 0;
			motor[Right] = 0;
			motor[mLift] = 0;
			motor[mFlag] = 0;
			motor[mWinch1] = motor[mWinch2] = 0;
			servo[sCubes] = 127;
		}
	}
}
