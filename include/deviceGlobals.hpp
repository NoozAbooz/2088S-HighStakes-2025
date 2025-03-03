#pragma once
#include "main.h"

// Controller
inline pros::Controller controller(pros::E_CONTROLLER_MASTER);

// Drivetrain

// ri24
// inline pros::MotorGroup leftDrive({14, -15, 16}); 
// inline pros::MotorGroup rightDrive({-12, 13, -17});

// v1
inline pros::MotorGroup leftDrive({4, -3, -5});
inline pros::MotorGroup rightDrive({-7, 10, 8});

// Intake
inline pros::MotorGroup intake({-9});
inline pros::Motor wallStake(15);

// Pneumatics
inline pros::adi::Pneumatics clampPiston('A', false);
inline pros::adi::Pneumatics leftDoinkerPiston('B', false);
inline pros::adi::Pneumatics rightDoinkerPiston('C', false);
inline pros::adi::Pneumatics intakeLiftPiston('D', false);

/* Declare sensors */
inline pros::Optical optical(6);
inline pros::Distance dist(21);
inline pros::Imu inertial1(2);
inline pros::Rotation wallStakeRotationSensor(11);

inline pros::Distance backwardDist(18); // 4.8in back from center
inline pros::Distance leftDist(20); // 6in left of center

inline pros::Rotation verticalEncoder(-13);
inline pros::Rotation horizontalEncoder(1);
//hello world it is 210K secret note iykyk :D
// horizontal tracking wheel
inline lemlib::TrackingWheel vertical_tracking_wheel(&verticalEncoder, lemlib::Omniwheel::NEW_275, 0.876);
// vertical tracking wheel
inline lemlib::TrackingWheel horizontal_tracking_wheel(&horizontalEncoder, lemlib::Omniwheel::NEW_275, -3.2455);

// drivetrain settings
inline lemlib::Drivetrain drivetrain(&leftDrive, // left motor group
                              &rightDrive, // right motor group
                              11.75, // track width
                              lemlib::Omniwheel::NEW_325,
                              450, // drivetrain rpm
                              2 // chase power is 2. If we had traction wheels, it would have been 8
);
// lateral motion controller
inline lemlib::ControllerSettings lateralController(6, // proportional gain (kP)
                                              0, // integral gain (kI)
                                              8, // derivative gain (kD)
                                              3, // anti windup
                                              1, // small error range, in inches
                                              100, // small error range timeout, in milliseconds
                                              3, // large error range, in inches
                                              500, // large error range timeout, in milliseconds
                                              40 // maximum acceleration (slew)
);
// angular motion controller
inline lemlib::ControllerSettings angularController(2.5, // proportional gain (kP)
                                              0, // integral gain (kI)
                                              17.4, // derivative gain (kD)
                                              3, // anti windup
                                              1, // small error range, in inches
                                              100, // small error range timeout, in milliseconds
                                              3, // large error range, in inches
                                              500, // large error range timeout, in milliseconds
                                              0 // maximum acceleration (slew)
);
// sensors for odometry
// note that in this example we use internal motor encoders, so we don't pass vertical tracking wheels
inline lemlib::OdomSensors sensors(&vertical_tracking_wheel, // vertical tracking wheel 1, set to nullptr as we don't have one
                            nullptr, // vertical tracking wheel 2, set to nullptr as we don't have one
                            &horizontal_tracking_wheel, // horizontal tracking wheel 1
                            nullptr, // horizontal tracking wheel 2, set to nullptr as we don't have a second one
                            &inertial1 // inertial sensor
);
// create the chassis
inline lemlib::Chassis chassis(drivetrain, lateralController, angularController, sensors);

inline catlib::Drivetrain dt(
    &leftDrive,
    &rightDrive,
    catlib::omniWheel::OMNI_325,
    450
);

inline catlib::PIDConstants lateral_pid(
    6.5,
    0,
    30
);

inline catlib::PIDConstants angular_pid(
    2.5,
    0,
    25
);

inline catlib::TrackingWheel vertical_tracker(
    &verticalEncoder,
    2.75,
    0.876
);

inline catlib::TrackingWheel horizontal_tracker(
    &horizontalEncoder,
    2.75,
    -3.2455
);

inline catlib::OdomSensors bensors(
    &inertial1,
    &vertical_tracker,
    &horizontal_tracker
);

inline catlib::Chassis cat (
    &dt,
    &lateral_pid,
    &angular_pid,
    &bensors,
    catlib::DriveType::SPLIT_ARCADE
);