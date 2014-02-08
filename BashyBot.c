#pragma #allday #yolo
/** hand-made by yo face **/

#define LEFT 1
#define RIGHT -1

// set the left side of the drive motors
int left(int power)
{
  return motor[mLeft] = motor[mLeft2] = power;
}

// set the right side of the drive motors
int right(int power)
{
  return motor[mRight] = motor[mRight2] = power;
}

// Moves the robot straight like a heterosexual potato
void move(int power)
{
  left(right(power));
}

// Moves the robot not-straight like a bisexual potato
// dir: use the constants LEFT and RIGHT
void turn(int power, int dir)
{
  left(- right(power * dir));
}

// Party like a plantsexual walrus in the USSR
// Ask the paddies for tips
// they and their friend with plant-based sexuality, Ian, can tell you a lot
task main()
{
  waitForStart();


}
