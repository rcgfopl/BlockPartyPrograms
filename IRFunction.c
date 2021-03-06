#pragma config(Hubs,  S1, HTMotor,  HTMotor,  HTMotor,  none)
#pragma config(Sensor, S4,     IR,             sensorHiTechnicIRSeeker600)
#pragma config(Motor,  motorA,           ,             tmotorNXT, openLoop)
#pragma config(Motor,  motorB,           ,             tmotorNXT, openLoop)
#pragma config(Motor,  motorC,           ,             tmotorNXT, openLoop)
#pragma config(Motor,  mtr_S1_C1_1,     Right,         tmotorTetrix, openLoop, reversed, encoder)
#pragma config(Motor,  mtr_S1_C1_2,     mLift,         tmotorTetrix, openLoop, encoder)
#pragma config(Motor,  mtr_S1_C2_1,     mIntake,       tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C2_2,     mFlag,         tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C3_1,     Left,          tmotorTetrix, openLoop, encoder)
#pragma config(Motor,  mtr_S1_C3_2,     mDispenser,    tmotorTetrix, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

#include "FunctionLibrary.c"
#include "JoystickDriver.c"
#define right -1
#define left 1
int getIRReading(){
	wait1Msec(1);
	return SensorValue(S4);}

task main()
{
	waitForStart();
	//wait1Msec(20000);
  nMotorEncoder[Right] = 0;
	Forward(3100,70);
	nMotorEncoder[mLift] = 0;
	while(nMotorEncoder[mLift] < 3800)
	{
		motor[mLift] = 50;
	}

	motor[mLift] = 0;
	Forward(700,70);
	wait1Msec(1000);
  Turn(720,100,right);
  while (getSensorReading()>2){
		motor[Right] = 70;
		motor[Left] = 70;
	}
	motor[Right]=0;
	motor[Left]=0;

	motor[mDispenser] = -50;
	wait1Msec(200);
	motor[mDispenser] = 50;
	wait1Msec(200);
	motor[mDispenser] = 0;
  wait1Msec(500);
  Forward(5700,100);
  motor[mIntake] = 100;
  wait10Msec(10);
	motor[mIntake] = 0;
	while (getSensorReading>2){
		motor[Right] = 70;
		motor[Left] = 70;
	}
	motor[Right]=0;
	motor[Left]=0;
	motor[mDispenser] = -50;
	wait1Msec(200);
	motor[mDispenser] = 50;
	wait1Msec(200);
	motor[mDispenser] = 0;
  wait1Msec(500);
	Backward(1700,70);
	wait1Msec(500);

}
