#include <cassert>
#include <iostream>
#include "Test.h"
int main()
{
	assert(donothing(0) == 5);
	assert(donothing(-1) == 4);
	assert(donothing(1) == 8); 

	assert(test_quad(0) == -7);
	assert(test_quad(-1) == -8);
	assert(test_quad(1) == -4);

	return 0;

}