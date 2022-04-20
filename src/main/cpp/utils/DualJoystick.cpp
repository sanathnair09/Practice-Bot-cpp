#include "utils/DualJoystick.h"
#include "utils/Constants.h"
#include <iostream>

DualJoystick::DualJoystick()
{
    if (DEBUG)
    {
        std::cout << "Init Dual Joystick" << std::endl;
    }
}

double DualJoystick::getRightRawAxis(int axis)
{
    return calculateDeadZone(right->GetRawAxis(axis));
}

double DualJoystick::getLeftRawAxis(int axis)
{
    return calculateDeadZone(left->GetRawAxis(axis));
}

double DualJoystick::calculateDeadZone(double value)
{
    return abs(value) > DEADZONE ? value : 0;
}

double DualJoystick::getSlowMode()

{
    return ((getLeftRawAxis(DIAL) * -1) + 1) / 2;
}

frc::Joystick *DualJoystick::getRightJoystick()
{
    return right;
}

frc::Joystick *DualJoystick::getLeftJoystick()
{
    return right;
}

double DualJoystick::getAirplaneSpeed()
{
    return ((getRightRawAxis(DIAL) * -1) + 1) / 2;
}