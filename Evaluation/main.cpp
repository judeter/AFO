#include "Optimizer.h"
#include "TestFunctions.h"
#include <iostream>
int main(void)
{
	Optimizer::domain domain{ -5.12, 5.12, -5.12, 5.12 };
	Optimizer::Dummy test_dummy(rastrigin, 12345, domain, 0.001, 50);
	test_dummy.optimize();
	std::cout << "Number of evaluated points: " << test_dummy.getEvaluatedPoints().size() << std::endl;
	for(auto pi : test_dummy.getOptimumPoints())
	{
		std::cout << " x: " << pi.x << " y: " << pi.y << " z: " << pi.z << std::endl;
	}

	return 0;
}