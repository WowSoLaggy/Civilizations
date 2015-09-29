#include "stdafx.h"
#include "CBlueprint.h"

CBlueprint CBlueprint::blueprints[clim_end];


CBlueprint::CBlueprint()
{
	Clear();
}

void CBlueprint::Clear()
{
	type = clim_unknown;

	minTemperatureInc = 0;
	maxTemperatureExc = 0;
	colderClimate = clim_unknown;
	warmerClimate = clim_unknown;
	surfNearWater = surf_unknown;
	surfFarFromWater = surf_unknown;
	waterDeepType = surf_unknown;
	waterType = surf_unknown;
	waterFreshType = surf_unknown;
	waterLakeType = surf_unknown;
	nativeTrees.clear();
	nativeBushes.clear();
	nativeFauna.clear();
}

void CBlueprint::InitBlueprints()
{
	CBlueprint bp;

	// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-

	bp.type = clim_glacier;
	bp.minTemperatureInc = -std::numeric_limits<int>::max();
	bp.maxTemperatureExc = -20;
	bp.colderClimate = clim_unknown;
	bp.warmerClimate = clim_permafrost;
	bp.surfNearWater = surf_snow;
	bp.surfFarFromWater = surf_snow;
	bp.waterDeepType = surf_ice;
	bp.waterType = surf_ice;
	bp.waterFreshType = surf_waterfreshfrozen;
	bp.waterLakeType = surf_lakefrozen;
	bp.nativeTrees = {};
	bp.nativeBushes = {};
	bp.nativeFauna = {};
	blueprints[bp.type] = bp;

	// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-

	bp.type = clim_permafrost;
	bp.minTemperatureInc = -20;
	bp.maxTemperatureExc = 0;
	bp.colderClimate = clim_glacier;
	bp.warmerClimate = clim_tundra;
	bp.surfNearWater = surf_snow;
	bp.surfFarFromWater = surf_snow;
	bp.waterDeepType = surf_deepwater;
	bp.waterType = surf_ice;
	bp.waterFreshType = surf_waterfreshfrozen;
	bp.waterLakeType = surf_lakefrozen;
	bp.nativeTrees = { obj_fir };
	bp.nativeBushes = {};
	bp.nativeFauna = { obj_fish, obj_whale, obj_bear_polar, obj_pinguin, obj_seal };
	blueprints[bp.type] = bp;

	// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-

	bp.type = clim_tundra;
	bp.minTemperatureInc = 0;
	bp.maxTemperatureExc = 7;
	bp.colderClimate = clim_permafrost;
	bp.warmerClimate = clim_temperate;
	bp.surfNearWater = surf_tundra;
	bp.surfFarFromWater = surf_tundra;
	bp.waterDeepType = surf_deepwater;
	bp.waterType = surf_water;
	bp.waterFreshType = surf_waterfresh;
	bp.waterLakeType = surf_lake;
	bp.nativeTrees = { obj_juniper };
	bp.nativeBushes = { obj_dwarfbirch };
	bp.nativeFauna = { obj_hare, obj_fox,  obj_fish, obj_whale, obj_deer };
	blueprints[bp.type] = bp;

	// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-

	bp.type = clim_temperate;
	bp.minTemperatureInc = 7;
	bp.maxTemperatureExc = 26;
	bp.colderClimate = clim_tundra;
	bp.warmerClimate = clim_savanna;
	bp.surfNearWater = surf_coast;
	bp.surfFarFromWater = surf_grass;
	bp.waterDeepType = surf_deepwater;
	bp.waterType = surf_water;
	bp.waterFreshType = surf_waterfresh;
	bp.waterLakeType = surf_lake;
	bp.nativeTrees = { obj_oak };
	bp.nativeBushes = { obj_raspberry };
	bp.nativeFauna = { obj_hare, obj_fox,  obj_fish, obj_horse, obj_whale, obj_bear };
	blueprints[bp.type] = bp;

	// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-

	bp.type = clim_savanna;
	bp.minTemperatureInc = 26;
	bp.maxTemperatureExc = 36;
	bp.colderClimate = clim_temperate;
	bp.warmerClimate = clim_tropics;
	bp.surfNearWater = surf_coast;
	bp.surfFarFromWater = surf_savanna;
	bp.waterDeepType = surf_deepwater;
	bp.waterType = surf_water;
	bp.waterFreshType = surf_waterfresh;
	bp.waterLakeType = surf_lake;
	bp.nativeTrees = { obj_baobab, obj_acacia, obj_oak };
	bp.nativeBushes = { obj_aloe, obj_raspberry };
	bp.nativeFauna = { obj_monkey,  obj_fish, obj_crocodile, obj_whale };
	blueprints[bp.type] = bp;

	// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-

	bp.type = clim_tropics;
	bp.minTemperatureInc = 36;
	bp.maxTemperatureExc = 46;
	bp.colderClimate = clim_savanna;
	bp.warmerClimate = clim_desert;
	bp.surfNearWater = surf_tropics;
	bp.surfFarFromWater = surf_tropics;
	bp.waterDeepType = surf_deepwater;
	bp.waterType = surf_water;
	bp.waterFreshType = surf_waterfresh;
	bp.waterLakeType = surf_lake;
	bp.nativeTrees = { obj_palm };
	bp.nativeBushes = { obj_fern };
	bp.nativeFauna = { obj_monkey, obj_fish, obj_crocodile, obj_whale };
	blueprints[bp.type] = bp;

	// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-

	bp.type = clim_desert;
	bp.minTemperatureInc = 46;
	bp.maxTemperatureExc = std::numeric_limits<int>::max();
	bp.colderClimate = clim_tropics;
	bp.warmerClimate = clim_unknown;
	bp.surfNearWater = surf_oasis;
	bp.surfFarFromWater = surf_desert;
	bp.waterDeepType = surf_deepwater;
	bp.waterType = surf_water;
	bp.waterFreshType = surf_waterfresh;
	bp.waterLakeType = surf_lake;
	bp.nativeTrees = { obj_palm, obj_cactus };
	bp.nativeBushes = { obj_fern, obj_camelthorn };
	bp.nativeFauna = { obj_fish, obj_crocodile, obj_whale };
	blueprints[bp.type] = bp;
}
