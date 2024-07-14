#include "main.h"

using namespace ks;

void moveRaw(int voltage, int time) {
	leftDrive.move_voltage(voltage);
	rightDrive.move_voltage(voltage);

	pros::delay(time);

	leftDrive.move_voltage(0);
	rightDrive.move_voltage(0);
}

double driveCurve(double input, double curve) {
    return (std::pow(2.718, -(curve / 10)) + std::pow(2.718, (std::abs(input) - 127) / 10) * (1 - std::pow(2.718, -(curve / 10)))) * input;
}

void arcadeDrive(int linCurve, int rotCurve, double turnScale) {
    // poll joystick input and convert to mv, then run through drivecurve function
    int power = ks::driveCurve(controller.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y), linCurve);
    int turn = ks::driveCurve((controller.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_X) * turnScale), rotCurve);

    // move motors based on direction (eg move left more when turn is positive)
    leftDrive.move_voltage((power + turn) * (12000.0 / 127));
    rightDrive.move_voltage((power - turn) * (12000.0 / 127));
}