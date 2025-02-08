#include "main.h"

bool intakeLock = false;
bool colourSortToggle = true;
bool antiJamToggle = true;

// Colour Sorter
void initializeColourSort() {
	pros::Task([] {
		double previousIntakeVel;
		double intakeVel;
		double derivative;
		while (true) {
			//console.printf("Hue: %d\n", optical.get_hue());
			if (colourSortToggle == true && (alliance == "red" && optical.get_hue() > 200 && optical.get_hue() < 230) ||
				(alliance == "blue" && optical.get_hue() > 8 && optical.get_hue() < 15)) {
				colourSortToggle = false;
				// eject blue rings
				console.println("eject impostor");
				intakeLock = true;
				pros::delay(240);
				intake.brake();
				pros::delay(220);
				intake.move_voltage(12000);
				intakeLock = false;
				colourSortToggle = true;
			}

			if (controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_LEFT)) {
				colourSortToggle = !colourSortToggle;
			}

			// anti-jam
			intakeVel = intake.get_actual_velocity();
			derivative = previousIntakeVel - intakeVel;

			if (derivative < -50 && intake.get_voltage() > 6000 && ((wallStakeRotationSensor.get_angle() / 100) < 20 || (wallStakeRotationSensor.get_angle() / 100) > 365) && antiJamToggle == true) {
				console.println("anti-jam triggered");
				antiJamToggle = false;
				intakeLock = true;
				intake.move_voltage(-8000);
				pros::delay(190);
				intake.move_voltage(12000);
				intakeLock = false;
				antiJamToggle = true;
			}

			previousIntakeVel = intakeVel;
			pros::delay(5);
		}
	});
}