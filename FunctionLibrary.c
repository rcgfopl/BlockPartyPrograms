#include "drivers/hitechnic-sensormux.h"
#include "drivers/lego-ultrasound.h"


//various methods to move forward.

void Forward(int distance, int power)
{
	nMotorEncoder[Left] = 0;
	nMotorEncoder[Right] = 0;

	while((nMotorEncoder[Right]) < distance)
	{
		motor[Left] = power;
		motor[Right] = power;
	}
  	motor[Left] = 0;
	motor[Right] = 0;
}

void ForwardWithSonar(int distance, int power)
{
	nMotorEncoder[Left] = 0;
	nMotorEncoder[Right] = 0;

	while((nMotorEncoder[Right]) < distance)
  {
		int value = SensorValue[Ultra];
		if((value>=255 || value<0))
		{
			motor[Left] = power;
			motor[Right] = power;
		}
	}
	motor[Left] = 0;
	motor[Right] = 0;
}

void ForwardWithTwoSonar(int distance, int power)
{
	nMotorEncoder[Left] = 0;
	nMotorEncoder[Right] = 0;

	while((nMotorEncoder[Right]) < distance)
  {
		int value  = USreadDist(Ultra);
		int value2 = USreadDist(Ultra2);
		if((value>=255 || value<0) || (value2>=255 || value<0))
		{
			motor[Left] = power;
			motor[Right] = power;
		}
	}
	motor[Left] = 0;
	motor[Right] = 0;
}

void ForwardWithTimeUS(int time, int power)
{
	unsigned long endTime = nPgmTime + time;
	while(nPgmTime < endTime)
	{
		int leftUS = USreadDist (Ultra);
		int rightUS = USreadDist (Ultra2);
		if ((leftUS > 0 && leftUS < 255) || (rightUS > 0 && rightUS < 255))
		{
				motor[Right] = 0;
				motor[Left] = 0;
		}
		else
		{
				motor[Right] = power;
				motor[Left] = power;
		}
	}
	motor[Right] = 0;
	motor[Left] = 0;
}

void ForwardWithTime(int time, int power)
{
	unsigned long endTime = nPgmTime + time;
	while(nPgmTime < endTime)
	{
				motor[Right] = power;
				motor[Left] = power;
	}
	motor[Right] = 0;
	motor[Left] = 0;
}

void ForwardWithModTime(int time, int power)
{
	unsigned long endTime = nPgmTime + time;
	while(nPgmTime < endTime)
	{
				motor[Right] = power + 15;
				motor[Left] = power;
	}
	motor[Right] = 0;
	motor[Left] = 0;
}

void ModForward(int distance, int power)
{
	nMotorEncoder[Left] = 0;
	nMotorEncoder[Right] = 0;

	while((nMotorEncoder[Right]) < distance)
	{
		motor[Left] = power + 25;
		motor[Right] = power;
	}
  	motor[Left] = 0;
	motor[Right] = 0;
}
//void ForwardWithTwoTime(int time, int power)
//{
//	unsigned long endTime = nPgmTime + time;
//	while(nPgmTime < endTime)
//	{
//				motor[Right] = power;
//				motor[Right2] = power;
//				motor[Left] = power;
//				motor[Left2] = power;
//	}
//	motor[Left] = 0;
//	motor[Right2] = 0;
//	motor[Right] = 0;
//	motor[Left2] = 0;
//}

//various methods to move backwards.

void Backward(int distance, int power)
{
	nMotorEncoder[Left] = 0;
	nMotorEncoder[Right] = 0;

	while((nMotorEncoder[Right] )> -distance)
	{
		motor[Left] = -power;
		motor[Right] = -power;
	}
	motor[Left] = 0;
	motor[Right] = 0;
}

void BackwardWithSonar(int distance, int power)
{
	nMotorEncoder[Left] = 0;
	nMotorEncoder[Right] = 0;

	while((nMotorEncoder[Right] )> -distance)
	{
		int value = SensorValue[Ultra];
		if(value>=255 || value<0)
		{
			motor[Left] = -power;
			motor[Right] = -power;
		}
	}
	motor[Left] = 0;
	motor[Right] = 0;
}

void BackwardWithTwoSonar(int distance, int power)
{
	nMotorEncoder[Left] = 0;
	nMotorEncoder[Right] = 0;

	while((nMotorEncoder[Right]) < distance)
  {
		int value  = USreadDist(Ultra);
		int value2 = USreadDist(Ultra2);
		if((value>=255 || value<0) || (value2>=255 || value<0))
		{
			motor[Left] = -power;
			motor[Right] = -power;
		}
	}
	motor[Left] = 0;
	motor[Right] = 0;
}

void BackwardWithTimeUS(int time, int power)
{
	unsigned long endTime = nPgmTime + time;
	while(nPgmTime < endTime)
	{
		int leftUS = USreadDist (Ultra);
		int rightUS = USreadDist (Ultra2);
		if ((leftUS > 0 || leftUS < 255) || (rightUS > 0 || rightUS < 255))
		{
				motor[Right] = -power;
				motor[Left] = -power;
		}
		else
		{
				motor[Right] = -power;
				motor[Left] = -power;
		}
	}
	motor[Right] = 0;
	motor[Left] = 0;
}

void BackwardWithTime(int time, int power)
{
	unsigned long endTime = nPgmTime + time;
	while(nPgmTime < endTime)
	{
				motor[Right] = -power;
				motor[Left] = -power;
	}
	motor[Right] = 0;
	motor[Left] = 0;
}

void BackwardWithModTime(int time, int power)
{
	unsigned long endTime = nPgmTime + time;
	while(nPgmTime < endTime)
	{
				motor[Right] = -power - 15;
				motor[Left] = -power;
	}
	motor[Right] = 0;
	motor[Left] = 0;
}

void ModBackward(int distance, int power)
{
	nMotorEncoder[Left] = 0;
	nMotorEncoder[Right] = 0;

	while((nMotorEncoder[Right] )> -distance)
	{
		motor[Left] = -power-25;
		motor[Right] = -power;
	}
	motor[Left] = 0;
	motor[Right] = 0;
}

//void BackwardWithTwoTime(int time, int power)
//{
//	unsigned long endTime = nPgmTime + time;
//	while(nPgmTime < endTime)
//	{
//				motor[Right] = -power;
//				motor[Right2] = -power;
//				motor[Left] = -power;
//				motor[Left2] = -power;
//	}
//	motor[Left] = 0;
//	motor[Right2] = 0;
//	motor[Right] = 0;
//	motor[Left2] = 0;
//}

//a couple methods to turn.

void Turn(int distance, int power, int dir)
{
	nMotorEncoder[Left] = 0;
	nMotorEncoder[Right] = 0;

	while(abs(nMotorEncoder[Right]) < distance)
	{
		motor[Left] = power*dir;
		motor[Right] = -power*dir;
	}
	motor[Left] = 0;
	motor[Right] = 0;
}

void ModTurn(int distance, int power, int dir)
{
	nMotorEncoder[Left] = 0;
	nMotorEncoder[Right] = 0;

	while(abs(nMotorEncoder[Right]) < distance)
	{
		motor[Left] = power*dir + 20 * dir;
		motor[Right] = -power*dir;
	}
	motor[Left] = 0;
	motor[Right] = 0;
}

//Miscellaneous methods

int picker() //allows us to pick our choice of autonomous program.
{
	int x = 1;
	int y = 0;
	if(y == 0)
	{
		while(nNxtButtonPressed != 3)
		{
			nxtDisplayCenteredTextLine(2,"Hello There! This is the Autonomous Chooser.");
		 	nxtDisplayCenteredBigTextLine(4,"Please pick the autonomous program number you would like to run.");
   	}
   	while(nNxtButtonPressed == 3) {}
   	eraseDisplay();
   	y++;
 	}
  if (y == 1)
  {
			nxtDisplayCenteredTextLine(5,"%d",x);
		if(nNxtButtonPressed == 1)
		{
			if(x == 4)
				{x=1;}
			else
	 			{x++;}
		}
		else if(nNxtButtonPressed == 2)
		{
			if(x == 1)
				{x=4;}
			else
	 			{x--;}
		}
		else if(nNxtButtonPressed == 3)
		{
	 		return x;
		}
		eraseDisplay();
	}
	eraseDisplay();
	nxtDisplayCenteredTextLine(4, "Oh my. Why did we get here? Something went wrong.");
	wait1Msec(100);
	return 1;

}

void selectTime() //allows us to pick the time we wait before our autonomous program starts.
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


void startSelect() //allows us to pick if we want WaitForStart method to run.
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
