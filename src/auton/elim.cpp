#include "main.h"

void ring_rush() {
    alliance = "red";

    if (alliance == "red" || alliance == "na"){
    chassis.moveToPoint(0, 0, 1250);
    colourSortToggle = false;
    chassis.moveToPoint(-2.5, 45.551, 1250);
    intake.move_voltage(12000);
    leftDoinkerPiston.set_value(true);
    pros::delay(1450);
    chassis.moveToPoint(0.837, 17.534, 1250, {.forwards = false, .maxSpeed = 100});
    intake.move_voltage(0);
    pros::delay(960);
    leftDoinkerPiston.set_value(false);
    // pros::delay(850);
    chassis.turnToHeading(230, 500, {}, false);

    // grab mogo
    pros::Task ([] {
        pros::delay(750);
        clampPiston.set_value(true);
        pros::delay(880);
        intake.move_voltage(12000);
        colourSortToggle = true;
    });
    chassis.moveToPoint(14.945, 28.287, 1450, {.forwards = false, .maxSpeed = 80}, false);

    // move to 2 ring stack
    chassis.moveToPoint(-23.934, 37.051, 1500, {.maxSpeed = 60});
    pros::delay(1600);
    chassis.turnToHeading(200, 500);
    // chassis.moveToPoint(-14, 25, 1000, {.forwards = false});

    // travel to corner
    chassis.moveToPoint(-39.974, -2.218, 1650, {.maxSpeed= 50});
    pros::delay(500);

    // corner clear
    rightDoinkerPiston.set_value(true);
    chassis.turnToHeading(113.5, 1100, {.maxSpeed = 69});
    pros::delay(250);
    rightDoinkerPiston.set_value(false);
    pros::delay(300);
    chassis.moveToPoint(-30, 9, 1000, {.forwards = false});
    pros::delay(100);
    chassis.moveToPoint(-39, -3, 1000);
    pros::delay(200);
    chassis.turnToHeading(110, 500);
    chassis.moveToPoint(-10, 3, 3000, {.maxSpeed = 80});
    pros::delay(100);
    chassis.moveToPoint(-8, 6.218, 600, {.minSpeed= 127});
    chassis.moveToPoint(10.174, -1.218, 1050, {.minSpeed= 80});
    chassis.moveToPoint(32, -1, 1000, {.maxSpeed = 60});
    pros::delay(500);
    chassis.moveToPoint(70, -10, 2000);

    } else { // blue

    }
    
}