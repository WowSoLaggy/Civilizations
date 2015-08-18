#include "stdafx.h"
#include "Weather.h"

#include "Game.h"

float *Weather::tmpf = nullptr;
short *Weather::tmps = nullptr;


void Weather::Load()
{
	tmpf = new float[WWIDTH * WHEIGHT];
	tmps = new short[WWIDTH * WHEIGHT];

	ZeroMemory(tmpf, WWIDTH * WHEIGHT * sizeof(float));
	ZeroMemory(tmps, WWIDTH * WHEIGHT * sizeof(short));
}

void Weather::UnLoad()
{
	delete[] tmpf;
	delete[] tmps;
}
