// Optimizer.cpp : Defines the functions for the static library.
//

#include "pch.h"
#include "framework.h"

#include "Optimizer.h"
#include <stdexcept>

namespace Optimizer
{

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
		if (this->mOptimumPoints.empty())
		{
			this->mOptimumPoints.push_back(newPoint);
		}
		else if (this->mOptimumPoints.back().z > newPoint.z) // Check if newest point is optimum.
		{
			this->mOptimumPoints.push_back(newPoint);
		}
		return newPoint.z;
	}

	Optimizer::Optimizer(double (*func)(double, double), domain domain, double tollerance, unsigned maxEvaluations)
	{
		mTargetFunc = func;
		setDomain(domain);
		setTollerance(tollerance);
		setMaxEvaluations(maxEvaluations);
	}

	Optimizer::~Optimizer()
	{
	}

}




