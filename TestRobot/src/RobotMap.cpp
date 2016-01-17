// RobotBuilder Version: 2.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.


#include "RobotMap.h"
#include "LiveWindow/LiveWindow.h"


// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=ALLOCATION
std::shared_ptr<CANTalon> RobotMap::driveBaseSubfrontLeftTalon;
std::shared_ptr<CANTalon> RobotMap::driveBaseSubfrontRightTalon;
std::shared_ptr<CANTalon> RobotMap::driveBaseSubbackLeftTalon;
std::shared_ptr<CANTalon> RobotMap::driveBaseSubbackRightTalon;
std::shared_ptr<RobotDrive> RobotMap::driveBaseSubrobotDrive;
std::shared_ptr<CANTalon> RobotMap::shooterSubsystemshooterTalon;
// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=ALLOCATION

void RobotMap::init() {
    // BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTORS
    LiveWindow *lw = LiveWindow::GetInstance();

    driveBaseSubfrontLeftTalon.reset(new CANTalon(1));
    lw->AddActuator("DriveBaseSub", "frontLeftTalon", driveBaseSubfrontLeftTalon);
    
    driveBaseSubfrontRightTalon.reset(new CANTalon(2));
    lw->AddActuator("DriveBaseSub", "frontRightTalon", driveBaseSubfrontRightTalon);
    
    driveBaseSubbackLeftTalon.reset(new CANTalon(3));
    lw->AddActuator("DriveBaseSub", "backLeftTalon", driveBaseSubbackLeftTalon);
    
    driveBaseSubbackRightTalon.reset(new CANTalon(4));
    lw->AddActuator("DriveBaseSub", "backRightTalon", driveBaseSubbackRightTalon);
    
    driveBaseSubrobotDrive.reset(new RobotDrive(driveBaseSubfrontLeftTalon, driveBaseSubbackLeftTalon,
              driveBaseSubfrontRightTalon, driveBaseSubbackRightTalon));
    
    driveBaseSubrobotDrive->SetSafetyEnabled(false);
        driveBaseSubrobotDrive->SetExpiration(0.1);
        driveBaseSubrobotDrive->SetSensitivity(0.5);
        driveBaseSubrobotDrive->SetMaxOutput(1.0);

    shooterSubsystemshooterTalon.reset(new CANTalon(5));
    lw->AddActuator("ShooterSubsystem", "shooterTalon", shooterSubsystemshooterTalon);
    

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTORS
}
