#include "main.h"

void skills() { /* NO COLOUR SORT */

       chassis.moveToPoint(0, 0, 1000);
       wallStake.move_voltage(12000);
       pros::delay(510);
       wallStake.brake();
       chassis.moveToPoint(-0.038, 15.025, 1000, {.forwards = false, .maxSpeed = 80}); //mogo
       pros::Task([] {
              liftControl(wallstakeStates[0]);
              pros::delay(500);
              clampPiston.set_value(true);
              pros::delay(500);
               intake.move_voltage(12000);
        });
       chassis.moveToPoint(17.148, 37.401, 5000); //r1
       pros::Task([] {
              pros::delay(1200);
              liftControl(wallstakeStates[1]);
              pros::delay(1200);
              intake.move_voltage(0);
        });
       chassis.moveToPoint(36.962, 84.731, 5000); //wall ring
       // chassis.moveToPoint(9.566, 78.573, 5000); //r2
       // chassis.moveToPoint(6.237, 84.361, 5000); //r3
       // chassis.moveToPoint(1.235, 55.073, 5000); //r4&5
       // chassis.moveToPoint(-26.486, 30.112, 5000); //r6
       // chassis.moveToPoint(-23.423, 47.616, 5000); //corner
       //first corner

       // chassis.moveToPoint(-42.31, 40.021, 5000);
       // chassis.moveToPoint(25.875, -10.271, 5000);
       // chassis.moveToPoint(48.833, 2.558, 5000);
       // chassis.moveToPoint(95.949, 16.432, 5000);
       // chassis.moveToPoint(88.174, -9.078, 5000);
       // chassis.moveToPoint(91.554, -13.878, 5000);
       // chassis.moveToPoint(64.07, -15.409, 5000);
       // chassis.moveToPoint(37.752, -38.792, 5000);
       // chassis.moveToPoint(53.868, -39.967, 5000);
       // chassis.moveToPoint(43.597, -59.568, 5000);
       // chassis.moveToPoint(49.364, 34.722, 5000);
       // chassis.moveToPoint(97.581, 79.078, 5000);
       // chassis.moveToPoint(81.186, 87.531, 5000);
       // chassis.moveToPoint(64.129, 108.565, 5000);
       // chassis.moveToPoint(53.976, 100.678, 5000);
       // chassis.moveToPoint(47.059, 110.45, 5000);
       // chassis.moveToPoint(56.69, 127.279, 5000);
       // chassis.moveToPoint(53.463, 68.844, 5000);
       // chassis.moveToPoint(80.705, 65.765, 5000);
       // chassis.moveToPoint(116.273, 32.536, 5000);
       // chassis.moveToPoint(123.362, 22.92, 5000);
       // chassis.moveToPoint(126.634, 38.101, 5000);
       // chassis.moveToPoint(142.544, 29.838, 5000);
       // chassis.moveToPoint(112.646, 54.682, 5000);
       // chassis.moveToPoint(83.502, 34.088, 5000);
       // chassis.moveToPoint(66.918, 35.783, 5000);
       



       //old stuff
// intake.move_voltage(12000);
// pros::delay(400);
// intake.move_voltage(0);
// chassis.moveToPoint(0, 11, 1000);
// pros::delay(100);
// chassis.turnToHeading(90, 500);
// chassis.moveToPoint(-21 , 14, 1100, {.forwards = false, .maxSpeed = 60});
// pros::delay(800);
// clampPiston.set_value(true);
// chassis.turnToHeading(0, 600);
// intake.move_voltage(12000);
// chassis.moveToPoint(-20, 32, 500);
// chassis.moveToPoint(-38, 47, 800);
// chassis.moveToPoint(-47, 84, 1700);
// pros::delay(800);
// liftControl(wallstakeStates[1]);
// pros::delay(400);
// chassis.turnToHeading(180, 700);
// pros::delay(500);
// chassis.moveToPoint(-40, 63, 2700);
// pros::delay(1300);
// intake.move_voltage(0);
// // pros::delay(100);
// // wallStake.move_voltage(10000);
// // pros::delay(200);
// // wallStake.brake();
// chassis.turnToHeading(270, 700);
// // intake.move_voltage(12000);
// chassis.moveToPoint(-68, 63.7, 1000);
// intake.move_voltage(-100);
// chassis.turnToHeading(270, 400);
// liftControl(wallstakeStates[2]);
// chassis.moveToPoint(-68, 63.7, 1000);
// pros::delay(300);
// intake.move_voltage(12000);
// chassis.moveToPoint(-48, 63, 2000, {.forwards = false});
// pros::delay(200);
// chassis.turnToHeading(180, 700);
// chassis.moveToPoint(-48, 0, 2000, {.maxSpeed = 60});
// chassis.moveToPoint(-44, 15, 1000, {.forwards = false});
// chassis.turnToHeading(270, 700);
// chassis.moveToPoint(-62, 15, 1000);
// pros::delay(600);
// chassis.moveToPoint(-64, 0, 1000, {.forwards = false});
// pros::delay(700);
// clampPiston.set_value(false);

// pros::Task([] {
//        liftControl(wallstakeStates[0]);
// });


// chassis.moveToPoint(0, 10, 1500);
// intake.move_voltage(0);
// pros::delay(100);
// chassis.turnToHeading(270, 500);
// chassis.moveToPoint(30 , 9, 1100, {.forwards = false, .maxSpeed = 60});
// pros::delay(800);
// clampPiston.set_value(true);
// chassis.turnToHeading(0, 600);
// intake.move_voltage(12000);
// pros::delay(200);
// chassis.moveToPoint(24, 24, 1000);
// chassis.moveToPoint(42, 47, 900);
// chassis.moveToPoint(49, 82, 1300);
// pros::delay(900);
// liftControl(wallstakeStates[1]);
// pros::delay(400);
// chassis.turnToHeading(180, 700);
// chassis.moveToPoint(44, 58, 2800);
// pros::delay(1200);
// intake.move_voltage(0);
// pros::delay(100);
// chassis.turnToHeading(90, 700);
// // // intake.move_voltage(12000);
// chassis.moveToPoint(67, 57.7, 1000);
// // intake.move_voltage(-300);
// chassis.turnToHeading(90, 400);
// liftControl(wallstakeStates[2]);
// chassis.moveToPoint(67, 57.7, 1000);
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

void skillsCS() { /* WITH COLOUR SORT */

alliance = "red";

}