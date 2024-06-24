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

using namespace strait;

void testPID() {
    chassis.moveToPoint(0, 0, 10);
    chassis.moveToPoint(0, 24, 5000);
}

void sixballs() {
    
}

void closeside() {
    
}

rd::Selector gui_selector({
    {"PID test", &testPID, "/usd/images/pidtest.bin"},
    {"Six balls", &sixballs},
    {"Close side", &closeside}
});

void autonomous() {
    chassis.setPose(0,0,0);
    gui_selector.run_auton();
    // switch(selector::auton) {
    //     case 0: // Do nothing
    //         break;
    // }
}



