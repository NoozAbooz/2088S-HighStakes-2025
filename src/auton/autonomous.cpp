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

void testPID() {
    chassis.moveToPoint(0, 24, 1000);
    //chassis.turnToHeading(90, 2000);
    //chassis.moveToPoint(24, 24, 1000);
}
void testBM() {
    chassis.moveToPose(24, 24, 90, 1500);
}
void calibrateOdomOffsets() {
    printf("Copy this:\n");
    printf("\\left[");

    chassis.turnToHeading(359, 1000, {.direction = lemlib::AngularDirection::CW_CLOCKWISE});
    while (chassis.isInMotion()) {
        printf("\\left(%f,%f\\right),", chassis.getPose().x, chassis.getPose().y);
        pros::delay(20);
    }

    printf("\\right]");
}


void SIG_SAWP() {
    chassis.moveToPoint(0, 0, 1250);
    // wallStake.move_voltage(10000);
    // pros::delay(800);
    // wallStake.brake();
   chassis.moveToPoint(-15.167, -28.355, 1250, {.forwards = false, .maxSpeed = 127});
    pros::delay(850);
    clampPiston.set_value(true);
    intake.move_voltage(12000);
    chassis.moveToPoint(-12.243, -68.251, 1250);
    // chassis.moveToPoint(0.165, -51.6, 1250);
    // chassis.moveToPoint(-8.078, -9.727, 1250);
    // chassis.moveToPoint(-23.904, 7.748, 1250);
    // chassis.moveToPoint(-44.511, 0.989, 1250);
    // chassis.moveToPoint(-47.808, -15.167, 1250);



}

/* Legacy Auton Routines */
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
        chassis.turnToHeading(180, 500);  
        chassis.moveToPoint(7.141, -43.686, 1000); // Ring 3
        pros::delay(1000);
        chassis.moveToPoint(12.68, -36.144, 1300, {.forwards = false}); 
        pros::delay(200);
        chassis.turnToHeading(180, 410);
        chassis.moveToPoint(13.605, -44.186, 1200);
        pros::delay(1100);
        chassis.moveToPoint(-3.559, -34.032, 1000, {.forwards = false});
        chassis.moveToPoint(-5, -33, 2000);
        chassis.turnToHeading(45, 500, {.direction = lemlib::AngularDirection::CW_CLOCKWISE});
        chassis.moveToPoint(-24, -36, 2000, {.forwards = false});
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
        chassis.turnToHeading(180, 500);  
        chassis.moveToPoint(-7.141, -43.686, 1000); // Ring 3
        pros::delay(1000);
        chassis.moveToPoint(-12.68, -36.144, 1300, {.forwards = false}); 
        pros::delay(200);
        chassis.turnToHeading(180, 410);
        chassis.moveToPoint(-13.605, -44.186, 1200);
        pros::delay(1100);
        chassis.moveToPoint(3.559, -34.032, 1000, {.forwards = false});
        chassis.moveToPoint(5, -33, 2000);
        chassis.turnToHeading(315, 500, {.direction = lemlib::AngularDirection::CCW_COUNTERCLOCKWISE});
        chassis.moveToPoint(24, -36, 2000, {.forwards = false});
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
        chassis.moveToPoint(7.141, -43.686, 1000); // Ring 3
        pros::delay(1000);
        chassis.moveToPoint(12.68, -36.144, 1300, {.forwards = false}); 
        pros::delay(200);
        chassis.turnToHeading(180, 410);
        chassis.moveToPoint(13.605, -44.186, 1200);
        pros::delay(1100);
        chassis.moveToPoint(-3.559, -34.032, 1000, {.forwards = false});
        chassis.moveToPoint(29, 12, 2500, {.maxSpeed = 57});
        pros::delay(2100);
        chassis.moveToPoint(10, -5, 1500, {.forwards = false, .maxSpeed = 60});
        chassis.moveToPoint(20.559, 0.032, 1000, {.minSpeed = 127});
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
        chassis.moveToPoint(-7.141, -43.686, 1000); // Ring 3
        pros::delay(1000);
        chassis.moveToPoint(-12.68, -36.144, 1300, {.forwards = false}); 
        pros::delay(200);
        chassis.turnToHeading(180, 410);
        chassis.moveToPoint(-13.605, -44.186, 1200);
        pros::delay(1100);
        chassis.moveToPoint(3.559, -34.032, 1000, {.forwards = false});
        chassis.moveToPoint(-29, 12, 2500, {.maxSpeed = 57});
        pros::delay(2100);
        chassis.moveToPoint(-10, -5, 1500, {.forwards = false, .maxSpeed = 60});
        chassis.moveToPoint(-20.559, 0.032, 1000, {.minSpeed = 127});
    }
}

void SAWP_4() {
    if (alliance == "red" || alliance == "na") {
        chassis.moveToPoint(0.233, -11.351, 700, {.forwards = false});
        chassis.turnToHeading(30, 500);
        chassis.moveToPoint(-10.595, -28.875, 700, {.forwards = false});
        pros::delay(790);
        clampPiston.set_value(true);
        pros::delay(20);
        intake.move_voltage(12000); // Preload
        pros::delay(1050);
        intake.move_voltage(0);
        clampPiston.set_value(false);
        chassis.moveToPoint(8.16, -15.615, 1000);
        chassis.turnToHeading(270,700);
        wallStake.move_voltage(10000);
        pros::delay(300);
        wallStake.brake();
        chassis.moveToPoint(40.977, -30.415, 2000, {.forwards = false, .maxSpeed = 57}); // mogo 2
        pros::delay(1730);
        clampPiston.set_value(true);
        intake.move_voltage(12000);
        chassis.moveToPoint(56.985, -30.505, 1500); // ring 1
        pros::delay(1000);
        chassis.turnToHeading(180, 500);
        chassis.moveToPoint(54.486, -46.39, 1000); // ring 2
        pros::delay(100);
        chassis.moveToPoint(59.746, -34.505, 1000, {.forwards = false});
        chassis.turnToHeading(180, 500);
        chassis.moveToPoint(61.446, -46.356, 1000); // ring 3
        pros::delay(1200);
        chassis.moveToPoint(60, 45, 700, {.forwards = false});
        chassis.turnToHeading(45, 500);
        chassis.moveToPoint(24.418, -36.738, 1200, {.forwards = false}); // Ladder
    } else { // blue
        chassis.moveToPoint(-0.233, -11.351, 700, {.forwards = false});
        chassis.turnToHeading(330, 500);
        chassis.moveToPoint(10.595, -28.875, 700, {.forwards = false});
        pros::delay(790);
        clampPiston.set_value(true);
        pros::delay(20);
        intake.move_voltage(12000); // Preload
        pros::delay(1050);
        intake.move_voltage(0);
        clampPiston.set_value(false);
        chassis.moveToPoint(-8.16, -15.615, 1000);
        chassis.turnToHeading(90,700);
        wallStake.move_voltage(10000);
        pros::delay(300);
        wallStake.brake();
        chassis.moveToPoint(-40.977, -30.415, 2000, {.forwards = false, .maxSpeed = 57}); // mogo 2
        pros::delay(1730);
        clampPiston.set_value(true);
        intake.move_voltage(12000);
        chassis.moveToPoint(-56.985, -30.505, 1500); // ring 1
        pros::delay(1000);
        chassis.turnToHeading(180, 500);
        chassis.moveToPoint(-54.486, -46.39, 1000); // ring 2
        pros::delay(100);
        chassis.moveToPoint(-59.746, -34.505, 1000, {.forwards = false});
        chassis.turnToHeading(180, 500);
        chassis.moveToPoint(-61.446, -46.356, 1000); // ring 3
        pros::delay(1200);
        chassis.moveToPoint(-60, 45, 700, {.forwards = false});
        chassis.turnToHeading(315, 500);
        chassis.moveToPoint(-24.418, -36.738, 1200, {.forwards = false}); // Ladder
    }
}

rd::Selector gui_selector({
    // {"E 5 Ring", Five_Ring},
    // {"Q 4 Ring + Bar", four_ring_bar},
    // {"Q SAWP 2 Mogo", SAWP_4},
    {"Mecha SAWP", SIG_SAWP},
    {"Skills", skills, "", 0},

    { "Test PID", testPID, "", 220 },
    { "Test BM", testBM, "", 220 },
    { "Odom Offsets", calibrateOdomOffsets, "", 220 }
});

void autonomous() {
    //initializeColourSort();
    chassis.setPose(0, 0, 0);
    field_status = "autonomous";
    console.println("Running auton...");
    gui_selector.run_auton();
}