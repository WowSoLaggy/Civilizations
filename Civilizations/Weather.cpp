#include "stdafx.h"
#include "Weather.h"

#include "Game.h"

int Weather::w3 = 0;
int Weather::h3 = 0;
float *Weather::tmp = nullptr;
float *Weather::afforestation = nullptr;


void Weather::Load()
{
	tmp = new float[WWIDTH * WHEIGHT];

	w3 = (WWIDTH + (AFFORESTATIONSTEP - (WWIDTH % AFFORESTATIONSTEP))) / AFFORESTATIONSTEP;
	h3 = (WHEIGHT + (AFFORESTATIONSTEP - (WHEIGHT % AFFORESTATIONSTEP))) / AFFORESTATIONSTEP;

	afforestation = new float[w3 * h3];
	ZeroMemory(afforestation, w3 * h3 * sizeof(float));
}

void Weather::UnLoad()
{
	delete[] tmp;
	delete[] afforestation;
}
