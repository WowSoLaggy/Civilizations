#include "stdafx.h"
#include "Nature.h"

#include "Game.h"

float *Nature::tmpf = nullptr;
short *Nature::tmps = nullptr;

float *Nature::heats = nullptr;


void Nature::Load()
{
	tmpf = new float[WWIDTH * WHEIGHT];
	tmps = new short[WWIDTH * WHEIGHT];
	ZeroMemory(tmpf, WWIDTH * WHEIGHT * sizeof(float));
	ZeroMemory(tmps, WWIDTH * WHEIGHT * sizeof(short));

	heats = new float[WHEIGHT];
	for (int i = 0; i < WHEIGHT; ++i)
		heats[i] = sinf((float)i / WHEIGHT * (float)M_PI) * TEMPERATURE_RANGE * (1 - TEMPERATURE_PENALTY);
}

void Nature::UnLoad()
{
	delete[] heats;

	delete[] tmpf;
	delete[] tmps;
}
