#include "math.h"
#include "Integrals.h"

double Integrals::booleRule(double (*func)(double), double lower_bound, double upper_bound,
		double err_tol) {

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
	double lower_lower_midpoint = (lower_bound + lower_midpoint) / 2.0;
	double lower_upper_midpoint = (midpoint + lower_midpoint) / 2.0;

	double upper_midpoint = (midpoint + upper_bound) / 2.0;
	double upper_upper_midpoint = (upper_bound + upper_midpoint) / 2.0;
	double upper_lower_midpoint = (midpoint + upper_midpoint) / 2.0;

	double arr[9] = { func(lower_bound), func(lower_lower_midpoint), func(
			lower_midpoint), func(lower_upper_midpoint), func(midpoint), func(
			upper_lower_midpoint), func(upper_midpoint), func(
			upper_upper_midpoint), func(upper_bound) };

	double boole =
			(upper_bound - lower_bound) / 90.0
					* (7 * arr[0] + 32 * arr[2] + 12 * arr[4] + 32 * arr[6]
							+ 7 * arr[8]);

	double lower_area =
			(midpoint - lower_bound) / 90.0
					* (7 * arr[0] + 32 * arr[1] + 12 * arr[2] + 32 * arr[3]
							+ 7 * arr[4]);
	double upper_area =
			(upper_bound - midpoint) / 90.0
					* (7 * arr[4] + 32 * arr[5] + 12 * arr[6] + 32 * arr[7]
							+ 7 * arr[8]);

	double area = lower_area + upper_area;

	double err = abs(boole - area);

	if (err > err_tol) {

		lower_area = booleRule(func, lower_bound, midpoint, err_tol);
		upper_area = booleRule(func, midpoint, upper_bound, err_tol);
		area = lower_area + upper_area;

	}

	return area;

}
