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
    intake.move_voltage(12000);
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
void sawp() {

    chassis.moveToPoint(0, 0, 1250);
    wallStake.move_voltage(10000);
    pros::delay(700);
    wallStake.move_voltage(-10000);
    pros::delay(300);
    wallStake.brake();
    chassis.moveToPoint(-35.1, -19.526, 1750, {.forwards = false, .maxSpeed = 60});
    pros::delay(1590);
    clampPiston.set_value(true);
    pros::delay(100);
    intake.move_voltage(12000);
    chassis.moveToPoint(-42.426, -39.767, 1250);
    chassis.turnToHeading(165, 500);
    chassis.moveToPoint(-40.045, -59.267, 1350, {.maxSpeed = 115});
    chassis.moveToPoint(-38.326, -36.767, 1250, {.forwards = false});
    chassis.moveToPoint(-29.352, -49.075, 1000);
    chassis.moveToPoint(-20.042, 5.3, 1250);
    pros::delay(900);
    intake.move_voltage(0);
    pros::delay(850);
    clampPiston.set_value(false);
    pros::delay(200);
    chassis.moveToPoint(-41.971, 20.681, 1850, {.forwards = false});
    pros::delay(1000);
    clampPiston.set_value(true);
    intake.move_voltage(12000);
    pros::delay(300);
    chassis.moveToPoint(-51.858, 43.824, 1100);
    pros::delay(1000);
    chassis.moveToPoint(-52.552, 16.16, 1300);
    pros::delay(950);
    wallStake.move_voltage(10000);
    pros::delay(250);
    wallStake.move_voltage(0);


    
}

void SIG_SAWP() {
    //intake.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
	//wall_stake_rotation_sensor.set_position(382.0);
	// turn so front is facing alliance stake and back is facing goal
    chassis.turnToHeading(45, 1000);

	// score alliance stake
	// driver.alliance_stake();
	// pros::delay(500);

	// chassis.setPose(0, 0, 0);
	// chassis.moveToPoint(0, -5, 600);

	// driver.next_state();
	chassis.turnToHeading(17, 1000); //-20

	// clamp goal
	chassis.setPose(0, 0, 0);
	chassis.moveToPoint(0, -28, 500);
	chassis.moveToPoint(0, -32, 2000);

	clampPiston.set_value(true);
	pros::delay(150);

	// turn to ring 1
	chassis.turnToHeading(-86, 1000);

	// intake ring 1
	intake.move_voltage(12000);

	chassis.setPose(0, 0, 0);
	chassis.moveToPoint(0, 25, 500);
	chassis.moveToPoint(0, 20, 450); // move back to align with ring closest to middle in 8-stack

	// turn to ring 2
	// r_pid.set_r_constants(2.5, 0, 17);
	// chassis.turnToHeading(180, 90, 2); //185
	chassis.setPose(0, 0, 0);
	chassis.turnToHeading(-100, 1000);

	// drive to intake ring 2 and drive back
	chassis.setPose(0, 0, 0);
	chassis.moveToPoint(0, 16.5, 700);
	pros::delay(250);
	chassis.moveToPoint(0, 10, 700);

	// turn to ring 3

	chassis.turnToHeading(-320, 1000);

	intake.move_voltage(12000);

	// intake ring 3
	chassis.setPose(0, 0, 0);
	chassis.moveToPoint(0, 32, 650); // 42

	chassis.turnToHeading(-270, 1000);

	clampPiston.set_value(false);

	intake.move_voltage(9000);

	// intake double ring stack at mid
	chassis.setPose(0, 0, 0);
	chassis.moveToPoint(0, 45, 2500);

	chassis.turnToHeading(8, 1000); // 21.5 degrees

	chassis.setPose(0, 0, 0);
	chassis.moveToPoint(0, -28, 1000);

	clampPiston.set_value(true);
	pros::delay(250);
	

	chassis.turnToHeading(80, 1000);
	intake.move_voltage(12000);

	intake.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);

	chassis.setPose(0, 0, 0);
	chassis.moveToPoint(0, 29, 1000);
	intake.move_voltage(0);
	chassis.moveToPoint(5, -6, 1000);

}
void ring_rush() {
    if (alliance == "red" || alliance == "na"){
    chassis.moveToPoint(0, 0, 1250);
    chassis.moveToPoint(-0.8, 46.051, 1250);
    intake.move_voltage(12000);
    leftDoinkerPiston.set_value(true);
    pros::delay(1480);
    intake.move_voltage(0);
    chassis.moveToPoint(-0.037, 17.634, 1050, {.forwards = false, .maxSpeed = 80});
    pros::delay(860);
    leftDoinkerPiston.set_value(false);
    // pros::delay(850);
    chassis.turnToHeading(230, 500);
    chassis.moveToPoint(13.945, 28.287, 1450, {.forwards = false, .maxSpeed = 80});
    pros::delay(750);
    clampPiston.set_value(true);
    pros::delay(530);
    intake.move_voltage(12000);
    chassis.moveToPoint(-18.634, 35.051, 2050);
    pros::delay(800);
    intake.move_voltage(-12000);
    antiJamToggle = false;
    intake.move_voltage(6000);
    chassis.moveToPoint(-35.174, 0.218, 1650, {.maxSpeed= 90});
    pros::delay(300);
    intakeLiftPiston.set_value(true);
    pros::delay(1000);
    intakeLiftPiston.set_value(false);
    chassis.moveToPoint(-30, 2, 600, {.forwards = false});
    chassis.moveToPoint(-36.174, 0.218, 1200, {.minSpeed= 127});
    pros::delay(1000);
    chassis.moveToPoint(-22, 10, 1500, {.forwards = false});
    antiJamToggle = true;
    pros::delay(300);
    chassis.moveToPoint(-36.174, 0.218, 1200, {.minSpeed= 127});
    pros::delay(300);
    intake.move_voltage(12000);
    // chassis.moveToPoint(-44.174, -15.218, 1850, {.maxSpeed= 80});
    // pros::delay(2000);
    // chassis.moveToPoint(-22, -1, 1000, {.forwards = false});
    // pros::delay(100);
    chassis.moveToPoint(18.174, 0.218, 1050, {.minSpeed= 127});
    chassis.moveToPoint(31, 2, 1000, {.maxSpeed = 127});
    chassis.moveToPoint(50, -3, 10000, {.maxSpeed = 75});

    // resetWallstakes();
    antiJamToggle = false;
    // intakeLiftPiston.set_value(true);
    // pros::delay(1050);
    // intakeLiftPiston.set_value(false);
    // pros::delay(1200);
    // chassis.moveToPoint(21.5, -18.3, 1200);
    // pros::delay(100);
    // intake.move_voltage(-500);
    // wallStake.move_voltage(12000);
    // pros::delay(900);
    // wallStake.brake();
    // chassis.moveToPoint(-39.384, 5.946, 1250);
    // chassis.moveToPoint(24.607, 3.935, 1250);

    } else { // blue

    }
    
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
    {"Mecha SAWP", sawp},
    {"Ring Rush", ring_rush},
    // {"Skills", skills, "", 0},

    { "Test PID", testPID},
    { "Test BM", testBM},
    { "Odom Offsets", calibrateOdomOffsets}
});

void autonomous() {
    //initializeColourSort();
    chassis.setPose(0, 0, 0);
    optical.set_led_pwm(100);
    field_status = "autonomous";
    console.println("Running auton...");
    gui_selector.run_auton();
}