// TestFunctions.cpp : Defines the functions for the static library.
//


#include "TestFunctions.h"
#define _USE_MATH_DEFINES
#include <math.h>

double rastrigin(const double x, const double y)
{
	double z = 10.0 * 2.0 + (x * x - 10.0 * cos(2.0 * M_PI * x)) + (y * y - 10.0 * cos(2.0 * M_PI * y));
	return z;
}
