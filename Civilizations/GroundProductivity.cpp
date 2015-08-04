#include "stdafx.h"
#include "Weather.h"

void Weather::UpdateGroundProductivity()
{
	int w = Game::world->width;
	int h = Game::world->height;

	for (int y = 1; y < h - 1; ++y)
	{
		for (int x = 1; x < w - 1; ++x)
		{
			tmp[x + y * w] = (
				TILE(x - 1, y - 1)->productivity + TILE(x + 0, y - 1)->productivity + TILE(x + 1, y - 1)->productivity +
				TILE(x - 1, y + 0)->productivity + TILE(x + 0, y + 0)->productivity + TILE(x + 1, y + 0)->productivity +
				TILE(x - 1, y + 1)->productivity + TILE(x + 0, y + 1)->productivity + TILE(x + 1, y + 1)->productivity) / 9;
		}
	}

	for (int i = 0; i < w * h; ++i)
		TILEP(i)->productivity = EManager::IsFreshWaterTile(*SURFATP(i)) ? 100 : tmp[i] * PRODUCTIVITY_PENALTY * ETables::GetSurfProdMp(SURFATP(i)->type);
}
