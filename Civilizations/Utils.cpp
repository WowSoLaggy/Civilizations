#include "stdafx.h"
#include "Utils.h"

static unsigned long x = 123456789;
static unsigned long y = 362436069;
static unsigned long z = 521288629;

void initRand()
{
	srand((unsigned int)time(0));
	x = rand() % 200000000;
	y = rand() % 200000000 + 200000000;
	z = rand() % 200000000 + 400000000;
}

unsigned long xorshf96()
{
	unsigned long t;

	x ^= x << 16;
	x ^= x >> 5;
	x ^= x << 1;

	t = x;
	x = y;
	y = z;

	z = t ^ x ^ y;

	return z;
}
