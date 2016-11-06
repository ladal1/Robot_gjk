#pragma config(Sensor, S1,     Touch,          sensorEV3_Touch)
#pragma config(Sensor, S2,     Gyro,           sensorEV3_Gyro)
#pragma config(Sensor, S3,     Ultrasonic,     sensorEV3_Ultrasonic)
#pragma config(Sensor, S4,     Colour,         sensorEV3_Color)
#pragma config(Motor,  motorB,          LeftM,         tmotorEV3_Large, PIDControl, driveLeft, encoder)
#pragma config(Motor,  motorC,          RightM,        tmotorEV3_Large, PIDControl, driveRight, encoder)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

task main()
{
	float USD;
	while(true){
		// stop if touch down
		if(getTouchValue(Touch)){
			USD = getUSDistance(Ultrasonic);
			setMotorSpeed(LeftM, -30);
			setMotorSpeed(RightM, -30);
			wait1Msec(200);
			// choice
			if(USD < 12){
				// Left full
				setMotorSpeed(LeftM, 50);
				setMotorSpeed(RightM, -50);
				wait1Msec(450);
			}
			else{
				//Left clear
				setMotorSpeed(LeftM, -50);
				setMotorSpeed(RightM, 50);
				wait1Msec(450);
			}
		}
	setMotorSpeed(LeftM, 50);
	setMotorSpeed(RightM, 50);
	wait1Msec(200);
	}
}