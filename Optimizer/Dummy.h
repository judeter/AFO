#pragma once

#include "Optimizer.h"

using namespace Optimizer;

class Dummy : public Optimizer {
public:
	Dummy(double (*func)(double, double), int randomSeed, domain domain, double tol, unsigned maxIterations);
	~Dummy();
	void optimize();
private:
	int mRandomSeed;
};