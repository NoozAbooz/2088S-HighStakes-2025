#include "main.h"

void ring_rush() {
    alliance = "red";

    if (alliance == "red" || alliance == "na"){
    alliance = "na";
    chassis.moveToPoint(0, 0, 1250);
    chassis.moveToPoint(-2.5, 45.751, 1250);
    intake.move_voltage(12000);
    leftDoinkerPiston.set_value(true);
    pros::delay(1380);
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
        pros::delay(1100);
        intake.move_voltage(12000);
        alliance = "red";
    });
    chassis.moveToPoint(14.945, 28.287, 1450, {.forwards = false, .maxSpeed = 80}, false);

    // move to 2 ring stack
    chassis.moveToPoint(-23.934, 37.051, 1400, {.maxSpeed = 70});
    pros::delay(1600);
    chassis.turnToHeading(200, 500);
    // chassis.moveToPoint(-14, 25, 1000, {.forwards = false});

    // travel to corner
    chassis.moveToPoint(-39.974, -2.218, 1650, {.maxSpeed= 50});
    pros::delay(500);

    // corner clear
    rightDoinkerPiston.set_value(true);
    chassis.turnToHeading(113.5, 900, {.maxSpeed = 70});
    pros::delay(250);
    rightDoinkerPiston.set_value(false);
    pros::delay(800);
    
    chassis.setPose(0, 0, 0);
    chassis.moveToPoint(3, 14, 1250);
    chassis.moveToPoint(3, 40, 1000);

    chassis.moveToPoint(-12, 30, 1500);
    chassis.turnToHeading(-5, 1000, {}, false);

    chassis.setPose(0, 0, 0);
    chassis.moveToPoint(0, 62, 3000, {.maxSpeed = 80});
    

    } else { // blue

    }
    
}