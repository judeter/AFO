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
	double z;
};

class Optimizer {
public:
	Optimizer(double (*func)(double, double), domain domain, point initial_guess, double tol);
	~Optimizer();
	void setDomain(const domain domainIn);  // Check that the input domain is valid.
	void runOptimizer();  // Step the optimizer untill tol or max iteration condition is meet.
	virtual std::vector<point> stepOptimizer();  // Run a single step of the optimizer.
	bool checkDomain(std::vector<point>& proposedPoints);  // Check that proposed points fall withing the domain.
	bool checkDomain(point point);
	void evaluatePoints(std::vector<point>& proposedPoints);  // Evalueate proposed points.
	
	void updatePoints(std::vector<point>& proposedPoints);  // Update the mEvaluated and mOptimum.
private:
	double (*mTargetFunc)(double, double);  // The target function to optimize.
	domain mDomain;  // Domain over which to find the optimum.
	double mTol;  // Convergance tollerance.
	unsigned mMaxIterations = 100; 
	std::vector<point> mEvaluatedPoints;  // Contains all evaluated points. 
	std::vector<point> mOptimumPoints;  // Contains the optimum point at each step.		
};

Optimizer::Optimizer(double(*func)(double, double), domain domain, point initial_guess, double tol)
{
	mTargetFunc = func;
	setDomain(domain);
	if (checkDomain(initial_guess))
	{

	}
}

Optimizer::~Optimizer()
{
}

void Optimizer::setDomain(const domain domainIn)
{
	if (domainIn.xMax > domainIn.xMin && domainIn.xMax > domainIn.xMin)
	{
		mDomain = domainIn;
	}
	else 
	{ 
		throw std::runtime_error("Domain is incorrect."); 
	}
}

void Optimizer::evaluatePoints(std::vector<point>& proposedPoints)
{
	for (auto& pt : proposedPoints) 
	{
		pt.z = mTargetFunc(pt.x, pt.y);
	}
}

/*
	The optimization process is done here. While either the tollerance condition or the max
	iterations not complete the optimizer is steped, points are evaluated and the status of 
	the optimization is updated.
*/
void Optimizer::runOptimizer()
{
	unsigned iterCount = 0;
	double currTol = mTol * 10;
	while (iterCount < mMaxIterations )
	{
		std::vector<point> proposedPoints = stepOptimizer();
		if( checkDomain(proposedPoints) )
		{
			evaluatePoints(proposedPoints);
			updatePoints(proposedPoints);
		}else{
			throw std::runtime_error("Domain is incorrect.");
		}
	}
}