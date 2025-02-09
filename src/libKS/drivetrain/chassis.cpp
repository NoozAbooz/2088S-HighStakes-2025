#include "main.h"

void ks::moveRaw(int voltage, int time) {
	leftDrive.move_voltage(voltage);
	rightDrive.move_voltage(voltage);

	pros::delay(time);

	leftDrive.move_voltage(0);
	rightDrive.move_voltage(0);
}

// opcontrol
double ks::driveCurve(double input, double curve) {
    return (std::pow(2.718, -(curve / 10)) + std::pow(2.718, (std::fabs(input) - 127) / 10) * (1 - std::pow(2.718, -(curve / 10)))) * input;
}

void ks::arcadeDrive(int linCurve, int rotCurve, double turnScale) {
    int power = controller.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y);
    int turn = controller.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_X) * turnScale;

    if (linCurve != 0 && rotCurve != 0) {
        // poll joystick input and convert to mv, then run through drivecurve function
        power = ks::driveCurve(controller.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y), linCurve);
        turn = ks::driveCurve(controller.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_X), rotCurve) * turnScale;
    }

    // move motors based on direction (eg move left more when turn is positive)
    leftDrive.move_voltage((power + turn) * (12000.0 / 127));
    rightDrive.move_voltage((power - turn) * (12000.0 / 127));
}