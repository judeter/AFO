#include "pch.h"
#include "gtest/gtest.h"
#include "../TestFunctions/TestFunctions.h"


namespace {

	TEST(TestTestFunctions, rastrigin) {
		EXPECT_EQ(0.0, rastrigin(0.0, 0.0));
	}

}