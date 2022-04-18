#pragma once

#include <frc/GenericHID.h>
#include <frc/Joystick.h>

class DualJoystick
{

private:
    frc::Joystick *right = new frc::Joystick{0};
    frc::Joystick *left = new frc::Joystick{1};

    double calculateDeadZone(double value);

public:
    DualJoystick();
    double getRightRawAxis(int axis);
    double getLeftRawAxis(int axis);
    double getSlowMode();
    frc::Joystick *getRightJoystick();
    frc::Joystick *getLeftJoystick();
    double getAirplaneSpeed();
    ~DualJoystick()
    {
        delete right;
        delete left;
    }
};
