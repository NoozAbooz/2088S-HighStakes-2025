#include "main.h"

void half_sawp() {
    if (alliance == "red" || alliance == "na"){
        chassis.moveToPoint(0, 0, 1250);
        wallStake.move_voltage(10000);
        pros::delay(670);
        wallStake.move_voltage(-10000);
        pros::delay(300);
        wallStake.brake();
        chassis.moveToPoint(-37.1, -20.926, 1750, {.forwards = false, .maxSpeed = 65});
        pros::delay(1640);
        clampPiston.set_value(true);
        pros::delay(100);
        intake.move_voltage(12000);
        chassis.moveToPoint(-42.426, -39.767, 1450);
        chassis.turnToHeading(165, 500);
        chassis.moveToPoint(-39.945, -61.267, 1350, {.minSpeed = 80});
        chassis.moveToPoint(-37.326, -36.767, 1250, {.forwards = false});
        chassis.moveToPoint(-27.352, -49.075, 1000);
        chassis.moveToPoint(-34, -17, 2000);
        chassis.turnToHeading(270, 1000);
        wallStake.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
        wallStake.move_voltage(12000);
        pros::delay(300);
        wallStake.move_voltage(0);
    } else {
        chassis.moveToPoint(0, 0, 1250);
        wallStake.move_voltage(10000);
        pros::delay(670);
        wallStake.move_voltage(-10000);
        pros::delay(300);
        wallStake.brake();
        chassis.moveToPoint(36.1, -19.526, 1750, {.forwards = false, .maxSpeed = 65});
        pros::delay(1590);
        clampPiston.set_value(true);
        pros::delay(800);
        intake.move_voltage(12000);
        chassis.moveToPoint(42.326, -38.767, 1250);
        chassis.turnToHeading(195, 500);
        chassis.moveToPoint(39.845, -62.267, 1550);
        chassis.moveToPoint(38.326, -36.767, 1250, {.forwards = false});
        chassis.moveToPoint(26.352, -48.075, 1000);
        chassis.moveToPoint(34, -17, 2000);
        chassis.turnToHeading(45, 1000);
        wallStake.move_voltage(10000);
        pros::delay(200);
        wallStake.move_voltage(0);
    }
}

void sawp() {
    if (alliance == "red" || alliance == "na") {
        chassis.moveToPoint(0, 0, 1250);
        wallStake.move_voltage(10000);
        pros::delay(670);
        wallStake.move_voltage(-10000);
        pros::delay(300);
        wallStake.brake();
        chassis.moveToPoint(-36.1, -19.526, 1750, {.forwards = false, .maxSpeed = 65});
        pros::delay(1620);
        clampPiston.set_value(true);
        pros::delay(100);
        intake.move_voltage(12000);
        chassis.moveToPoint(-42.426, -39.767, 1250);
        chassis.turnToHeading(165, 500);
        chassis.moveToPoint(-40.045, -61.267, 1350, {.maxSpeed = 115});
        chassis.moveToPoint(-38.326, -36.767, 1250, {.forwards = false});
        chassis.moveToPoint(-27.352, -49.075, 1000);
        chassis.moveToPoint(-20.042, 5.3, 1250);
        pros::delay(900);
        intake.move_voltage(0);
        pros::delay(850);
        clampPiston.set_value(false);
        pros::delay(200);
        chassis.moveToPoint(-41.971, 22.681, 1850, {.forwards = false});
        pros::delay(1100);
        clampPiston.set_value(true);
        intake.move_voltage(12000);
        pros::delay(300);
        chassis.moveToPoint(-51.858, 46.824, 1150);
        pros::delay(1000);
        chassis.moveToPoint(-48.552, 16.16, 1300);
        pros::delay(1150);
        wallStake.move_voltage(11000);
        pros::delay(100);
        wallStake.brake();
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
        pros::delay(1150);
        wallStake.move_voltage(11000);
        pros::delay(100);
        wallStake.brake();
    }
}