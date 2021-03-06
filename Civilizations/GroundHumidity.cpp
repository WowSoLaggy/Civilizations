#include "stdafx.h"
#include "Nature.h"

void Nature::UpdateGroundHumidity()
{
	for (int y = 1; y < WHEIGHT - 1; ++y)
	{
		for (int x = 1; x < WWIDTH - 1; ++x)
		{
			tmpf[x + y * WWIDTH] = (
				TILE(x - 1, y - 1)->humidity + TILE(x + 0, y - 1)->humidity + TILE(x + 1, y - 1)->humidity +
				TILE(x - 1, y + 0)->humidity + TILE(x + 0, y + 0)->humidity + TILE(x + 1, y + 0)->humidity +
				TILE(x - 1, y + 1)->humidity + TILE(x + 0, y + 1)->humidity + TILE(x + 1, y + 1)->humidity) / 9;
		}
	}

	for (int i = 0; i < WWIDTH * WHEIGHT; ++i)
		TILEP(i)->humidity = EManager::IsWaterTile(*SURFATP(i)) ? 100 : tmpf[i] * HUMIDITY_PENALTY;
}
