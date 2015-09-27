#include "stdafx.h"
#include "Nature.h"

void Nature::UpdateAirTemperature()
{
	for (int y = 1; y < WHEIGHT - 1; ++y)
	{
		for (int x = 1; x < WWIDTH - 1; ++x)
		{
			tmpf[x + y * WWIDTH] = (
				TILE(x - 1, y - 1)->temperature + TILE(x + 0, y - 1)->temperature + TILE(x + 1, y - 1)->temperature +
				TILE(x - 1, y + 0)->temperature + TILE(x + 0, y + 0)->temperature + TILE(x + 1, y + 0)->temperature +
				TILE(x - 1, y + 1)->temperature + TILE(x + 0, y + 1)->temperature + TILE(x + 1, y + 1)->temperature) / 9;

			tmpf[x + y * WWIDTH] = (tmpf[x + y * WWIDTH] - TEMPERATURE_MIN) * TEMPERATURE_PENALTY + TEMPERATURE_MIN;
			tmpf[x + y * WWIDTH] += heats[y];
		}

		tmpf[y * WWIDTH] = tmpf[1 + y * WWIDTH];
		tmpf[(WWIDTH - 1) + y * WWIDTH] = tmpf[(WWIDTH - 2) + y * WWIDTH];
	}
	memcpy(tmpf, tmpf + WWIDTH, WWIDTH * sizeof(float));
	memcpy(tmpf + (WHEIGHT - 1) * WWIDTH, tmpf + (WHEIGHT - 2) * WWIDTH, WWIDTH * sizeof(float));

	for (int i = 0; i < WWIDTH * WHEIGHT; ++i)
		TILEP(i)->temperature = tmpf[i];
}
