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
	pros::Task([] { // run only in competition
		if (isCompetition == true) {
			Gif* gif = new Gif("/usd/nokotan.gif", rd_view_obj(gifview));
			rd_view_focus(gifview);
			console.println("Running gif...");
		}
	});

	while (true) { // Main continuous loop
		/* Drive */
		ks::arcadeDrive(0, 0, 0.8);

		/* Subsystem Listeners */
		refreshIntake();
		refreshClamp();
		refreshDoinker();
		refreshWallstakes();
		resetWallstakes();

		// Report temperature telemetry 😭
		double drivetrainTemps = ks::vector_average(leftDrive.get_temperature_all());
		controller.print(0, 0, "DT%.0lf INT%.0lf %.0lf   ", drivetrainTemps, intake.get_temperature(), chassis.getPose().theta);
		//controller.print(0, 0, "X%.0lf Y%.0lf ROT%.0lf   ", chassis.getPose().x, chassis.getPose().y, chassis.getPose().theta);
		pros::delay(10); // Delay to save resources on brain
	}
}