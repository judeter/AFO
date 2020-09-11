
#include "pch.h"
#include "framework.h"

#include "Optimizer.h"
#include <random>
#include <iostream>

namespace Optimizer
{

	Dummy::Dummy(double (*func)(double, double), int randomSeed, domain domain, double tol, unsigned maxIterations) :
		Optimizer(func, domain, tol, maxIterations), mRandomSeed(randomSeed) {}

	Dummy::~Dummy(){}

	void Dummy::optimize() {
		std::default_random_engine genorator(mRandomSeed);
		std::uniform_real_distribution<double> xDistribution(getDomain().xMin, getDomain().xMax);
		std::uniform_real_distribution<double> yDistribution(getDomain().yMin, getDomain().yMax);
		double x, y, z = 0.0;
		while (!this->atMaxEvaluations() & !this->converged())
		{
			x = xDistribution(genorator);
			y = yDistribution(genorator);
			z = this->evaluateTarget(xDistribution(genorator), yDistribution(genorator));
			//std::cout << " x: " << x << " y: " << y << " z: " << z << std::endl;
		}
	}

}

