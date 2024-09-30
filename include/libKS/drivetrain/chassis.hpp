#pragma once
#include "main.h"

namespace ks {
    void moveRaw(int voltage, int time);
    double driveCurve(double input, double curve);
    void arcadeDrive(int linCurve, int rotCurve, double turnScale);
}