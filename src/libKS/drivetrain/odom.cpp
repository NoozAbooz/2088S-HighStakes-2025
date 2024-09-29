#include "main.h"

using namespace ks;

double    x = 0; // global X
double    y = 0; // global Y
double    theta; // global theta

Position odom_pos;

// Gyro scale effect from 2775V
// If it is a bit less than 360, that's your number. If it is a bit more than 0, add 360 and that's your number.
double gyro_scale1 = 357.91;
double gyro_scale2 = 360.8;

double vertical_wheel_diameter = 3.25;
double vertical_wheel_offset = 10.75;

double horizontal_wheel_diameter = 3.25;
double horizontal_wheel_offset = 10.75;

// Return robot rotation in radians, unwrapped to 360
double get_imu_rotation() {
	double rotation1 = inertial1.get_rotation();
	double rotation2 = inertial2.get_rotation();

	double average_rotation = ((rotation1 * (360.0 / gyro_scale1)) + (rotation2 * (360.0 / gyro_scale2))) / 2;
	return fmod(average_rotation - 90, 360);
}

double get_vertical_distance_traveled() { 
	double current_vertical_pos = verticalEncoder.get_angle();

	// Divide current angle for centidegree ticks conversion to get amount of wheel rots and multiple by circumference to get total distance
	return (current_vertical_pos / 36000) * (M_PI * vertical_wheel_diameter);
}

double get_horizontal_distance_traveled() { 
	double current_horizontal_pos = horizontalEncoder.get_angle();
	return (current_horizontal_pos / 36000) * (M_PI * horizontal_wheel_diameter);
}

// double get_dt_heading() {
// 	double wheel_circumference = M_PI * wheel_diameter;

// 	double left_distance = (leftDrive.at(1).get_position() / 360) * wheel_circumference / gear_ratio;
// 	double right_distance = (rightDrive.at(1).get_position() / 360) * wheel_circumference / gear_ratio;

// 	double heading_in_radians = (left_distance - right_distance) / track_width;
// 	return std::fmod(to_deg(heading_in_radians), 360);
// }

void ks::odomThread() {
	inertial2.reset();

	while (true) {
		double vertical_pos = get_vertical_distance_traveled();
		double horizontal_pos = get_horizontal_distance_traveled();

		// Find average between dt and imu heading
		// wrap to [0, 360)
		double heading = ks::to_rad(get_imu_rotation());
        
		// Only run calcs if robot is acively moving
		if (inertial1.get_accel().x > 0.1 || inertial1.get_accel().y > 0.1) {
			// double deltaLeft = (vertical_pos - prev_vertical_pos) * (M_PI / 180) * WHEEL_RADIUS; // Convert degrees to radians
			// double deltaPerpendicular = (perpendicularPosition - prevPerpendicularPosition) * (M_PI / 180) * WHEEL_RADIUS;

			// delta_distance = distance_traveled - previous_distance_traveled;
			// // std trig functions are in radians, so we have intermediary conversion to radians
        	// x += delta_distance * std::cos(heading);
        	// y += delta_distance * std::sin(heading);

			// // Set previous_distance_travelled for the next loop iteration
        	// previous_distance_traveled = distance_traveled;
		}

		// print for debugging
		//chassis.setPose(chassis.getPose().x, chassis.getPose().y, get_imu_rotation());
		// console.printf("X: %f, Y: %f, Theta: %f\n", x, y, get_imu_rotation());
		printf("Theta: %f\n", get_imu_rotation());

        pros::delay(100); // todo
    }
}