#include "math.h"
#include "Integrals.h"

double Integrals::simpsonRule(double (*func)(double), double lower_bound,
		double upper_bound, double err_tol) {

	/*
	 * Adaptive Trapezoid Method: High Performance Integration for Smooth Functions
	 *
	 * Input:
	 * 1. Function to Integrate
	 * 2. Lower Bound of Interval
	 * 3. Upper Bound of Interval
	 * 4. Desired Error Tolerance
	 *
	 * Output:
	 * 1. The Integral
	 */

	double midpoint = (upper_bound + lower_bound) / 2.0;
	double lower_midpoint = (lower_bound + midpoint) / 2.0;
	double upper_midpoint = (midpoint + upper_bound) / 2.0;
	double arr[5] = { func(lower_bound), func(lower_midpoint), func(midpoint),
			func(upper_midpoint), func(upper_bound) };

	double simpson = ((upper_bound - lower_bound) / 6.0)
			* (arr[0] + 4 * arr[2] + arr[4]);

	double lower_area = ((midpoint - lower_bound) / 6.0)
			* (arr[0] + 4 * arr[1] + arr[2]);
	double upper_area = ((upper_bound - midpoint) / 6.0)
			* (arr[2] + 4 * arr[3] + arr[4]);
	double area = lower_area + upper_area;

	double error = abs(simpson - area);

	if (error > err_tol) {

		lower_area = simpsonRule(func, lower_bound, midpoint, err_tol);
		upper_area = simpsonRule(func, midpoint, upper_bound, err_tol);
		area = lower_area + upper_area;

	}

	return area;

}
