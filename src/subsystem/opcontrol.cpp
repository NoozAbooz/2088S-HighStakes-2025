#include "main.h"

// Intake (hold down button to spin motor)
void refreshIntake() {
	if(controller.get_digital(pros::E_CONTROLLER_DIGITAL_L1)) {
		intake.move_voltage(12000);
	} else if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_L2)) {
		intake.move_voltage(-12000);
	} else {
		intake.move_voltage(0);
	}
}

void refreshWallstakes() {
	if(controller.get_digital(pros::E_CONTROLLER_DIGITAL_R1)) {
		wallStake.move_voltage(5000);
	} else if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_R2)) {
		wallStake.move_voltage(-5000);
	} else {
		wallStake.brake();
	}
}

void resetWallstakes() {
	if(controller.get_digital(pros::E_CONTROLLER_DIGITAL_A)) {
		pros::Task([] {
			wallStake.move_absolute(800, 12000);
			controller.rumble("-");
		});
	}
}
void loadWallstakes() {
	if (controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_A)) {
    	pros::Task([] {
        	while(wallstakePositionSensor.get_value() > 2700) {
    			wallStake.move_voltage(10000);
				pros::delay(10);
			}
			wallStake.brake();
			controller.rumble(".");
    	});
    }
}

bool clampToggle = false;
void refreshClamp() {
	if (controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_RIGHT)) {
    	clampToggle = !clampToggle;
		clampPiston.set_value(clampToggle);
    }
}

bool doinkerToggle = false;
void refreshDoinker() {
	if (controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_Y)) {
    	doinkerToggle = !doinkerToggle;
		doinkerPiston.set_value(doinkerToggle);
    }
}