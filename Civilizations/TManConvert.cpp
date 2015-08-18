#include "stdafx.h"
#include "TManager.h"

void TManager::CheckTilesClimate()
{
	for (int i = 0; i < WWIDTH * WHEIGHT; ++i)
	{
		Entity *surf = SURFATP(i);

		if (EManager::IsWaterTile(*surf))
		{
			// Water

			if (TILEP(i)->temperature < TEMPERATURE_BORDER_FREEZE)
			{
				if (EManager::IsFreshWaterTile(*surf))
					ConvertSurfaceToType(*TILEP(i), surf_waterfreshfrozen);
				else if (EManager::IsLakeTile(*surf))
					ConvertSurfaceToType(*TILEP(i), surf_lakefrozen);
				else
					ConvertSurfaceToType(*TILEP(i), surf_ice);
			}
			else if (EManager::IsFreshWaterTile(*surf))
				ConvertSurfaceToType(*TILEP(i), surf_waterfresh);
			else if (EManager::IsLakeTile(*surf))
				ConvertSurfaceToType(*TILEP(i), surf_lake);
			else if (TILEP(i)->height >= -DEEPWATER_DEPTH)
				ConvertSurfaceToType(*TILEP(i), surf_water);
			else
				ConvertSurfaceToType(*TILEP(i), surf_deepwater);
		}
		else if (TILEP(i)->humidity > HUMIDITY_BORDER)
		{
			// Near water

			if (TILEP(i)->temperature < TEMPERATURE_BORDER_FREEZE)
				ConvertSurfaceToType(*TILEP(i), surf_snow);
			else if (TILEP(i)->temperature < TEMPERATURE_BORDER_TUNDRA)
				ConvertSurfaceToType(*TILEP(i), surf_tundra);
			else if (TILEP(i)->temperature < TEMPERATURE_BORDER_SAVANNA)
				ConvertSurfaceToType(*TILEP(i), surf_coast);
			else if (TILEP(i)->temperature < TEMPERATURE_BORDER_TROPICS)
				ConvertSurfaceToType(*TILEP(i), surf_coast);
			else if (TILEP(i)->temperature < TEMPERATURE_BORDER_DESERT)
				ConvertSurfaceToType(*TILEP(i), surf_tropics);
			else
				ConvertSurfaceToType(*TILEP(i), surf_oasis);
		}
		else
		{
			// Dry

			if (TILEP(i)->temperature < TEMPERATURE_BORDER_FREEZE)
				ConvertSurfaceToType(*TILEP(i), surf_snow);
			else if (TILEP(i)->temperature < TEMPERATURE_BORDER_TUNDRA)
				ConvertSurfaceToType(*TILEP(i), surf_tundra);
			else if (TILEP(i)->temperature < TEMPERATURE_BORDER_SAVANNA)
				ConvertSurfaceToType(*TILEP(i), surf_grass);
			else if (TILEP(i)->temperature < TEMPERATURE_BORDER_TROPICS)
				ConvertSurfaceToType(*TILEP(i), surf_savanna);
			else if (TILEP(i)->temperature < TEMPERATURE_BORDER_DESERT)
				ConvertSurfaceToType(*TILEP(i), surf_tropics);
			else
				ConvertSurfaceToType(*TILEP(i), surf_desert);
		}
	}
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
