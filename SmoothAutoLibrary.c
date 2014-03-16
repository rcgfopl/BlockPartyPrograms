#define FrontVal 8800

void counter()
{
	if(nNxtButtonPressed == 1)
	{
		PlaySound(soundBlip);
		wait1Msec(500);
		if(programCounter == max)
		{
			programCounter = 1;
		}
		else
		{
			programCounter++;
		}
	}
	else if(nNxtButtonPressed == 2)
	{
		PlaySound(soundBlip);
		wait1Msec(500);
		if(programCounter == 1)
		{
			programCounter = max;
		}
		else
		{
			programCounter--;
		}
	}
}

void AutoNoStop_F()
{
	int distance=0;
	int add=0;
	nMotorEncoder[mRight] = 0;

	while(SensorValue(IR) != 5)
	{
		motor[mLeft] = 30;
		motor[mRight] = 30;
	}
	motor[mLeft] = 0;
	motor[mRight] = 0;
	wait1Msec(500);
	distance = nMotorEncoder[mRight];
	if(abs(distance) <= 5000)
	{
			add = 300;
	}
	else
	{
			add = -200;
	}
  if(add > 0)
  {
		Forward(add, 30);
  }
  else
  {
  	Backward(abs(add), 30);
  }
	wait1Msec(500);

	servo[AutoHook] = 0;
	wait1Msec(1000);
	servo[AutoHook] = 250;
	wait1Msec(500);

	if(abs(distance) <= 5000)
	{
		Backward(abs(distance) + add, 30);
		wait1Msec(500);

		Turn(1640, 100, right);
		motor[mRight] = 0;
		motor[mLeft] = 0;
		wait1Msec(500);

		//goes backwards and towards the ramp
		Backward(4000,50);
		motor[mRight] = 0;
		motor[mLeft] = 0;
		wait1Msec(500);

		//turns towards the ramp
		Turn(1900, 100, right);
		motor[mRight] = 0;
		motor[mLeft] = 0;
		wait1Msec(500);

		//goes onto the ramp
		Backward(4500,100);
	}
	else
	{
		Forward(FrontVal - abs(distance) - add, 30);

		//turns to be parallel to the ramp
		Turn(1800, 100, right);
		motor[mRight] = 0;
		motor[mLeft] = 0;
		wait1Msec(500);

		//goes backwards and towards the ramp
		Backward(3900,50);
		motor[mRight] = 0;
		motor[mLeft] = 0;
		wait1Msec(500);

		//turns towards the ramp
		Turn(1850,100,left);
		motor[mRight] = 0;
		motor[mLeft] = 0;
		wait1Msec(500);

		//goes onto the ramp
		Backward(4500,100);
	}
}

void AutoNSF_Front()
{
	int distance=0;
	int add=0;
	nMotorEncoder[mRight] = 0;

	while(SensorValue(IR) != 5)
	{
		motor[mLeft] = 30;
		motor[mRight] = 30;
	}
	motor[mLeft] = 0;
	motor[mRight] = 0;
	wait1Msec(500);
	distance = nMotorEncoder[mRight];
	if(abs(distance) <= 5000)
	{
			add = 300;
	}
	else
	{
			add = -200;
	}
  if(add > 0)
  {
		Forward(add, 30);
  }
  else
  {
  	Backward(abs(add), 30);
  }
	wait1Msec(500);

	servo[AutoHook] = 0;
	wait1Msec(1000);
	servo[AutoHook] = 250;
	wait1Msec(500);

	Forward(FrontVal - abs(distance) - add, 30);

	//turns to be parallel to the ramp
	Turn(1800, 100, right);
	motor[mRight] = 0;
	motor[mLeft] = 0;
	wait1Msec(500);

	//goes backwards and towards the ramp
	Backward(3900,50);
	motor[mRight] = 0;
	motor[mLeft] = 0;
	wait1Msec(500);

	//turns towards the ramp
	Turn(2200,100,left);
	motor[mRight] = 0;
	motor[mLeft] = 0;
	wait1Msec(500);

	//goes onto the ramp
	Backward(4500,100);
}

void AutoNSF_Back()
{
	int distance=0;
	int add=0;
	nMotorEncoder[mRight] = 0;

	while(SensorValue(IR) != 5)
	{
		motor[mLeft] = 30;
		motor[mRight] = 30;
	}
	motor[mLeft] = 0;
	motor[mRight] = 0;
	wait1Msec(500);
	distance = nMotorEncoder[mRight];
	if(abs(distance) <= 5000)
	{
			add = 300;
	}
	else
	{
			add = -200;
	}
  if(add > 0)
  {
		Forward(add, 30);
  }
  else
  {
  	Backward(abs(add), 30);
  }
	wait1Msec(500);

	servo[AutoHook] = 0;
	wait1Msec(1000);
	servo[AutoHook] = 250;
	wait1Msec(500);

	Backward(abs(distance) + add, 30);
	wait1Msec(500);

	Turn(1640, 100, right);
	motor[mRight] = 0;
	motor[mLeft] = 0;
	wait1Msec(500);

	//goes backwards and towards the ramp
	Backward(4000,50);
	motor[mRight] = 0;
	motor[mLeft] = 0;
	wait1Msec(500);

	//turns towards the ramp
	Turn(1900, 100, right);
	motor[mRight] = 0;
	motor[mLeft] = 0;
	wait1Msec(500);

	//goes onto the ramp
	Backward(4500,100);
}

void AutoNoStop_B()
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

	if(abs(distance) <= 3500)
	{
		Forward(abs(distance) + add, 30);
		wait1Msec(500);

		Turn(1800, 100, left);
		motor[mRight] = 0;
		motor[mLeft] = 0;
		wait1Msec(500);

		//goes backwards and towards the ramp
		Forward(4000,50);
		motor[mRight] = 0;
		motor[mLeft] = 0;
		wait1Msec(500);

		//turns towards the ramp
		Turn(1900, 100, left);
		motor[mRight] = 0;
		motor[mLeft] = 0;
		wait1Msec(500);

		//goes onto the ramp
		Forward(4500,100);
	}
	else
	{
		Backward(FrontVal - abs(distance) - add, 30);

		//turns to be parallel to the ramp
		Turn(1800, 100, left);
		motor[mRight] = 0;
		motor[mLeft] = 0;
		wait1Msec(500);

		//goes backwards and towards the ramp
		Forward(3900,50);
		motor[mRight] = 0;
		motor[mLeft] = 0;
		wait1Msec(500);

		//turns towards the ramp
		Turn(2200,100,right);
		motor[mRight] = 0;
		motor[mLeft] = 0;
		wait1Msec(500);

		//goes onto the ramp
		Forward(4500,100);
	}
}

void AutoNSB_Front()
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

	Forward(abs(distance) + add, 30);
	wait1Msec(500);

	Turn(1800, 100, left);
	motor[mRight] = 0;
	motor[mLeft] = 0;
	wait1Msec(500);

	//goes backwards and towards the ramp
	Forward(4000,50);
	motor[mRight] = 0;
	motor[mLeft] = 0;
	wait1Msec(500);

	//turns towards the ramp
	Turn(1900, 100, left);
	motor[mRight] = 0;
	motor[mLeft] = 0;
	wait1Msec(500);

	//goes onto the ramp
	Forward(4500,100);
}

void AutoNSB_Back()
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
	Turn(1850,100,right);
	motor[mRight] = 0;
	motor[mLeft] = 0;
	wait1Msec(500);

	//goes onto the ramp
	Forward(4500,100);
}
