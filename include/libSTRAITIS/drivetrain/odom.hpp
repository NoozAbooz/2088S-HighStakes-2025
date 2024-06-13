#include "main.h"

namespace strait
{
	class Position{
        public:
            double x;
            double y;
            double theta;
    };

    extern Position odom_pos;

    void odomViewInit();
}