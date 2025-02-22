#include "main.h"

void ring_rush() {
    alliance = "red";

    if (alliance == "red" || alliance == "na"){
    colourSortToggle = false;
    antiJamToggle = false;
    chassis.moveToPoint(0, 0, 1250);
    chassis.moveToPoint(-2.1, 45.651, 1450);
    intake.move_voltage(12000);
    leftDoinkerPiston.set_value(true);
    pros::delay(1435);
    chassis.moveToPoint(3.50, 17.704, 1550, {.forwards = false, .maxSpeed = 50});
    intake.move_voltage(0);
    pros::delay(1200);
    leftDoinkerPiston.set_value(false);
    // pros::delay(850);
    chassis.turnToHeading(230, 500, {.maxSpeed = 60}, false);

    // grab mogo
    pros::Task ([] {
        pros::delay(850);
        clampPiston.set_value(true);
        pros::delay(770);
        intake.move_voltage(12000);
    });
    chassis.moveToPoint(16.945, 28.287, 1450, {.forwards = false, .maxSpeed = 80}, false);

    //move to 2 ring stack
    chassis.moveToPoint(-23.34, 37.551, 2000, {.maxSpeed = 65});
    colourSortToggle = true;
    pros::delay(1810);
    // antiJamToggle = true;
    chassis.turnToHeading(200, 500);
    // chassis.moveToPoint(-14, 25, 1000, {.forwards = false});

    // travel to corner
    chassis.moveToPoint(-39.974, -2.218, 1650, {.maxSpeed= 75});
    pros::delay(600);

    // corner clear
    rightDoinkerPiston.set_value(true);
    chassis.turnToHeading(110.9, 1000, {.maxSpeed = 63});
    pros::delay(800);
    rightDoinkerPiston.set_value(false);
    //chassis.moveToPoint(-30, 9, 1000, {.forwards = false});
    pros::delay(100);
    chassis.moveToPoint(-27.5, -3, 800, {.maxSpeed = 80});
    pros::delay(200);
    // chassis.turnToHeading(110, 500);
    // pros::delay(300);
    // chassis.moveToPoint(6, -10, 3000, {.maxSpeed = 80});
    // chassis.moveToPoint(-8, 3.218, 600, {.minSpeed= 127});
    chassis.moveToPoint(-16, 4, 1000);
    chassis.moveToPoint(8, 3.7, 1250, {.maxSpeed = 60});
    pros::delay(300);
    // chassis.moveToPoint(32, -1, 1000, {.maxSpeed = 60});
    pros::delay(500);
    chassis.moveToPoint(75, -30, 4000);

    } else { // blue
        colourSortToggle = false;
        antiJamToggle = false;
        chassis.moveToPoint(0, 0, 1250);
        chassis.moveToPoint(2.1, 45.651, 1450);
        intake.move_voltage(12000);
        rightDoinkerPiston.set_value(true);
        pros::delay(1435);
        chassis.moveToPoint(-3.5, 17.704, 1550, {.forwards = false, .maxSpeed = 50});
        intake.move_voltage(0);
        pros::delay(1200);
        rightDoinkerPiston.set_value(false);
        // pros::delay(850);
        chassis.turnToHeading(130, 500, {.maxSpeed = 60}, false);
    
        // grab mogo
        pros::Task ([] {
            pros::delay(850);
            clampPiston.set_value(true);
            pros::delay(770);
            intake.move_voltage(12000);
        });
        chassis.moveToPoint(-16.945, 28.287, 1450, {.forwards = false, .maxSpeed = 80}, false);
    
        //move to 2 ring stack
        chassis.moveToPoint(23.34, 37.551, 2000, {.maxSpeed = 65});
        colourSortToggle = true;
        pros::delay(1810);
        // antiJamToggle = true;
        chassis.turnToHeading(160, 500);
        // chassis.moveToPoint(14, 25, 1000, {.forwards = false});
    
        // travel to corner
        chassis.moveToPoint(39.974, -2.218, 1650, {.maxSpeed= 75});
        pros::delay(600);
    
        // corner clear
        leftDoinkerPiston.set_value(true);
        chassis.turnToHeading(249.1, 1000, {.maxSpeed = 63});
        pros::delay(800);
        leftDoinkerPiston.set_value(false);
        //chassis.moveToPoint(30, 9, 1000, {.forwards = false});
        pros::delay(100);
        chassis.moveToPoint(27.5, -3, 800, {.maxSpeed = 80});
        pros::delay(200);
        // chassis.turnToHeading(250, 500);
        // pros::delay(300);
        // chassis.moveToPoint(-6, -10, 3000, {.maxSpeed = 80});
        // chassis.moveToPoint(8, 3.218, 600, {.minSpeed= 127});
        chassis.moveToPoint(16, 4, 1000);
        chassis.moveToPoint(-8, 3.7, 1250, {.maxSpeed = 60});
        pros::delay(300);
        // chassis.moveToPoint(-32, -1, 1000, {.maxSpeed = 60});
        pros::delay(500);
        chassis.moveToPoint(-75, -30, 4000);
    }
    
}