#include "iostream"
#include "chrono"
#include "omp.h"

#include "Integrals/Integrals.h"
#include "Functions/Functions.h"

using namespace std;
using namespace chrono;

void integrals() {

	// Define Parameters
	double lower = -6;
	double upper = 6;
	double err_tol = 1.0e-8;
	double area;

	// Initialize Object
	Integrals integrate;

	// Adaptive Trapezoid Method
	auto t_start = high_resolution_clock::now();
	area = integrate.trapezoidRule(&normalDistribution, lower, upper, err_tol);
	auto t_stop = high_resolution_clock::now();
	cout << "Trapezoid Method Approximate Area: " << area << endl;
	auto t_time = duration_cast<nanoseconds>(t_stop - t_start);
	cout << "Time in Nanoseconds: " << t_time.count() << endl;
	cout << "\n";

	// Adaptive Simpson Method
	auto s_start = high_resolution_clock::now();
	area = integrate.simpsonRule(&normalDistribution, lower, upper, err_tol);
	auto s_stop = high_resolution_clock::now();
	cout << "Simpson Method Approximate Area: " << area << endl;
	auto s_time = duration_cast<nanoseconds>(s_stop - s_start);
	cout << "Time in Nanoseconds: " << s_time.count() << endl;
	cout << "\n";

	// Adaptive Boole Method
	auto b_start = high_resolution_clock::now();
	area = integrate.booleRule(&normalDistribution, lower, upper, err_tol);
	auto b_stop = high_resolution_clock::now();
	cout << "Boole Method Approximate Area: " << area << endl;
	auto b_time = duration_cast<nanoseconds>(b_stop - b_start);
	cout << "Time in Nanoseconds: " << b_time.count() << endl;
	cout << "\n";

}

void derivatives() {

}

int main() {

	integrals();

	return 0;

}
