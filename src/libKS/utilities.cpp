#include "main.h"

#include <vector>
#include <numeric>  // for std::accumulate
#include <algorithm>
#include <deque>

using namespace ks;

double vector_average(const std::vector<double>& v) {
    return std::accumulate(v.begin(), v.end(), 0.0) / v.size();
}
double median_filter(std::deque<double>& buffer, double newVal, int windowSize) {
	buffer.push_back(newVal);
	if (buffer.size() > windowSize) {
	    buffer.pop_front();
	}

	std::vector<double> data(buffer.begin(), buffer.end());
	std::sort(data.begin(), data.end());

	return data[windowSize / 2];
}
// prolly dont use this 💀
double tripleIMUHeading(double heading1, double heading2, double heading3, double threshold) { 
	// Run through median filter
    int windowSize = 20;
	std::deque<double> buffer1;
	std::deque<double> buffer2;
	std::deque<double> buffer3;
	heading1 = ks::median_filter(buffer1, heading1, windowSize);
	heading2 = ks::median_filter(buffer2, heading2, windowSize);
	heading3 = ks::median_filter(buffer3, heading3, windowSize);
    // Calculate the absolute differences between the headings
    double diff12 = std::abs(heading1 - heading2);
    double diff23 = std::abs(heading2 - heading3);
    double diff13 = std::abs(heading1 - heading3);
    // Check if one of the sensors is drifting
    if (diff12 > threshold && diff13 > threshold) {
        // Sensor 1 is drifting, return mean of sensor 2 and 3
        return (heading2 + heading3) / 2.0;
    } else if (diff12 > threshold && diff23 > threshold) {
        // Sensor 2 is drifting, return mean of sensor 1 and 3
        return (heading1 + heading3) / 2.0;
    } else if (diff23 > threshold && diff13 > threshold) {
        // Sensor 3 is drifting, return mean of sensor 1 and 2
        return (heading1 + heading2) / 2.0;
    } else {
        // No sensor is drifting, return mean of all sensors 
		// (or all of them are drifing and we just gotta pray 💀)
        return (heading1 + heading2 + heading3) / 3.0;
    }
}
bool isDriverControl() {
	return pros::competition::is_connected() && !pros::competition::is_autonomous() && !pros::competition::is_disabled();
}
float reduce_0_to_360(float angle) {
  while(!(angle >= 0 && angle < 360)) {
    if( angle < 0 ) { angle += 360; }
    if(angle >= 360) { angle -= 360; }
  }
  return(angle);
}
float reduce_negative_180_to_180(float angle) {
  while(!(angle >= -180 && angle < 180)) {
    if( angle < -180 ) { angle += 360; }
    if(angle >= 180) { angle -= 360; }
  }
  return(angle);
}
float reduce_negative_90_to_90(float angle) {
  while(!(angle >= -90 && angle < 90)) {
    if( angle < -90 ) { angle += 180; }
    if(angle >= 90) { angle -= 180; }
  }
  return(angle);
}
double to_rad(double angle_deg){
  return(angle_deg/(180.0/M_PI));
}
double to_deg(double angle_rad){
  return(angle_rad*(180.0/M_PI));
}
float clamp(float input, float min, float max){
  if( input > max ){ return(max); }
  if(input < min){ return(min); }
  return(input);
}
bool isReversed(double input){
  if(input<0) return(true);
  return(false);
}
float to_milivolt(float input){
  return(input * (12000.0/127.0));
}
float deadband(float input, float width){
  if (fabs(input)<width){
    return(0);
  }
  return(input);
}

void calibrateIMU(pros::Imu inertial1, pros::Imu inertial2) {
    int attempt = 1;
    bool calibrated = false;
    // calibrate inertial, and if calibration fails, then repeat 5 times or until successful
    while (attempt <= 5) {
        inertial1.reset();
		    inertial2.reset();
        // wait until IMU is calibrated
        do pros::delay(10);
        while (inertial1.get_status() != pros::ImuStatus::error && inertial1.is_calibrating());
        while (inertial2.get_status() != pros::ImuStatus::error && inertial2.is_calibrating());
        // exit if imu has been calibrated
        if (!isnanf(inertial1.get_heading()) && !isinf(inertial1.get_heading()) && !isnanf(inertial2.get_heading()) && !isinf(inertial2.get_heading())) {
            calibrated = true;
            break;
        }
        // indicate error
        pros::c::controller_rumble(pros::E_CONTROLLER_MASTER, "---");
        console.printf("IMU failed to calibrate! Attempt #%d", attempt);
        attempt++;
    }
    // check if calibration attempts were successful
    if (attempt > 5) {
		console.println("IMU calibration failed, defaulting to tracking wheels / motor encoders");
    }
}