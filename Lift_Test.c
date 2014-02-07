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

task main()
{
	nMotorEncoder[mLift1] = 0;
	while(true)
	{
		if(nNxtButtonPressed == 1)
		{
			motor[mLift1]  = 100;
		}
		else if(nNxtButtonPressed == 2)
		{
			motor[mLift1] = -100;
		}
		else
		{
			motor[mLift1] = 0;
		}
		nxtDisplayCenteredTextLine(5, "%d", nMotorEncoder[mLift1]);
	}


}
