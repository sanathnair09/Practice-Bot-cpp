// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/SubsystemBase.h>
#include <ctre/Phoenix.h>
#include "utils/Constants.h"

class DriveTrain : public frc2::SubsystemBase
{
public:
  DriveTrain();

  void Periodic() override;
  void drive(double leftSpeed, double rightSpeed);
  void stop();
  DriveMode getDriveMode() { return driveMode; };

  void setDriveMode(DriveMode driveMode) { this->driveMode = driveMode; };

  ~DriveTrain()
  {
    delete frontL;
    delete frontR;
    delete backL;
    delete backR;
  }

private:
  TalonSRX *frontL = new TalonSRX{DRIVETRAIN_FRONT_LEFT};
  TalonSRX *frontR = new TalonSRX{DRIVETRAIN_FRONT_RIGHT};
  TalonSRX *backL = new TalonSRX{DRIVETRAIN_BACK_LEFT};
  TalonSRX *backR = new TalonSRX{DRIVETRAIN_BACK_RIGHT};

  DriveMode driveMode = DriveMode::ArcadeDrive;

  void tankDrive(double leftSpeed, double rightSpeed);
  void arcadeDrive(double x, double y);
};
