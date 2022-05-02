#include "math.h"
#include "Integrals.h"

double Integrals::trapezoidRule(double (*func)(double), double lower_bound,
		double upper_bound, double err_tol) {

	/*
	 * Adaptive Trapezoid Method: High Performance Integration for Rigid Functions
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
	double arr[3] = { func(lower_bound), func(midpoint), func(upper_bound) };

	double trapezoid = (upper_bound - lower_bound) * 0.5 * (arr[0] + arr[2]);

	double lower_area = (midpoint - lower_bound) * 0.5 * (arr[0] + arr[1]);
	double upper_area = (upper_bound - midpoint) * 0.5 * (arr[1] + arr[2]);
	double area = lower_area + upper_area;

	double error = abs(trapezoid - area);

	if (error > err_tol) {

		lower_area = trapezoidRule(func, lower_bound, midpoint, err_tol);
		upper_area = trapezoidRule(func, midpoint, upper_bound, err_tol);
		area = lower_area + upper_area;

	}

	return area;

}
