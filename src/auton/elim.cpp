#include "main.h"

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