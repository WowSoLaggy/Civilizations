#pragma once

#ifndef WEATHER_H
#define WEATHER_H

#include "EManager.h"


class Nature
{
public:

	static void Load();
	static void UnLoad();

	static void UpdateGroundHumidity();
	static void UpdateAirTemperature();
	static void UpdateGroundProductivity();
	static void UpdateAfforestation();
	static void UpdateFaunation();

private:

	static float *tmpf;
	static short *tmps;

	static float *heats;
};

#endif // WEATHER_H
