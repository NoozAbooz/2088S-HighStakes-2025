#include "main.h"

void pid_sawp() {
    if (alliance == "red" || alliance == "na"){
        cat.setBrakeMode(pros::E_MOTOR_BRAKE_BRAKE);
        // lb alliance stake
        wallStake.move_voltage(10000);
        pros::delay(670);

        pros::Task([] {
            wallStake.move_voltage(-10000);
            pros::delay(300);
            wallStake.brake();
        });
        pros::delay(100);

        chassis.turnToHeading(50, 800, {.maxSpeed = 100});

        // move to mogo 1
        cat.movePID(-20, 2000, 1.2, 5);
        pros::Task([] {
            pros::delay(500);
            clampPiston.set_value(true);
        });
        cat.movePID(-20, 1000, 1);

        // turn to ring stack 1
        chassis.turnToHeading(220, 1000, {}, false);
        intake.move_voltage(12000); // TODO ENABLE
        cat.movePID(24, 900, 1, 1);

        // ringstack 2
        chassis.turnToHeading(95, 1000);
        cat.movePID(25, 2000, 1, 1);
        pros::delay(600);

        // back out and go to mogo #2
        inertial1.set_rotation(0);
        chassis.turnToHeading(-85, 1000);
        pros::Task([] {
            pros::delay(1800);
            clampPiston.set_value(false);
        });
        cat.movePID(60, 4000, 1.2, 1);

        // clamp mogo #2
        chassis.turnToHeading(25, 800, {.earlyExitRange = 10}, false);
        pros::Task([] {
            pros::delay(900);
            clampPiston.set_value(true);
        });
        cat.movePID(-32, 1000, 0.3);

        // ring stack 3
        chassis.setPose(0, 0, 0);
        chassis.turnToHeading(255, 1000, {}, false);
        cat.movePID(18, 1000, 1.2, 1.3);

        // touch ladder
        cat.setBrakeMode(pros::E_MOTOR_BRAKE_COAST);
        chassis.moveToPoint(24, 2, 1000, {.minSpeed = 110});
        pros::Task([] {
            pros::delay(1000);
            wallStake.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
            wallStake.move_voltage(12000);
        });
    }
}

void sawp() {
    if (alliance == "red" || alliance == "na") {
        chassis.moveToPoint(0, 0, 1250);
        wallStake.move_voltage(10000);
        pros::delay(490);
        wallStake.move_voltage(-10000);
        pros::delay(240);
        wallStake.brake();
        chassis.moveToPoint(-36.1, -20.526, 1750, {.forwards = false, .maxSpeed = 65});
        pros::delay(1620);
        clampPiston.set_value(true);
        pros::delay(200);
        chassis.moveToPoint(-46.4726, -41.967, 1650);
        pros::delay(100);
        intake.move_voltage(12000);
        pros::delay(1000);
        chassis.moveToPoint(-35, -25, 1000, {.forwards = false});
        // chassis.turnToHeading(165, 500);
        // chassis.moveToPoint(-40.045, -61.267, 1350, {.maxSpeed = 115});
        // chassis.moveToPoint(-38.326, -36.767, 1250, {.forwards = false});
        chassis.moveToPoint(-25.852, -53.075, 1300);
        pros::delay(700);
        chassis.moveToPoint(-15.042, 13.3, 1850);
        pros::delay(900);
        intake.move_voltage(0);
        pros::delay(850);
        clampPiston.set_value(false);
        pros::delay(200);
        chassis.moveToPoint(-42.971, 26.681, 1400, {.forwards = false, .maxSpeed = 80});
        pros::delay(1270);
        clampPiston.set_value(true);
        chassis.turnToHeading(345, 600);
        chassis.moveToPoint(-48.858, 52.824, 1550);
        pros::delay(400);
        intake.move_voltage(12000);
        pros::delay(1000);
        chassis.moveToPoint(-38.552, 27.16, 1400);
        pros::Task([] {
            pros::delay(1550);
            wallStake.move_voltage(11000);
            pros::delay(150);
            wallStake.brake();
        });
        chassis.turnToHeading(215, 900);
    } else {
        chassis.moveToPoint(0, 0, 1250);
        wallStake.move_voltage(10000);
        pros::delay(670);
        wallStake.move_voltage(-10000);
        pros::delay(300);
        wallStake.brake();
        chassis.moveToPoint(36.1, -19.826, 1750, {.forwards = false, .maxSpeed = 65});
        pros::delay(1620);
        clampPiston.set_value(true);
        pros::delay(800);
        intake.move_voltage(12000);
        chassis.moveToPoint(42.326, -38.767, 1250);
        chassis.turnToHeading(195, 500);
        chassis.moveToPoint(39.745, -62.967, 1250);
        chassis.moveToPoint(38.326, -36.767, 1250, {.forwards = false});
        chassis.moveToPoint(26.352, -48.075, 1000);
        chassis.moveToPoint(20.042, 10.3, 1250);
        pros::delay(900);
        intake.move_voltage(0);
        pros::delay(850);
        clampPiston.set_value(false);
        pros::delay(200);
        chassis.moveToPoint(41.971, 22.681, 1850, {.forwards = false});
        pros::delay(1100);
        clampPiston.set_value(true);
        intake.move_voltage(12000);
        pros::delay(300);
        chassis.moveToPoint(51.858, 46.824, 1150);
        pros::delay(1000);
        chassis.moveToPoint(48.552, 16.16, 1300);
        pros::delay(0);
        wallStake.move_voltage(11000);
        pros::delay(100);
        wallStake.brake();
    }
}