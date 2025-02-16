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

void testPID() {
    chassis.moveToPoint(0, 24, 1000);
    intake.move_voltage(12000);
    //chassis.turnToHeading(90, 2000);
    //chassis.moveToPoint(24, 24, 1000);
}
void testBM() {
    chassis.moveToPose(24, 24, 90, 1500);
}
void calibrateOdomOffsets() {
    printf("Copy this:\n");
    printf("\\left[");

    chassis.turnToHeading(359, 1000, {.direction = lemlib::AngularDirection::CW_CLOCKWISE});
    while (chassis.isInMotion()) {
        printf("\\left(%f,%f\\right),", chassis.getPose().x, chassis.getPose().y);
        pros::delay(20);
    }

    printf("\\right]");
}

/* Legacy Auton Routines */
void driveForward() {
    while (isnanf(inertial1.get_rotation()) || isinf(inertial1.get_rotation())) {
		pros::delay(10);
	}
    cat.setBrakeMode(pros::E_MOTOR_BRAKE_BRAKE);
    cat.movePID(24, 2000);
    cat.movePID(24, 2000);
}

rd::Selector gui_selector({
    // {"E 5 Ring", Five_Ring},
    // {"Q 4 Ring + Bar", four_ring_bar},
    // {"Q SAWP 2 Mogo", SAWP_4},
    {"Mecha SAWP", sawp, "", 0},
    {"PID SAWP", pid_sawp, "", 0},
    {"Ring Rush", ring_rush, "", 0},
    {"Move forward", driveForward, "", 0},
    {"Skills", skills, "", 100},

    { "Test PID", testPID, "", 220},
    { "Test BM", testBM, "", 220},
    { "Odom Offsets", calibrateOdomOffsets, "", 220}
});

void autonomous() {
    inertial1.tare();
    inertial2.tare();

    if (alliance == "blue") {
        cat.mirrorAutons(true);
    }

    chassis.setPose(0, 0, 0);
    optical.set_led_pwm(100);
    field_status = "autonomous";
    console.println("Running auton...");
    gui_selector.run_auton();
}