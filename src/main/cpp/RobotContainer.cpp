// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "RobotContainer.h"
#include "utils/Constants.h"
#include <frc2/command/InstantCommand.h>

RobotContainer::RobotContainer()
{
  // Initialize all of your commands and subsystems here
  driveTrain->setDriveMode(ArcadeDrive);
  driveTrain->SetDefaultCommand(std::move(*drive));

  ConfigureButtonBindings();
}

void RobotContainer::ConfigureButtonBindings()
{
  button8->WhenPressed(new frc2::InstantCommand([this]
                                                { ChangeDriveMode(); }));
  button1->WhenHeld(shootAirplane);
}

void RobotContainer::ChangeDriveMode()
{
  switch (driveTrain->getDriveMode())
  {
  case ArcadeDrive:
    driveTrain->setDriveMode(TankDrive);
    break;
  case TankDrive:
    driveTrain->setDriveMode(ArcadeDrive);
    break;
  default:
    driveTrain->setDriveMode(ArcadeDrive);
    break;
  }
}

frc2::Command *RobotContainer::GetAutonomousCommand()
{
  // An example command will be run in autonomous
  return nullptr;
}
