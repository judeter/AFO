#include "TestFunctions.h"
#include <iostream>
#include <vector>
#include <string>


int test_rastrigin_minimum()
/* Test that the minimum of the rastrigin function is f(0)=0. */
{
	return (0.0 == rastrigin(0.0, 0.0)) ? 0 : 1;
}

int test_rastrigin_domain()
{
	std::vector<double> x{5.2, 0.0, -5.2, 0.0};
	std::vector<double> y{0.0, 5.2, 0.0, -5.2};
	for (int i=0; i < x.size(); i++){
		try {
			rastrigin(x[i], y[i]);
			return 1; //Test fails if this line is hit.
		} catch (const std::domain_error&) {}
	}
	return 0;
}


int main(void) 
{
	std::vector<int (*)()> tests;
	tests.push_back(&test_rastrigin_minimum); //Test 1.
	tests.push_back(&test_rastrigin_domain); //Test 2.

	int testCount = 0;
	int testResult = 0;
	for (auto test : tests) 
	{	
		testResult = test();
		testCount++;
		std::cout << "[ test " << std::to_string(testCount) << " ]";
		if (testResult != 0) { 
			std::cout << " FAIL" << std::endl;
		}
		else {
			std::cout << " PASS" << std::endl;
		}
	}
	return 0;
}