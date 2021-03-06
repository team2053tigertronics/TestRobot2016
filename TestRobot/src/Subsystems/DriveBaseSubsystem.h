#ifndef DRIVEBASESUBSYSTEM_H
#define DRIVEBASESUBSYSTEM_H

#include "Commands/Subsystem.h"
#include "WPILib.h"
#include "../TigerDrive/TigerDrive.h"

class DriveBaseSubsystem: public Subsystem {
private:
	std::shared_ptr<CANTalon> frontLeftTalon;
	std::shared_ptr<CANTalon> frontRightTalon;
	std::shared_ptr<CANTalon> backLeftTalon;
	std::shared_ptr<CANTalon> backRightTalon;
	std::shared_ptr<RobotDrive> robotDrive;
public:
	DriveBaseSubsystem();
	void InitDefaultCommand();
	void MecanumDrive(float x, float y, float rot, float gyro);
	float CalculateRotValue(float setAngle, float setSpeed);
	void IMU_YAWoffset(float offset);
	float getAdjYaw();
	void setAdjYaw(float offset);
	float getImuYaw();
	bool getIsRotDone();
	void setIsRotDone(bool isDone);
	void setIsRotDoneOverride(bool isDone);
	void setTimesThroughLoop(int timeLoop);
	bool getIsRotDoneOverride();
	bool IsAlignedX();
	bool IsAlignedY();
	float calculatedoffset; //calculated for imu offset
	float yawoffset; //param
	float IMU_Yaw; //return value for imuoffset
	AHRS* imuRobot;
	TigerDrive* tigerDrive;
	bool isAlignedX;
	bool isAlignedY;
};

#endif
