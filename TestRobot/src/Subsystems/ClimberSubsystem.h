#ifndef ClimberSubsystem_H
#define ClimberSubsystem_H

#include "Commands/Subsystem.h"
#include "WPILib.h"

class ClimberSubsystem: public Subsystem
{
private:
	//std::shared_ptr<CANTalon> climbTalonLeft;
	std::shared_ptr<CANTalon> climbTalonRight;
	std::shared_ptr<DoubleSolenoid> climbSolenoid;
public:
	ClimberSubsystem();
	void InitDefaultCommand();
	void ClimbMotor(float speed);
	void ClimbMotorRight(float speed);
	//void ClimbMotorLeft(float speed);
	void SetSolenoidForward();
	void SetSolenoidReverse();
	bool GetForwardLimit();
	bool GetReverseLimit();
};

#endif
