#pragma config(Sensor, S1,     Touch,          sensorEV3_Touch)
#pragma config(Sensor, S2,     Gyro,           sensorEV3_Gyro)
#pragma config(Sensor, S3,     Ultrasonic,     sensorEV3_Ultrasonic)
#pragma config(Sensor, S4,     Colour,         sensorEV3_Color)
#pragma config(Motor,  motorB,          LeftM,         tmotorEV3_Large, PIDControl, driveLeft, encoder)
#pragma config(Motor,  motorC,          RightM,        tmotorEV3_Large, PIDControl, driveRight, encoder)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

task main()
{
	//Konstanty
	int speed = 70;
	int speedTurn = 70;
	int speedTurnNeg = -70;
	int waitTurn = 290;
	int speedBack = -50;
	int waitBack = 310;
	int waitFwd = 850;
	float USD = 15.0;

	while(true){
		//zastavi se na zacatku kazdeho cyklu
		setMotorSpeed(RightM, 0);
		setMotorSpeed(LeftM, 0);
		//reset pokud se zasekne
		if(getTouchValue(Touch) && getUSDistance(Ultrasonic)>USD){
			//vyrovnat se
			setMotorSpeed(LeftM, speed);
			setMotorSpeed(RightM, speed);
			wait1Msec(30);
			//couva
			setMotorSpeed(LeftM, speedBack);
			setMotorSpeed(RightM, speedBack);
			wait1Msec(waitBack);
			//stop
			setMotorSpeed(LeftM, 0);
			setMotorSpeed(RightM, 0);
			wait1Msec(19);
		}


		//Je-li vzdalenost vlevo mensi nez 20 cm, Zatoci doleva
		if(getUSDistance(Ultrasonic)>USD){
			setMotorSpeed(LeftM, speedTurnNeg);
			setMotorSpeed(RightM, speedTurn);
			wait1Msec(waitTurn);
		}
		//Je-li tlacitko zmackle, couvne a otoci se o 90 stupnu
		if(getTouchValue(Touch)){
			//vyrovnat se
			setMotorSpeed(LeftM, speed);
			setMotorSpeed(RightM, speed);
			wait1Msec(10);
			//couva
			setMotorSpeed(LeftM, speedBack);
			setMotorSpeed(RightM, speedBack);
			wait1Msec(waitBack);
			//stop
			setMotorSpeed(LeftM, 0);
			setMotorSpeed(RightM, 0);
			wait1Msec(19);
			//toci
			setMotorSpeed(LeftM, speedTurn);
			setMotorSpeed(RightM, speedTurnNeg);
			wait1Msec(waitTurn);
		}
		//zastavi se na 10 ms
		setMotorSpeed(LeftM, 0);
		setMotorSpeed(RightM, 0);
		wait1Msec(10);
		//Jede rovne 1 ctverec
		setMotorSpeed(LeftM, speed);
		setMotorSpeed(RightM, speed);
		wait1Msec(waitFwd);
	}
}
