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

std::string auton_name = "null";

void testPID() {
    clampPiston.set_value(true);
    pros::delay(1000);
    // chassis.moveToPoint(0, 24, 5000);
    chassis.turnToHeading(90, 1000);
    // chassis.moveToPoint(24, 24, 5000)   
}
void testBM() {
    chassis.moveToPose(52, 6, 320, 1000, {.forwards = false});
}

void four_ring_bar() {
    if (alliance == "red" || alliance == "na") {
        wallStake.move_voltage(10000); // Start
        pros::delay(300);
        wallStake.brake();
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
        chassis.turnToHeading(180, 600);  
        chassis.moveToPoint(5.841, -43.686, 1000, {.maxSpeed = 60}); // Ring 3
        pros::delay(1000);
        chassis.moveToPoint(12.68, -29.144, 1300, {.forwards = false}); 
        pros::delay(200);
        chassis.moveToPoint(12.905, -44.186, 1200);
        pros::delay(1100);
        chassis.moveToPoint(-3.559, -34.032, 1000, {.forwards = false});
        chassis.moveToPoint(-5, -33, 2000);
        chassis.moveToPoint(-24, -36, 2000);
    } else {
        wallStake.move_voltage(10000); // Start
        pros::delay(300);
        wallStake.brake();
        chassis.moveToPoint(0, -14.237, 1000, {.forwards = false}); // Mogo  
        pros::delay(20);
        chassis.turnToHeading(315, 500); 
        pros::delay(20);
        chassis.moveToPoint(9.788, -27.808, 1000, {.forwards = false}); // Mogo
        pros::delay(790);
        clampPiston.set_value(true);
        pros::delay(20);
        intake.move_voltage(12000); // Preload
        pros::delay(800);
        chassis.turnToHeading(270, 700);
        chassis.moveToPoint(-5.786, -28.589, 1000); // Ring 2
        pros::delay(1000); 
        chassis.turnToHeading(180, 600);  
        chassis.moveToPoint(-5.841, -43.686, 1000, {.maxSpeed = 60}); // Ring 3
        pros::delay(1000);
        chassis.moveToPoint(-12.68, -29.144, 1300, {.forwards = false}); 
        pros::delay(200);
        chassis.moveToPoint(-12.905, -44.186, 1200);
        pros::delay(1100);
        chassis.moveToPoint(3.559, -34.032, 1000, {.forwards = false});
        chassis.moveToPoint(5, -33, 2000);
        chassis.moveToPoint(24, -36, 2000);
    }
}

void Five_Ring() {
    if (alliance == "red" || alliance == "na") {
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
    } else { // blue
        chassis.moveToPoint(0, -14.237, 1000, {.forwards = false}); // Mogo  
        pros::delay(20);
        chassis.turnToHeading(315, 500); 
        pros::delay(20);
        chassis.moveToPoint(9.788, -27.808, 1000, {.forwards = false}); // Mogo
        pros::delay(790);
        clampPiston.set_value(true);
        pros::delay(20);
        intake.move_voltage(12000); // Preload
        pros::delay(800);
        chassis.turnToHeading(270, 700);
        chassis.moveToPoint(-5.786, -28.589, 1000); // Ring 2
        pros::delay(1000); 
        chassis.turnToHeading(180, 500);  
        chassis.moveToPoint(-7.841, -43.686, 1000); // Ring 3
        pros::delay(1000);
        chassis.moveToPoint(-8.68, -29.144, 1300, {.forwards = false}); 
        pros::delay(200);
        chassis.moveToPoint(-12.905, -44.186, 1200);
        pros::delay(1100);
        chassis.moveToPoint(3.559, -34.032, 1000, {.forwards = false});
        chassis.moveToPoint(-25, 8, 1500, {.minSpeed = 127});
        pros::delay(2100);
        chassis.moveToPoint(-10, -5, 1500, {.forwards = false, .maxSpeed = 60});
        chassis.moveToPoint(-20.559, 0.032, 1000, {.maxSpeed = 90});
    }
}

void SAWP_4() {
    if (alliance == "red" || alliance == "na") {
        chassis.moveToPoint(0, 0, 1500);
        chassis.moveToPoint(0.233, -11.351, 700, {.forwards = false});
        chassis.turnToHeading(30, 500);
        chassis.moveToPoint(-10.595, -28.875, 700, {.forwards = false});
        pros::delay(790);
        clampPiston.set_value(true);
        pros::delay(20);
        intake.move_voltage(12000); // Preload
        pros::delay(850);
        intake.move_voltage(0);
        clampPiston.set_value(false);
        chassis.moveToPoint(8.16, -15.615, 900);
        chassis.turnToHeading(270,600);
        wallStake.move_voltage(10000);
        pros::delay(300);
        wallStake.brake();
        chassis.moveToPoint(34.977, -25.915, 1250, {.forwards = false, .maxSpeed = 80});
        pros::delay(1030);
        clampPiston.set_value(true);
        intake.move_voltage(12000);
        chassis.moveToPoint(56.985, -34.505, 1500); // ring 1
        pros::delay(600);
        chassis.turnToHeading(180, 500);
        chassis.moveToPoint(53.486, -46.39, 1000); // ring 2
        pros::delay(1000);
        chassis.moveToPoint(59.746, -34.505, 1000, {.forwards = false});
        chassis.turnToHeading(180, 500);
        chassis.moveToPoint(60.446, -46.356, 1000); // ring 3
        pros::delay(1200);
        chassis.moveToPoint(60, 45, 700, {.forwards = false});
        chassis.turnToHeading(215, 500);
        chassis.moveToPoint(24.418, -36.738, 1200); // Ladder
    } else { // blue
        chassis.moveToPoint(0, 0, 1500);
        chassis.moveToPoint(-0.233, -11.351, 700, {.forwards = false});
        chassis.turnToHeading(330, 500);
        chassis.moveToPoint(10.595, -28.875, 700, {.forwards = false});
        pros::delay(790);
        clampPiston.set_value(true);
        pros::delay(20);
        intake.move_voltage(12000); // Preload
        pros::delay(850);
        intake.move_voltage(0);
        clampPiston.set_value(false);
        chassis.moveToPoint(-8.16, -15.615, 900);
        chassis.turnToHeading(90,600);
        wallStake.move_voltage(10000);
        pros::delay(300);
        wallStake.brake();
        chassis.moveToPoint(-34.977, -25.915, 1250, {.forwards = false, .maxSpeed = 80});
        pros::delay(1030);
        clampPiston.set_value(true);
        intake.move_voltage(12000);
        chassis.moveToPoint(-56.985, -34.505, 1500); // ring 1
        pros::delay(600);
        chassis.turnToHeading(180, 500);
        chassis.moveToPoint(-53.486, -46.39, 1000); // ring 2
        pros::delay(1000);
        chassis.moveToPoint(-59.746, -34.505, 1000, {.forwards = false});
        chassis.turnToHeading(180, 500);
        chassis.moveToPoint(-60.446, -46.356, 1000); // ring 3
        pros::delay(1200);
        chassis.moveToPoint(-60, 45, 700, {.forwards = false});
        chassis.turnToHeading(145, 500);
        chassis.moveToPoint(-24.418, -36.738, 1200); // Ladder
    }
}

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
    chassis.moveToPoint(-28.014, 37.971, 900); // Ring 1
    chassis.turnToHeading(315, 500);
    chassis.moveToPoint(-60.818, 60.586, 1200); // Ring 2
    pros::delay(1500);
    chassis.moveToPoint(-56, 58.286, 800, {.forwards = false});
    chassis.turnToHeading(180, 500);
    chassis.moveToPoint(-47.994, 35.438, 1100, {.maxSpeed = 55}); // Ring 3
    pros::delay(1500);
    chassis.moveToPoint(-47.927, 14.123, 1100, {.maxSpeed = 55}); // Ring 4
    pros::delay(1500);
    chassis.moveToPoint(-47.928, -0.999, 1100, {.maxSpeed = 55}); // Ring 5
    pros::delay(1500);
    chassis.moveToPoint(-44, 11, 1000, {.forwards = false});    
    chassis.turnToHeading(270, 800);
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
    chassis.moveToPoint(27.118, 13.424, 2000, {.forwards = false, .maxSpeed = 65}); // Mogo
    pros::delay(1100);
    clampPiston.set_value(true);
    pros::delay(500);
    chassis.turnToHeading(0, 400);  
    chassis.moveToPoint(30.014, 33.971, 900); // Ring 1
    chassis.turnToHeading(45, 500);
    chassis.moveToPoint(60.918, 60.686, 1200); // Ring 2
    pros::delay(1500);
    chassis.moveToPoint(56, 58.286, 800, {.forwards = false});
    chassis.turnToHeading(180, 500);
    chassis.moveToPoint(48.994, 35.438, 1100, {.maxSpeed = 55}); // Ring 3
    pros::delay(1500);
    chassis.moveToPoint(48.927, 14.123, 1100, {.maxSpeed = 55}); // Ring 4
    pros::delay(1500);
    chassis.moveToPoint(48.928, -0.999, 1100, {.maxSpeed = 55}); // Ring 5
    pros::delay(1500);
    chassis.moveToPoint(44, 11, 1000, {.forwards = false});    
    chassis.turnToHeading(90, 800);
    chassis.moveToPoint(59.617, 11.725, 1000); // Ring 6
    pros::delay(700);
    chassis.moveToPoint(60, 12, 1000, {.forwards = false});
    chassis.moveToPoint(69.384, -6.098, 1200, {.forwards = false});
    pros::delay(1100);
    clampPiston.set_value(false);
    pros::delay(500);
    chassis.moveToPoint(-23, 90, 2500);
    pros::delay(1700);
    intake.move_voltage(0);
    chassis.turnToHeading(225, 600);
    chassis.moveToPoint(2, 113, 2000, {.forwards = false, .maxSpeed = 65});
    pros::delay(1400);
    clampPiston.set_value(true);
    pros::delay(500);
    intake.move_voltage(12000);
    chassis.moveToPoint(-20, 98, 1000);
    chassis.moveToPoint(-50, 93, 2000, {.maxSpeed = 75});
    pros::delay(2000);
    chassis.turnToHeading(0, 600);
    chassis.moveToPoint(-50, 102, 800);
    pros::delay(800);
    chassis.moveToPoint(-50, 95, 1500, {.forwards = false, .maxSpeed = 50});
    chassis.moveToPoint(-60, 105, 800);
    pros::delay(1500);
    chassis.moveToPoint(-50, 115, 800);
    pros::delay(1500);
    chassis.moveToPoint(-69, 120, 800, {.forwards = false});
    pros::delay(1000);
    clampPiston.set_value(false);
    pros::delay(600);


    // chassis.moveToPoint(-7, 11, 2000);
    // chassis.turnToHeading(270, 700);
    // chassis.moveToPoint(23, 11, 1300, {.forwards = false, .maxSpeed = 60});
    // pros::delay(1400);
    // clampPiston.set_value(true);
    // chassis.turnToHeading(0, 500);
    // chassis.moveToPoint(18, 30, 1000);
    // chassis.turnToHeading(45, 600);
    // chassis.moveToPoint(49, 54, 1000);
    // pros::delay(1000);
    // chassis.moveToPoint(38, 23, 1200);
    // chassis.moveToPoint(38, -2, 1200);
    // pros::delay(1000);
    // chassis.moveToPoint(38, -7, 1000);
    // chassis.moveToPoint(38, 2, 1000, {.forwards = false});
    // chassis.turnToHeading(90, 600);
   
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

rd::Selector gui_selector({
    {"E 5 Ring", Five_Ring},
    {"E 4 Ring + Bar", four_ring_bar},
    {"Q SAWP 2Mogo", SAWP_4},
    {"Skills", skills},
});
void autonomous() {
    //initializeColourSort();
    chassis.setPose(0, 0, 0);
    field_status = "autonomous";
    console.println("Running auton...");
    gui_selector.run_auton();
}

void driverSkillsMacro() {
    // pros::Task skillsTask(skills, "skills");

    // pros::Task([&] {
    //     while (true) {
	// 	    if (controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_DOWN)) {
    //             skillsTask.remove();
    //             chassis.cancelAllMotions();
    //             break;
	// 	    }
    //     }
	// });
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

void WP_3Rush() {
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