#include "main.h"

// ks::LateralPID pid;

double global_kp = 0;
double global_ki = 0;
double global_kd = 0;
double global_timeOut = 0;

void ks::LateralPID::set_lateral_constants(double kp, double ki, double kd, double timeOut) {
	global_kp = kp;
	global_ki = ki;
	global_kd = kd;	
	global_timeOut = timeOut;
}

void ks::LateralPID::move_lateral_pid(double target, double maxSpeed, double minSpeed) {
	double prevError = 0;
	double integral = 0;
	double derivative = 0;
	double power = 0;
	double currentTime = 0;

	double tolerance = 0;
	double local_timer = 0;

	while (true) {
		double distance_travelled = ((verticalEncoder.get_position()) * 2 * M_PI / 36000);
		//printf("%f\n", distance_travelled);
		double error = target - distance_travelled;
		integral = (integral + error);
		derivative = (error - prevError);

		power = (global_kp * error) + (global_ki * integral) + (global_kd * derivative);
		if (power * (12000.0 / 127) > maxSpeed * (12000.0 / 127)) {
			power = maxSpeed;
		} else if (power * (12000.0 / 127) < -maxSpeed * (12000.0 / 127)) {
			power = -maxSpeed;
		}

		if (power * (12000.0 / 127) < minSpeed * (12000.0 / 127)) {
			power = minSpeed;
		} else if (power * (12000.0 / 127) > -minSpeed * (12000.0 / 127)) {
			power = -minSpeed;
		}

		// printf("%f\n", power);
		leftDrive.move_voltage(to_milivolt(power));
		rightDrive.move_voltage(to_milivolt(power));

		if (local_timer > (global_timeOut * 100)) {
			leftDrive.move_voltage(0);
			rightDrive.move_voltage(0);
			return;
		}

		local_timer++;
		prevError = error;
		pros::delay(10);
	}
}
