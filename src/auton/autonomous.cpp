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

std::string autonName = "null";

void testPID() {
    autonName = "PID Test";
    chassis.setPose(0, 0, 0);
    clampPiston.set_value(true);
    pros::delay(1000);
    // chassis.moveToPoint(0, 24, 5000);
    chassis.turnToHeading(90, 1000);
    // chassis.moveToPoint(24, 24, 5000)   
}
void testBM() {
    chassis.setPose(0, 0, 0);
    chassis.moveToPose(52, 6, 320, 1000, {.forwards = false});
}

void Five_Ring() {
    autonName = "5 Ring Elim";
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
    chassis.turnToHeading(90, 700);
    chassis.moveToPoint(5.786, -28.589, 1000); // Ring 2
    pros::delay(1000); 
    chassis.turnToHeading(180, 500);  
    chassis.moveToPoint(7.841, -43.686, 1000); // Ring 3
    pros::delay(1000);
    chassis.moveToPoint(8.68, -29.144, 1300, {.forwards = false}); 
    pros::delay(200);
    chassis.moveToPoint(12.905, -44.186, 1200);
    pros::delay(1100);
    chassis.moveToPoint(-3.559, -34.032, 1000, {.forwards = false});
    chassis.moveToPoint(25, 8, 1500, {.minSpeed = 127});
    pros::delay(2100);
    // chassis.turnToHeading(45, 1000, {.maxSpeed = 70});
    // chassis.moveToPoint(25.995, 10.009, 2000, {.forwards = true});
    // pros::delay(2000);
    chassis.moveToPoint(10, -5, 1500, {.forwards = false, .maxSpeed = 60});
    chassis.moveToPoint(20.559, 0.032, 1000, {.maxSpeed = 90});

}

void SAWP_5NoRush() {
    autonName = "WP No Rush";
    // get alliance stake
    clampPiston.set_value(true);
    chassis.moveToPoint(0, -17, 1000, {.forwards = false, .maxSpeed = 80});
    chassis.turnToHeading(90, 1000);
    chassis.moveToPoint(-7, -17, 2000, {.forwards = false}); // move into wall
    intake.move_voltage(12000);
    pros::delay(700);
    intake.move_voltage(0);
    chassis.moveToPoint(0, -17, 2000); // ram into wall
    chassis.moveToPoint(-10, -17, 1000, {.forwards = false, .minSpeed = 90});
    pros::delay(1000);
    ks::resetOdomPosition();
    pros::delay(500);
    chassis.moveToPoint(0, 5, 2000, {.minSpeed = 80});

    // clamp mogo
    // chassis.turnToHeading(180, 1000);
    // chassis.moveToPoint(0, -5, 1000);
    // clampPiston.set_value(false);
    // chassis.moveToPoint(30, 6, 1500, {.forwards = false, .maxSpeed = 80});
    // pros::delay(1500);
    // clampPiston.set_value(true);

}

void WP_3Rush() {
    autonName = "WP 3Rush";
    chassis.moveToPoint(0, 0, 1500);
    chassis.moveToPoint(0, -39.095, 1050, {.forwards = false});
    chassis.turnToHeading(315, 450);
    pros::delay(20);
    chassis.moveToPoint(8.793, -44.79, 1200, {.forwards = false});
    pros::delay(670);
    clampPiston.set_value(true);
    chassis.turnToHeading(90, 600);
    chassis.moveToPoint(19.5, -38.898, 1200);
    intake.move_voltage(12000);
    pros::delay(1000);
    chassis.turnToHeading(0, 600);
    chassis.moveToPoint(21.481, -13.598, 1200);
    chassis.turnToHeading(180, 600);
    pros::delay(800);
    clampPiston.set_value(false);
    chassis.moveToPoint(23.314, -17.952, 1500, {.forwards = false});
    pros::delay(750);
    clampPiston.set_value(true);
    // chassis.moveToPoint(32.64, -30.308, 1500);
    // chassis.moveToPoint(11.89, -35.671, 1500);
    // chassis.moveToPoint(55.255, -34.272, 1500);


}

void skills() {
    chassis.moveToPoint(0, 0, 1000);
    clampPiston.set_value(true);
    chassis.moveToPoint(-0.233, -5.595, 300);
    intake.move_voltage(12000);
    pros::delay(450);
    chassis.moveToPoint(-0.466, 11.424, 1000);
    clampPiston.set_value(false);
    chassis.turnToHeading(90, 500);
    chassis.moveToPoint(-23.118, 13.424, 1300, {.forwards = false, .maxSpeed = 70}); // Mogo
    pros::delay(850);
    clampPiston.set_value(true);
    chassis.turnToHeading(0, 400);  
    chassis.moveToPoint(-23.014, 33.971, 900); // Ring 1
    chassis.turnToHeading(315, 500);
    chassis.moveToPoint(-58.818, 59.486, 1000); // Ring 2
    pros::delay(800);
    chassis.moveToPoint(-56, 60.286, 800, {.forwards = false});
    chassis.turnToHeading(180, 500);
    chassis.moveToPoint(-51.594, 35.438, 1100, {.maxSpeed = 65}); // Ring 3
    chassis.moveToPoint(-51.527, 12.123, 1100, {.maxSpeed = 65}); // Ring 4
    chassis.moveToPoint(-51.528, -0.999, 1100, {.maxSpeed = 65}); // Ring 5
    pros::delay(2000);
    chassis.turnToHeading(315, 800);
    pros::delay(500);
    chassis.moveToPoint(-60.617, 14.725, 1000); // Ring 6
    pros::delay(1200);
    chassis.moveToPoint(-60, 12, 1000, {.forwards = false});
    chassis.moveToPoint(-69.384, -4.098, 1300, {.forwards = false});
    pros::delay(1000);
    clampPiston.set_value(false);
    pros::delay(500);
    chassis.moveToPoint(-25, 10, 1000);
    chassis.turnToHeading(270, 600);
    pros::delay(1000);
    chassis.moveToPoint(0, 11, 2250, {.forwards = false});

    // pros::delay(850);
    // clampPiston.set_value(true);
    // chassis.turnToHeading(0, 600);  
    // chassis.moveToPoint(2.514, 27.971, 900); // Ring 1
    // chassis.moveToPoint(57, 60, 1000);
    // chassis.moveToPoint(59.118, 60.286, 1000); // Ring 2
    // pros::delay(800);
    // chassis.moveToPoint(56, 60.286, 800, {.forwards = false});
    // chassis.turnToHeading(180, 500);
    // chassis.moveToPoint(50.994, 35.438, 1100, {.maxSpeed = 65}); // Ring 3
    // chassis.moveToPoint(50.927, 12.123, 1100, {.maxSpeed = 65});
    // chassis.moveToPoint(50.928, -0.999, 1100, {.maxSpeed = 65});
    // pros::delay(1000);
    // chassis.turnToHeading(45, 800);
    // pros::delay(500);
    // chassis.moveToPoint(60.617, 14.725, 1000);
    // pros::delay(1500);
    // chassis.moveToPoint(60, 12, 1000, {.forwards = false});
    // chassis.moveToPoint(69.384, -4.098, 1300, {.forwards = false});
    // pros::delay(1500);
    // clampPiston.set_value(false);


    // chassis.moveToPoint(-0.699, 58.286, 1500);
    // chassis.moveToPoint(-3.497, 99.785, 1500);
    // chassis.moveToPoint(-24.48, 80.9, 1500);
    // chassis.moveToPoint(-48.494, 82.299, 1500);
    // chassis.moveToPoint(-48.027, 104.215, 1500);
    // chassis.moveToPoint(-47.794, 117.97, 1500);
    // chassis.moveToPoint(-60.151, 105.613, 1500);
    // chassis.moveToPoint(-61.083, 116.571, 1500);
    // chassis.moveToPoint(-66.912, 125.197, 1500);
    // chassis.moveToPoint(-28.91, 116.804, 1500);
    // chassis.moveToPoint(65.28, 124.498, 1500);
    // chassis.moveToPoint(45.929, 117.504, 1500);
    // chassis.moveToPoint(0.233, 111.908, 1500);
    // chassis.moveToPoint(0.466, 122.4, 1500);
    // chassis.moveToPoint(17.952, 96.521, 1500);
}

/* Legacy Auton Routines */
// collect mogo, score preload and ring to the side. works for either alliance
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

rd::Selector gui_selector({
    {"5 Ring", Five_Ring},
    {"WP Rush", WP_3Rush},
    {"SAWP NoRush", SAWP_5NoRush},
    {"Scrim Right", scrimRightSide},
    {"Skills", skills},
    {"PID test", testPID},
    {"BM test", testBM}
});
void autonomous() {
    //initializeColourSort();
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