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

std::string autonName = "noname";

void testPID() {
    autonName = "PID Test";
    chassis.setPose(0, 0, 0);
    // chassis.moveToPoint(0, 24, 5000);
    chassis.turnToHeading(90, 1000);
    // chassis.moveToPoint(24, 24, 5000);
    
}

ASSET(test_txt);
void Five_Ring() {
    chassis.moveToPoint(0, 0, 1000); // Start
    chassis.moveToPoint(0, -14.237, 1000, {.forwards = false}); // Mogo  
    pros::delay(20);
    chassis.turnToHeading(45, 500); 
    pros::delay(20);
    chassis.moveToPoint(-9.788, -27.808, 1000, {.forwards = false}); // Mogo
    pros::delay(790);
    clampPiston.set_value(true);
    pros::delay(20);
    intake.move_voltage(12000); // Preload
    pros::delay(800);
    chassis.moveToPoint(4.786, -26.589, 1000); // Ring 2
    pros::delay(1000); 
    chassis.turnToHeading(180, 500);  
    chassis.moveToPoint(6.841, -39.986, 1000); // Ring 3
    pros::delay(1000);
    chassis.moveToPoint(12.68, -29.144, 1300, {.forwards = false}); 
    pros::delay(200);
    chassis.moveToPoint(14.505, -40.686, 1000);
    pros::delay(1100);
    chassis.moveToPoint(-3.559, -34.032, 1000, {.forwards = false});
    chassis.turnToHeading(45, 600);
    chassis.moveToPoint(27.695, 3.009, 1200);
    pros::delay(1500);
    chassis.moveToPoint(0.695, -30.009, 1500, {.forwards = false, .maxSpeed = 50});
    chassis.moveToPoint(27.695, 3.009, 1200, {.forwards = true, .maxSpeed = 70});



}

void testBM() {
    chassis.setPose(0, 0, 0);
    chassis.moveToPose(52, 6, 320, 1000, {.forwards = false});
}

void WP_3Rush() {
    autonName = "WP 3Rush";
    chassis.moveToPose(0, 0, 315, 5000, {.forwards = false, .horizontalDrift = 7});
    pros::delay(790);
    clampPiston.set_value(true);
    chassis.moveToPose(9.326, -47.794, 270, 5000, {.forwards = false, .horizontalDrift = 7});
    chassis.moveToPoint(24.946, -13.056, 5000);
    chassis.moveToPoint(33.806, -26.112, 5000);
    chassis.moveToPoint(13.289, -30.775, 5000);
    chassis.moveToPoint(57.586, -30.308, 5000);

}

void scrimRightSide(){
    clampPiston.set_value(false);
    chassis.moveToPoint(0, -28, 1000, {.forwards = false, .maxSpeed = 70});
    pros::delay(1500);
    clampPiston.set_value(true);
    intake.move_voltage(12000);
    pros::delay(2000);

    chassis.moveToPoint(-19, -30, 1600);
    pros::delay(2000);
    chassis.moveToPoint(24, -24, 2000);
    pros::delay(2000);
    wallStake.move_voltage(10000);
    pros::delay(500);
    wallStake.brake();
    // chassis.moveToPoint(-44, 9, 4000, {.minSpeed = 127});
    // pros::delay(2000);

}

void scrimLeftSide(){ // not updated yet
    clampPiston.set_value(false);
    chassis.moveToPoint(0, -28, 1000, {.forwards = false, .maxSpeed = 70});
    pros::delay(1500);
    clampPiston.set_value(true);
    intake.move_voltage(12000);
    pros::delay(2000);

    chassis.moveToPoint(20, -32, 1000);
    pros::delay(3000);
    chassis.moveToPoint(50, -32, 4000, {.minSpeed = 127});
    pros::delay(3000);
    clampPiston.set_value(false);
}

void skills() {
    //all test code right now will tue Nov 15, 2024 :D
    chassis.moveToPoint(0, 0, 500); //start
    intake.move_voltage(12000); //red alliance
    pros::delay(1000); //time to intake preload
    chassis.moveToPoint(0.199, 15.955, 700); //move foward
    chassis.turnToHeading(270, 400); //turn 90 deg
    chassis.moveToPoint(22.145, 13.959, 800, {.forwards = false}); //move to mogo
    pros::delay(750); //time to intake
    clampPiston.set_value(true); //clamp mogo
    chassis.moveToPoint(24.527, 28.685, 1200); //ring 1
    pros::delay(1000); //time to intake
    chassis.moveToPoint(47, 27, 1300);
    pros::delay(1000); //time to intake
    chassis.moveToPoint(52.248, 81.531, 1500); //Ring1
    pros::delay(1000); //time to intake
    chassis.moveToPoint(46.251, 1.392, 1000); //ring 2
    pros::delay(1000); //time to intake
    chassis.moveToPoint(45.552, -7.88, 1000); //ring 4
    pros::delay(1000);
    chassis.moveToPoint(50.412, 4.48, 1300); //ring 3
    pros::delay(1000); //time to intake
    chassis.moveToPoint(58.389, -9.185, 1200, {.forwards = false}); //pos mogo
    pros::delay(1250);
    clampPiston.set_value(false); //release mogo
    chassis.moveToPoint(-22.145, 13.959, 800, {.forwards = false}); //move to mogo
     pros::delay(750); //time to intake
    clampPiston.set_value(true); //clamp mogo
    chassis.moveToPoint(-24.527, 28.685, 1200); //ring 1
    pros::delay(1000); //time to intake
    chassis.moveToPoint(-47, 27, 1300);
    pros::delay(1000); //time to intake
    chassis.moveToPoint(-52.248, 81.531, 1500); //Ring1
    pros::delay(1000); //time to intake
    chassis.moveToPoint(-46.251, 1.392, 1000); //ring 2
    pros::delay(1000); //time to intake
    chassis.moveToPoint(-45.552, -7.88, 1000); //ring 4
    pros::delay(1000);
    chassis.moveToPoint(-50.412, 4.48, 1300); //ring 3
    pros::delay(1000); //time to intake
    chassis.moveToPoint(-58.389, -9.185, 1200, {.forwards = false}); //pos mogo
    pros::delay(1250);
    
    //29 points



    // chassis.moveToPoint(45.611, 57.206, 1100); //wallstake 1
    // chassis.moveToPoint(18.248, 81.531, 1500); //Ring1
    // pros::delay(300); //time to intake
    // intake.move_voltage(0); //stop intake
    // chassis.moveToPoint(10.73, 91.855, 1000, {.forwards = false}); //mogo setup
    // chassis.moveToPoint(-5, 92.251, 1000, {.forwards = false}); //mogo
    // pros::delay(750); //time to clamp mogo
    // clampPiston.set_value(true); //clamp mogo
    // intake.move_voltage(12000); //intake ring 1
    // chassis.moveToPoint(22.926, 84.926, 1000); //ring 2
    // chassis.moveToPoint(45.453, 107.653, 1000); //ring 3
    // chassis.moveToPoint(45.852, 118.618, 1000); //ring 4
    // chassis.moveToPoint(58.412, 108.052, 1000); //ring 5
    // chassis.moveToPoint(64.99, 125.396, 2000, {.forwards = false}); //pos
    // clampPiston.set_value(false); //release mogo
    // pros::delay(750); //time to release mogo
    // chassis.moveToPoint(-0.399, 60.405, 1000); //ring 1
    // pros::delay(500); //time to intake
    // intake.move_voltage(0); //hold ring
    // chassis.moveToPoint(-21.331, 18.142, 2000); //mogo
    // clampPiston.set_value(true); //clamp mogo
    // pros::delay(750); //time to clamp mogo
    // intake.move_voltage(12000); //intake ring 1
    // chassis.moveToPoint(-24.521, 37.28, 1000); //ring 2
    // chassis.moveToPoint(-48.045, 36.482, 1000); //ring 3
    // chassis.moveToPoint(-47.846, 13.556, 1000); //ring 4
    // chassis.moveToPoint(-48.045, 2.193, 1000); //ring 5
    // chassis.moveToPoint(-60.007, 13.556, 1000); //ring 6
    // chassis.moveToPoint(-63.595, -2.592, 1000, {.forwards = false}); //pos mogo
    // clampPiston.set_value(false); //release mogo
    // pros::delay(750); //time to release mogo
    // resetWallstakes(); //prime wallstakes
    // chassis.moveToPoint(-59.408, 59.807, 1000); //wallstake setup
    // chassis.turnToHeading(270, 500); //turn 180 deg
    // chassis.moveToPoint(-65.19, 59.807, 1000); //wallstake 1
    // wallStake.move_voltage(12000); //wallstake 1
    // pros::delay(1000); //time to wallstake 1
    // wallStake.move_voltage(-12000); //stop wallstake 1
    // pros::delay(500); //time to reset
    // wallStake.move_voltage(0); //stop wall stake
    // chassis.moveToPoint(-47.646, 84.129, 5000); //blue alliance
    // pros::delay(500); //time to intake
    // intake.move_voltage(0); //stop intake
    // chassis.moveToPoint(-26.515, 115.228, 1500, {.forwards = false}); //mogo setup
    // clampPiston.set_value(true); //clamp mogo
    // pros::delay(750); //time to clamp mogo
    // chassis.moveToPoint(-65.19, 125.595, 2000, {.forwards = false}); //pos mogo
    // clampPiston.set_value(false); //release mogo
    // pros::delay(750); //time to release mogo
    // chassis.moveToPoint(-0.199, 107.852, 2000);
    // chassis.turnToHeading(0, 500);
    // chassis.moveToPoint(0, 123.003, 1000);
    // intake.move_voltage(12000);
    // chassis.moveToPoint(-23.923, 83.929, 1000);
    //  pros::delay(500); //time to intake
    // intake.move_voltage(0); //stop intake
    // chassis.moveToPoint(-1.196, 93.1, 1000);
    // chassis.turnToHeading(0, 500);
    // chassis.moveToPoint(-0.399, 122.804, 2000);
    // intake.move_voltage(12000);//second blue alliance
    //total theroetical score: 55 right now @ 15

}

rd::Selector gui_selector({
    {"5 Ring", Five_Ring},
    {"WP Rush", WP_3Rush},
    //{"Scrim Left", scrimLeftSide},
    //{"Scrim Right", scrimRightSide},
    {"Skills", skills},
    {"PID test", testPID},
    {"BM test", testBM}
});

void autonomous() {
    //initializeColourSort();
    controller.print(0, 0, "Auton: %s | %.0lf   ", autonName.c_str(), chassis.getPose().theta);
    chassis.setPose(0,0,0);
    console.println("Running auton...");
    gui_selector.run_auton();
}

void driverSkillsMacro() {
    pros::Task skillsTask(skills, "skills");

    pros::Task([&] {
        while (true) {
		    if (controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_DOWN)) {
                skillsTask.remove();
                chassis.cancelAllMotions();
                break;
		    }
        }
	});
}

/* Legacy Auton Routines */

// collect mogo, score preload and ring to the side. works for either alliance
