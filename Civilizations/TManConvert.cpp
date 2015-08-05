#include "stdafx.h"
#include "TManager.h"

void TManager::CheckTilesClimate()
{
	for (int y = 0; y < WHEIGHT; ++y)
	{
		for (int x = 0; x < WWIDTH; ++x)
		{
			Entity *surf = SURFAT(x, y);

			if (EManager::IsWaterTile(*surf))
			{
				// Water

				if (TILE(x, y)->temperature < TEMPERATURE_BORDER_FREEZE)
				{
					if (EManager::IsFreshWaterTile(*surf))
						ConvertSurfaceToType(*TILE(x, y), surf_waterfreshfrozen);
					else if (EManager::IsLakeTile(*surf))
						ConvertSurfaceToType(*TILE(x, y), surf_lakefrozen);
					else
						ConvertSurfaceToType(*TILE(x, y), surf_ice);
				}
				else if (EManager::IsFreshWaterTile(*surf))
					ConvertSurfaceToType(*TILE(x, y), surf_waterfresh);
				else if (EManager::IsLakeTile(*surf))
					ConvertSurfaceToType(*TILE(x, y), surf_lake);
				else if (TILE(x, y)->height >= -DEEPWATER_DEPTH)
					ConvertSurfaceToType(*TILE(x, y), surf_water);
				else
					ConvertSurfaceToType(*TILE(x, y), surf_deepwater);
			}
			else if (TILE(x, y)->humidity > HUMIDITY_BORDER)
			{
				// Near water

				if (TILE(x, y)->temperature < TEMPERATURE_BORDER_FREEZE)
					ConvertSurfaceToType(*TILE(x, y), surf_snow);
				else if (TILE(x, y)->temperature < TEMPERATURE_BORDER_TUNDRA)
					ConvertSurfaceToType(*TILE(x, y), surf_tundra);
				else if (TILE(x, y)->temperature < TEMPERATURE_BORDER_SAVANNA)
					ConvertSurfaceToType(*TILE(x, y), surf_coast);
				else if (TILE(x, y)->temperature < TEMPERATURE_BORDER_TROPICS)
					ConvertSurfaceToType(*TILE(x, y), surf_coast);
				else if (TILE(x, y)->temperature < TEMPERATURE_BORDER_DESERT)
					ConvertSurfaceToType(*TILE(x, y), surf_tropics);
				else
					ConvertSurfaceToType(*TILE(x, y), surf_oasis);
			}
			else
			{
				// Dry

				if (TILE(x, y)->temperature < TEMPERATURE_BORDER_FREEZE)
					ConvertSurfaceToType(*TILE(x, y), surf_snow);
				else if (TILE(x, y)->temperature < TEMPERATURE_BORDER_TUNDRA)
					ConvertSurfaceToType(*TILE(x, y), surf_tundra);
				else if (TILE(x, y)->temperature < TEMPERATURE_BORDER_SAVANNA)
					ConvertSurfaceToType(*TILE(x, y), surf_grass);
				else if (TILE(x, y)->temperature < TEMPERATURE_BORDER_TROPICS)
					ConvertSurfaceToType(*TILE(x, y), surf_savanna);
				else if (TILE(x, y)->temperature < TEMPERATURE_BORDER_DESERT)
					ConvertSurfaceToType(*TILE(x, y), surf_tropics);
				else
					ConvertSurfaceToType(*TILE(x, y), surf_desert);
			}
		}
	}
}

void TManager::ConvertSurfaceToType(Tile &pTile, EntityType pType)
{
	Entity *surf = SURF(pTile.surfaceCell);

	if (EManager::IsMountain(*surf))
	{
		EntityType mntType = ETables::GetMntForSurface(pType);

		if (EManager::IsEntityType(*surf, mntType))
			return;

		if (RAND(3, 0) != 0)
			return;

		surf->type = mntType;
		surf->ti = ETables::GetTiSurface(mntType);
	}
	else
	{
		if (EManager::IsEntityType(*surf, pType))
			return;

		if (RAND(3, 0) != 0)
			return;

		surf->type = pType;
		surf->ti = ETables::GetTiSurface(pType);
	}
}
