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

void Auto_Encoder()
{
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
				Forward(2600,35);
				motor[mRight] = 0;
				motor[mLeft] = 0;
				wait1Msec(1000);
			}
			else if(beacon == 1)
			{
				//the distance to get to the second beacon
				Forward(700,35);
				motor[mRight] = 0;
				motor[mLeft] = 0;
				wait1Msec(1000);
			}
			else if(beacon == 2)
			{
				//the distance to get to the third beacon
				Forward(2100,35);
				motor[mRight] = 0;
				motor[mLeft] = 0;
				wait1Msec(1000);
			}
			else if(beacon == 3)
			{
				//the distance to get to the fourth beacon
				Forward(600,35);
				motor[mRight] = 0;
				motor[mLeft] = 0;
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
	if(beacon == 1) //beacon was on first box
	{
		//goes backwards from the box
		Backward(2160,50);
		motor[mRight] = 0;
		motor[mLeft] = 0;
		wait1Msec(500);

		//turns to be parallel to the ramp
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
	else if (beacon == 2) //beacon was on second box
	{
		//goes backwards from the box
		Backward(3400,50);
		motor[mRight] = 0;
		motor[mLeft] = 0;
		wait1Msec(500);

		//turns to be parallel to the ramp
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
		Turn(1600, 100, right);
		motor[mRight] = 0;
		motor[mLeft] = 0;
		wait1Msec(500);

		//goes onto the ramp
		Backward(4500,100);
	}
	else if (beacon == 3) //beacon was on third box
	{
		//goes forward from the box
		Forward(2700,50);
		motor[mRight] = 0;
		motor[mLeft] = 0;
		wait1Msec(500);

		//turns to be parallel to the ramp
		Turn(1840, 100, right);
		motor[mRight] = 0;
		motor[mLeft] = 0;
		wait1Msec(500);

		//goes backwards and towards the ramp
		Backward(4000,50);
		motor[mRight] = 0;
		motor[mLeft] = 0;
		wait1Msec(500);

		//turns towards the ramp
		Turn(2100,100,left);
		motor[mRight] = 0;
		motor[mLeft] = 0;
		wait1Msec(500);

		//goes onto the ramp
		Backward(4500,80);
	}
	else if (beacon == 4) //beacon was on fourth ring
	{
		//goes forward from the box
		Forward(1360,50);
		motor[mRight] = 0;
		motor[mLeft] = 0;
		wait1Msec(500);

		//turns to be parallel to the ramp
		Turn(1840, 100, right);
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
}

void Hardcoded_Autonomous()
{
	beacon = picker(); //assigns the beacon we want to go to to this value.
	if(beacon == 1) //going to the first beacon
	{
		//the distance to get to the first beacon
		Forward(2600,35);
		motor[mRight] = 0;
		motor[mLeft] = 0;
		wait1Msec(1000);
	}
	else if(beacon == 2) //going to the second beacon
	{
		//the distance to get to the second beacon
		Forward(3400,35);
		motor[mRight] = 0;
		motor[mLeft] = 0;
		wait1Msec(1000);
	}
	else if(beacon == 3) //going to the third beacon
	{
		//the distance to get to the third beacon
		Forward(5900,35);
		motor[mRight] = 0;
		motor[mLeft] = 0;
		wait1Msec(1000);
	}
	else if(beacon == 4) //going to the fourth beacon
	{
		//the distance to get to the fourth beacon
		Forward(6900,35);
		motor[mRight] = 0;
		motor[mLeft] = 0;
		wait1Msec(1000);
	}

	//code that runs after  we stop in front of a beacon.
	servo[AutoHook] = 255;	//dispenses the cube
	wait1Msec(900);
	servo[AutoHook] = 0;
	wait1Msec(1000);

	//pick where to  go based on beacon #.
	//if the robot is at rings 1 or 4, it turns, goes back, then turns to face the ramp.
	//if the robots is at rings 2 or 3, it goes backwards, turns, goes backwards again, and then turns to face the ramp.
	if(beacon == 1) //beacon was on first box
	{
		//goes backwards from the box
		Backward(2160,50);
		motor[mRight] = 0;
		motor[mLeft] = 0;
		wait1Msec(500);

		//turns to be parallel to the ramp
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
		Turn(1800, 100, right);
		motor[mRight] = 0;
		motor[mLeft] = 0;
		wait1Msec(500);

		//goes onto the ramp
		Backward(4500,100);
	}
	else if (beacon == 2) //beacon was on second box
	{
		//goes backwards from the box
		Backward(3400,50);
		motor[mRight] = 0;
		motor[mLeft] = 0;
		wait1Msec(500);

		//turns to be parallel to the ramp
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
		Turn(1600, 100, right);
		motor[mRight] = 0;
		motor[mLeft] = 0;
		wait1Msec(500);

		//goes onto the ramp
		Backward(4500,100);
	}
	else if (beacon == 3) //beacon was on third box
	{
		//goes forward from the box
		Forward(2700,50);
		motor[mRight] = 0;
		motor[mLeft] = 0;
		wait1Msec(500);

		//turns to be parallel to the ramp
		Turn(1840, 100, right);
		motor[mRight] = 0;
		motor[mLeft] = 0;
		wait1Msec(500);

		//goes backwards and towards the ramp
		Backward(4000,50);
		motor[mRight] = 0;
		motor[mLeft] = 0;
		wait1Msec(500);

		//turns towards the ramp
		Turn(2100,100,left);
		motor[mRight] = 0;
		motor[mLeft] = 0;
		wait1Msec(500);

		//goes onto the ramp
		Backward(4500,80);
	}
	else if (beacon == 4) //beacon was on fourth ring
	{
		//goes forward from the box
		Forward(1360,50);
		motor[mRight] = 0;
		motor[mLeft] = 0;
		wait1Msec(500);

		//turns to be parallel to the ramp
		Turn(1840, 100, right);
		motor[mRight] = 0;
		motor[mLeft] = 0;
		wait1Msec(500);

		//goes backwards and towards the ramp
		Backward(3900,50);
		motor[mRight] = 0;
		motor[mLeft] = 0;
		wait1Msec(500);

		//turns towards the ramp
		Turn(2000,100,left);
		motor[mRight] = 0;
		motor[mLeft] = 0;
		wait1Msec(500);

		//goes onto the ramp
		Backward(4500,100);
	}
}

void Auto_Front_Ramp()
{
	//holds which beacon the robot is at
	int beacon = 0;
	//holds the IR sensor value
	int i = 0;

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
				Forward(2600,35);
				motor[mRight] = 0;
				motor[mLeft] = 0;
				wait1Msec(1000);
			}
			else if(beacon == 1)
			{
				//the distance to get to the second beacon
				Forward(700,35);
				motor[mRight] = 0;
				motor[mLeft] = 0;
				wait1Msec(1000);
			}
			else if(beacon == 2)
			{
				//the distance to get to the third beacon
				Forward(2100,35);
				motor[mRight] = 0;
				motor[mLeft] = 0;
				wait1Msec(1000);
			}
			else if(beacon == 3)
			{
				//the distance to get to the fourth beacon
				Forward(600,35);
				motor[mRight] = 0;
				motor[mLeft] = 0;
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
	if(beacon == 1) //beacon was on first box
	{
		//goes forward from the box
		Forward(5600,50);
		motor[mRight] = 0;
		motor[mLeft] = 0;
		wait1Msec(500);

		//turns to be parallel to the ramp
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
		Turn(1900,100,left);
		motor[mRight] = 0;
		motor[mLeft] = 0;
		wait1Msec(500);

		//goes onto the ramp
		Backward(4500,80);
	}
	else if (beacon == 2) //beacon was on second box
	{
		//goes forward from the box
		Forward(4700,50);
		motor[mRight] = 0;
		motor[mLeft] = 0;
		wait1Msec(500);

		//turns to be parallel to the ramp
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
		Turn(1600,100,left);
		motor[mRight] = 0;
		motor[mLeft] = 0;
		wait1Msec(500);

		//goes onto the ramp
		Backward(4500,80);
	}
	else if (beacon == 3) //beacon was on third box
	{
		//goes forward from the box
		Forward(2700,50);
		motor[mRight] = 0;
		motor[mLeft] = 0;
		wait1Msec(500);

		//turns to be parallel to the ramp
		Turn(1840, 100, right);
		motor[mRight] = 0;
		motor[mLeft] = 0;
		wait1Msec(500);

		//goes backwards and towards the ramp
		Backward(4000,50);
		motor[mRight] = 0;
		motor[mLeft] = 0;
		wait1Msec(500);

		//turns towards the ramp
		Turn(2100,100,left);
		motor[mRight] = 0;
		motor[mLeft] = 0;
		wait1Msec(500);

		//goes onto the ramp
		Backward(4500,80);
	}
	else if (beacon == 4) //beacon was on fourth ring
	{
		//goes forward from the box
		Forward(1360,50);
		motor[mRight] = 0;
		motor[mLeft] = 0;
		wait1Msec(500);

		//turns to be parallel to the ramp
		Turn(1840, 100, right);
		motor[mRight] = 0;
		motor[mLeft] = 0;
		wait1Msec(500);

		//goes backwards and towards the ramp
		Backward(3900,50);
		motor[mRight] = 0;
		motor[mLeft] = 0;
		wait1Msec(500);

		//turns towards the ramp
		Turn(2000,100,left);
		motor[mRight] = 0;
		motor[mLeft] = 0;
		wait1Msec(500);

		//goes onto the ramp
		Backward(4500,100);
	}
}

void Auto_Back_Ramp()
{
	 //holds which beacon the robot is at
	int beacon = 0;
	//holds the IR sensor value
	int i = 0;

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
				Forward(2600,35);
				motor[mRight] = 0;
				motor[mLeft] = 0;
				wait1Msec(1000);
			}
			else if(beacon == 1)
			{
				//the distance to get to the second beacon
				Forward(700,35);
				motor[mRight] = 0;
				motor[mLeft] = 0;
				wait1Msec(1000);
			}
			else if(beacon == 2)
			{
				//the distance to get to the third beacon
				Forward(2100,35);
				motor[mRight] = 0;
				motor[mLeft] = 0;
				wait1Msec(1000);
			}
			else if(beacon == 3)
			{
				//the distance to get to the fourth beacon
				Forward(600,35);
				motor[mRight] = 0;
				motor[mLeft] = 0;
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
	if(beacon == 1) //beacon was on first box
	{
		//goes backwards from the box
		Backward(2660,50);
		motor[mRight] = 0;
		motor[mLeft] = 0;
		wait1Msec(500);

		//turns to be parallel to the ramp
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
	else if (beacon == 2) //beacon was on second box
	{
		//goes backwards from the box
		Backward(3900,50);
		motor[mRight] = 0;
		motor[mLeft] = 0;
		wait1Msec(500);

		//turns to be parallel to the ramp
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
	else if (beacon == 3) //beacon was on third box
	{
		//goes backwards from the box
		Backward(5600,50);
		motor[mRight] = 0;
		motor[mLeft] = 0;
		wait1Msec(500);

		//turns to be parallel to the ramp
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
	else if (beacon == 4) //beacon was on fourth ring
	{
		//goes backwards from the box
		Backward(6600,50);
		motor[mRight] = 0;
		motor[mLeft] = 0;
		wait1Msec(500);

		//turns to be parallel to the ramp
		Turn(1640, 100, right);
		motor[mRight] = 0;
		motor[mLeft] = 0;
		wait1Msec(500);

		//goes backwards and towards the ramp
		Backward(3900,50);
		motor[mRight] = 0;
		motor[mLeft] = 0;
		wait1Msec(500);

		//turns towards the ramp
		Turn(1600, 100, right);
		motor[mRight] = 0;
		motor[mLeft] = 0;
		wait1Msec(500);

		//goes onto the ramp
		Backward(4500,100);
	}
}

void Hardcoded_Reverse()
{
	//goes  in front  of box
	Backward(900,50);
  wait1Msec(500);

	//code that runs after we stop in front of the box.
	servo[AutoHook] = 255;	//dispenses the cube
	wait1Msec(900);
	servo[AutoHook] = 0;
	wait1Msec(1000);

	//goes forward from the box
	Forward(1360,50);
	motor[mRight] = 0;
	motor[mLeft] = 0;
	wait1Msec(500);

	//turns to be parallel to the ramp
	Turn(1840, 100, right);
	motor[mRight] = 0;
	motor[mLeft] = 0;
	wait1Msec(500);

	//goes backwards and towards the ramp
	Backward(3900,50);
	motor[mRight] = 0;
	motor[mLeft] = 0;
	wait1Msec(500);

	//turns towards the ramp
	Turn(2000,100,left);
	motor[mRight] = 0;
	motor[mLeft] = 0;
	wait1Msec(500);

	//goes onto the ramp
	Backward(4500,100);
}

void IR_Tester()
{
}

void Reverse_Autonomous()
{
}

void Reverse_Auto_Front_Ramp()
{
}

void Reverse_Auto_Back_Ramp()
{
}
