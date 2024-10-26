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
    // ks::LateralPID::set_lateral_constants(21, 0, 0.24, 5000);
    // ks::LateralPID::move_lateral_pid(24, 127, 0, 4);
    chassis.setPose(0, 0, 0);
    chassis.moveToPoint(0, 24, 5000);
    chassis.turnToHeading(90, 1000);
    chassis.moveToPoint(24, 24, 5000);
    
}
 
void test() {

chassis.moveToPoint(0.00, 0.00, 1000, {.forwards = true, .maxSpeed = 127, .minSpeed = 0}); // Point 1
chassis.moveToPoint(0, 40.35, 1000, {.forwards = true, .maxSpeed = 127, .minSpeed = 0}); // Point 2
chassis.turnToPoint(100,400,500);
chassis.moveToPoint(4.5, 50, 1500, {.forwards = true, .maxSpeed = 127, .minSpeed = 0}); // Point 3
pros::delay(600);
doinkerPiston.set_value(true);
pros::delay(800);
chassis.moveToPoint(4.5, 29.54, 3000, {.forwards = false, .maxSpeed = 60, .minSpeed = 0}); // Point 3
pros::delay(1500);
doinkerPiston.set_value(false);
pros::delay(800);
chassis.moveToPoint(4.5, 37, 1000);
chassis.turnToPoint(80, 45, 1000);
pros::delay(200);
chassis.moveToPoint(-13, 37, 1000, {false, 127, 0});
pros::delay(500);
clampPiston.set_value(true);
pros::delay(100);
intake.move_voltage(12000);
pros::delay(2000);
clampPiston.set_value(false);
pros::delay(100);
intake.move_voltage(0);
chassis.turnToPoint(-80, 19.5, 2000);
pros::delay(1000);
chassis.setPose(0,0,0);
chassis.turnToPoint(-6, 6, 1000);
chassis.moveToPoint(4, -4, 1000, {false, 127, 0});
intake.move_voltage(-12000);
chassis.moveToPoint(0.5, -15, 1000);

}

void WP_3Rush() {
    // libKS MTPoint v0.1
// Starting point: (58.76 in, -24.06 in)
// blue side
chassis.moveToPoint(0.00, 0.00, 2000, {.forwards = true, .maxSpeed = 127, .minSpeed = 0}); // Point 1
chassis.moveToPoint(0.39, 58.57, 2000, {.forwards = false, .maxSpeed = 127, .minSpeed = 0}); // Point 2
chassis.moveToPoint(-7.50, 42.20, 2000, {.forwards = true, .maxSpeed = 127, .minSpeed = 0}); // Point 3
chassis.moveToPoint(11.68, 33.23, 2000, {.forwards = false, .maxSpeed = 127, .minSpeed = 0}); // Point 4
chassis.moveToPoint(-42.36, 10.33, 2000, {.forwards = true, .maxSpeed = 127, .minSpeed = 0}); // Point 5
chassis.moveToPoint(-17.38, 20.68, 2000, {.forwards = false, .maxSpeed = 127, .minSpeed = 0}); // Point 6
chassis.moveToPoint(12.64, -9.16, 2000, {.forwards = true, .maxSpeed = 127, .minSpeed = 0}); // Point 7
chassis.moveToPoint(30.17, 26.67, 2000, {.forwards = true, .maxSpeed = 127, .minSpeed = 0}); // Point 8

// libKS MTPoint v0.1
// Starting point: (-60.43 in, -24.06 in)
// red side
chassis.moveToPoint(0.00, 0.00, 2000, {.forwards = true, .maxSpeed = 127, .minSpeed = 0}); // Point 1
chassis.moveToPoint(-0.39, 58.57, 2000, {.forwards = false, .maxSpeed = 127, .minSpeed = 0}); // Point 2
chassis.moveToPoint(7.50, 42.20, 2000, {.forwards = true, .maxSpeed = 127, .minSpeed = 0}); // Point 3
chassis.moveToPoint(-11.68, 33.23, 2000, {.forwards = false, .maxSpeed = 127, .minSpeed = 0}); // Point 4
chassis.moveToPoint(42.36, 10.33, 2000, {.forwards = true, .maxSpeed = 127, .minSpeed = 0}); // Point 5
chassis.moveToPoint(17.38, 20.68, 2000, {.forwards = false, .maxSpeed = 127, .minSpeed = 0}); // Point 6
chassis.moveToPoint(-12.64, -9.16, 2000, {.forwards = true, .maxSpeed = 127, .minSpeed = 0}); // Point 7
chassis.moveToPoint(-30.17, 26.67, 2000, {.forwards = true, .maxSpeed = 127, .minSpeed = 0}); // Point 8


}

void WP4() {
    // libKS MTPoint v0.1
// Starting point: (-60.43 in, -24.06 in)
// blue side
chassis.moveToPoint(0.00, 0.00, 2000, {.forwards = true, .maxSpeed = 127, .minSpeed = 0}); // Point 1
chassis.moveToPoint(-0.39, 58.57, 2000, {.forwards = false, .maxSpeed = 127, .minSpeed = 0}); // Point 2
chassis.moveToPoint(7.50, 42.20, 2000, {.forwards = true, .maxSpeed = 127, .minSpeed = 0}); // Point 3
chassis.moveToPoint(-11.68, 33.23, 2000, {.forwards = false, .maxSpeed = 127, .minSpeed = 0}); // Point 4
chassis.moveToPoint(42.36, 10.33, 2000, {.forwards = true, .maxSpeed = 127, .minSpeed = 0}); // Point 5
chassis.moveToPoint(17.38, 20.68, 2000, {.forwards = false, .maxSpeed = 127, .minSpeed = 0}); // Point 6
chassis.moveToPoint(-12.64, -9.16, 2000, {.forwards = true, .maxSpeed = 127, .minSpeed = 0}); // Point 7
chassis.moveToPoint(-30.17, 26.67, 2000, {.forwards = true, .maxSpeed = 127, .minSpeed = 0}); // Point 8

// libKS MTPoint v0.1
// Starting point: (-60.43 in, 23.22 in)
// red side
chassis.moveToPoint(0.00, 0.00, 2000, {.forwards = true, .maxSpeed = 127, .minSpeed = 0}); // Point 1
chassis.moveToPoint(0.00, -29.67, 2000, {.forwards = false, .maxSpeed = 127, .minSpeed = 0}); // Point 2
chassis.moveToPoint(16.09, -52.81, 2000, {.forwards = true, .maxSpeed = 127, .minSpeed = 0}); // Point 3
chassis.moveToPoint(25.15, -52.81, 2000, {.forwards = true, .maxSpeed = 127, .minSpeed = 0}); // Point 4
chassis.moveToPoint(41.24, -56.33, 2000, {.forwards = true, .maxSpeed = 127, .minSpeed = 0}); // Point 5
chassis.moveToPoint(21.63, -37.22, 2000, {.forwards = true, .maxSpeed = 127, .minSpeed = 0}); // Point 6
chassis.moveToPoint(-23.64, 8.05, 2000, {.forwards = true, .maxSpeed = 127, .minSpeed = 0}); // Point 7
chassis.moveToPoint(-23.13, -30.68, 2000, {.forwards = true, .maxSpeed = 127, .minSpeed = 0}); // Point 8


}

void Elim_rush () {
    // libKS MTPoint v0.1
// Starting point: (60.27 in, -58.25 in)
// blue side
chassis.moveToPoint(0.00, 0.00, 2000, {.forwards = true, .maxSpeed = 127, .minSpeed = 0}); // Point 1
chassis.moveToPoint(1.16, -52.91, 2000, {.forwards = true, .maxSpeed = 127, .minSpeed = 0}); // Point 2
chassis.moveToPoint(14.73, -54.60, 2000, {.forwards = true, .maxSpeed = 127, .minSpeed = 0}); // Point 3
chassis.moveToPoint(-2.19, -39.71, 2000, {.forwards = true, .maxSpeed = 127, .minSpeed = 0}); // Point 4
chassis.moveToPoint(-22.09, -42.71, 2000, {.forwards = true, .maxSpeed = 127, .minSpeed = 0}); // Point 5
chassis.moveToPoint(5.01, 3.44, 2000, {.forwards = true, .maxSpeed = 127, .minSpeed = 0}); // Point 6
chassis.moveToPoint(-52.62, -23.07, 2000, {.forwards = true, .maxSpeed = 127, .minSpeed = 0}); // Point 7
chassis.moveToPoint(-55.94, -4.25, 2000, {.forwards = true, .maxSpeed = 127, .minSpeed = 0}); // Point 8

// libKS MTPoint v0.1
// Starting point: (-61.94 in, -58.25 in)
// red side
chassis.moveToPoint(0.00, 0.00, 2000, {.forwards = true, .maxSpeed = 127, .minSpeed = 0}); // Point 1
chassis.moveToPoint(-1.16, -52.91, 2000, {.forwards = true, .maxSpeed = 127, .minSpeed = 0}); // Point 2
chassis.moveToPoint(-14.73, -54.60, 2000, {.forwards = true, .maxSpeed = 127, .minSpeed = 0}); // Point 3
chassis.moveToPoint(2.19, -39.71, 2000, {.forwards = true, .maxSpeed = 127, .minSpeed = 0}); // Point 4
chassis.moveToPoint(22.09, -42.71, 2000, {.forwards = true, .maxSpeed = 127, .minSpeed = 0}); // Point 5
chassis.moveToPoint(-5.01, 3.44, 2000, {.forwards = true, .maxSpeed = 127, .minSpeed = 0}); // Point 6
chassis.moveToPoint(52.62, -23.07, 2000, {.forwards = true, .maxSpeed = 127, .minSpeed = 0}); // Point 7
chassis.moveToPoint(55.94, -4.25, 2000, {.forwards = true, .maxSpeed = 127, .minSpeed = 0}); // Point 8

}

void Elim_score() {
    // libKS MTPoint v0.1
// Starting point: (57.25 in, 11.15 in)
// blue side
chassis.moveToPoint(0.00, 0.00, 2000, {.forwards = false, .maxSpeed = 127, .minSpeed = 0}); // Point 1
chassis.moveToPoint(12.80, -26.32, 2000, {.forwards = true, .maxSpeed = 127, .minSpeed = 0}); // Point 2
chassis.moveToPoint(0.71, -46.94, 2000, {.forwards = true, .maxSpeed = 127, .minSpeed = 0}); // Point 3
chassis.moveToPoint(12.09, -58.32, 2000, {.forwards = true, .maxSpeed = 127, .minSpeed = 0}); // Point 4
chassis.moveToPoint(8.89, -65.08, 2000, {.forwards = true, .maxSpeed = 127, .minSpeed = 0}); // Point 5
chassis.moveToPoint(0.36, -77.17, 2000, {.forwards = true, .maxSpeed = 127, .minSpeed = 0}); // Point 6

// libKS MTPoint v0.1
// Starting point: (-58.92 in, 11.15 in)
// red side
chassis.moveToPoint(0.00, 0.00, 2000, {.forwards = false, .maxSpeed = 127, .minSpeed = 0}); // Point 1
chassis.moveToPoint(-12.80, -26.32, 2000, {.forwards = true, .maxSpeed = 127, .minSpeed = 0}); // Point 2
chassis.moveToPoint(-0.71, -46.94, 2000, {.forwards = true, .maxSpeed = 127, .minSpeed = 0}); // Point 3
chassis.moveToPoint(-12.09, -58.32, 2000, {.forwards = true, .maxSpeed = 127, .minSpeed = 0}); // Point 4
chassis.moveToPoint(-8.89, -65.08, 2000, {.forwards = true, .maxSpeed = 127, .minSpeed = 0}); // Point 5
chassis.moveToPoint(-0.36, -77.17, 2000, {.forwards = true, .maxSpeed = 127, .minSpeed = 0}); // Point 6

}

rd::Selector gui_selector({
    {"PID test", &testPID},
    {"WP Rush", &WP_3Rush},
    {"WP 4 Ring", &WP4},
    {"Elim Rush", &Elim_rush},
    {"Elim Score", &Elim_score}
});

void autonomous() {
    chassis.setPose(0,0,0);
    console.println("Running auton...");
    //gui_selector.run_auton();
    test();
    rd_view_focus(gifview);
}