#pragma once
#include "main.h"

// Controller
inline pros::Controller controller(pros::E_CONTROLLER_MASTER);

// Drivetrain

// ri24
inline pros::MotorGroup leftDrive({14, -15, 16}); 
inline pros::MotorGroup rightDrive({-12, 13, -17});

// v1
// inline pros::MotorGroup leftDrive({-1, -2, 3});
// inline pros::MotorGroup rightDrive({6, -7, 8});

// Intake
inline pros::Motor intake(-10);
inline pros::Motor wallStake(9);

// Pneumatics
inline pros::adi::Pneumatics clampPiston('A', false);
inline pros::adi::Pneumatics doinkerPiston('B', false);
inline pros::adi::Pneumatics hoodPiston('C', false, true);

/* Declare sensors */
inline pros::Optical optical(14);
inline pros::Imu inertial1(17);
//inline pros::Imu inertial1(3);
inline pros::Imu inertial2(15);

inline pros::Rotation verticalEncoder(22);
inline pros::Rotation horizontalEncoder(22);
// horizontal tracking wheel
inline lemlib::TrackingWheel vertical_tracking_wheel(&verticalEncoder, lemlib::Omniwheel::NEW_2, 5.75);
// vertical tracking wheel
inline lemlib::TrackingWheel horizontal_tracking_wheel(&horizontalEncoder, lemlib::Omniwheel::NEW_2, 2.5);

// drivetrain settings
inline lemlib::Drivetrain drivetrain(&leftDrive, // left motor group
                              &rightDrive, // right motor group
                              13.5, // track width
                              lemlib::Omniwheel::NEW_4,
                              360, // drivetrain rpm
                              2 // chase power is 2. If we had traction wheels, it would have been 8
);
// lateral motion controller
inline lemlib::ControllerSettings linearController(21, // proportional gain (kP)
                                            0, // integral gain (kI)
                                            24, // derivative gain (kD)
                                            3, // anti windup
                                            1, // small error range, in inches
                                            100, // small error range timeout, in milliseconds
                                            3, // large error range, in inches
                                            500, // large error range timeout, in milliseconds
                                            20 // maximum acceleration (slew)
);
// angular motion controller
inline lemlib::ControllerSettings angularController(5, // proportional gain (kP)
                                             0, // integral gain (kI)
                                             50, // derivative gain (kD)
                                             3, // anti windup
                                             1, // small error range, in degrees
                                             100, // small error range timeout, in milliseconds
                                             3, // large error range, in degrees
                                             500, // large error range timeout, in milliseconds
                                             0 // maximum acceleration (slew)
);
// sensors for odometry
// note that in this example we use internal motor encoders, so we don't pass vertical tracking wheels
inline lemlib::OdomSensors sensors(nullptr, // vertical tracking wheel 1, set to nullptr as we don't have one
                            nullptr, // vertical tracking wheel 2, set to nullptr as we don't have one
                            nullptr, // horizontal tracking wheel 1
                            nullptr, // horizontal tracking wheel 2, set to nullptr as we don't have a second one
                            &inertial1 // inertial sensor
);
// create the chassis
inline lemlib::Chassis chassis(drivetrain, linearController, angularController, sensors);