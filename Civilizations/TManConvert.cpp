#include "stdafx.h"
#include "TManager.h"

void TManager::CheckTilesClimate()
{
	//for (Tile &tile : TILES)
	concurrency::parallel_for(0, (const int)(WHEIGHT), [] (const int &y)
	{
		for (int x = 0; x < (const int)(WWIDTH); ++x)
		{
			Tile tile = *(TILE(x, y));

			Entity *surf = SURF(tile.surfaceCell);

			if (EManager::IsWaterTile(*surf))
			{
				// Water

				if (tile.temperature < TEMPERATURE_BORDER_FREEZE)
				{
					if (EManager::IsFreshWaterTile(*surf))
						ConvertSurfaceToType(tile, surf_waterfreshfrozen);
					else if (EManager::IsLakeTile(*surf))
						ConvertSurfaceToType(tile, surf_lakefrozen);
					else
						ConvertSurfaceToType(tile, surf_ice);
				}
				else if (EManager::IsFreshWaterTile(*surf))
					ConvertSurfaceToType(tile, surf_waterfresh);
				else if (EManager::IsLakeTile(*surf))
					ConvertSurfaceToType(tile, surf_lake);
				else if (tile.height >= -DEEPWATER_DEPTH)
					ConvertSurfaceToType(tile, surf_water);
				else
					ConvertSurfaceToType(tile, surf_deepwater);
			}
			else if (tile.humidity > HUMIDITY_BORDER)
			{
				// Near water

				if (tile.temperature < TEMPERATURE_BORDER_FREEZE)
					ConvertSurfaceToType(tile, surf_snow);
				else if (tile.temperature < TEMPERATURE_BORDER_TUNDRA)
					ConvertSurfaceToType(tile, surf_tundra);
				else if (tile.temperature < TEMPERATURE_BORDER_SAVANNA)
					ConvertSurfaceToType(tile, surf_coast);
				else if (tile.temperature < TEMPERATURE_BORDER_TROPICS)
					ConvertSurfaceToType(tile, surf_coast);
				else if (tile.temperature < TEMPERATURE_BORDER_DESERT)
					ConvertSurfaceToType(tile, surf_tropics);
				else
					ConvertSurfaceToType(tile, surf_oasis);
			}
			else
			{
				// Dry

				if (tile.temperature < TEMPERATURE_BORDER_FREEZE)
					ConvertSurfaceToType(tile, surf_snow);
				else if (tile.temperature < TEMPERATURE_BORDER_TUNDRA)
					ConvertSurfaceToType(tile, surf_tundra);
				else if (tile.temperature < TEMPERATURE_BORDER_SAVANNA)
					ConvertSurfaceToType(tile, surf_grass);
				else if (tile.temperature < TEMPERATURE_BORDER_TROPICS)
					ConvertSurfaceToType(tile, surf_savanna);
				else if (tile.temperature < TEMPERATURE_BORDER_DESERT)
					ConvertSurfaceToType(tile, surf_tropics);
				else
					ConvertSurfaceToType(tile, surf_desert);
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
		surf->UpdateBlueprint();
	}
	else
	{
		if (EManager::IsEntityType(*surf, pType))
			return;

		if (RAND0NEQ0(3))
			return;

		surf->type = pType;
		surf->UpdateBlueprint();
	}
}
