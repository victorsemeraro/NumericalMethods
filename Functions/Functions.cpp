#include "math.h"

double normalDistribution(double x) {

	return (1 / sqrt(2 * M_PI)) * exp(-0.5 * pow(x, 2));

}
