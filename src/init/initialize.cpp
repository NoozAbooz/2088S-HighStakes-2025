#include "main.h"

/**
 * Runs initialization code. This occurs as soon as the program is started.
 *
 * All other competition modes are blocked by initialize; it is recommended
 * to keep execution time for this mode under a few seconds.
 */
void initialize() {
    rdconfig_init();
    pros::delay(10);

    pros::Task([] {
        chassis.calibrate();
    });

    // pros::Task([] {
    //     ks::odomThread();   
    // });

    optical.set_led_pwm(75); // enable led on optical sensor for accuracy
    optical.set_integration_time(10); // refresh every 10ms
    wallStake.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
    wallStake.tare_position_all();
    console.println("Robot initialized");
}

/**
 * Runs while the robot is in the disabled state of Field Management System or
 * the VEX Competition Switch, following either autonomous or opcontrol. When
 * the robot is enabled, this task will exit.
 */
void disabled() {
}

/**
 * Runs after initialize(), and before autonomous when connected to the Field
 * Management System or the VEX Competition Switch. This is intended for
 * competition-specific initialization routines, such as an autonomous selector
 * on the LCD.
 *
 * This task will exit when the robot is enabled and autonomous or opcontrol
 * starts.
 */
bool isCompetition = false;
void competition_initialize() {
    rd_view_focus(allianceview);
    isCompetition = true;
}
