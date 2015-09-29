#pragma once

#ifndef EBLUEPRINT_H
#define EBLUEPRINT_H

#include "EntityTypes.h"
#include "Features.h"
#include "Utils.h"


class EBlueprint
{
public:

	EBlueprint();
	void Clear();

	EntityType type;

	// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-

	std::vector<unsigned char> tis;

	int feats;
	int mmColor;
	std::string description;

	std::vector<EntityType> nativeSurfs;
	std::vector<EntityType> nativeMnts;
	std::vector<EntityType> nativeHills;

	float baseProdPen;

	short affBase;
	short affMin;
	short affMax;
	short ageAdulthood;
	short ageOldness;
	short ageDecay;
	int chanceToGrow;
	int chanceToReproduce;

	short faunationBase;
	short faunationMin;
	short faunationMax;

	// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-

	static void InitBlueprints();
	static EBlueprint &GetBlueprint(EntityType pType) { return blueprints[pType]; }

private:

	static EBlueprint blueprints[type_end];
};


#endif // EBLUEPRINT_H
