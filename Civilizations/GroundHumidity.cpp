#include "stdafx.h"
#include "Weather.h"

void Weather::UpdateGroundHumidity()
{
	for (int y = 1; y < WHEIGHT - 1; ++y)
	{
		for (int x = 1; x < WWIDTH - 1; ++x)
		{
			tmp[x + y * WWIDTH] = (
				TILE(x - 1, y - 1)->humidity + TILE(x + 0, y - 1)->humidity + TILE(x + 1, y - 1)->humidity +
				TILE(x - 1, y + 0)->humidity + TILE(x + 0, y + 0)->humidity + TILE(x + 1, y + 0)->humidity +
				TILE(x - 1, y + 1)->humidity + TILE(x + 0, y + 1)->humidity + TILE(x + 1, y + 1)->humidity) / 9;
		}
	}

	for (int i = 0; i < WWIDTH * WHEIGHT; ++i)
		TILEP(i)->humidity = EManager::IsWaterTile(*SURFATP(i)) ? 100 : tmp[i] * HUMIDITY_PENALTY;
}
