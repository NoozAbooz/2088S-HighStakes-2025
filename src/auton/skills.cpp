#include "main.h"

void skills() {

intake.move_voltage(12000);
pros::delay(400);
intake.move_voltage(0);
chassis.moveToPoint(0, 11, 1000);
pros::delay(100);
chassis.turnToHeading(90, 500);
chassis.moveToPoint(-21 , 14, 1100, {.forwards = false, .maxSpeed = 60});
pros::delay(800);
clampPiston.set_value(true);
chassis.turnToHeading(0, 600);
intake.move_voltage(12000);
chassis.moveToPoint(-20, 32, 700);
chassis.moveToPoint(-38, 47, 900);
chassis.moveToPoint(-45, 86, 1700);
pros::delay(900);
liftControl(wallstakeStates[1]);
pros::delay(400);
chassis.turnToHeading(180, 700);
pros::delay(500);
chassis.moveToPoint(-40, 63, 3000);
pros::delay(1200);
intake.move_voltage(0);
// pros::delay(100);
// wallStake.move_voltage(10000);
// pros::delay(200);
// wallStake.brake();
chassis.turnToHeading(270, 700);
// intake.move_voltage(12000);
chassis.moveToPoint(-67, 61.7, 1000);
intake.move_voltage(-300);
chassis.turnToHeading(270, 400);
liftControl(wallstakeStates[2]);
chassis.moveToPoint(-67, 61.7, 1000);
pros::delay(300);
intake.move_voltage(12000);
chassis.moveToPoint(-48, 63, 2000, {.forwards = false});
pros::delay(200);
chassis.turnToHeading(180, 700);
chassis.moveToPoint(-48, 4, 2000, {.maxSpeed = 60});
chassis.moveToPoint(-44, 15, 1000, {.forwards = false});
chassis.turnToHeading(270, 700);
chassis.moveToPoint(-62, 15, 1000);
pros::delay(400);
chassis.moveToPoint(-64, 0, 1000, {.forwards = false});
pros::delay(700);
clampPiston.set_value(false);
pros::delay(200);

intake.move_voltage(0);
liftControl(wallstakeStates[0]);

chassis.moveToPoint(0, 11, 2000);
pros::delay(100);
chassis.turnToHeading(270, 500);
chassis.moveToPoint(21 , 10, 1100, {.forwards = false, .maxSpeed = 60});
pros::delay(800);
clampPiston.set_value(true);
chassis.turnToHeading(0, 600);
// intake.move_voltage(12000);
// chassis.moveToPoint(20, 30, 700);
// chassis.moveToPoint(38, 47, 900);
// chassis.moveToPoint(45, 84, 1300);
// pros::delay(700);
// liftControl(wallstakeStates[1]);
// pros::delay(400);
// chassis.turnToHeading(180, 700);
// pros::delay(500);
// chassis.moveToPoint(40, 63, 3000);
// pros::delay(1200);
// intake.move_voltage(0);
// // pros::delay(100);
// // wallStake.move_voltage(10000);
// // pros::delay(200);
// // wallStake.brake();
// chassis.turnToHeading(90, 700);
// // intake.move_voltage(12000);
// chassis.moveToPoint(67, 61.7, 1000);
// intake.move_voltage(-300);
// chassis.turnToHeading(90, 400);
// liftControl(wallstakeStates[2]);
// chassis.moveToPoint(67, 61.7, 1000);
// pros::delay(300);
// intake.move_voltage(12000);
// chassis.moveToPoint(48, 63, 2000, {.forwards = false});
// pros::delay(200);
// chassis.turnToHeading(180, 700);
// chassis.moveToPoint(48, 0, 2000, {.maxSpeed = 70});
// chassis.moveToPoint(44, 15, 1000, {.forwards = false});
// chassis.turnToHeading(90, 700);
// chassis.moveToPoint(60, 15, 1000);
// pros::delay(300);
// chassis.moveToPoint(63, 0, 1000, {.forwards = false});
// pros::delay(700);
// clampPiston.set_value(false);



}