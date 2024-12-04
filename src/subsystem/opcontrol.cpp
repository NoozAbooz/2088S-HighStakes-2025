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
		// if ((wallStakeSensor.get_angle() / 100 < 130 && wallStakeSensor.get_angle() / 100 > 0)) {
			wallStake.move_voltage(8000);
		// }

	} else if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_R2)) {
		wallStake.move_voltage(-10000);
	} else {
		wallStake.brake();
	}
}

void resetWallstakes() {
	if(controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_A)) {
		pros::Task([] {
			console.printf("%d", wallStakeSensor.get_angle() / 100);

			// if ((wallStakeSensor.get_angle() / 100) > 40) {
			// 	while ((wallStakeSensor.get_angle() / 100) > 28) {
			// 		wallStake.move_voltage(-8000);
			// 	}
			// } else {
				while ((wallStakeSensor.get_angle() / 100) < 32) {
					wallStake.move_voltage(10000);
				}
			// }
			controller.rumble(".");
		});
		// wallStake.move_voltage(10000);
		// pros::delay(170);
		// wallStake.brake();
		// controller.rumble(".");
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