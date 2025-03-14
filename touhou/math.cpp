#include"math.h"

bool compleDistance(float distance, float center_x, float center_y, float comple_x, float comple_y) {
	float dis = sqrt(pow(center_x - comple_x, 2) + pow(center_y - comple_y, 2));
	if (dis > distance) {
		return false;
	}
	else {
		return true;
	}
	return false;
}
