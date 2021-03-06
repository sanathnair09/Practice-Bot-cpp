// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/SubsystemBase.h>
#include <ctre/Phoenix.h>
#include "utils/Constants.h"

class AirplaneLauncher : public frc2::SubsystemBase
{
public:
  AirplaneLauncher();

  /**
   * Will be called periodically whenever the CommandScheduler runs.
   */
  void Periodic() override;
  ~AirplaneLauncher()
  {
    delete left;
    delete right;
  }
  void shoot(double speed);
  void stop();

private:
  TalonSRX *left = new TalonSRX{AIRPLANE_LEFT};
  TalonSRX *right = new TalonSRX{AIRPLANE_RIGHT};

  // Components (e.g. motor controllers and sensors) should generally be
  // declared private and exposed only through public methods.
};
