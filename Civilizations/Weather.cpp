#include "stdafx.h"
#include "Weather.h"

#include "Game.h"

float *Weather::tmpf = nullptr;
short *Weather::tmps = nullptr;

float *Weather::heats = nullptr;


void Weather::Load()
{
	tmpf = new float[WWIDTH * WHEIGHT];
	tmps = new short[WWIDTH * WHEIGHT];
	ZeroMemory(tmpf, WWIDTH * WHEIGHT * sizeof(float));
	ZeroMemory(tmps, WWIDTH * WHEIGHT * sizeof(short));

	heats = new float[WHEIGHT];
	for (int i = 0; i < WHEIGHT; ++i)
		heats[i] = sinf((float)i / WHEIGHT * (float)M_PI) * TEMPERATURE_RANGE * (1 - TEMPERATURE_PENALTY);
}

void Weather::UnLoad()
{
	delete[] heats;

	delete[] tmpf;
	delete[] tmps;
}
