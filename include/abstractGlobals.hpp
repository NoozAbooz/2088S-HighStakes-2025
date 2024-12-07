#pragma once

// 3rd party libraries
#include "lemlib/api.hpp"
#include "gif-pros/gifclass.hpp"
#include "robodash/api.h"
#include "liblvgl/lvgl.h"

extern rd::Console console;
extern rd_view_t *gifview;
extern rd_view_t *allianceview;
extern rd::Selector gui_selector;
void rdconfig_init();

extern bool isCompetition;
extern std::string alliance;
extern std::string auton_name;
extern std::string field_status;

/* Functions */
// DT
void arcadeDrive();

void refreshIntake();
void refreshClamp();
void refreshDoinker();
void refreshWallstakes();
void resetWallstakes();

void initializeColourSort();

void driverSkillsMacro();