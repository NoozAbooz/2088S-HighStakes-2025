#include "main.h"

// Intake (hold down button to spin motor)
void refreshIntake() {
	if(controller.get_digital(pros::E_CONTROLLER_DIGITAL_R1)) {
		intake.move_voltage(12000);
	} else if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_R2)) {
		intake.move_voltage(-12000);
	} else {
		intake.move_voltage(0);
	}
}

// Wings
bool leftWingToggle = false;
bool rightWingToggle = false;
bool tailToggle = true;

// Refresh wing status
void refreshWings() {
    if (controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_L1)) {
    	leftWingToggle = !leftWingToggle; 
		leftWingPiston.set_value(leftWingToggle);
    }

	if (controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_L2)) {
    	rightWingToggle = !rightWingToggle; 
		rightWingPiston.set_value(rightWingToggle);
    }

	if (controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_B)) {
    	tailToggle = !tailToggle;
		tailPiston.set_value(tailToggle);
    }
}