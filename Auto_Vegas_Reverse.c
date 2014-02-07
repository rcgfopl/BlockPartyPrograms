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


bool timeSelected = false;
bool startSelected = false;
bool waitSelected = true;
int waitTime = 0;
string wait = "Yes";

#include "JoystickDriver.c"
#include "FunctionLibrary.c"

#define left 1
#define right -1
task main()
{

	selectTime();
	startSelect();
	if(waitSelected)
	{
		waitForStart();
	}
	wait1Msec(1000*waitTime);
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
				ModBackward(1700,35);
				motor[Right] = 0;
				motor[Left] = 0;
				wait1Msec(1000);
			}
			else if(beacon == 1)
			{
				//the distance to get to the second beacon
				ModBackward(400,35);
				motor[Right] = 0;
				motor[Left] = 0;
				wait1Msec(1000);
			}
			else if(beacon == 2)
			{
				//the distance to get to the third beacon
				ModBackward(1200,35);
				motor[Right] = 0;
				motor[Left] = 0;
				wait1Msec(1000);
			}
			else if(beacon == 3)
			{
				//the distance to get to the fourth beacon
				ModBackward(300,35);
				motor[Right] = 0;
				motor[Left] = 0;
				wait1Msec(1000);
			}
			beacon++;
		}
	}

	//code that runs after  we stop in front of a beacon.
	servo[AutoHook] = 255;	//dispenses the cube
	wait1Msec(900);
	servo[AutoHook] = 0;
	wait1Msec(1000);

	//pick where to  go based on beacon #.
	//if the robot is at rings 1 or 4, it turns, goes back, then turns to face the ramp.
	//if the robots is at rings 2 or 3, it goes backwards, turns, goes backwards again, and then turns to face the ramp.
	if(beacon == 1) //beacon was on first ring
	{
		ModForward(1560,50);
		motor[Right] = 0;
		motor[Left] = 0;
		wait1Msec(500);

		ModTurn(1940, 100, right);
		motor[Right] = 0;
		motor[Left] = 0;
		wait1Msec(500);

		ModBackward(4000,50);
		motor[Right] = 0;
		motor[Left] = 0;
		wait1Msec(500);

		ModTurn(2700,100,left);
		motor[Right] = 0;
		motor[Left] = 0;
		wait1Msec(500);

		ModBackward(4500,100);
	}
	else if (beacon == 2) //beacon was on second ring
	{
		ModForward(2700,50);
		motor[Right] = 0;
		motor[Left] = 0;
		wait1Msec(500);

		ModTurn(2040, 100, right);
		motor[Right] = 0;
		motor[Left] = 0;
		wait1Msec(500);

		ModBackward(4000,50);
		motor[Right] = 0;
		motor[Left] = 0;
		wait1Msec(500);

		ModTurn(2700,100,left);
		motor[Right] = 0;
		motor[Left] = 0;
		wait1Msec(500);

		ModBackward(4500,80);


	}
	else if (beacon == 3) //beacon was on third ring
	{
		ModBackward(2900,50);
		motor[Right] = 0;
		motor[Left] = 0;
		wait1Msec(500);

		ModTurn(1840, 100, right);
		motor[Right] = 0;
		motor[Left] = 0;
		wait1Msec(500);

		ModBackward(4000,50);
		motor[Right] = 0;
		motor[Left] = 0;
		wait1Msec(500);

		ModTurn(2700, 100, right);
		motor[Right] = 0;
		motor[Left] = 0;
		wait1Msec(500);

		ModBackward(4500,100);
	}
	else if (beacon == 4) //beacon was on fourth ring
	{
		ModBackward(1760,50);
		motor[Right] = 0;
		motor[Left] = 0;
		wait1Msec(500);

		ModTurn(1840, 100, right);
		motor[Right] = 0;
		motor[Left] = 0;
		wait1Msec(500);

		ModBackward(4000,50);
		motor[Right] = 0;
		motor[Left] = 0;
		wait1Msec(500);

		ModTurn(2700, 100, right);
		motor[Right] = 0;
		motor[Left] = 0;
		wait1Msec(500);

		ModBackward(4500,100);
	}
}