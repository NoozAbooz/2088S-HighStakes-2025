#pragma once
#include "main.h"

// Controller
extern pros::Controller controller;

// Drivetrain
extern pros::MotorGroup leftDrive;
extern pros::MotorGroup rightDrive;

extern lemlib::Chassis chassis;

// Intake
extern pros::Motor intake;

// Catapult
extern pros::Motor slapper;

// Inertial
extern pros::Imu inertial;
extern pros::Imu inertial2;

extern pros::Rotation verticalEncoder;
extern pros::Rotation horizontalEncoder;

extern pros::adi::Potentiometer potentiometer;

extern pros::adi::DigitalOut leftWingPiston;
extern pros::adi::DigitalOut rightWingPiston;

extern pros::adi::DigitalOut liftPiston;
extern pros::adi::DigitalOut tailPiston;
extern pros::adi::DigitalOut ptoPiston;
