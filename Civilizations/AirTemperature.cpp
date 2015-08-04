#include "stdafx.h"
#include "Weather.h"

void Weather::UpdateAirTemperature()
{
	int w = Game::world->width;
	int h = Game::world->height;

	for (int y = 1; y < h - 1; ++y)
	{
		for (int x = 1; x < w - 1; ++x)
		{
			tmp[x + y * w] = (
				TILE(x - 1, y - 1)->temperature + TILE(x + 0, y - 1)->temperature + TILE(x + 1, y - 1)->temperature +
				TILE(x - 1, y + 0)->temperature + TILE(x + 0, y + 0)->temperature + TILE(x + 1, y + 0)->temperature +
				TILE(x - 1, y + 1)->temperature + TILE(x + 0, y + 1)->temperature + TILE(x + 1, y + 1)->temperature) / 9;

			tmp[x + y * w] = (tmp[x + y * w] - TEMPERATURE_MIN) * TEMPERATURE_PENALTY + TEMPERATURE_MIN;

			float heat = sinf((float)y / h * (float)M_PI) * TEMPERATURE_RANGE * (1 - TEMPERATURE_PENALTY);

			tmp[x + y * w] = tmp[x + y * w] + heat;
		}

		tmp[y * w] = tmp[1 + y * w];
		tmp[(w - 1) + y * w] = tmp[(w - 2) + y * w];
	}
	memcpy(tmp, tmp + w, w * sizeof(float));
	memcpy(tmp + (h - 1) * w, tmp + (h - 2) * w, w * sizeof(float));

	for (int y = 0; y < h; ++y)
	{
		for (int x = 0; x < w; ++x)
			TILE(x, y)->temperature = tmp[x + y * w];
	}
}
