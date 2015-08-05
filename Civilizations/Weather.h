#pragma once

#ifndef WEATHER_H
#define WEATHER_H

#include "EManager.h"


class Weather
{
public:

	static int w3;
	static int h3;
	static float *afforestation;

	static void Load();
	static void UnLoad();

	static void UpdateGroundHumidity();
	static void UpdateAirTemperature();
	static void UpdateGroundProductivity();
	static void UpdateAfforestation();

private:

	static float *tmp;
};

#endif // WEATHER_H
