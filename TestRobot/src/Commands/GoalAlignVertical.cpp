#include "GoalAlignVertical.h"

GoalAlignVertical::GoalAlignVertical(float distanceAway)
{
	Requires(Robot::driveBaseSubsystem.get());
	distanceTarget = distanceAway;
	inToleranceY = false;
	distanceY = 0;
	speedY = 0;
	isDone = false;
	calrot = 0;
	adjyaw = 0;
	Robot::driveBaseSubsystem->isAlignedY = false;
}

// Called just before this Command runs the first time
void GoalAlignVertical::Initialize()
{
	inToleranceY = false;
	distanceY = 0;
	speedY = 0;
	isDone = false;
	calrot = 0;
	adjyaw = 0;
	Robot::driveBaseSubsystem->isAlignedY = false;
}

// Called repeatedly when this Command is scheduled to run
void GoalAlignVertical::Execute()
{
	Robot::driveBaseSubsystem->isAlignedY = false;
	distanceY = Robot::visionClass->getDistanceY();
	adjyaw = Robot::driveBaseSubsystem->getAdjYaw();
	calrot = Robot::driveBaseSubsystem->CalculateRotValue(0, 1);

	if(distanceY >= 144) {
		speedY = 1.0;
	}
	if(distanceY >= 120) {
		speedY = .8;
	}
	if(distanceY >= 96) {
		speedY = .6;
	}
	if(distanceY >= 60) {
		speedY = .2;
	}

	bool tooClose = distanceY <= (distanceTarget - toleranceY);
	bool tooFar = distanceY >= (distanceTarget + toleranceY);
	std::cout << "distanceY: " << distanceY << std::endl;

	std::cout << "tooClose: " << tooClose << std::endl;
	std::cout << "tooFar: " << tooFar << std::endl;
	if(tooClose) {
		printf("bot is too close!\n");
		inToleranceY = false;
		Robot::driveBaseSubsystem->MecanumDrive(0, speedY, calrot, adjyaw);
	}
	else if(tooFar) {
		printf("bot is too far!\n");
		inToleranceY = false;
		Robot::driveBaseSubsystem->MecanumDrive(0, -speedY, calrot, adjyaw);
	}
	else {
		printf("inTolerance == true\n");
		inToleranceY = true;
	}

	if(inToleranceY) {
		Robot::driveBaseSubsystem->isAlignedY = true;
		Robot::driveBaseSubsystem->MecanumDrive(0, 0, 0, 0);
		printf("Target aligned in Y!\n");
		isDone = true;
	}
}

// Make this return true when this Command no longer needs to run execute()
bool GoalAlignVertical::IsFinished()
{
	return isDone || IsTimedOut();
}

// Called once after isFinished returns true
void GoalAlignVertical::End()
{
	Robot::driveBaseSubsystem->MecanumDrive(0, 0, 0, 0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void GoalAlignVertical::Interrupted()
{
	Robot::driveBaseSubsystem->MecanumDrive(0, 0, 0, 0);
}