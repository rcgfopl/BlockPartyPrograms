#pragma config(Hubs,  S1, HTMotor,  HTMotor,  HTMotor,  HTServo)
#pragma config(Sensor, S1,     ,               sensorI2CMuxController)
#pragma config(Sensor, S2,     Ultra,          sensorSONAR)
#pragma config(Sensor, S3,     Ultra2,         sensorSONAR)
#pragma config(Sensor, S4,     IR,             sensorHiTechnicIRSeeker600)
#pragma config(Motor,  motorA,           ,             tmotorNXT, openLoop)
#pragma config(Motor,  motorB,           ,             tmotorNXT, openLoop)
#pragma config(Motor,  motorC,           ,             tmotorNXT, openLoop)
#pragma config(Motor,  mtr_S1_C1_1,     Left,          tmotorTetrix, openLoop, reversed)
#pragma config(Motor,  mtr_S1_C1_2,     mFlag,         tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C2_1,     mHinge,        tmotorTetrix, openLoop, reversed)
#pragma config(Motor,  mtr_S1_C2_2,     Right,         tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C3_1,     mLift,         tmotorTetrix, openLoop, reversed)
#pragma config(Motor,  mtr_S1_C3_2,     mWrist,        tmotorTetrix, openLoop)
#pragma config(Servo,  srvo_S1_C4_1,    sHook,                tServoStandard)
#pragma config(Servo,  srvo_S1_C4_2,    AutoDispenser,        tServoStandard)
#pragma config(Servo,  srvo_S1_C4_3,    servo3,               tServoNone)
#pragma config(Servo,  srvo_S1_C4_4,    servo4,               tServoNone)
#pragma config(Servo,  srvo_S1_C4_5,    servo5,               tServoNone)
#pragma config(Servo,  srvo_S1_C4_6,    servo6,               tServoNone)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

#include "JoystickDriver.c"
#include "FunctionLibrary.c"
task main()
{

	waitForStart();
	int beacon = 0; //holds which beacon the robot is at.
	int i = 0; 			//holds the IR sensor value.

	//loops until the sensor finds the beacon or until it gets to the final beacon.
	while(i != 5 && beacon < 4)
	{
		i=0;
		//this section prevents the reading of random IR values and makes sure the value is constant.
		//when the value is the constant we want, the beacon is in front of the sensor.
		for(int a = 0; a <100; a++)
		{
			if(a == 0)
			{
				//gets original ir value
				i  = SensorValue[IR];
			}
			else
			{
				int b = SensorValue[IR];
				if(b != i)
				{
					//if a different value is sensed, then the original value was not constant; thus, we restart the checking
					//to try and gete a constant value.
					i = 0;
					a = 0;
				}
			}
		}
		if(i != 5)
		{
			if(beacon == 0)
			{
				//the distance to get to the first beacon
				ForwardWithModTime(1200,35);
				motor[Right] = 0;
				motor[Left] = 0;
				wait1Msec(1000);
			}
			else if(beacon == 1)
			{
				//the distance to get to the second beacon
				ForwardWithModTime(450,35);
				motor[Right] = 0;
				motor[Left] = 0;
				wait1Msec(1000);
			}
			else if(beacon == 2)
			{
				//the distance to get to the third beacon
				ForwardWithModTime(900,35);
				motor[Right] = 0;
				motor[Left] = 0;
				wait1Msec(1000);
			}
			else if(beacon == 3)
			{
				//the distance to get to the fourth beacon
				ForwardWithModTime(470,35);
				motor[Right] = 0;
				motor[Left] = 0;
				wait1Msec(1000);
			}
			beacon++;
		}
	}

	//code that runs after  we stop in front of a beacon.
		servo[AutoDispenser] = 255;	//dispenses the cube
		wait1Msec(900);
		servo[AutoDispenser] = 0;
		wait1Msec(1000);

	//pick where to  go based on beacon #.
	//if the robot is at rings 1 or 4, it turns, goes back, then turns to face the ramp.
	//if the robots is at rings 2 or 3, it goes backwards, turns, goes backwards again, and then turns to face the ramp.
	if(beacon == 1) //beacon was on first ring
	{
		BackwardWithModTime(800,50);
		motor[Right] = 0;
		motor[Left] = 0;
		wait1Msec(500);

		motor[Right] = -100;
		motor[Left] = 100;
		wait1Msec(700);
		motor[Right] = 0;
		motor[Left] = 0;
		wait1Msec(500);

		BackwardWithModTime(1600,50);
		motor[Right] = 100;
		motor[Left] = -100;
		wait1Msec(900);
		motor[Right] = 0;
		motor[Left] = 0;
		wait1Msec(500);

		ForwardWithModTime(1400,100);
	}
	else if (beacon == 2) //beacon was on second ring
	{
		BackwardWithModTime(1200,50);
		motor[Right] = 0;
		motor[Left] = 0;
		wait1Msec(500);

		motor[Right] = -100;
		motor[Left] = 100;
		wait1Msec(700);
		motor[Right] = 0;
		motor[Left] = 0;
		wait1Msec(500);

		BackwardWithModTime(1600,50);
		motor[Right] = 0;
		motor[Left] = 0;
		wait1Msec(500);

		motor[Right] = 100;
		motor[Left] = -100;
		wait1Msec(900);
		motor[Right] = 0;
		motor[Left] = 0;
		wait1Msec(500);

		ForwardWithModTime(1400,100);
	}
	else if (beacon == 3) //beacon was on third ring
	{
		ForwardWithModTime(1000,50);
		motor[Right] = 0;
		motor[Left] = 0;
		wait1Msec(500);

		motor[Right] = 100;
		motor[Left] = -100;
		wait1Msec(900);
		motor[Right] = 0;
		motor[Left] = 0;
		wait1Msec(500);

		ForwardWithModTime(1600,50);
		motor[Right] = 0;
		motor[Left] = 0;
		wait1Msec(500);

		motor[Right] = -100;
		motor[Left] = 100;
		wait1Msec(900);
		motor[Right] = 0;
		motor[Left] = 0;
		wait1Msec(500);

		BackwardWithModTime(1400,100);
	}
	else if (beacon == 4) //beacon was on fourth ring
	{
		ForwardWithModTime(800,50);
		motor[Right] = 0;
		motor[Left] = 0;
		wait1Msec(500);

		motor[Right] = 100;
		motor[Left] = -100;
		wait1Msec(700);
		motor[Right] = 0;
		motor[Left] = 0;
		wait1Msec(500);

		ForwardWithModTime(1600,50);
		motor[Right] = 0;
		motor[Left] = 0;
		wait1Msec(500);

		motor[Right] = -100;
		motor[Left] = 100;
		wait1Msec(800);
		motor[Right] = 0;
		motor[Left] = 0;
		wait1Msec(500);

		BackwardWithModTime(1500,100);
	}
}
