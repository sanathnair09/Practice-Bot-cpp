// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/ShootAirplane.h"

ShootAirplane::ShootAirplane(AirplaneLauncher *airplaneLauncher)
{
  // Use addRequirements() here to declare subsystem dependencies.
  this->airplaneLauncher = airplaneLauncher;
}

// Called when the command is initially scheduled.
void ShootAirplane::Initialize() {}

// Called repeatedly when this Command is scheduled to run
void ShootAirplane::Execute()
{
  airplaneLauncher->shoot();
}

// Called once the command ends or is interrupted.
void ShootAirplane::End(bool interrupted)
{
  airplaneLauncher->stop();
}

// Returns true when the command should end.
bool ShootAirplane::IsFinished()
{
  return false;
}
