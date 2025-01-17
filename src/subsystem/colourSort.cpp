#include "main.h"

bool sortToggle = true;
bool lock = false;

// Colour Sorter


void initializeColourSort() {
	pros::Task([] {
		while (true) {
			if (alliance == "red" && optical.get_hue() > 100 && optical.get_hue() < 200 && lock == false && sortToggle == true) {
				// eject blue rings
			}
			if (alliance == "blue" && optical.get_hue() > 15 && optical.get_hue() < 40 && lock == false && sortToggle == true) {
				// eject red rings
			}
		
			if (controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_B)) {
    			sortToggle = !sortToggle;
				optical.set_led_pwm((sortToggle == true ? 75 : 0)); // Turn off LED if not sorting
    		}
		}
	});
}