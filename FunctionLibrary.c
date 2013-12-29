#include "drivers/hitechnic-sensormux.h"

#include "drivers/lego-ultrasound.h"

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

int picker()
{
	int x = 1;
	int y = 0;
	if(y == 0)
	{
		while(nNxtButtonPressed != 3)
		{
			nxtDisplayCenteredTextLine(3,"Hello There! This is the Autonomous Chooser.");
		 	nxtDisplayCenteredTextLine(4,"Please pick the autonomous program number you would like to run.");
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
			if(x == 5)
				{x=1;}
			else
	 			{x++;}
		}
		else if(nNxtButtonPressed == 2)
		{
			if(x == 1)
				{x=5;}
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
	return -1;

}

void ForwardWithTimeUS(int time, int power)
{
	unsigned long endTime = nPgmTime + time;
	while(nPgmTime < endTime)
	{
		int leftUS = USreadDist (Ultra);
		int rightUS = USreadDist (Ultra2);
		if ((leftUS > 0 || leftUS < 255) || (rightUS > 0 || rightUS < 255))
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
//void selectTime()
//{
//	while(!timeSelected)
//	{
//		nxtDisplayCenteredTextLine(2, "Time: %.1f", (waitTime));
//		if (nNxtButtonPressed == 1)
//		{
//			wait1Msec(500);
//			PlaySound(soundBlip);
//			waitTime += 2.5;
//		}
//		else if (nNxtButtonPressed == 2)
//		{
//			wait1Msec(500);
//			PlaySound(soundBlip);
//			waitTime -= 2.5;
//		}
//		if (waitTime > 10)
//		{
//			waitTime = 10;
//		}
//		else if (waitTime < 0)
//		{
//			waitTime = 0;
//		}
//		if(nNxtButtonPressed == 3)
//		{
//			wait1Msec(500);
//			timeSelected = true;
//		}
//	}
//}


//void startSelect()
//{
//	while(!startSelected)
//	{
//		nxtDisplayCenteredTextLine(2, "WaitForStart? %s", wait);
//		if (nNxtButtonPressed == 1)
//		{
//			wait1Msec(500);
//			PlaySound(soundBlip);
//			wait = "Yes";
//			waitSelected = true;
//		}
//		else if (nNxtButtonPressed == 2)
//		{
//			wait1Msec(500);
//			PlaySound(soundBlip);
//			wait = "No";
//			waitSelected = false;
//		}
//		if(nNxtButtonPressed == 3)
//		{
//			wait1Msec(500);
//			startSelected = true;
//		}
//	}
//}
