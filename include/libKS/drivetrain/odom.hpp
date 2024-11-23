#include "main.h"

namespace ks
{
	class Position{
        public:
            double x;
            double y;
            double theta;
    };

    extern Position odom_pos;

    extern void odomThread();
    extern void resetOdomPosition();
}