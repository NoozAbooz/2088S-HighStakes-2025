#pragma once

// 3rd party libraries
#include "lemlib/api.hpp"
#include "gif-pros/gifclass.hpp"
#include "robodash/api.h"

extern rd::Console console;
extern rd_view_t *gifview;
extern Gif gif;

/* Functions */
// DT
void arcadeDrive();

// Intake
void refreshIntake();

// Wings
void refreshClamp();