#include "drivers/hitechnic-sensormux.h"
#include "drivers/lego-ultrasound.h"

// Direction representing a mLeft (counter-clockwise) turn
// This is used as a parameter for turning functions.
#define Left 1
// Direction representing a mRight (clockwise) turn
// This is used as a parameter for turning functions.
#define Right -1

//various methods to move forward.

// Move forward based on encoders
// distance: the number of degrees to elapse on the encoders
// power: the power level the motors will be driven at
void Forward(int distance, int power)
{
	nMotorEncoder[mLeft] = 0;
	nMotorEncoder[mRight] = 0;

	while((nMotorEncoder[mRight]) < distance)
	{
		motor[mLeft] = power;
		motor[mRight] = power;
	}
  	motor[mLeft] = 0;
	motor[mRight] = 0;
}

// Move forward based on encoders while avoiding collisions
// If the ultrasonic sensors see another robot, this will stop the robot until the
// other robot moves away.
// distance: the number of degrees to elapse on the encoders
// power: the power level the motors will be driven at
void ForwardWithSonar(int distance, int power)
{
	nMotorEncoder[mLeft] = 0;
	nMotorEncoder[mRight] = 0;

	while((nMotorEncoder[mRight]) < distance)
  {
		int value = SensorValue[Ultra];
		if((value>=255 || value<0))
		{
			motor[mLeft] = power;
			motor[mRight] = power;
		}
	}
	motor[mLeft] = 0;
	motor[mRight] = 0;
}

// Move forward based on encoders while avoiding collisions
// If the ultrasonic sensors see another robot, this will stop the robot until the
// Uses both the ultrasonic sensors in parallel.
// other robot moves away.
// distance: the number of degrees to elapse on the encoders
// power: the power level the motors will be driven at
void ForwardWithTwoSonar(int distance, int power)
{
	nMotorEncoder[mLeft] = 0;
	nMotorEncoder[mRight] = 0;

	while((nMotorEncoder[mRight]) < distance)
  {
		int value  = USreadDist(Ultra);
		int value2 = USreadDist(Ultra2);
		if((value>=255 || value<0) || (value2>=255 || value<0))
		{
			motor[mLeft] = power;
			motor[mRight] = power;
		}
	}
	motor[mLeft] = 0;
	motor[mRight] = 0;
}

// Move forward based on time while avoiding collisions
// If the ultrasonic sensors see another robot, this will stop the robot until the
// Uses both the ultrasonic sensors in parallel.
// other robot moves away.
// time: the number of milliseconds to move for
// power: the power level the motors will be driven at
void ForwardWithTimeUS(int time, int power)
{
	unsigned long endTime = nPgmTime + time;
	while(nPgmTime < endTime)
	{
		int mLeftUS = USreadDist (Ultra);
		int mRightUS = USreadDist (Ultra2);
		if ((mLeftUS > 0 && mLeftUS < 255) || (mRightUS > 0 && mRightUS < 255))
		{
				motor[mRight] = 0;
				motor[mLeft] = 0;
		}
		else
		{
				motor[mRight] = power;
				motor[mLeft] = power;
		}
	}
	motor[mRight] = 0;
	motor[mLeft] = 0;
}

// Move forward based on encoders
// time: the number of milliseconds to move for
// power: the power level the motors will be driven at
void ForwardWithTime(int time, int power)
{
	unsigned long endTime = nPgmTime + time;
	while(nPgmTime < endTime)
	{
				motor[mRight] = power;
				motor[mLeft] = power;
	}
	motor[mRight] = 0;
	motor[mLeft] = 0;
}

// Move forward based on encoders
// Compensates for a weaker mRight side of the drive train.
// time: the number of milliseconds to move for
// power: the power level the motors will be driven at
void ForwardWithModTime(int time, int power)
{
	unsigned long endTime = nPgmTime + time;
	while(nPgmTime < endTime)
	{
				motor[mRight] = power + 15;
				motor[mLeft] = power;
	}
	motor[mRight] = 0;
	motor[mLeft] = 0;
}

// Move forward based on encoders
// Compensates for a weaker mRight side of the drive train.
// distance: the number of degrees to elapse on the encoders
// power: the power level the motors will be driven at
void ModForward(int distance, int power)
{
	nMotorEncoder[mLeft] = 0;
	nMotorEncoder[mRight] = 0;

	while((nMotorEncoder[mRight]) < distance)
	{
		motor[mLeft] = power + 25;
		motor[mRight] = power;
	}
  	motor[mLeft] = 0;
	motor[mRight] = 0;
}

//various methods to move backwards.

// Move backward based on encoders
// distance: the number of degrees to elapse on the encoders
// power: the power level the motors will be driven at
void Backward(int distance, int power)
{
	nMotorEncoder[mLeft] = 0;
	nMotorEncoder[mRight] = 0;

	while((nMotorEncoder[mRight] )> -distance)
	{
		motor[mLeft] = -power;
		motor[mRight] = -power;
	}
	motor[mLeft] = 0;
	motor[mRight] = 0;
}

// Move backward based on encoders while avoiding collisions
// If the ultrasonic sensors see another robot, this will stop the robot until the
// other robot moves away.
// distance: the number of degrees to elapse on the encoders
// power: the power level the motors will be driven at
void BackwardWithSonar(int distance, int power)
{
	nMotorEncoder[mLeft] = 0;
	nMotorEncoder[mRight] = 0;

	while((nMotorEncoder[mRight] )> -distance)
	{
		int value = SensorValue[Ultra];
		if(value>=255 || value<0)
		{
			motor[mLeft] = -power;
			motor[mRight] = -power;
		}
	}
	motor[mLeft] = 0;
	motor[mRight] = 0;
}

// Move backward based on encoders while avoiding collisions
// If the ultrasonic sensors see another robot, this will stop the robot until the
// Uses both the ultrasonic sensors in parallel.
// other robot moves away.
// distance: the number of degrees to elapse on the encoders
// power: the power level the motors will be driven at
void BackwardWithTwoSonar(int distance, int power)
{
	nMotorEncoder[mLeft] = 0;
	nMotorEncoder[mRight] = 0;

	while((nMotorEncoder[mRight]) < distance)
  {
		int value  = USreadDist(Ultra);
		int value2 = USreadDist(Ultra2);
		if((value>=255 || value<0) || (value2>=255 || value<0))
		{
			motor[mLeft] = -power;
			motor[mRight] = -power;
		}
	}
	motor[mLeft] = 0;
	motor[mRight] = 0;
}

// Move backward based on time while avoiding collisions
// If the ultrasonic sensors see another robot, this will stop the robot until the
// Uses both the ultrasonic sensors in parallel.
// other robot moves away.
// time: the number of milliseconds to move for
// power: the power level the motors will be driven at
void BackwardWithTimeUS(int time, int power)
{
	unsigned long endTime = nPgmTime + time;
	while(nPgmTime < endTime)
	{
		int mLeftUS = USreadDist (Ultra);
		int mRightUS = USreadDist (Ultra2);
		if ((mLeftUS > 0 || mLeftUS < 255) || (mRightUS > 0 || mRightUS < 255))
		{
				motor[mRight] = -power;
				motor[mLeft] = -power;
		}
		else
		{
				motor[mRight] = -power;
				motor[mLeft] = -power;
		}
	}
	motor[mRight] = 0;
	motor[mLeft] = 0;
}

// Move backward based on encoders
// time: the number of milliseconds to move for
// power: the power level the motors will be driven at
void BackwardWithTime(int time, int power)
{
	unsigned long endTime = nPgmTime + time;
	while(nPgmTime < endTime)
	{
				motor[mRight] = -power;
				motor[mLeft] = -power;
	}
	motor[mRight] = 0;
	motor[mLeft] = 0;
}

// Move backward based on encoders
// Compensates for a weaker mRight side of the drive train.
// time: the number of milliseconds to move for
// power: the power level the motors will be driven at
void BackwardWithModTime(int time, int power)
{
	unsigned long endTime = nPgmTime + time;
	while(nPgmTime < endTime)
	{
				motor[mRight] = -power - 15;
				motor[mLeft] = -power;
	}
	motor[mRight] = 0;
	motor[mLeft] = 0;
}

// Move backward based on encoders
// Compensates for a weaker mRight side of the drive train.
// distance: the number of degrees to elapse on the encoders
// power: the power level the motors will be driven at
void ModBackward(int distance, int power)
{
	nMotorEncoder[mLeft] = 0;
	nMotorEncoder[mRight] = 0;

	while((nMotorEncoder[mRight] )> -distance)
	{
		motor[mLeft] = -power-25;
		motor[mRight] = -power;
	}
	motor[mLeft] = 0;
	motor[mRight] = 0;
}

//a couple methods to turn.

// Turn based on encoders
// distance: the number of degrees to elapse on the encoders
// power: the power level the motors will be driven at
// dir: 1 for mLeft, -1 for mRight
void Turn(int distance, int power, int dir)
{
	nMotorEncoder[mLeft] = 0;
	nMotorEncoder[mRight] = 0;

	while(abs(nMotorEncoder[mRight]) < distance)
	{
		motor[mLeft] = power*dir;
		motor[mRight] = -power*dir;
	}
	motor[mLeft] = 0;
	motor[mRight] = 0;
}

// Turn based on encoders
// Compensates for a weaker mRight side of the drive train.
// distance: the number of degrees to elapse on the encoders
// power: the power level the motors will be driven at
// dir: 1 for mLeft, -1 for mRight
void ModTurn(int distance, int power, int dir)
{
	nMotorEncoder[mLeft] = 0;
	nMotorEncoder[mRight] = 0;

	while(abs(nMotorEncoder[mRight]) < distance)
	{
		motor[mLeft] = power*dir + 20 * dir;
		motor[mRight] = -power*dir;
	}
	motor[mLeft] = 0;
	motor[mRight] = 0;
}

//Miscellaneous methods

// Allows us to pick our choice of autonomous program.
// Uses a GUI and the NXT buttons.
int picker()
{
	while(true)
	{
		wait1Msec(500);
		int x = 1;
		int y = 0;
		if(y == 0)
		{
			while(nNxtButtonPressed != 3)
			{
				nxtDisplayCenteredTextLine(2,"Hello There! This is the Autonomous Chooser.");
			 	nxtDisplayCenteredBigTextLine(4,"Please pick the beacon you would like to go to.");
	   	}
	   	while(nNxtButtonPressed == 3) {}
	   	eraseDisplay();
	   	wait1Msec(500);
	   	y++;
	 	}
	  while (y > 0)
	  {
			nxtDisplayCenteredTextLine(2,"%d",x);
			if(nNxtButtonPressed == 1)
			{
				wait1Msec(500);
				if(x == 4)
					{x=1;}
				else
		 			{x++;}
			}
			else if(nNxtButtonPressed == 2)
			{
				wait1Msec(500);
				if(x == 1)
					{x=4;}
				else
		 			{x--;}
			}
			else if(nNxtButtonPressed == 3)
			{
				wait1Msec(500);
		 		return x;
			}
			eraseDisplay();
		}
	}
	eraseDisplay();
	nxtDisplayCenteredTextLine(2, "Oh my. Why did we get here? Something went wrong.");
	wait1Msec(100);
	return 1;

}

// allows us to pick the time we wait before our autonomous program starts.
void selectTime()
{
	while(!timeSelected)
	{
		nxtDisplayCenteredTextLine(2, "Time: %2.1f", (waitTime));
		if (nNxtButtonPressed == 1)
		{
			wait1Msec(500);
			PlaySound(soundBlip);
			waitTime += 2.5;
		}
		else if (nNxtButtonPressed == 2)
		{
			wait1Msec(500);
			PlaySound(soundBlip);
			waitTime -= 2.5;
		}
		if (waitTime > 15)
		{
			waitTime = 15;
		}
		else if (waitTime < 0)
		{
			waitTime = 0;
		}
		if(nNxtButtonPressed == 3)
		{
			wait1Msec(500);
			timeSelected = true;
		}
	}
}

// allows us to pick if we want WaitForStart method to run.
void startSelect()
{
	while(!startSelected)
	{
		nxtDisplayCenteredTextLine(2, "WaitForStart? %s", wait);
		if (nNxtButtonPressed == 1)
		{
			wait1Msec(500);
			PlaySound(soundBlip);
			wait = "Yes";
			waitSelected = true;
		}
		else if (nNxtButtonPressed == 2)
		{
			wait1Msec(500);
			PlaySound(soundBlip);
			wait = "No";
			waitSelected = false;
		}
		if(nNxtButtonPressed == 3)
		{
			wait1Msec(500);
			startSelected = true;
		}
	}
}

//// The encoder distance width of the ramp
//// This is used in functions such as straightRamp().
//#define RAMP_DIST 1600

//// The minimum motor power value of the ramp
//// The motors start at this power when the robot has not yet moved and
//// when the robot is finishing its movement.
//// This must be powerful enough to overcome inertia and move the robot.
//// This is used in functions such as straightRamp().
//#define RAMP_MIN 25

//// Moves the robot straight for the given encoder distance, ramping up and down to reduce skipping
//// Ramp up based on encoder distance, going from 25% to 100% over the first 1600 degrees.
//// Ramp down based on encoder distance, going from 25% to 0% over the last 1600 degrees.
//// Ramps are cut off at the given power, without changing the ramp slope; in other words,
//// the lower the power, the shorter the ramp time.
//// dist: The encoder distance which the robot will move. Must be positive.
//// power: The maximum motor power at which the robot will move. May be negative to go backwards.
//void straightRamp(int dist, int power)
//{
//  int encVal = nMotorEncoder[mRight] = 0; // reset the encoder

//  while (encVal < dist) { // loop while the robot has not yet traversed the given distance
//    float mStart = (float)(100 - RAMP_MIN) / RAMP_DIST; // calculate the slope of the starting ramp
//    int rampStart = mStart * encVal + RAMP_MIN; // calculate the power value of the starting ramp

//    float mEnd = (float)(100 - RAMP_MIN) / (- RAMP_DIST); // calculate the slope of the ending ramp
//    int rampEnd = m * (encVal - dist) + RAMP_MIN; // calculate the power value of the ending ramp

//    if (rampStart < power) power = rampStart; // find the minimum power value between the given power and the starting ramp
//    if (rampEnd < power) power = rampEnd; // find the minimum power value between the given power and the ending ramp

//    motor[mLeft] = motor[mRight] = power; // set the drive motors to the final calculated power value

//    wait10Msec(1); // wait 10 msecs to allow the robot to move a bit before repeating
//    encVal = abs(nMotorEncoder[mRight]); // get the current traversed distance on the encoder
//  }

//  motor[mLeft] = motor[mRight] = 0; // halt both drive motors now that we're done
//}

//// Moves the robot straight for the given encoder distance, ramping up and down to reduce skipping
//// Ramp up based on encoder distance, going from 25% to 100% over the first 1600 degrees.
//// Ramp down based on encoder distance, going from 25% to 0% over the last 1600 degrees.
//// Ramps are cut off at the given power, without changing the ramp slope; in other words,
//// the lower the power, the shorter the ramp time.
//// dist: The encoder distance which the robot will move. Must be positive.
//// power: The maximum motor power at which the robot will move. Must be positive.
//// dir: The direction, mLeft or mRight.
//void turnRamp(int dist, int power, int dir)
//{
//  power *= dir; // incorporate the turning direction into the power

//  int encVal = nMotorEncoder[mRight] = 0; // reset the encoder

//  while (encVal < dist) { // loop while the robot has not yet traversed the given distance
//    float mStart = (float)(100 - RAMP_MIN) / RAMP_DIST; // calculate the slope of the starting ramp
//    int rampStart = mStart * encVal + RAMP_MIN; // calculate the power value of the starting ramp

//    float mEnd = (float)(100 - RAMP_MIN) / (- RAMP_DIST); // calculate the slope of the ending ramp
//    int rampEnd = m * (encVal - dist) + RAMP_MIN; // calculate the power value of the ending ramp

//    if (rampStart < power) power = rampStart; // find the minimum power value between the given power and the starting ramp
//    if (rampEnd < power) power = rampEnd; // find the minimum power value between the given power and the ending ramp

//    motor[mLeft] = - (motor[mRight] = power); // set the drive motors to the final calculated power value

//    wait10Msec(1); // wait 10 msecs to allow the robot to move a bit before repeating
//    encVal = abs(nMotorEncoder[mRight]); // get the current traversed distance on the encoder
//  }

//  motor[mLeft] = motor[mRight] = 0; // halt both drive motors now that we're done
//}
