#pragma config(I2C_Usage, I2C1, i2cSensors)
#pragma config(Sensor, in1,    manipulator,    sensorPotentiometer)
#pragma config(Sensor, dgtl3,  hook,           sensorQuadEncoder)
#pragma config(Sensor, I2C_1,  bR,             sensorQuadEncoderOnI2CPort,    , AutoAssign)
#pragma config(Sensor, I2C_2,  bL,             sensorQuadEncoderOnI2CPort,    , AutoAssign)
#pragma config(Motor,  port1,           TM_Right,      tmotorVex393, openLoop)
#pragma config(Motor,  port2,           Front_Left,    tmotorVex393, openLoop, reversed)
#pragma config(Motor,  port3,           Back_Left,     tmotorVex393, openLoop, reversed, encoder, encoderPort, I2C_2, 1000)
#pragma config(Motor,  port4,           Back_Right,    tmotorVex393, openLoop, encoder, encoderPort, I2C_1, 1000)
#pragma config(Motor,  port5,           Front_Right,   tmotorVex393, openLoop)
#pragma config(Motor,  port6,           M_TopLeft,     tmotorVex393, openLoop)
#pragma config(Motor,  port7,           M_BottomLeft,  tmotorVex393, openLoop, reversed)
#pragma config(Motor,  port8,           M_TopRight,    tmotorVex393, openLoop)
#pragma config(Motor,  port9,           M_BottomRight, tmotorVex393, openLoop, reversed)
#pragma config(Motor,  port10,          TM_Left,       tmotorVex393, openLoop, reversed)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

//Note: Alex is dumb. You cannot put comments before the Declaration of Motor Independence >:|    ^^
//Version 1.5.0 Remember to change versions after every revision Brandon
#pragma platform(VEX)

//Competition Control and Duration Settings
#pragma competitionControl(Competition)
#pragma autonomousDuration(15)
#pragma userControlDuration(120)

#include "Vex_Competition_Includes.c"   //Main competition background code...do not modify!


/*
int x;

//Manipulator Settings
float arm1 = 1872;
float arm2 = 1713;
float arm3 = 1760;
float hook1;
float hook2;
float hook3;

//Autonomous Functions
void resetSensors()
{
	nMotorEncoder[Back_Right] = 0;
	nMotorEncoder[Back_Left] = 0;
}
void forward()
{
	motor[Back_Left] = 127;
	motor[Front_Left] = 127;
	motor[Back_Right] = 75;
	motor[Front_Right] = 75;
}
void stahp()
{
	motor[Back_Left] = 0;
	motor[Front_Left] = 0;
	motor[Back_Right] = 0;
	motor[Front_Right] = 0;
}
void forward(int distance)
{
	while (nMotorEncoder[Back_Right] < distance)
	{
		forward();
	}
	stahp();
}
void backward()
{
	motor[Back_Left] = -127;
	motor[Front_Left] = -127;
	motor[Back_Right] = -127;
	motor[Front_Right] = -127;
}
void backward(int distance)
{
	while (-nMotorEncoder[bL] > distance || nMotorEncoder[bR] > distance)
	{
		backward();
	}
	stahp();
}
void turnRight()
{
	motor[Back_Left] = 127;
	motor[Front_Left] = 127;
	motor[Back_Right] = -127;
	motor[Front_Right] = -127;
}
void turnRight(float time)
{
	motor[Back_Left] = 127;
	motor[Front_Left] = 127;
	motor[Back_Right] = -127;
	motor[Front_Right] = -127;
	wait1Msec(time/100);
	motor[Back_Left] = 0;
	motor[Front_Left] = 0;
	motor[Back_Right] = 0;
	motor[Front_Right] = 0;
}
void turnLeft()
{
	motor[Back_Left] = -127;
	motor[Front_Left] = -127;
	motor[Back_Right] = 127;
	motor[Front_Right] = 127;
}
void turnLeft(float time)
{
	motor[Back_Left] = -127;
	motor[Front_Left] = -127;
	motor[Back_Right] = 127;
	motor[Front_Right] = 127;
	wait1Msec(time/100);
	motor[Back_Left] = 0;
	motor[Front_Left] = 0;
	motor[Back_Right] = 0;
	motor[Front_Right] = 0;
}
void turnLeft90()
{
	turnLeft(insert 90 degree turn time 90);
}
void turnRight90()
{
	turnRight(insert 90 degree turn time 90);
}
void juan80()
{
	turnRight(insert 180 degree turn time 180);
}
void manipulatorUp()
{
	motor[M_BottomLeft] = 127;
	motor[M_BottomRight] = 127;
	motor[M_TopLeft] = 127;
	motor[M_TopRight] = 127;
}
void manipulatorDown()
{
	motor[M_BottomLeft] = -127;
	motor[M_BottomRight] = -127;
	motor[M_TopLeft] = -127;
	motor[M_TopRight] = -127;
}
void manipulatorStahp()
{
	motor[M_BottomLeft] = 0;
	motor[M_BottomRight] = 0;
	motor[M_TopLeft] = 0;
	motor[M_TopRight] = 0;
}
void manipulatorSet(float level)
{
	if (SensorValue(manipulator) > level)
	{
		while (SensorValue(manipulator) > level)
		{
			manipulatorDown();
		}
		manipulatorUp();
	}
	else if (SensorValue(manipulator) < level)
	{
		while (SensorValue(manipulator) < manipulator)
		{
			manipulatorUp();
		}
		manipulatorStahp();
	}
}
void hookUp(float hook)
{
	motor[TM_Left] = 127;
	motor[TM_Right] = 127;
}
void hookDown()
{
	motor[TM_Left] = -127;
	motor[TM_Right] = -127;
}
void hookStahp()
{
	motor[TM_Left] = 0;
	motor[TM_Right] = 0;
}
void hookSet(float level)
{
	if (SensorValue(hook) > level)
	{
		while (SensorValue(hook) > level)
		{
			motor[TM_Left] = -127;
			motor[TM_Right] = -127;
		}
		motor[TM_Left] = 0;
		motor[TM_Right] = 0;
	}
	else if (SensorValue(hook) < level)
	{
		while (SensorValue(hook) < hook)
		{
			motor[TM_Left] = 127;
			motor[TM_Right] = 127;
		}
		motor[TM_Left] = 0;
		motor[TM_Right] = 0;
	}

}

/*void danceParty()
{
	forward(3);
	turnLeft(1);
	backward(3);
	turnRight(5);
	forward(3);
	turnRight(1);
	backward(3);
	for (int z = 0; z < 10; z++)
	{
		turnRight(.1);
		turnLeft(.1);
	}
}
*/
void pre_auton()
{
  // Set bStopTasksBetweenModes to false if you want to keep user created tasks running between
  // Autonomous and Tele-Op modes. You will need to manage all user created tasks if set to false.
  bStopTasksBetweenModes = true;

	// All activities that occur before the competition starts
	// Example: clearing encoders, setting servo positions, ...
}

task autonomous()
{
	motor[port2] = 127;
	motor[port3] = 127;
	motor[port4] = 127;
	motor[port5] = 127;
	wait1Msec(650);
	motor[port2] = 0;
	motor[port3] = 0;
	motor[port4] = 0;
	motor[port5] = 0;
	wait1Msec(100);
	motor[port1] = 127;
	motor[port10] = 127;
	wait1Msec(800);
	motor[port2] = 123;
	motor[port3] = 123;
	motor[port4] = 73;
	motor[port5] = 73;
	motor[port1] = 0;
	motor[port10] = 0;
	wait1Msec(3800);
	motor[port2] = 0;
	motor[port3] = 0;
	motor[port4] = 0;
	motor[port5] = 0;
	motor[port6] = 127;
	motor[port7] = 127;
	motor[port8] = 127;
	motor[port9] = 127;
	wait1Msec(2200);
	motor[port6] = 30;
	motor[port7] = 30;
	motor[port8] = 30;
	motor[port9] = 30;
	motor[port2] = 127;
	motor[port3] = 127;
	motor[port4] = 127;
	motor[port5] = 127;
	wait1Msec(300);
	motor[port2] = 0;
	motor[port3] = 0;
	motor[port4] = 0;
	motor[port5] = 0;
	wait1Msec(100);
	motor[port6] = 0;
	motor[port7] = 0;
	motor[port8] = 0;
	motor[port9] = 0;
	motor[port1] = -80;
	motor[port10] = -80;
	wait1Msec(2000);
	motor[port1] = 0;
	motor[port10] = 0;
	motor[port2] = -100;
	motor[port3] = -100;
	motor[port4] = -100;
	motor[port5] = -100;
	wait1Msec(1000);
	motor[port2] = 0;
	motor[port3] = 0;
	motor[port4] = 0;
	motor[port5] = 0;

	/*resetSensors();
	forward();
	wait1Msec(300);
	stahp();
	hookUp();
	wait1Msec(300);
	hookStahp();
	forward();
	wait1Msec(5700);
	stahp();
	manipulatorSet(arm3);
	hookDown();
	wait1Msec(1000);
	hookStahp();*/
}

task usercontrol()
{
	// User control code here, inside the loop

	//resetSensors();
	while (true)
	{

	if (vexRT[Ch3] > 25 || vexRT[Ch3] < -25)
	{
		motor[Back_Left] = vexRT[Ch3];
		motor[Front_Left] = vexRT[Ch3];
	}else{
		motor[Back_Left] = 0;
		motor[Front_Left] = 0;
	}
	if (vexRT[Ch2] > 25 || vexRT[Ch2] < -25)
	{
		motor[Back_Right] = vexRT[Ch2];
		motor[Front_Right] = vexRT[Ch2];
	}else{
		motor[Back_Right] = 0;
		motor[Front_Right] = 0;
	}

		motor[M_BottomLeft] = vexRT[Ch3Xmtr2];
		motor[M_TopLeft] = vexRT[Ch3Xmtr2];
		motor[M_BottomRight] = vexRT[Ch3Xmtr2];
		motor[M_TopRight] = vexRT[Ch3Xmtr2];

		motor[TM_Right] = vexRT[Ch2Xmtr2];
		motor[TM_Left] = vexRT[Ch2Xmtr2];
	}
}
