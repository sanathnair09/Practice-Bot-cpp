// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/DriveTrain.h"
#include "ctre/Phoenix.h"
#include "utils/Constants.h"
#include <iostream>

DriveTrain::DriveTrain()
{
    if (DEBUG)
    {
        std::cout << "Init DriveTrain" << std::endl;
    }
    backL->Follow(*frontL);
    backR->Follow(*frontR);

    frontL->SetInverted(true);
    backL->SetInverted(true);
    frontR->SetInverted(false);
    backR->SetInverted(false);

    frontL->SetNeutralMode(Brake);
    frontR->SetNeutralMode(Brake);
    backL->SetNeutralMode(Brake);
    backR->SetNeutralMode(Brake);
}

// This method will be called once per scheduler run
void DriveTrain::Periodic() {}

void DriveTrain::tankDrive(double leftSpeed, double rightSpeed)
{
    frontL->Set(TalonSRXControlMode::PercentOutput, leftSpeed);
    frontR->Set(TalonSRXControlMode::PercentOutput, rightSpeed);
}
void DriveTrain::arcadeDrive(double x, double y)
{
    frontL->Set(TalonSRXControlMode::PercentOutput, y - x);
    frontR->Set(TalonSRXControlMode::PercentOutput, y + x);
}

void DriveTrain::stop()
{
    frontL->Set(TalonSRXControlMode::PercentOutput, 0);
    frontR->Set(TalonSRXControlMode::PercentOutput, 0);
}

void DriveTrain::drive(double leftSpeed, double rightSpeed)
{
    switch (driveMode)
    {
    case DriveMode::ArcadeDrive:
        arcadeDrive(leftSpeed, rightSpeed);
        break;
    case DriveMode::TankDrive:
        tankDrive(leftSpeed, rightSpeed);
        break;
    default:
        arcadeDrive(leftSpeed, rightSpeed);
        break;
    }
}
