#include "RandomNumberGenerator.h"

float RandomNumberGenerator::RandomFloat(float min, float max)
{
	float r = (float)std::rand() / (float)RAND_MAX;
	return min + r * (max - min);
}