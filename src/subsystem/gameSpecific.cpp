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

bool clampToggle = false;
// Refresh wing status
void refreshClamp() {
	if (controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_B)) {
    	clampToggle = !clampToggle;
		clampPiston.set_value(clampToggle);
    }
}