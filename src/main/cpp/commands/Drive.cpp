// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/Drive.h"
#include "subsystems/DriveTrain.h"
#include "utils/DualJoystick.h"

Drive::Drive(DriveTrain *driveTrain, DualJoystick *joysticks)
{
  // Use addRequirements() here to declare subsystem dependencies.
  AddRequirements(driveTrain);
  this->driveTrain = driveTrain;
  this->joysticks = joysticks;
}

// Called when the command is initially scheduled.
void Drive::Initialize() {}

// Called repeatedly when this Command is scheduled to run
void Drive::Execute()
{
  double y, x, dial;
  dial = joysticks->getSlowMode();
  switch (driveTrain->getDriveMode())
  {
  case ArcadeDrive:
    y = joysticks->getLeftRawAxis(Y_AXIS);
    x = joysticks->getRightRawAxis(X_AXIS) / 2;
    break;
  case TankDrive:
    x = joysticks->getLeftRawAxis(Y_AXIS);
    y = joysticks->getRightRawAxis(Y_AXIS);
    break;
  default:
    y = joysticks->getLeftRawAxis(Y_AXIS);
    x = joysticks->getRightRawAxis(X_AXIS) / 2;
    break;
  }
  driveTrain->drive(x * dial, y * dial);
}

// Called once the command ends or is interrupted.
void Drive::End(bool interrupted)
{
  driveTrain->stop();
}

// Returns true when the command should end.
bool Drive::IsFinished()
{
  return false;
}
