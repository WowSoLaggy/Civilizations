#include "stdafx.h"
#include "Nature.h"

void Nature::UpdateFaunation()
{
	// Land

	for (int y = 1; y < WHEIGHT - 1; ++y)
	{
		for (int x = 1; x < WWIDTH - 1; ++x)
		{
			tmps[x + y * WWIDTH] = (
				TILE(x - 1, y - 1)->faunaLand + TILE(x + 0, y - 1)->faunaLand + TILE(x + 1, y - 1)->faunaLand +
				TILE(x - 1, y + 0)->faunaLand + TILE(x + 0, y + 0)->faunaLand + TILE(x + 1, y + 0)->faunaLand +
				TILE(x - 1, y + 1)->faunaLand + TILE(x + 0, y + 1)->faunaLand + TILE(x + 1, y + 1)->faunaLand) / 9;
		}
	}

	for (int i = 0; i < WWIDTH * WHEIGHT; ++i)
	{
		if (EManager::IsWaterTile(*SURFATP(i)))
			TILEP(i)->faunaLand = 0;
		else if (FAUNAATP(i) != nullptr)
			TILEP(i)->faunaLand = FAUNAATP(i)->eblueprint().faunationBase;
		else
			TILEP(i)->faunaLand = (short)(tmps[i] * FAUNATION_PENALTY);
	}

	// Water

	for (int y = 1; y < WHEIGHT - 1; ++y)
	{
		for (int x = 1; x < WWIDTH - 1; ++x)
		{
			tmps[x + y * WWIDTH] = (
				TILE(x - 1, y - 1)->faunaWater + TILE(x + 0, y - 1)->faunaWater + TILE(x + 1, y - 1)->faunaWater +
				TILE(x - 1, y + 0)->faunaWater + TILE(x + 0, y + 0)->faunaWater + TILE(x + 1, y + 0)->faunaWater +
				TILE(x - 1, y + 1)->faunaWater + TILE(x + 0, y + 1)->faunaWater + TILE(x + 1, y + 1)->faunaWater) / 9;
		}
	}

	for (int i = 0; i < WWIDTH * WHEIGHT; ++i)
	{
		if (!EManager::IsWaterTile(*SURFATP(i)))
			TILEP(i)->faunaWater = 0;
		else if (FAUNAATP(i) != nullptr)
			TILEP(i)->faunaWater = FAUNAATP(i)->eblueprint().faunationBase;
		else
			TILEP(i)->faunaWater = (short)(tmps[i] * FAUNATION_PENALTY);
	}
}
