#include "main.h"

void skills() {
    clampPiston.set_value(true);
    chassis.moveToPoint(-0.233, -5.595, 300);
    intake.move_voltage(12000);
    pros::delay(650);
    chassis.moveToPoint(-0.466, 11.424, 1000);
    clampPiston.set_value(false);
    chassis.turnToHeading(90, 500);
    chassis.moveToPoint(-23.118, 13.424, 1400, {.forwards = false, .maxSpeed = 50}); // Mogo
    pros::delay(1050);
    clampPiston.set_value(true);
    chassis.turnToHeading(0, 400);  
    chassis.moveToPoint(-24.014, 37.971, 900); // Ring 1
    chassis.turnToHeading(315, 500);
    chassis.moveToPoint(-59.818, 62.586, 1200); // Ring 2
    pros::delay(1400);
    chassis.moveToPoint(-56, 58.286, 800, {.forwards = false});
    chassis.turnToHeading(180, 500);
    chassis.moveToPoint(-47.994, 35.438, 1100, {.maxSpeed = 55}); // Ring 3
    pros::delay(1400);
    chassis.moveToPoint(-47.927, 14.123, 1100, {.maxSpeed = 55}); // Ring 4
    pros::delay(1600);
    chassis.moveToPoint(-47.928, -0.999, 1100, {.maxSpeed = 55}); // Ring 5
    pros::delay(1300);
    chassis.moveToPoint(-44, 11, 1000, {.forwards = false});    
    chassis.turnToHeading(270, 500);
    chassis.moveToPoint(-59.617, 11.725, 1000); // Ring 6
    pros::delay(1000);
    chassis.moveToPoint(-60, 12, 1000, {.forwards = false});
    chassis.moveToPoint(-69.384, -6.098, 1200, {.forwards = false});
    pros::delay(1100);
    clampPiston.set_value(false);
    pros::delay(500);

    chassis.moveToPoint(0.466, 11.424, 1500);
    clampPiston.set_value(false);
    chassis.turnToHeading(270, 700);
    pros::delay(100);
    chassis.moveToPoint(34.118, 14.924, 2200, {.forwards = false, .maxSpeed = 50}); // Mogo
    pros::delay(1500);
    clampPiston.set_value(true);
    pros::delay(500);
    chassis.turnToHeading(0, 400);  
    chassis.moveToPoint(30.014, 33.971, 900); // Ring 1
    chassis.turnToHeading(45, 500);
    chassis.moveToPoint(62.918, 62.686, 1200); // Ring 2
    pros::delay(1500);
    chassis.moveToPoint(56, 60, 800, {.forwards = false});
    chassis.turnToHeading(180, 500);
    chassis.moveToPoint(53.524, 35.438, 1100, {.maxSpeed = 55}); // Ring 3
    pros::delay(1300);
    chassis.moveToPoint(52.927, 16.123, 1100, {.maxSpeed = 55}); // Ring 4
    pros::delay(1300);
    chassis.moveToPoint(52.928, -0.999, 1100, {.maxSpeed = 55}); // Ring 5
    pros::delay(1300);
    chassis.moveToPoint(44, 11, 1000, {.forwards = false});    
    chassis.turnToHeading(90, 600);
    chassis.moveToPoint(62.617, 11.725, 1000); // Ring 6
    pros::delay(700);
    chassis.moveToPoint(60, 12, 1000, {.forwards = false});
    chassis.moveToPoint(69.384, -6.098, 1200, {.forwards = false});
    pros::delay(1100);
    clampPiston.set_value(false);
    pros::delay(500);
    chassis.moveToPoint(-23, 90, 2500);
    pros::delay(2300);
    intake.move_voltage(0);
    chassis.turnToHeading(225, 600);
    chassis.moveToPoint(8, 120, 2200, {.forwards = false, .maxSpeed = 50});
    pros::delay(1900);
    clampPiston.set_value(true);
    pros::delay(500);
    intake.move_voltage(12000);
    pros::delay(800);
    chassis.moveToPoint(22, 96, 1000);
    pros::delay(1000);
    chassis.moveToPoint(57, 96, 2000, {.maxSpeed = 75});
    pros::delay(1000);
    chassis.turnToHeading(0, 500);
    chassis.moveToPoint(57, 113, 800);
    pros::delay(800);
    chassis.moveToPoint(63, 95, 1600, {.forwards = false, .maxSpeed = 50});
    chassis.moveToPoint(67, 113, 800);
    pros::delay(1200);
    chassis.moveToPoint(59, 130, 800);
    pros::delay(1000);
    chassis.moveToPoint(59, 120, 800, {.forwards = false});
    chassis.turnToHeading(225, 700);
    pros::delay(1100);
    intake.move_voltage(0);
    chassis.moveToPoint(69, 130, 1000, {.forwards = false});
    pros::delay(800);
    clampPiston.set_value(false);
    pros::delay(500);
    chassis.moveToPoint(30, 120, 2000);
    chassis.turnToHeading(90, 600);
    chassis.moveToPoint(25, 110, 1000, {.forwards = false});
    chassis.moveToPoint(-25, 125, 1000, {.forwards = false});
    chassis.moveToPoint(-64, 128, 1800, {.forwards = false, .minSpeed = 127});
    intake.move_voltage(12000);
    chassis.moveToPoint(-59, 107, 2000);
    pros::delay(1200);
    intake.move_voltage(0);
    chassis.moveToPoint(4.5, 110, 2400);
    chassis.turnToHeading(180, 600);
    chassis.moveToPoint(4.5, 135, 2000, {.forwards = false}); 
    pros::delay(100);
    intake.move_voltage(12000);
    pros::delay(500);
}