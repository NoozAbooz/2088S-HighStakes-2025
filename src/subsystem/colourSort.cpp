#include "main.h"

bool intakeLock = false;

// Colour Sorter
void initializeColourSort() {
	pros::Task([] {
		while (true) {
			//console.printf("Hue: %d\n", optical.get_hue());
			if (alliance == "red" && optical.get_hue() > 100 && optical.get_hue() < 230 ||
				alliance == "blue" && optical.get_hue() > 15 && optical.get_hue() < 27) {
				// eject blue rings
				console.println("eject impostor");
				intakeLock = true;
				pros::delay(220);
				intake.brake();
				pros::delay(190);
				intake.move_voltage(12000);
				intakeLock = false;
			}

			pros::delay(10);
		}
	});
}