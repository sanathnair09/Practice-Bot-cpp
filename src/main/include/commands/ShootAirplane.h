// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>
#include "subsystems/AirplaneLauncher.h"
#include "utils/DualJoystick.h"

class ShootAirplane
    : public frc2::CommandHelper<frc2::CommandBase, ShootAirplane>
{
public:
  ShootAirplane(AirplaneLauncher *airplaneLauncher, DualJoystick *joysticks);

  void Initialize() override;

  void Execute() override;

  void End(bool interrupted) override;

  bool IsFinished() override;
  ~ShootAirplane()
  {
    delete airplaneLauncher;
    delete joysticks;
  }

private:
  AirplaneLauncher *airplaneLauncher;
  DualJoystick *joysticks;
};
