#define BOOST_TEST_MODULE Test_TestFunctions

#include "boost/test/included/unit_test.hpp"
#include "TestFunctions.h"

BOOST_AUTO_TEST_CASE(rastrigin_minimum)
/* Test that the minimum of the rastrigin function is f(0)=0. */
{
	BOOST_CHECK_EQUAL(0.0, rastrigin(0.0, 0.0));
}

