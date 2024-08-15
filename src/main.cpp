#include "main.h"

/**
 * Runs the operator control code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled.
 *
 * If the robot is disabled or communications is lost, the
 * operator control task will be stopped. Re-enabling the robot will not resume 
 * the task from where it left off.
 */
void opcontrol() {
	while (true) { // Main continuous loop
		/* Drive */
		ks::arcadeDrive(0, 0, 1);

		/* Subsystem Listeners */
		refreshIntake();
		refreshClamp();

		// Report temperature telemetry (this code has never worked since the beginning 😭)
		double drivetrainTemps = ks::vector_average(leftDrive.get_temperature_all());
		controller.print(0, 0, "DT%.0lf %.0lf %.0lf", drivetrainTemps, chassis.getPose().x, chassis.getPose().y);

		pros::delay(10); // Delay to save resources on brain
	}
}