#include "stdafx.h"
#include "Weather.h"

void Weather::UpdateAirTemperature()
{
	for (int y = 1; y < WHEIGHT - 1; ++y)
	{
		float heat = sinf((float)y / WHEIGHT * (float)M_PI) * TEMPERATURE_RANGE * (1 - TEMPERATURE_PENALTY);

		for (int x = 1; x < WWIDTH - 1; ++x)
		{
			tmpf[x + y * WWIDTH] = (
				TILE(x - 1, y - 1)->temperature + TILE(x + 0, y - 1)->temperature + TILE(x + 1, y - 1)->temperature +
				TILE(x - 1, y + 0)->temperature + TILE(x + 0, y + 0)->temperature + TILE(x + 1, y + 0)->temperature +
				TILE(x - 1, y + 1)->temperature + TILE(x + 0, y + 1)->temperature + TILE(x + 1, y + 1)->temperature) / 9;

			tmpf[x + y * WWIDTH] = (tmpf[x + y * WWIDTH] - TEMPERATURE_MIN) * TEMPERATURE_PENALTY + TEMPERATURE_MIN;
			tmpf[x + y * WWIDTH] += heat;
		}

		tmpf[y * WWIDTH] = tmpf[1 + y * WWIDTH];
		tmpf[(WWIDTH - 1) + y * WWIDTH] = tmpf[(WWIDTH - 2) + y * WWIDTH];
	}
	memcpy(tmpf, tmpf + WWIDTH, WWIDTH * sizeof(float));
	memcpy(tmpf + (WHEIGHT - 1) * WWIDTH, tmpf + (WHEIGHT - 2) * WWIDTH, WWIDTH * sizeof(float));

	for (int i = 0; i < WWIDTH * WHEIGHT; ++i)
		TILEP(i)->temperature = tmpf[i];
}
