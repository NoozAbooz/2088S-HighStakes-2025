#include "main.h"

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

// Slapper
void refreshSlapper() {
	if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_L2)) {
		slapper.move_voltage(12000);
	} else {
		slapper.move_voltage(0);
	}
}