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


	assert(quad(4, 1, -5).roots == 2);

	assert(lerp(0, 0, 0) == 0);

	assert(distance({0, 0}, { 0,0 }) == 0);

	assert(INNER({ 0, 0, 0, }, { 0, 0, 0 }) == 0);

	assert(Point({0, 0, 1, 1, }, { 0, 2, 0 }) == 1);


	return 0;

}