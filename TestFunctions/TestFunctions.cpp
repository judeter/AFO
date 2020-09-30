// TestFunctions.cpp : Defines the functions for the static library.
//


#include "TestFunctions.h"
#define _USE_MATH_DEFINES
#include <math.h>
#include <stdexcept>

double rastrigin(const double x, const double y)
{
	if ( abs(x) > 5.12 || abs(y) > 5.12){
		throw std::domain_error("Domain of the rastrign function is (-5.12, 5.12).");
	}
	double z = 10.0 * 2.0 + (x * x - 10.0 * cos(2.0 * M_PI * x)) + (y * y - 10.0 * cos(2.0 * M_PI * y));
	return z;
}

double ackley(const double x, const double y) 
{
	if (abs(x) > 5.12 || abs(y) > 5.12) {
		throw std::domain_error("Domain of the Ackley function is (-5.0, 5.0).");
	}
	double expTerm1 = -0.2 * sqrt(0.5 * (x * x + y * y));
	double expTerm2 = 0.5 * (cos(2.0 * M_PI * x) + cos(2.0 * M_PI * y));
	double z = -20.0 * exp(expTerm1) - exp(expTerm2) + M_E + 20;
	return z;
}
