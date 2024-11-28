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
    // chassis.moveToPoint(24, 24, 5000)
    
}

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
    chassis.turnToHeading(90, 500);
    chassis.moveToPoint(4.786, -28.589, 1000); // Ring 2
    pros::delay(1000); 
    chassis.turnToHeading(180, 500);  
    chassis.moveToPoint(6.841, -41.686, 1000); // Ring 3
    pros::delay(1000);
    chassis.moveToPoint(12.68, -29.144, 1300, {.forwards = false}); 
    pros::delay(200);
    chassis.moveToPoint(14.505, -41.286, 1000);
    pros::delay(1100);
    chassis.moveToPoint(-3.559, -34.032, 1000, {.forwards = false});
    chassis.turnToHeading(45, 600);
    chassis.moveToPoint(27.695, 2.009, 1500);
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

void WP_5NORush() {
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
    chassis.moveToPoint(0, 0, 1000);
    clampPiston.set_value(true);
    chassis.moveToPoint(-0.233, -5.595, 800);
    intake.move_voltage(12000);
    pros::delay(800);
    chassis.moveToPoint(-0.466, 11.424, 1000);
    clampPiston.set_value(false);
    chassis.turnToHeading(90, 500);
    chassis.moveToPoint(-19.118, 11.424, 1000); // Mogo
    clampPiston.set_value(true);
    pros::delay(750);
    chassis.moveToPoint(-24.014, 34.971, 1000); // Ring 1
    chassis.moveToPoint(-59.918, 58.286, 1000); // Ring 2
    pros::delay(800);
    chassis.moveToPoint(-48.494, 35.438, 1000); // Ring 3
    chassis.turnToHeading(180, 500);
    pros::delay(500);
    // chassis.moveToPoint(-48.027, 12.123, 1500);
    // chassis.moveToPoint(-47.328, -0.699, 1500);
    // chassis.moveToPoint(-60.617, 10.725, 1500);
    // chassis.moveToPoint(-60.384, -2.098, 1500);
    // chassis.moveToPoint(-0.233, 11.657, 1500);
    // chassis.moveToPoint(17.253, 11.657, 1500);
    // chassis.moveToPoint(23.081, 34.971, 1500);
    // chassis.moveToPoint(58.519, 58.985, 1500);
    // chassis.moveToPoint(45.929, 34.971, 1500);
    // chassis.moveToPoint(46.395, 10.725, 1500);
    // chassis.moveToPoint(45.463, -1.399, 1500);
    // chassis.moveToPoint(58.286, 11.424, 1500);
    // chassis.moveToPoint(61.55, -4.896, 1500);
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

rd::Selector gui_selector({
    {"5 Ring", Five_Ring},
    {"WP Rush", WP_3Rush},
    {"WP NoRush", WP_5NORush},
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
