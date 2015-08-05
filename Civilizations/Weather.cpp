#include "stdafx.h"
#include "Weather.h"

#include "Game.h"

float *Weather::tmp = nullptr;
float *Weather::m_afforestation = nullptr;


void Weather::Load()
{
	tmp = new float[WWIDTH * WHEIGHT];

	int w = (WWIDTH + (AFFORESTATIONSTEP - (WWIDTH % AFFORESTATIONSTEP))) / AFFORESTATIONSTEP;
	int h = (WHEIGHT + (AFFORESTATIONSTEP - (WHEIGHT % AFFORESTATIONSTEP))) / AFFORESTATIONSTEP;

	m_afforestation = new float[w * h];
}

void Weather::UnLoad()
{
	delete[] tmp;
	delete[] m_afforestation;
}
