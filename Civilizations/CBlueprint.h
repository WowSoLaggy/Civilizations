#pragma once

#ifndef CBLUEPRINT_H
#define CBLUEPRINT_H

#include "ClimateTypes.h"
#include "EntityTypes.h"


class CBlueprint
{
public:

	CBlueprint();
	void Clear();

	ClimateType type;

	// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-

	int minTemperatureInc;
	int maxTemperatureExc;

	ClimateType colderClimate;
	ClimateType warmerClimate;

	EntityType surfNearWater;
	EntityType surfFarFromWater;

	EntityType waterDeepType;
	EntityType waterType;
	EntityType waterFreshType;
	EntityType waterLakeType;

	std::vector<EntityType> nativeFlora;
	std::vector<EntityType> nativeFauna;

	// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-

	static void InitBlueprints();
	static CBlueprint &GetBlueprint(ClimateType pType) { return blueprints[pType]; }

private:

	static CBlueprint blueprints[clim_end];
};


#endif // CBLUEPRINT_H
