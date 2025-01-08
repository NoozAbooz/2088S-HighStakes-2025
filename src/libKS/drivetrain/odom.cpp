#include "main.h"

using namespace ks;

double    x = 0; // global X
double    y = 0; // global Y
double    theta; // global theta

Position ks::odom_pos;

// Gyro scale effect from 2775V
// If it is a bit less than 360, that's your number. If it is a bit more than 0, add 360 and that's your number.
double gyro_scale1 = 360;
double gyro_scale2 = 360;

double vertical_wheel_diameter = 2.75;
double vertical_wheel_offset = 0.44;

double horizontal_wheel_diameter = 2.75;
double horizontal_wheel_offset = 1.65;
double gear_ratio = 36.0 / 48;

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
    if (!isnanf(verticalEncoder.get_position()) && !isinf(verticalEncoder.get_position())) { // use rot sensor as priority
        return ((verticalEncoder.get_position()) * vertical_wheel_diameter * M_PI / 36000); // 1 is gear ratio
    } else if (!isnanf(leftDrive.get_position(0)) && !isinf(leftDrive.get_position(0))) { // 900 is cartridge gearing, leave since its factored into rpm
            double left_distance = (leftDrive.get_position(0) / 900 * (vertical_wheel_diameter * M_PI) / gear_ratio);
			double right_distance = (rightDrive.get_position(0) / 900 * (vertical_wheel_diameter * M_PI) / gear_ratio);

			return (left_distance + right_distance) / 2; // find avg
    } else {
        return 0;
    }
}

double get_horizontal_distance_traveled() { 
	return ((horizontalEncoder.get_position()) * horizontal_wheel_diameter * M_PI / 36000);
}

// double get_dt_heading() {
// 	double wheel_circumference = M_PI * wheel_diameter;

// 	double left_distance = (leftDrive.at(1).get_position() / 360) * wheel_circumference / gear_ratio;
// 	double right_distance = (rightDrive.at(1).get_position() / 360) * wheel_circumference / gear_ratio;

// 	double heading_in_radians = (left_distance - right_distance) / track_width;
// 	return std::fmod(to_deg(heading_in_radians), 360);
// }


// important vars for odom
double vertical_pos;
double horizontal_pos;

double prev_vertical_pos = 0;
double prev_horizontal_pos = 0;

double delta_vertical;
double delta_horizontal;

double heading;
double prev_heading;
double delta_heading;
double avg_heading;
	
double deltaXLocal;
double deltaYLocal;

void ks::initializeOdom() {
	pros::Task odom_task(ks::odomUpdate);
}

void ks::setOdomPosition(double x_new = 0, double y_new = 0, double theta_new = 0) {
	odom_task.suspend();
	x = x_new;
	y = y_new;

	verticalEncoder.reset_position();
	horizontalEncoder.reset_position();

	vertical_pos = 0;
	horizontal_pos = 0;
	prev_vertical_pos = 0;
	prev_horizontal_pos = 0;
	prev_heading = 0;

	inertial1.set_heading(theta_new);
	inertial2.set_heading(theta_new);
	odom_task.resume();
}

void ks::odomUpdate() {
	inertial1.reset();
	inertial2.reset();

	verticalEncoder.reset_position();
	horizontalEncoder.reset_position();

	while (isnanf(inertial1.get_heading()) || isinf(inertial1.get_heading())) {
		pros::delay(10);
	}

	while (true) {
		printf("%f, %f\n", get_vertical_distance_traveled(), get_horizontal_distance_traveled());
		vertical_pos = get_vertical_distance_traveled();
		horizontal_pos = get_horizontal_distance_traveled();
        
		delta_vertical = (vertical_pos - prev_vertical_pos);
		delta_horizontal = (horizontal_pos - prev_horizontal_pos);

		prev_vertical_pos = vertical_pos;
		prev_horizontal_pos = horizontal_pos;
		
		heading = to_rad(fmod((360 - get_imu_rotation()) + 90, 360)); // convert compass to standard position in RAD
		delta_heading = heading - prev_heading;
		prev_heading = heading;
		
		if (delta_heading == 0) {
			deltaXLocal = delta_horizontal;
			deltaYLocal = delta_vertical;
		} else {
			// LEFT_TRACKING_RADIUS is the distance from the left tracking wheel to the tracking center of the robot
			// PERPENDICULAR_TRACKING_RADIUS is the distance from the perpendicular tracking wheel to the tracking center of the robot
			deltaXLocal = 2 * sin(delta_heading / 2) * ((delta_horizontal / delta_heading) + horizontal_wheel_offset);
			deltaYLocal = 2 * sin(delta_heading / 2) * ((delta_vertical / delta_heading) + vertical_wheel_offset);
		}

		avg_heading = heading - (delta_heading / 2);

		x += (deltaYLocal * cos(avg_heading)) + (deltaXLocal * sin(avg_heading));
		y += (deltaYLocal * sin(avg_heading)) - (deltaXLocal * cos(avg_heading));

		theta = fmod(get_imu_rotation(), 360); // wrap to [0, 360) for user view
    	if (theta < 0) {
       		theta += 360;
		}

		// funky stuff for alliance colours :(
		chassis.setPose(x, y, get_imu_rotation());
        pros::delay(5);
    }
}