class Integrals {

public:

	double trapezoidRule(double (*func)(double), double lower_bound,
			double upper_bound, double err_tol);

	double simpsonRule(double (*func)(double), double lower_bound,
			double upper_bound, double err_tol);

	double booleRule(double (*func)(double), double lower_bound,
			double upper_bound, double err_tol);

};

