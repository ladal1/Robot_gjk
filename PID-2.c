#pragma config(Sensor, S1,     Touch,          sensorEV3_Touch)
#pragma config(Sensor, S2,     Gyro,           sensorEV3_Gyro)
#pragma config(Sensor, S3,     Ultrasonic,     sensorEV3_Ultrasonic)
#pragma config(Sensor, S4,     Colour,         sensorEV3_Color)
#pragma config(Motor,  motorB,          LeftM,         tmotorEV3_Large, PIDControl, driveLeft, encoder)
#pragma config(Motor,  motorC,          RightM,        tmotorEV3_Large, PIDControl, driveRight, encoder)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

task main()
{
	/*
	startTask(gyroReset);
	int CnMotorSpeed = 10;
	float CkP   = 10;
	float CkI = 0.0;
	float CkD = 0.0;
	float ClastError = 0;
	int Cmidpoint = 7;
	float Cerror = 0;
	float Cderivative = 0;
	float Cintegral = 0;
	float Ccorrection = 0;
	float CcorrectionP = 0;
	float CcorrectionI = 0;
	float CcorrectionD = 0;

	while(true){
	Cerror = Cmidpoint - getColorReflected(Colour);
	Cderivative = Cerror - ClastError;
	Cintegral = Cintegral + Cerror;
	CcorrectionP = CkP*Cerror;
	CcorrectionI = CkI*Cintegral;
	CcorrectionD = CkD*Cderivative;
	Ccorrection = round(CcorrectionP + CcorrectionI +CcorrectionD);
	setMotorSpeed(LeftM, CnMotorSpeed+Ccorrection);
	setMotorSpeed(RightM, CnMotorSpeed-Ccorrection);
	ClastError = Cerror;
	//datalogging
	datalogAddValue(0, getGyroDegrees(Gyro));
	//continue
	if(abs(getGyroDegrees(Gyro)) > 7){
	setMotorSpeed(RightM, 50);
	setMotorSpeed(LeftM, 50);
	wait1Msec(2000);
	break;
	}
	}
	*/

	setMotorBrakeMode(LeftM,motorBrake);
  setMotorBrakeMode(RightM,motorBrake);

	//Potreba kalibrovat
	int nSpeed = 50;
	int nSpeedTurn = -50;
	int nSpeedTurnNeg = 50;
	float USD = 0.0;

	while(true){
		if (getTouchValue(Touch)){
			setMotorSpeed(LeftM, 100);
			setMotorSpeed(RightM, 100);
			wait1Msec(100);
			//Couvnout
			setMotorSpeed(RightM, nSpeedTurn);
			setMotorSpeed(LeftM, nSpeedTurn);
			wait1Msec(250);
			setMotorSpeed(RightM, 0);
			setMotorSpeed(LeftM, 0);
			wait1Msec(100);
			USD = getUSDistance(Ultrasonic);
			//Otocit
			if(USD < 17.0){
				setMotorSpeed(RightM, nSpeedTurn);
				setMotorSpeed(LeftM, nSpeedTurnNeg);
				wait1Msec(450);
				setMotorSpeed(RightM, 0);
				setMotorSpeed(LeftM, 0);
				wait1Msec(100);
			}
			else{
				setMotorSpeed(RightM, nSpeedTurnNeg);
				setMotorSpeed(LeftM, nSpeedTurn);
				wait1Msec(300);
				setMotorSpeed(RightM, 0);
				setMotorSpeed(LeftM, 0);
				wait1Msec(100);
				setMotorSpeed(RightM, nSpeed);
				setMotorSpeed(LeftM, nSpeed);
				wait1Msec(920);

			}
		}
		setMotorSpeed(RightM, nSpeed);
		setMotorSpeed(LeftM, nSpeed);
		/*
		USD = getUSDistance(Ultrasonic);
		if(USD < 6.5){
			setMotorSpeed(RightM, nSpeed);
			setMotorSpeed(LeftM, nSpeed - 10);
			wait1Msec(20);
		}
		if(USD > 6.5 && USD < 20.0){
			//jed rovni
			setMotorSpeed(RightM, nSpeed);
			setMotorSpeed(LeftM, nSpeed);
			wait1Msec(20);
		}
		if(USD > 20.0){
			//Toc doleva
			setMotorSpeed(RightM, nSpeedTurnNeg);
			setMotorSpeed(LeftM, nSpeedTurn);
			wait1Msec(275);
			setMotorSpeed(RightM, nSpeed);
			setMotorSpeed(LeftM, nSpeed);
			wait1Msec(920);
		}

		Cerror = 0;
		Cderivative = 0;
		Ccorrection = 0;
		CcorrectionP = 0;
		CcorrectionD = 0;

		while(true){
		Cerror = Cmidpoint - getColorReflected(Colour);
		Cderivative = Cerror - ClastError;
		Cintegral = Cintegral + Cerror;
		CcorrectionP = CkP*Cerror;
		CcorrectionI = CkI*Cintegral;
		CcorrectionD = CkD*Cderivative;
		Ccorrection = round(CcorrectionP + CcorrectionI +CcorrectionD);
		setMotorSpeed(LeftM, CnMotorSpeed+Ccorrection);
		setMotorSpeed(RightM, CnMotorSpeed-Ccorrection);
		ClastError = Cerror;
		delay(1);
		}
		*/
	}
}
