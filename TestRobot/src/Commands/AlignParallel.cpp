#include "AlignParallel.h"

AlignParallel::AlignParallel(float angle, float distanceAway)
{
	Requires(Robot::driveBaseSubsystem.get());
	isDone = false;
	targetX = 0;
	inToleranceX = false;
	calrot = 0;
	adjyaw = 0;
	targetAngle = angle;
	distanceToCenter = 0;
	speedX = 0;
	XAxis = 0;
	YAxis = 0;
	RotAxis = 0;
	distanceTarget = distanceAway;
	inToleranceY = false;
	distanceY = 0;
	speedY = 0;
	//SetTimeout(2);
	Robot::driveBaseSubsystem->isAlignedX = false;
	Robot::driveBaseSubsystem->isAlignedY = false;
}

// Called just before this Command runs the first time
void AlignParallel::Initialize()
{
	isDone = false;
	targetX = 0;
	inToleranceX = false;
	calrot = 0;
	adjyaw = 0;
	distanceToCenter = 0;
	speedX = 0;
	Robot::driveBaseSubsystem->isAlignedX = false;
	Robot::driveBaseSubsystem->isAlignedY = false;
	inToleranceY = false;
	distanceY = 0;
	speedY = 0;
}

// Called repeatedly when this Command is scheduled to run
void AlignParallel::Execute()
{
	speedX = 0;
	speedY = 0;
	XAxis = Robot::oi->getdriverJoystick()->GetRawAxis(0);
	YAxis = Robot::oi->getdriverJoystick()->GetRawAxis(1);
	RotAxis = Robot::oi->getdriverJoystick()->GetRawAxis(4);
	Robot::driveBaseSubsystem->isAlignedX = false;
	Robot::driveBaseSubsystem->isAlignedY = false;
	distanceToCenter = Robot::table->GetNumber("center", 0.0);
	adjyaw = Robot::driveBaseSubsystem->getAdjYaw();
	distanceY = Robot::table->GetNumber("distance", 0.0);
	calrot = Robot::driveBaseSubsystem->CalculateRotValue(targetAngle, 1);
	targetX = Robot::table->GetNumber("targetX", 0.0);
	//std::cout << "TargetX: " << targetX << std::endl;

	if(XAxis > .2 || YAxis > .2 || RotAxis > .2) {
		isDone = true;
	}

	if(abs(distanceToCenter) <= 160)
	{
		speedX = 0.4;
	}
	if(abs(distanceToCenter) <= 80)
	{
		speedX = 0.4;
	}
	if(abs(distanceToCenter) <= 40)
	{
		speedX = 0.3;
	}

	if(distanceY <= 144) {
		speedY = .3;
	}
	if(distanceY <= 120) {
		speedY = .3;

	}
	if(distanceY <= 96) {
		speedY = .3;
	}
	if(distanceY <= 60) {
		speedY = .3;
	}

	bool tooClose = distanceY < (distanceTarget - toleranceY);
	bool tooFar = distanceY > (distanceTarget + toleranceY);

	inToleranceY = true;

	if(tooClose) {
		printf("bot is too close in y!\n");
		std::cout << "bot distance: " << distanceY << std::endl;
		inToleranceY = false;
		//Robot::driveBaseSubsystem->MecanumDrive(0, speedY, calrot, adjyaw);
	}
	else if(tooFar) {
		printf("bol is too far in y!\n");
		std::cout << "bot distance: " << distanceY << std::endl;
		inToleranceY = false;
		speedY = speedY * -1;
		//Robot::driveBaseSubsystem->MecanumDrive(0, -speedY, calrot, adjyaw);
	}

	//targetX = targetX - 2;
	inToleranceX = true;

	std::cout << "targetX: " << targetX << std::endl;
	std::cout << "centerX: " << centerX << std::endl;
	std::cout << "toleranceX: " << toleranceX << std::endl;

	if(distanceToCenter >= (0 + toleraceX)) {
		inToleranceX = false;
		std::cout << "bot is too far right!" << std::endl;
		//Robot::driveBaseSubsystem->MecanumDrive(speedX, 0, calrot, adjyaw);
	}
	if(distanceToCenter <= (0 - toleranceX)) {
		inToleranceX = false;
		std::cout << "bot is too far left!" << std::endl;
		speedX = speedX * -1;
		//Robot::driveBaseSubsystem->MecanumDrive(-speedX, 0, calrot, adjyaw);
	}

	if(inToleranceX == true) {
		std::cout << "inToleranceX!" << std::endl;
	}

	std::cout << "speedX: " << speedX << std::endl;
	std::cout << "speedY: " << speedY << std::endl;

	Robot::driveBaseSubsystem->MecanumDrive(speedX, speedY, calrot, adjyaw);

	if(inToleranceX && inToleranceY) {
		Robot::driveBaseSubsystem->MecanumDrive(0, 0, 0, 0);
		//printf("Target aligned in X dir!\n");
		Robot::driveBaseSubsystem->isAlignedX = true;
		Robot::driveBaseSubsystem->isAlignedY = true;
		isDone = true;
	}
}

// Make this return true when this Command no longer needs to run execute()
bool AlignParallel::IsFinished()
{
	return isDone;
}

// Called once after isFinished returns true
void AlignParallel::End()
{
	Robot::driveBaseSubsystem->MecanumDrive(0, 0, 0, 0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void AlignParallel::Interrupted()
{
	Robot::driveBaseSubsystem->MecanumDrive(0, 0, 0, 0);
}
