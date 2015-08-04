#include "stdafx.h"
#include "Weather.h"

void Weather::UpdateGroundHumidity()
{
	int w = Game::world->width;
	int h = Game::world->height;

	for (int y = 1; y < h - 1; ++y)
	{
		for (int x = 1; x < w - 1; ++x)
		{
			tmp[x + y * w] = (
				TILE(x - 1, y - 1)->humidity + TILE(x + 0, y - 1)->humidity + TILE(x + 1, y - 1)->humidity +
				TILE(x - 1, y + 0)->humidity + TILE(x + 0, y + 0)->humidity + TILE(x + 1, y + 0)->humidity +
				TILE(x - 1, y + 1)->humidity + TILE(x + 0, y + 1)->humidity + TILE(x + 1, y + 1)->humidity) / 9;
		}
	}

	for (int i = 0; i < w * h; ++i)
		TILEP(i)->humidity = EManager::IsWaterTile(*SURFATP(i)) ? 100 : tmp[i] * HUMIDITY_PENALTY;
}
