#include "stdafx.h"
#include "Weather.h"

void Weather::UpdateAirTemperature()
{
	for (int y = 1; y < WHEIGHT - 1; ++y)
	{
		for (int x = 1; x < WWIDTH - 1; ++x)
		{
			tmp[x + y * WWIDTH] = (
				TILE(x - 1, y - 1)->temperature + TILE(x + 0, y - 1)->temperature + TILE(x + 1, y - 1)->temperature +
				TILE(x - 1, y + 0)->temperature + TILE(x + 0, y + 0)->temperature + TILE(x + 1, y + 0)->temperature +
				TILE(x - 1, y + 1)->temperature + TILE(x + 0, y + 1)->temperature + TILE(x + 1, y + 1)->temperature) / 9;

			tmp[x + y * WWIDTH] = (tmp[x + y * WWIDTH] - TEMPERATURE_MIN) * TEMPERATURE_PENALTY + TEMPERATURE_MIN;

			float heat = sinf((float)y / WHEIGHT * (float)M_PI) * TEMPERATURE_RANGE * (1 - TEMPERATURE_PENALTY);

			tmp[x + y * WWIDTH] = tmp[x + y * WWIDTH] + heat;
		}

		tmp[y * WWIDTH] = tmp[1 + y * WWIDTH];
		tmp[(WWIDTH - 1) + y * WWIDTH] = tmp[(WWIDTH - 2) + y * WWIDTH];
	}
	memcpy(tmp, tmp + WWIDTH, WWIDTH * sizeof(float));
	memcpy(tmp + (WHEIGHT - 1) * WWIDTH, tmp + (WHEIGHT - 2) * WWIDTH, WWIDTH * sizeof(float));

	for (int y = 0; y < WHEIGHT; ++y)
	{
		for (int x = 0; x < WWIDTH; ++x)
			TILE(x, y)->temperature = tmp[x + y * WWIDTH];
	}
}
