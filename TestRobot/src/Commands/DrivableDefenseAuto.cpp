#include "DrivableDefenseAuto.h"
#include "DriveCommandAuto.h"
#include "ShooterControl.h"

DrivableDefenseAuto::DrivableDefenseAuto()
{
	printf("constructor for drivable defense!\n");
	AddParallel(new DriveCommandAuto(0, -1, 0, 1.5, 0));
	//AddParallel(new DriveCommandAuto(0, -1, 0, 2, 0));
	AddSequential(new ShooterControl(-1200, 2));
	AddSequential(new ShooterControl(-1200, 0.5));
	printf("after sequential for defense auto!\n");
}
