void Forward(int distance, int power)
{
	nMotorEncoder[mLeft] = 0;
	nMotorEncoder[mRight] = 0;

	while((nMotorEncoder[mLeft] + nMotorEncoder[mRight])/2 < distance)
	{
		motor[mLeft] = power;
		motor[mRight] = power;
	}
}

void Backward(int distance, int power)
{
	nMotorEncoder[mLeft] = 0;
	nMotorEncoder[mRight] = 0;

	while((nMotorEncoder[mLeft] + nMotorEncoder[mRight])/2 > -distance)
	{
		motor[mLeft] = -power;
		motor[mRight] = -power;
	}
}

void Turn(int distance, int power, int dir)
{
	nMotorEncoder[mLeft] = 0;
	nMotorEncoder[mRight] = 0;

	while(abs(nMotorEncoder[mLeft] + nMotorEncoder[mRight])/2 < distance)
	{
		motor[mLeft] = power*dir;
		motor[mRight] = -power*dir;
	}
}
