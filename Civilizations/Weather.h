#pragma once

#ifndef WEATHER_H
#define WEATHER_H

#include "EManager.h"


class Weather
{
public:

	static void Load();
	static void UnLoad();

	static void UpdateGroundHumidity();
	static void UpdateAirTemperature();
	static void UpdateGroundProductivity();

private:

	static float *tmp;
};

#endif // WEATHER_H
