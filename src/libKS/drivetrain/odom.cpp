#include "main.h"

using namespace ks;

double    x = 0; // global X
double    y = 0; // global Y
double    theta; // global theta

Position odom_pos;

// Gyro scale effect from 2775V
// If it is a bit less than 360, that's your number. If it is a bit more than 0, add 360 and that's your number.
double gyro_scale1 = 360;
double gyro_scale2 = 360;

double vertical_wheel_diameter = 3.25;
double vertical_wheel_offset = 10.75;

double horizontal_wheel_diameter = 3.25;
double horizontal_wheel_offset = 10.75;
std::string wheel_type = "motor";
double gear_ratio = 36.0 / 72;

// Return robot rotation in degrees, unwrapped
double get_imu_rotation() {
	double rotation1 = inertial1.get_rotation();
	double rotation2 = inertial2.get_rotation();

	double average_rotation = 0;
	if (!isnanf(inertial2.get_rotation()) && !isinf(inertial2.get_heading())) { // use imu 2 when available
		average_rotation = ((rotation1 * (360.0 / gyro_scale1)) + (rotation2 * (360.0 / gyro_scale2))) / 2;
	} else {
		average_rotation = rotation1 * (360.0 / gyro_scale1);
	}
	return average_rotation;
}

double get_vertical_distance_traveled() {
    if (wheel_type == "rotation") {
        return ((verticalEncoder.get_position()) * vertical_wheel_diameter * M_PI / 36000) / 1; // 1 is gear ratio
    } else if (wheel_type == "motor") { // cartridge gearing, leave since its factored into rpm
            double left_distance = (leftDrive.get_position(0) / 900 * (vertical_wheel_diameter * M_PI) / gear_ratio);
			double right_distance = (rightDrive.get_position(0) / 900 * (vertical_wheel_diameter * M_PI) / gear_ratio);

			return (left_distance + right_distance) / 2; // find avg
    } else {
        return 0;
    }
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
	inertial1.reset();
	inertial2.reset();

	while (isnanf(inertial1.get_heading()) || isinf(inertial1.get_heading())) {
		pros::delay(10);
	}

	double vertical_pos;
	double heading;
	double previous_distance_traveled = 0;
	double change_in_distance = 0;

	while (true) {
		vertical_pos = get_vertical_distance_traveled();
		heading = fmod((360 - get_imu_rotation()) + 90, 360); // convert compass to standard position
        
		change_in_distance = vertical_pos - previous_distance_traveled;
        
        x += change_in_distance * cos(ks::to_rad(heading));
        y += change_in_distance * sin(ks::to_rad(heading));
    	// At the end of the loop, set previous_distance_traveled for the next loop iteration
        previous_distance_traveled = vertical_pos;

		theta = fmod(get_imu_rotation(), 360); // wrap to [0, 360) for user view
    	if (theta < 0) {
       		theta += 360;
		}

		// print for debugging
		chassis.setPose(x, y, get_imu_rotation());
		//printf("X: %f, Y: %f, Theta: %f\n", x, y, theta);

        pros::delay(10); // todo
    }
}