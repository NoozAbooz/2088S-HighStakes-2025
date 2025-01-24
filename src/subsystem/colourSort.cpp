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
				intake.brake();
				pros::delay(600);
				intake.move_voltage(12000);
				intakeLock = false;
			}
			if (alliance == "blue" && optical.get_hue() > 15 && optical.get_hue() < 40) {
				// eject red rings
				intake.brake();
				console.println("eject red impostor");
			}

			pros::delay(10);
		}
	});
}