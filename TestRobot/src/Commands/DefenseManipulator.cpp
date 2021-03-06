#include "DefenseManipulator.h"

DefenseManipulator::DefenseManipulator(float speed, float target)
{
	Requires(Robot::defenseSubsystem.get());
	timer.reset(new Timer());
	timeCurrent = 0;
	timeTarget = target;
	inputSpeed = speed;
	isDone = false;
}

// Called just before this Command runs the first time
void DefenseManipulator::Initialize()
{
	timer->Reset();
	timer->Start();
	timeCurrent = 0;
	isDone = false;
}

// Called repeatedly when this Command is scheduled to run
void DefenseManipulator::Execute()
{
	timeCurrent = timer->Get();
	if(timeTarget == 0) {
		Robot::defenseSubsystem->DefenseMotor(inputSpeed);
		isDone = true;
	}
	else {
		if(timeCurrent >= timeTarget) {
			Robot::defenseSubsystem->DefenseMotor(0);
			isDone = true;
		}
		else {
			Robot::defenseSubsystem->DefenseMotor(inputSpeed);
			isDone = false;
		}
	}
}

// Make this return true when this Command no longer needs to run execute()
bool DefenseManipulator::IsFinished()
{
	return isDone;
}

// Called once after isFinished returns true
void DefenseManipulator::End()
{
	timer->Stop();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void DefenseManipulator::Interrupted()
{

}
