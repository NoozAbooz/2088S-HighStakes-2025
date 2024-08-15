#pragma once
#include "main.h"

namespace ks {
    double driveCurve(double input, double curve);
    void arcadeDrive(int linCurve, int rotCurve, double turnScale);
}