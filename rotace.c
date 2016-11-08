#pragma config(Sensor, S1,     Touch,          sensorEV3_Touch)
#pragma config(Sensor, S2,     Gyro,           sensorEV3_Gyro)
#pragma config(Sensor, S3,     Ultrasonic,     sensorEV3_Ultrasonic)
#pragma config(Sensor, S4,     Colour,         sensorEV3_Color)
#pragma config(Motor,  motorB,          LeftM,         tmotorEV3_Large, PIDControl, driveLeft, encoder)
#pragma config(Motor,  motorC,          RightM,        tmotorEV3_Large, PIDControl, driveRight, encoder)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

task main()
{
	int waitBack = 870;
	int waitTurn = 335;

	setMotorSpeed(LeftM, 70);
	setMotorSpeed(RightM, 70);
	wait1Msec(waitBack);

	setMotorSpeed(LeftM, 0);
	setMotorSpeed(RightM, 0);
	wait1Msec(10);

	setMotorSpeed(LeftM, -70);
	setMotorSpeed(RightM, 70);
	wait1Msec(waitTurn);
}