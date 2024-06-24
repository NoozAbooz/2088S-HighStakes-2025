#include "main.h"

/* Declare functional components */

// Controller
pros::Controller controller(pros::E_CONTROLLER_MASTER);

// Drivetrain
pros::MotorGroup leftDrive({-13, -14, -15});
pros::MotorGroup rightDrive({16, 17, 18});

// Intake
pros::Motor intake(10);

// Pneumatics
pros::adi::DigitalOut leftWingPiston('B');
pros::adi::DigitalOut rightWingPiston('C');

pros::adi::DigitalOut liftPiston('E');
pros::adi::DigitalOut tailPiston('D');
pros::adi::DigitalOut ptoPiston('X');

/* Declare sensors */
pros::adi::Potentiometer potentiometer('G');

pros::Imu inertial(2);
pros::Imu inertial2(3);

pros::Rotation verticalEncoder(15);
pros::Rotation horizontalEncoder(16);
// horizontal tracking wheel
lemlib::TrackingWheel vertical_tracking_wheel(&verticalEncoder, lemlib::Omniwheel::NEW_275, -5.75);
// vertical tracking wheel
lemlib::TrackingWheel horizontal_tracking_wheel(&horizontalEncoder, lemlib::Omniwheel::NEW_275, -2.5);

// drivetrain settings
lemlib::Drivetrain drivetrain(&leftDrive, // left motor group
                              &rightDrive, // right motor group
                              10.5, // 25 hole track width
                              lemlib::Omniwheel::NEW_325,
                              450, // drivetrain rpm
                              2 // chase power is 2. If we had traction wheels, it would have been 8
);
// lateral motion controller
lemlib::ControllerSettings linearController(21, // proportional gain (kP)
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
lemlib::ControllerSettings angularController(5, // proportional gain (kP)
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
lemlib::OdomSensors sensors(nullptr, // vertical tracking wheel 1, set to nullptr as we don't have one
                            nullptr, // vertical tracking wheel 2, set to nullptr as we don't have one
                            nullptr, // horizontal tracking wheel 1
                            nullptr, // horizontal tracking wheel 2, set to nullptr as we don't have a second one
                            &inertial // inertial sensor
);
// create the chassis
lemlib::Chassis chassis(drivetrain, linearController, angularController, sensors);