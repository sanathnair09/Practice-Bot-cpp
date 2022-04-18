// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

/**
 * The Constants header provides a convenient place for teams to hold robot-wide
 * numerical or boolean constants.  This should not be used for any other
 * purpose.
 *
 * It is generally a good idea to place constants into subsystem- or
 * command-specific namespaces within this header, which can then be used where
 * they are needed.
 */

constexpr int DRIVETRAIN_FRONT_LEFT = 0;
constexpr int DRIVETRAIN_BACK_LEFT = 1;
constexpr int DRIVETRAIN_FRONT_RIGHT = 2;
constexpr int DRIVETRAIN_BACK_RIGHT = 3;

constexpr int AIRPLANE_LEFT = 5;
constexpr int AIRPLANE_RIGHT = 6;

constexpr int X_AXIS = 0;
constexpr int Y_AXIS = 1;
constexpr int DIAL = 2;
constexpr int DEADZONE = 3;

constexpr bool DEBUG = true;

enum DriveMode
{
    ArcadeDrive,
    TankDrive
};
