#include "main.h"

/**
 * Runs the user autonomous code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the autonomous
 * mode. Alternatively, this function may be called in initialize or opcontrol
 * for non-competition testing purposes.
 *
 * If the robot is disabled or communications is lost, the autonomous task
 * will be stopped. Re-enabling the robot will restart the task, not re-start it
 * from where it left off.
 */

std::string autonName = "noname";

void testPID() {
    autonName = "PID Test";
    chassis.setPose(0, 0, 0);
    // chassis.moveToPoint(0, 24, 5000);
    chassis.turnToHeading(90, 1000);
    // chassis.moveToPoint(24, 24, 5000);
    
}

ASSET(test_txt);
void testPP() {
    chassis.setPose(-58, -46, 90);
    chassis.follow(test_txt, 20, 15000);
}

void testBM() {
    chassis.setPose(0, 0, 0);
    chassis.moveToPose(52, 6, 320, 1000, {.forwards = false});
}

void WP_3Rush() {
    autonName = "WP 3Rush";
    chassis.setPose(0, 0, 290);
    chassis.moveToPose(60, -20.5, 290, 2000, {.forwards = false, .horizontalDrift = 4, .lead = 0.2, .minSpeed = 50}, false);
    clampPiston.set_value(true);
    intake.move_voltage(12000);
    chassis.moveToPoint(34, -25, 2000);
    chassis.moveToPoint(-8, -44, 2000);
}

void skills() {

}

rd::Selector gui_selector({
    {"WP Rush", &WP_3Rush},

    {"PID test", &testPID},
    {"PP test", &testPP},
    {"BM test", &testBM}
});

void autonomous() {
    //initializeColourSort();
    controller.print(0, 0, "Auton: %s | %.0lf   ", autonName.c_str(), chassis.getPose().theta);
    chassis.setPose(0,0,0);
    console.println("Running auton...");
    gui_selector.run_auton();
}

void driverSkillsMacro() {
    pros::Task skillsTask(skills, "skills");

    pros::Task([&] {
        while (true) {
		    if (controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_DOWN)) {
                skillsTask.remove();
                chassis.cancelAllMotions();
                break;
		    }
        }
	});
}

/* Legacy Auton Routines */

// collect mogo, score preload and ring to the side. works for either alliance
void scrimLeftSide(){
    clampPiston.set_value(false);
    chassis.moveToPoint(0, -28, 1000, {.forwards = false, .maxSpeed = 70});
    pros::delay(1500);
    clampPiston.set_value(true);
    intake.move_voltage(12000);
    pros::delay(2000);

    chassis.moveToPoint(20, -32, 1000);
    pros::delay(3000);
    chassis.moveToPoint(50, -32, 4000, {.minSpeed = 127});
    pros::delay(3000);
    clampPiston.set_value(false);
}
void scrimRightSide(){
    clampPiston.set_value(false);
    chassis.moveToPoint(0, -28, 1000, {.forwards = false, .maxSpeed = 70});
    pros::delay(1500);
    clampPiston.set_value(true);
    intake.move_voltage(12000);
    pros::delay(2000);

    chassis.moveToPoint(-20, -32, 1000);
    pros::delay(3000);
    chassis.moveToPoint(-50, -32, 4000, {.minSpeed = 127});
    pros::delay(3000);
    clampPiston.set_value(false);
}