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

		int consequtiveTrigger = 0;
		while (true) {
			if (colourSortToggle == true && (alliance == "red" && optical.get_hue() > 160 && optical.get_hue() < 240) ||
				(alliance == "blue" && optical.get_hue() > 8 && optical.get_hue() < 35)) {

				if (consequtiveTrigger > 2) {
					pros::delay(1000);
					continue;
				}

				colourSortToggle = false;
				// eject blue rings
				console.println("eject impostor");
				intakeLock = true;

				int timer = 0;
				while (dist.get_distance() > 110 && timer < 800) {
					pros::delay(3);
					timer += 3;
				}

				pros::delay(25);
				intake.move_voltage(0);
				pros::delay(230);
				intake.move_voltage(12000);
				intakeLock = false;
				colourSortToggle = true;

				consequtiveTrigger++;
			} else {
				consequtiveTrigger = 0;
			}

			if (controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_LEFT)) {
				colourSortToggle = !colourSortToggle;
			}

			// anti-jam
			intakeVel = intake.get_actual_velocity();
			derivative = previousIntakeVel - intakeVel;

			if (derivative < -50 && intake.get_voltage() > 6000 && (wallStakeRotationSensor.get_angle() / 100) < wallstakeStates[1] && antiJamToggle == true) {
				console.println("anti-jam triggered");
				antiJamToggle = false;
				//intakeLock = true;
				intake.move_voltage(-10000);
				pros::delay(270);
				intake.move_voltage(12000);
				//intakeLock = false;
				antiJamToggle = true;
			}
			previousIntakeVel = intakeVel;

			pros::delay(3);
		}
});
}

int wallstakeStates[3] = {105, 130, 250};
int currState = 0;

ks::PIDConstants PIDconst(2.5, 0, 1);
ks::PID wallstakePID(&PIDconst);

void liftControl(double target) {
	wallstakePID.reset();
	double error = target - wallStakeRotationSensor.get_position() / 100.0;

	double timer = 0;

	wallStake.move(80);
	while (timer < 800) {
    	error = target - wallStakeRotationSensor.get_position() / 100.0;
    	wallStake.move(wallstakePID.output(error));

		if (fabs(error) < 2) {
			break;
		}

		timer += 10;
		pros::delay(10);
	}
	wallStake.brake();
}

void resetWallstakes() {
	pros::Task([] {
		isResetting = true;

		if (wallStakeRotationSensor.get_position() / 100.0 < wallstakeStates[1]) {
			liftControl(wallstakeStates[1]);
		} else if (wallStakeRotationSensor.get_position() / 100.0 > wallstakeStates[1]) {
			liftControl(wallstakeStates[0]);
		}

		controller.rumble(".");
		isResetting = false;
	});
}