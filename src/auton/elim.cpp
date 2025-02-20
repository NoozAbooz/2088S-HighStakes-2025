#include "main.h"

void ring_rush() {
    alliance = "red";

    if (alliance == "red" || alliance == "na"){
    chassis.moveToPoint(0, 0, 1250);
    colourSortToggle = false;
    chassis.moveToPoint(-2.5, 45.551, 1450);
    intake.move_voltage(12000);
    leftDoinkerPiston.set_value(true);
    pros::delay(1435);
    chassis.moveToPoint(4.35, 17.534, 1550, {.forwards = false, .maxSpeed = 55});
    intake.move_voltage(0);
    pros::delay(1200);
    leftDoinkerPiston.set_value(false);
    // pros::delay(850);
    chassis.turnToHeading(230, 500, {.maxSpeed = 60}, false);

    // grab mogo
    pros::Task ([] {
        pros::delay(790);
        clampPiston.set_value(true);
        pros::delay(760);
        intake.move_voltage(-12000);
        pros::delay(40);
        intake.move_voltage(12000);
    });
    chassis.moveToPoint(14.945, 28.287, 1450, {.forwards = false, .maxSpeed = 80}, false);

    // move to 2 ring stack
    chassis.moveToPoint(-23.34, 37.051, 2000, {.maxSpeed = 60});
    pros::delay(1600);
    chassis.turnToHeading(200, 500);
    // chassis.moveToPoint(-14, 25, 1000, {.forwards = false});

    // travel to corner
    chassis.moveToPoint(-39.974, -2.218, 1650, {.maxSpeed= 75});
    pros::delay(600);
         colourSortToggle = true;

    // corner clear
    rightDoinkerPiston.set_value(true);
    chassis.turnToHeading(112.7, 1000, {.maxSpeed = 59});
    pros::delay(500);
    rightDoinkerPiston.set_value(false);
    pros::delay(3);
    chassis.moveToPoint(-28.5, 9, 1000, {.forwards = false});
    pros::delay(100);
    chassis.moveToPoint(-30, -3, 1000, {.maxSpeed = 80});
    pros::delay(200);
    chassis.turnToHeading(110, 500);
    pros::delay(300);
    chassis.moveToPoint(6, -10, 3000, {.maxSpeed = 80});
    // chassis.moveToPoint(-8, 3.218, 600, {.minSpeed= 127});
    chassis.moveToPoint(9, 10, 1450);
    pros::delay(300);
    // chassis.moveToPoint(32, -1, 1000, {.maxSpeed = 60});
    pros::delay(500);
    chassis.moveToPoint(70, -18, 2000);

    } else { // blue

    }
    
}