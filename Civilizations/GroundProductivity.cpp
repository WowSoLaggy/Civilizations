#include "stdafx.h"
#include "Nature.h"

void Nature::UpdateGroundProductivity()
{
	for (int y = 1; y < WHEIGHT - 1; ++y)
	{
		for (int x = 1; x < WWIDTH - 1; ++x)
		{
			tmpf[x + y * WWIDTH] = (
				TILE(x - 1, y - 1)->productivity + TILE(x + 0, y - 1)->productivity + TILE(x + 1, y - 1)->productivity +
				TILE(x - 1, y + 0)->productivity + TILE(x + 0, y + 0)->productivity + TILE(x + 1, y + 0)->productivity +
				TILE(x - 1, y + 1)->productivity + TILE(x + 0, y + 1)->productivity + TILE(x + 1, y + 1)->productivity) / 9;
		}
	}

	for (int i = 0; i < WWIDTH * WHEIGHT; ++i)
		TILEP(i)->productivity = EManager::IsFreshWaterTile(*SURFATP(i)) ? 100 : tmpf[i] * SURFATP(i)->eblueprint().baseProdPen;
}
