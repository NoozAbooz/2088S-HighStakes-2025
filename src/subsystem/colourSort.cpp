#include "main.h"

bool intakeLock = false;

// Colour Sorter
void initializeColourSort() {
	pros::Task([] {
		while (true) {
			//console.printf("Hue: %d\n", optical.get_hue());
			if (alliance == "red" && optical.get_hue() > 100 && optical.get_hue() < 230) {
				// eject blue rings
				console.println("eject blue impostor");
				intakeLock = true;
				pros::delay(230);
				intake.brake();
				pros::delay(168);
				intake.move_voltage(12000);
				intakeLock = false;
			}
			if (alliance == "blue" && optical.get_hue() > 15 && optical.get_hue() < 27) {
				// eject red rings
				console.println("eject red impostor");
				intakeLock = true;
				pros::delay(230);
				intake.brake();
				pros::delay(168);
				intake.move_voltage(12000);
				intakeLock = false;
			}

			pros::delay(10);
		}
	});
}