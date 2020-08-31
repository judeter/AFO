// Optimizer.cpp : Defines the functions for the static library.
//

#include "pch.h"
#include "framework.h"
#include <stdexcept>
#include <vector>

struct domain 
{
	double xMin = -1.0;
	double xMax = 1.0;
	double yMin = -1.0;
	double yMax = 1.0;
};

struct point
{
	double x;
	double y;
};

class Optimizer {
public:
	Optimizer(double (*func)(double, double), domain domain, point initial_guess);
	void setDomain(domain domain);
	virtual std::vector<point> stepOptimizer();
private:
	domain domain;
	unsigned maxIterations = 100;
	std::vector<point> evaluatedPoints;



};

void Optimizer::setDomain(domain domain)
{
	if (domain.xMax > domain.xMin && domain.xMax > domain.xMin)
	{
		domain = domain;
	}
	else { throw std::runtime_error("Domain is incorrect."); }
}