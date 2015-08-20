#include "stdafx.h"
#include "TManager.h"

void TManager::CheckTilesClimate()
{
	//for (Tile &tile : TILES)
	concurrency::parallel_for(0, (const int)(WHEIGHT), [] (const int &y)
	//for (int y = 0; y < WHEIGHT; ++y)
	{
		for (int x = 0; x < WWIDTH; ++x)
		{
			Tile &tile = *(TILE(x, y));
			Entity *surf = SURF(tile.surfaceCell);

			// Update surface climate
			if (tile.temperature < surf->cblueprint().minTemperatureInc)
				surf->climtype = surf->cblueprint().colderClimate;
			else if (tile.temperature >= surf->cblueprint().maxTemperatureExc)
				surf->climtype = surf->cblueprint().warmerClimate;

			if (EManager::IsWaterTile(*surf))
			{
				// Water
				if (EManager::IsLakeTile(*surf))
					ConvertSurfaceToType(tile, surf->cblueprint().waterLakeType);
				else if (EManager::IsFreshWaterTile(*surf))
					ConvertSurfaceToType(tile, surf->cblueprint().waterFreshType);
				else if (tile.height >= -DEEPWATER_DEPTH)
					ConvertSurfaceToType(tile, surf->cblueprint().waterType);
				else
					ConvertSurfaceToType(tile, surf->cblueprint().waterDeepType);
			}
			else if (tile.humidity > HUMIDITY_BORDER)
			{
				// Near water
				ConvertSurfaceToType(tile, surf->cblueprint().surfNearWater);
			}
			else
			{
				// Dry
				ConvertSurfaceToType(tile, surf->cblueprint().surfFarFromWater);
			}
		}
	});
}

void TManager::ConvertSurfaceToType(Tile &pTile, EntityType pType)
{
	Entity *surf = SURF(pTile.surfaceCell);

	if (EManager::IsMountain(*surf))
	{
		EntityType mntType = RANDVECT(EBlueprint::GetBlueprint(pType).nativeMnts);
		if (mntType == type_unknown)
			return;

		if (EManager::IsEntityType(*surf, mntType))
			return;

		if (RAND0NEQ0(3))
			return;

		surf->type = mntType;
	}
	if (EManager::IsHill(*surf))
	{
		EntityType hillType = RANDVECT(EBlueprint::GetBlueprint(pType).nativeHills);
		if (hillType == type_unknown)
			return;

		if (EManager::IsEntityType(*surf, hillType))
			return;

		if (RAND0NEQ0(3))
			return;

		surf->type = hillType;
	}
	else
	{
		if (EManager::IsEntityType(*surf, pType))
			return;

		if (RAND0NEQ0(3))
			return;

		surf->type = pType;
	}
}
