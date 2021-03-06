#include "ShooterSubsystem.h"
#include "../RobotMap.h"
#include "../Commands/ShooterControl.h"

ShooterSubsystem::ShooterSubsystem() : Subsystem("ShooterSubsystem") {
	//printf("Shooter Subsystem!\n");
    shooterTalonLeft = RobotMap::shooterSubsystemshooterTalonLeft;
    shooterTalonRight = RobotMap::shooterSubsystemshooterTalonRight;
    shooterSolenoid = RobotMap::shooterSubsystemshooterSolenoid;
    shooterServoLeft = RobotMap::shooterSubsystemshooterServoLeft;
    shooterServoRight = RobotMap::shooterSubsystemshooterServoRight;
}

void ShooterSubsystem::InitDefaultCommand() {
    SetDefaultCommand(new ShooterControl(0, 0));
}

void ShooterSubsystem::Shoot(float speed)
{
	shooterTalonLeft->Set(speed);
	shooterTalonRight->Set(speed);
}

void ShooterSubsystem::ShootLeftMotor(float speed)
{
	shooterTalonLeft->Set(speed);
}

void ShooterSubsystem::ShootRightMotor(float speed) {
	shooterTalonRight->Set(speed);
}

void ShooterSubsystem::SetSolenoidForward() {
	shooterSolenoid->Set(DoubleSolenoid::kForward);
}

void ShooterSubsystem::SetSolenoidReverse() {
	shooterSolenoid->Set(DoubleSolenoid::kReverse);
}

double ShooterSubsystem::GetEncoderVelocityLeft() {
	return (shooterTalonLeft->GetEncVel() * -1);
}

double ShooterSubsystem::GetEncoderVelocityRight() {
	return (shooterTalonRight->GetEncVel() * -1);
}

void ShooterSubsystem::SetAngleLeftServo(float inputAngle) {
	shooterServoLeft->SetAngle(inputAngle);
}

void ShooterSubsystem::SetAngleRightServo(float inputAngle) {
	shooterServoRight->SetAngle(inputAngle);
}
