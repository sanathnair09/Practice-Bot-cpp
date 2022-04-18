// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/AirplaneLauncher.h"

AirplaneLauncher::AirplaneLauncher(){

};

// This method will be called once per scheduler run
void AirplaneLauncher::Periodic() {}

void AirplaneLauncher::shoot()
{
    right->Set(TalonSRXControlMode::PercentOutput, 0.1);
    left->Set(TalonSRXControlMode::PercentOutput, -0.1);
}

void AirplaneLauncher::stop(){
    right->Set(TalonSRXControlMode::PercentOutput, 0);
    left->Set(TalonSRXControlMode::PercentOutput, 0);
}