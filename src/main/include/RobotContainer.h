// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/Command.h>
#include <frc2/command/button/JoystickButton.h>

#include "commands/Drive.h"
#include "subsystems/DriveTrain.h"
#include "utils/DualJoystick.h"
#include "subsystems/AirplaneLauncher.h"
#include "commands/ShootAirplane.h"

class RobotContainer
{
public:
  RobotContainer();

  frc2::Command *GetAutonomousCommand();
  ~RobotContainer()
  {
    delete joysticks;
    delete driveTrain;
    delete button8;
    delete drive;
    delete airplaneLauncher;
  };

private:
  // utils
  DualJoystick *joysticks = new DualJoystick();
  frc2::JoystickButton *button8 = new frc2::JoystickButton(joysticks->getRightJoystick(), 8);
  frc2::JoystickButton *button1 = new frc2::JoystickButton(joysticks->getRightJoystick(), 1);

  void ChangeDriveMode();

  // subsystems
  DriveTrain *driveTrain = new DriveTrain();
  AirplaneLauncher *airplaneLauncher = new AirplaneLauncher();

  // commands
  Drive *drive = new Drive(driveTrain, joysticks);
  ShootAirplane *shootAirplane = new ShootAirplane(airplaneLauncher);

  void ConfigureButtonBindings();
};
