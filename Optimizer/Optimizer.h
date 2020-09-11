#pragma once

#ifdef OPTLIBRARY_EXPORTS
#define OPTLIBRARY_API __declspec(dllexport)
#else
#define OPTLIBRARY_API __declspec(dllimport)
#endif

#include <vector>

namespace Optimizer 
{

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

	class Optimizer
	{
	public:
		Optimizer(double (*func)(double, double), domain domain, double tollerance, unsigned maxEvaluations);
		~Optimizer();
		virtual void optimize() = 0;
		// Getters
		double getTollerance() { return this->mTollerance; };
		unsigned getMaxIterations() { return this->mMaxEvaluations; };
		domain getDomain() { return this->mDomain; };
		point getCurrentOptimum() { return this->mOptimumPoints.back(); };
		std::vector<point>& getEvaluatedPoints() { return this->mEvaluatedPoints; }
		std::vector<point>& getOptimumPoints() { return this->mOptimumPoints; }

		//Setters
		void setTollerance(double newTollerance);
		void setMaxEvaluations(unsigned newMaxEvaluations) { this->mMaxEvaluations = newMaxEvaluations; };
		void setDomain(domain newDomain);

		//Optimizer Termination Control.
		bool atMaxEvaluations() { return this->mEvaluatedPoints.size() > this->mMaxEvaluations; }
		bool converged();

		// Others
		double evaluateTarget(double x, double y);

	private:
		double (*mTargetFunc)(double, double);  // The target function to optimize.
		domain mDomain;  // Domain over which to find the optimum.
		double mTollerance;  // Convergence tolerance.
		unsigned mMaxEvaluations;
		std::vector<point> mEvaluatedPoints;  // Contains all evaluated points. 
		std::vector<point> mOptimumPoints;
	};

	class Dummy : public Optimizer 
	{
	public:
		Dummy(double (*func)(double, double), int randomSeed, domain domain, double tol, unsigned maxIterations);
		~Dummy();
		void optimize() override;
	private:
		int mRandomSeed;
	};

}
