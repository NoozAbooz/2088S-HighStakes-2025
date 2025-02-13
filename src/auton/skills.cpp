#include "main.h"

void skills() {

intake.move_voltage(12000);
pros::delay(400);
intake.move_voltage(0);
chassis.moveToPoint(0, 9, 1000);
pros::delay(100);
chassis.turnToHeading(90, 500);
chassis.moveToPoint(-19 ,14, 1100, {.forwards = false, .maxSpeed = 60});
pros::delay(800);
clampPiston.set_value(true);
chassis.turnToHeading(0, 600);
intake.move_voltage(12000);
chassis.moveToPoint(-20, 30, 700);
chassis.moveToPoint(-38, 47, 900);
chassis.moveToPoint(-45, 84, 1300);
pros::delay(400);
liftControl(wallstakeStates[1]);
pros::delay(600);
chassis.turnToHeading(180, 700);
pros::delay(400);
chassis.moveToPoint(-40, 63, 3000);
pros::delay(1100);
intake.move_voltage(0);
// pros::delay(100);
// wallStake.move_voltage(10000);
// pros::delay(200);
// wallStake.brake();
chassis.turnToHeading(270, 700);
// intake.move_voltage(12000);
chassis.moveToPoint(-67, 61.5, 1000);
intake.move_voltage(-300);
chassis.turnToHeading(270, 400);
pros::delay(200);
liftControl(wallstakeStates[2]);
pros::delay(400);
intake.move_voltage(12000);
chassis.moveToPoint(-48, 63, 2000, {.forwards = false});
pros::delay(400);
liftControl(wallstakeStates[0]);



}