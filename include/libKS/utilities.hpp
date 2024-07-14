#pragma once
#include "main.h"
#include <deque>

namespace ks
{
    double vector_average(const std::vector<double>& v);
    double median_filter(std::deque<double>& buffer, double newVal, int windowSize);
    float to_milivolt(float input);
    bool isDriverControl();

    double to_rad(double angle_deg);
    double to_deg(double angle_rad);

    void calibrateIMU(pros::Imu inertial1, pros::Imu inertial2);
}