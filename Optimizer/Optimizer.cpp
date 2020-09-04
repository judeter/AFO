// Optimizer.cpp : Defines the functions for the static library.
//

#include "pch.h"
#include "framework.h"
#include <stdexcept>
#include <vector>

#include <random>

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
	Optimizer(double (*func)(double, double), domain domain, double tollerance, unsigned maxEvaluations);
	~Optimizer();
	virtual void optimize();
	// Getters
	double getTollerance() { return this->mTollerance; };
	unsigned getMaxIterations() { return this->mMaxEvaluations; };
	domain getDomain() { return this->mDomain; };
	point getCurrentOptimum() { return this->mOptimumPoints.back(); };

	//Setters
	void setTollerance(double newTollerance);
	void setMaxEvaluations(unsigned newMaxEvaluations) { this->mMaxEvaluations = newMaxEvaluations; };
	void setDomain(domain newDomain);
	
	//Others
	bool atMaxEvaluations() { return this->mEvaluatedPoints.size() > this->mMaxEvaluations; }
	bool converged();
	double evaluateTarget(double x, double y);

private:
	double (*mTargetFunc)(double, double);  // The target function to optimize.
	domain mDomain;  // Domain over which to find the optimum.
	double mTollerance;  // Convergence tolerance.
	unsigned mMaxEvaluations; 
	std::vector<point> mEvaluatedPoints;  // Contains all evaluated points. 
	std::vector<point> mOptimumPoints;
};

bool Optimizer::converged() 
{
	if (mOptimumPoints.size() < 2) // Not enough optimum points to determine convergence.
		return false;
	if ((mOptimumPoints.end()[-2].z - mOptimumPoints.end()[-1].z) < this->mTollerance)
		return true;
	else
		return false;
}

void Optimizer::setTollerance(double newTollerance) 
{
	if (newTollerance > 1E-12) 
	{ 
		this->mTollerance = newTollerance; 
	}
	else 
	{ 
		throw std::invalid_argument("Convergence tolerance must be greater than 1E-12."); 
	}
}

void Optimizer::setDomain(domain newDomain) 
{
	if ((newDomain.xMax > newDomain.xMin) & (newDomain.yMax > newDomain.yMin))
	{
		mDomain = newDomain;
	}
	else { throw std::invalid_argument("Domain is incorrect."); }
}

double Optimizer::evaluateTarget(double x, double y) 
{
	point newPoint{ x, y, this->mTargetFunc(x, y) };
	this->mEvaluatedPoints.push_back(newPoint);  // Always add any evaluated points.
	if (this->mOptimumPoints.back().z > newPoint.z) // Check if newest point is optimum.
	{ 
		this->mOptimumPoints.push_back(newPoint); 
	}
}

Optimizer::Optimizer(double (*func)(double, double), domain domain , double tollerance, unsigned maxEvaluations)
{
	mTargetFunc = func;
	setDomain(domain);
	setTollerance(tollerance);
	setMaxEvaluations(maxEvaluations);
}

Optimizer::~Optimizer()
{
}

class Dummy : public Optimizer {
public:
	Dummy(double (*func)(double, double), int randomSeed, domain domain, double tol, unsigned maxIterations);
	~Dummy();
	void optimize();
private:
	int mRandomSeed;
};

Dummy::Dummy(double (*func)(double, double), int randomSeed, domain domain, double tol, unsigned maxIterations) : 
			 Optimizer(func, domain, tol, maxIterations), mRandomSeed (randomSeed) {}

void Dummy::optimize() {
	std::default_random_engine genorator(mRandomSeed);
	std::uniform_real_distribution<double> xDistribution(getDomain().xMin, getDomain().xMax);
	std::uniform_real_distribution<double> yDistribution(getDomain().yMin, getDomain().yMax);
	while(!this->atMaxEvaluations() & !this->converged())
	{
		this->evaluateTarget(xDistribution(genorator), yDistribution(genorator));
	}
}