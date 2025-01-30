#include "main.h"

bool intakeLock = false;
bool colourSortToggle = false;

// Colour Sorter
void initializeColourSort() {
	pros::Task([] {
		while (true) {
			//console.printf("Hue: %d\n", optical.get_hue());
			if (colourSortToggle == true && (alliance == "red" && optical.get_hue() > 100 && optical.get_hue() < 230 ||
				alliance == "blue" && optical.get_hue() > 15 && optical.get_hue() < 27))  {
				// eject blue rings
				console.println("eject impostor");
				intakeLock = true;
				pros::delay(220);
				intake.brake();
				pros::delay(190);
				intake.move_voltage(12000);
				intakeLock = false;
			}

			if (controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_LEFT)) {
				colourSortToggle = !colourSortToggle;
			}

			pros::delay(10);
		}
	});
}