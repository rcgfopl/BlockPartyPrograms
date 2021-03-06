#pragma config(Hubs,  S1, HTMotor,  HTMotor,  HTMotor,  HTServo)
#pragma config(Sensor, S1,     ,               sensorI2CMuxController)
#pragma config(Sensor, S2,     Ultra,          sensorSONAR)
#pragma config(Sensor, S3,     Ultra2,         sensorSONAR)
#pragma config(Sensor, S4,     IR,             sensorHiTechnicIRSeeker600)
#pragma config(Motor,  motorA,           ,             tmotorNXT, openLoop)
#pragma config(Motor,  motorB,           ,             tmotorNXT, openLoop)
#pragma config(Motor,  motorC,           ,             tmotorNXT, openLoop)
#pragma config(Motor,  mtr_S1_C1_1,     mLift2,        tmotorTetrix, openLoop, reversed)
#pragma config(Motor,  mtr_S1_C1_2,     mRight,        tmotorTetrix, openLoop, reversed, encoder)
#pragma config(Motor,  mtr_S1_C2_1,     mLift1,        tmotorTetrix, openLoop, reversed)
#pragma config(Motor,  mtr_S1_C2_2,     mFlag,         tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C3_1,     mLeft,         tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C3_2,     mWrist,        tmotorTetrix, openLoop)
#pragma config(Servo,  srvo_S1_C4_1,    AutoHook,             tServoStandard)
#pragma config(Servo,  srvo_S1_C4_2,    servo2,               tServoNone)
#pragma config(Servo,  srvo_S1_C4_3,    servo3,               tServoNone)
#pragma config(Servo,  srvo_S1_C4_4,    servo4,               tServoNone)
#pragma config(Servo,  srvo_S1_C4_5,    servo5,               tServoNone)
#pragma config(Servo,  srvo_S1_C4_6,    servo6,               tServoNone)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

/******************************
* DISTANCES TO EACH BOX	      *
* To box 2(forward) 3872      *
* To box 3(forward) 6657      *
* To box 2(backward) -2012    *
* To box 3(backward)  -4980   *
******************************/

#define left 1
#define right -1

// whether the user has finished selecting a delay time
bool timeSelected = false;
// whether the robot will wait for the FCS to start (disable when testing)
bool startSelected = false;
// whether the user has selected to delay at the beginning of autonomous
bool waitSelected = true;
// how many seconds to delay before starting autonomous (used for coordinating with
// other teams)
int waitTime = 0;
// the message used by the wait prompt
string wait = "Yes";
//holds which  autonomous program we will be running
int programCounter = 1;
//holds the  maximum amount of autonomous programs we can run
int max = 6;
//holds which beacon the robot is at
int beacon = 0;
//holds the IR sensor value
int i = 0;

// standard library for talking to Samantha FCS
#include "JoystickDriver.c"
// our team-built function library
#include "FunctionLibrary.c"
//our team-built Autonomous library
#include "AutonomousLibrary_NorCal.c"
#define FrontVal 8800

task main()
{
	int distance=0;
	int add=0;
	nMotorEncoder[mRight] = 0;

	while(SensorValue(IR) != 5)
	{
		motor[mLeft] = -30;
		motor[mRight] = -30;
	}
	motor[mLeft] = 0;
	motor[mRight] = 0;
	wait1Msec(500);
	distance = nMotorEncoder[mRight];
	if(abs(distance) <= 3500)
	{
			add = 300;
	}
	else
	{
			add = -200;
	}
  if(add > 0)
  {
		Backward(add, 30);
  }
  else
  {
  	Forward(abs(add), 30);
  }
	wait1Msec(500);

	servo[AutoHook] = 0;
	wait1Msec(1000);
	servo[AutoHook] = 250;
	wait1Msec(500);

	Backward(FrontVal - abs(distance) - add-150, 30);

	//turns to be parallel to the ramp
	Turn(1760, 100, left);
	motor[mRight] = 0;
	motor[mLeft] = 0;
	wait1Msec(500);

	//goes backwards and towards the ramp
	Forward(3900,50);
	motor[mRight] = 0;
	motor[mLeft] = 0;
	wait1Msec(500);

	//turns towards the ramp
	Turn(2100,100,right);
	motor[mRight] = 0;
	motor[mLeft] = 0;
	wait1Msec(500);

	//goes onto the ramp
	Forward(4500,100);
}
