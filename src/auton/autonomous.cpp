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

void half_sawp() {
    if (alliance == "red" || alliance == "na"){
        chassis.moveToPoint(0, 0, 1250);
        wallStake.move_voltage(10000);
        pros::delay(670);
        wallStake.move_voltage(-10000);
        pros::delay(300);
        wallStake.brake();
        chassis.moveToPoint(-37.1, -20.926, 1750, {.forwards = false, .maxSpeed = 65});
        pros::delay(1640);
        clampPiston.set_value(true);
        pros::delay(100);
        intake.move_voltage(12000);
        chassis.moveToPoint(-42.426, -39.767, 1450);
        chassis.turnToHeading(165, 500);
        chassis.moveToPoint(-39.945, -61.267, 1350, {.minSpeed = 80});
        chassis.moveToPoint(-37.326, -36.767, 1250, {.forwards = false});
        chassis.moveToPoint(-27.352, -49.075, 1000);
        chassis.moveToPoint(-34, -17, 2000);
        chassis.turnToHeading(270, 1000);
        wallStake.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
        wallStake.move_voltage(12000);
        pros::delay(300);
        wallStake.move_voltage(0);
    } else {
        chassis.moveToPoint(0, 0, 1250);
        wallStake.move_voltage(10000);
        pros::delay(670);
        wallStake.move_voltage(-10000);
        pros::delay(300);
        wallStake.brake();
        chassis.moveToPoint(36.1, -19.526, 1750, {.forwards = false, .maxSpeed = 65});
        pros::delay(1590);
        clampPiston.set_value(true);
        pros::delay(800);
        intake.move_voltage(12000);
        chassis.moveToPoint(42.326, -38.767, 1250);
        chassis.turnToHeading(195, 500);
        chassis.moveToPoint(39.845, -62.267, 1550);
        chassis.moveToPoint(38.326, -36.767, 1250, {.forwards = false});
        chassis.moveToPoint(26.352, -48.075, 1000);
        chassis.moveToPoint(34, -17, 2000);
        chassis.turnToHeading(45, 1000);
        wallStake.move_voltage(10000);
        pros::delay(200);
        wallStake.move_voltage(0);
    }
}

void sawp() {
    if (alliance == "red" || alliance == "na") {
        chassis.moveToPoint(0, 0, 1250);
        wallStake.move_voltage(10000);
        pros::delay(670);
        wallStake.move_voltage(-10000);
        pros::delay(300);
        wallStake.brake();
        chassis.moveToPoint(-36.1, -19.526, 1750, {.forwards = false, .maxSpeed = 65});
        pros::delay(1620);
        clampPiston.set_value(true);
        pros::delay(100);
        intake.move_voltage(12000);
        chassis.moveToPoint(-42.426, -39.767, 1250);
        chassis.turnToHeading(165, 500);
        chassis.moveToPoint(-40.045, -61.267, 1350, {.maxSpeed = 115});
        chassis.moveToPoint(-38.326, -36.767, 1250, {.forwards = false});
        chassis.moveToPoint(-27.352, -49.075, 1000);
        chassis.moveToPoint(-20.042, 5.3, 1250);
        pros::delay(900);
        intake.move_voltage(0);
        pros::delay(850);
        clampPiston.set_value(false);
        pros::delay(200);
        chassis.moveToPoint(-41.971, 22.681, 1850, {.forwards = false});
        pros::delay(1100);
        clampPiston.set_value(true);
        intake.move_voltage(12000);
        pros::delay(300);
        chassis.moveToPoint(-51.858, 46.824, 1150);
        pros::delay(1000);
        chassis.moveToPoint(-48.552, 16.16, 1300);
        pros::delay(1150);
        wallStake.move_voltage(11000);
        pros::delay(100);
        wallStake.brake();
    } else {
        chassis.moveToPoint(0, 0, 1250);
        wallStake.move_voltage(10000);
        pros::delay(670);
        wallStake.move_voltage(-10000);
        pros::delay(300);
        wallStake.brake();
        chassis.moveToPoint(36.1, -19.826, 1750, {.forwards = false, .maxSpeed = 65});
        pros::delay(1620);
        clampPiston.set_value(true);
        pros::delay(800);
        intake.move_voltage(12000);
        chassis.moveToPoint(42.326, -38.767, 1250);
        chassis.turnToHeading(195, 500);
        chassis.moveToPoint(39.745, -62.967, 1250);
        chassis.moveToPoint(38.326, -36.767, 1250, {.forwards = false});
        chassis.moveToPoint(26.352, -48.075, 1000);
        chassis.moveToPoint(20.042, 10.3, 1250);
        pros::delay(900);
        intake.move_voltage(0);
        pros::delay(850);
        clampPiston.set_value(false);
        pros::delay(200);
        chassis.moveToPoint(41.971, 22.681, 1850, {.forwards = false});
        pros::delay(1100);
        clampPiston.set_value(true);
        intake.move_voltage(12000);
        pros::delay(300);
        chassis.moveToPoint(51.858, 46.824, 1150);
        pros::delay(1000);
        chassis.moveToPoint(48.552, 16.16, 1300);
        pros::delay(1150);
        wallStake.move_voltage(11000);
        pros::delay(100);
        wallStake.brake();
    }
}

void SIG_SAWP() {

}

void ring_rush() {
    if (alliance == "red" || alliance == "na"){
    chassis.moveToPoint(0, 0, 1250);
    chassis.moveToPoint(-1.8, 46.251, 1250);
    intake.move_voltage(12000);
    leftDoinkerPiston.set_value(true);
    pros::delay(1480);
    intake.move_voltage(0);
    chassis.moveToPoint(-0.037, 17.634, 1050, {.forwards = false, .maxSpeed = 80});
    pros::delay(860);
    leftDoinkerPiston.set_value(false);
    // pros::delay(850);
    chassis.turnToHeading(230, 500);
    chassis.moveToPoint(14.945, 28.287, 1450, {.forwards = false, .maxSpeed = 80});
    pros::delay(750);
    clampPiston.set_value(true);
    pros::delay(270);
    intake.move_voltage(12000);
    chassis.moveToPoint(-21.934, 37.051, 1200);
    pros::delay(800);
    chassis.moveToPoint(-14, 25, 1000, {.forwards = false});
    chassis.moveToPoint(-39.674, -2.218, 1650, {.maxSpeed= 90});
    pros::delay(500);
    rightDoinkerPiston.set_value(true);
    chassis.turnToHeading(112, 500, {.maxSpeed = 80});
    pros::delay(250);
    rightDoinkerPiston.set_value(false);
    pros::delay(100);
    chassis.moveToPoint(-30, 9, 1000, {.forwards = false});
    pros::delay(400);
    chassis.moveToPoint(-38, -3, 800);
    chassis.moveToPoint(-33, 0, 1000, {.forwards = false});
    pros::delay(600);
    chassis.turnToHeading(110, 500);
    chassis.moveToPoint(-15, -7, 3000, {.maxSpeed = 90});
    pros::delay(100);
    chassis.moveToPoint(-5, 3.218, 600, {.minSpeed= 127});
    // chassis.moveToPoint(-44.174, -15.218, 1850, {.maxSpeed= 80});
    // pros::delay(2000);
    // chassis.moveToPoint(-22, -1, 1000, {.forwards = false});
    // pros::delay(100);
    chassis.moveToPoint(10.174, -1.218, 1050, {.minSpeed= 80});
    chassis.moveToPoint(32, -1, 1000, {.maxSpeed = 60});
    pros::delay(500);
    chassis.moveToPoint(70, -10, 2000);

    // resetWallstake();
    // chassis.turnToHeading(205, 500);
    // chassis.moveToPoint(18, 0, 1000);

    // resetWallstakes();
    antiJamToggle = false;
    // intakeLiftPiston.set_value(true);
    // pros::delay(1050);
    // intakeLiftPiston.set_value(false);
    // pros::delay(1200);
    // chassis.moveToPoint(21.5, -18.3, 1200);
    // pros::delay(100);
    // intake.move_voltage(-500);
    // wallStake.move_voltage(12000);
    // pros::delay(900);
    // wallStake.brake();
    // chassis.moveToPoint(-39.384, 5.946, 1250);
    // chassis.moveToPoint(24.607, 3.935, 1250);

    } else { // blue
    chassis.moveToPoint(0, 0, 1250);
    chassis.moveToPoint(1.6, 46.251, 1250);
    intake.move_voltage(12000);
    rightDoinkerPiston.set_value(true);
    pros::delay(1480);
    intake.move_voltage(0);
    chassis.moveToPoint(0.037, 17.634, 1050, {.forwards = false, .maxSpeed = 80});
    pros::delay(860);
    rightDoinkerPiston.set_value(false);
    // pros::delay(850);
    chassis.turnToHeading(130, 500);
    chassis.moveToPoint(-14.945, 28.287, 1450, {.forwards = false, .maxSpeed = 80});
    pros::delay(750);
    clampPiston.set_value(true);
    pros::delay(270);
    intake.move_voltage(12000);
    chassis.moveToPoint(22.934, 37.051, 1200);
    pros::delay(800);
    chassis.moveToPoint(14, 25, 1000, {.forwards = false});
    chassis.moveToPoint(39.674, -2.218, 1650, {.maxSpeed= 90});
    pros::delay(500);
    leftDoinkerPiston.set_value(true);
    chassis.turnToHeading(250, 500, {.maxSpeed = 80});
    pros::delay(250);
    leftDoinkerPiston.set_value(false);
    pros::delay(200);
    chassis.moveToPoint(38, -2.5, 1200);
    chassis.moveToPoint(36, -1, 1000, {.forwards = false});
    pros::delay(600);
    chassis.turnToHeading(250, 500);
    chassis.moveToPoint(10, -7, 3000, {.maxSpeed = 90});
    pros::delay(100);
    chassis.moveToPoint(5, 3.218, 600, {.minSpeed= 127});
    // chassis.moveToPoint(44.174, -15.218, 1850, {.maxSpeed= 80});
    // pros::delay(2000);
    // chassis.moveToPoint(22, -1, 1000, {.forwards = false});
    // pros::delay(100);
    chassis.moveToPoint(-10.174, .218, 1050, {.minSpeed= 80});
    chassis.moveToPoint(-32, -1, 1000, {.maxSpeed = 60});
    pros::delay(500);
    chassis.moveToPoint(-70, -10, 2000);

    // resetWallstake();
    // chassis.turnToHeading(155, 500);
    // chassis.moveToPoint(-18, 0, 1000);

    // resetWallstakes();
    antiJamToggle = false;
    }
    
}

void superScuffedSkills () {
    wallStake.move_voltage(10000);
        pros::delay(670);
        wallStake.move_voltage(-10000);
        pros::delay(300);
        wallStake.brake();

    chassis.moveToPoint(0, -20, 1000, {.forwards = false});
    pros::delay(800);
    clampPiston.set_value(true);
    pros::delay(100);

    chassis.turnToHeading(200, 1000);
    chassis.setPose(0, 0, 0);

    intake.move_voltage(12000);
    chassis.moveToPoint(0, 24, 1000);
}

/* Legacy Auton Routines */
void driveForward() {
    chassis.moveToPoint(0, 24, 1000);
}

rd::Selector gui_selector({
    // {"E 5 Ring", Five_Ring},
    // {"Q 4 Ring + Bar", four_ring_bar},
    // {"Q SAWP 2 Mogo", SAWP_4},
    {"Mecha SAWP", sawp},
    {"Half SAWP", half_sawp},
    {"Ring Rush", ring_rush},
    {"Move forward", driveForward},
    // {"Skills", skills, "", 0},

    { "Test PID", testPID},
    { "Test BM", testBM},
    { "Odom Offsets", calibrateOdomOffsets}
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