#include "../Optimizer/Optimizer.h"
#include "../Optimizer/Dummy.h"
#include "../TestFunctions/TestFunctions.h"

int main(void)
{
	domain domain{ -5.12, 5.12, -5.12, 5.12 };
	Dummy test_dummy(rastrigin, 12345, domain, 0.001, 20);
	return 0;
}