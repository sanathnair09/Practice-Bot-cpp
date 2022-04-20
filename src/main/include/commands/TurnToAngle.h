// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>
#include <frc2/command/PIDCommand.h>
#include "subsystems/DriveTrain.h"
#include <AHRS.h>
#include "utils/Constants.h"

/**
 * An example command.
 *
 * <p>Note that this extends CommandHelper, rather extending CommandBase
 * directly; this is crucially important, or else the decorator functions in
 * Command will *not* work!
 */
class TurnToAngle
    : public frc2::CommandHelper<frc2::CommandBase, TurnToAngle>
{
public:
  TurnToAngle(DriveTrain *driveTrain);

  void Initialize() override;

  void Execute() override;

  void End(bool interrupted) override;

  bool IsFinished() override;

private:
  DriveTrain *driveTrain;
  AHRS *navX = new AHRS(frc::SPI::Port::kMXP);
  frc2::PIDController *pidController = new frc2::PIDController{kP, kI, kD};
  double rotateToAngleRate;
};
