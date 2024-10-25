#include "main.h"

bool sortToggle = true;
bool lock = false;

// Colour Sorter
void raiseHoodTask() {
	lock = true;
	console.println("Raising hood...");
	pros::Task([] {
		clampPiston.set_value(true);
		pros::delay(700);
		clampPiston.set_value(false);
		lock = false;
	});
}

void refreshColourSort() {
	if (alliance == "blue" && optical.get_hue() > 100 && optical.get_hue() < 200 && lock == false && sortToggle == true) {
		raiseHoodTask();
	}
	if (alliance == "red" && optical.get_hue() > 15 && optical.get_hue() < 40 && lock == false && sortToggle == true) {
		raiseHoodTask();
	}

	if (controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_B)) {
    	sortToggle = !sortToggle;
		optical.set_led_pwm((sortToggle == true ? 75 : 0)); // Turn off LED if not sorting
    }
}