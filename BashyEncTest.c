#todo pragmas

// Power the left side of the drive train
int left(int power)
{
  return power;
}

// Power the right side of the drive train
int right(int power)
{
  return motor[Right] = power;
}

// The encoder distance width of the ramp
// This is used in functions such as straightRamp().
#define RAMP_DIST 1600

// The minimum motor power value of the ramp
// The motors start at this power when the robot has not yet moved and
// when the robot is finishing its movement.
// This must be powerful enough to overcome inertia and move the robot.
// This is used in functions such as straightRamp().
#define RAMP_MIN 25

// Moves the robot straight for the given encoder distance, ramping up and down to reduce skipping
// Ramp up based on encoder distance, going from 25% to 100% over the first 1600 degrees.
// Ramp down based on encoder distance, going from 25% to 0% over the last 1600 degrees.
// Ramps are cut off at the given power, without changing the ramp slope; in other words,
// the lower the power, the shorter the ramp time.
// dist: The encoder distance which the robot will move. Must be positive.
// power: The maximum motor power at which the robot will move. May be negative to go backwards.
void straightRamp(int dist, int power)
{
  int encVal = nMotorEncoder[Right] = 0; // reset the encoder

  while (encVal < dist) { // loop while the robot has not yet traversed the given distance
    float mStart = (float)(100 - RAMP_MIN) / RAMP_DIST; // calculate the slope of the starting ramp
    int rampStart = mStart * encVal + RAMP_MIN; // calculate the power value of the starting ramp

    float mEnd = (float)(100 - RAMP_MIN) / (- RAMP_DIST); // calculate the slope of the ending ramp
    int rampEnd = m * (encVal - dist) + RAMP_MIN; // calculate the power value of the ending ramp

    if (rampStart < power) power = rampStart; // find the minimum power value between the given power and the starting ramp
    if (rampEnd < power) power = rampEnd; // find the minimum power value between the given power and the ending ramp

    left(right(power));

    wait10Msec(1); // wait 10 msecs to allow the robot to move a bit before repeating
    encVal = abs(nMotorEncoder[Right]); // get the current traversed distance on the encoder
  }

  left(right(0));
}

// Moves the robot straight for the given encoder distance, ramping up and down to reduce skipping
// Ramp up based on encoder distance, going from 25% to 100% over the first 1600 degrees.
// Ramp down based on encoder distance, going from 25% to 0% over the last 1600 degrees.
// Ramps are cut off at the given power, without changing the ramp slope; in other words,
// the lower the power, the shorter the ramp time.
// dist: The encoder distance which the robot will move. Must be positive.
// power: The maximum motor power at which the robot will move. Must be positive.
// dir: The direction, left or right. 
void turnRamp(int dist, int power, int dir)
{
  power *= dir; // incorporate the turning direction into the power

  int encVal = nMotorEncoder[Right] = 0; // reset the encoder

  while (encVal < dist) { // loop while the robot has not yet traversed the given distance
    float mStart = (float)(100 - RAMP_MIN) / RAMP_DIST; // calculate the slope of the starting ramp
    int rampStart = mStart * encVal + RAMP_MIN; // calculate the power value of the starting ramp

    float mEnd = (float)(100 - RAMP_MIN) / (- RAMP_DIST); // calculate the slope of the ending ramp
    int rampEnd = m * (encVal - dist) + RAMP_MIN; // calculate the power value of the ending ramp

    if (rampStart < power) power = rampStart; // find the minimum power value between the given power and the starting ramp
    if (rampEnd < power) power = rampEnd; // find the minimum power value between the given power and the ending ramp

    left(- right(power));

    wait10Msec(1); // wait 10 msecs to allow the robot to move a bit before repeating
    encVal = abs(nMotorEncoder[Right]); // get the current traversed distance on the encoder
  }

  left(right(0));
}

task main()
{
  straightRamp(2000, 100);
}
