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
