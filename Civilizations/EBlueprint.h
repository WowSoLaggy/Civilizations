#pragma once

#ifndef EBLUEPRINT_H
#define EBLUEPRINT_H

#include "EntityTypes.h"
#include "Features.h"


class EBlueprint
{
public:

	EBlueprint();
	void Clear();

	EntityType type;

	std::vector<unsigned char> tis;

	int feats;
	int mmColor;
	std::string description;

	std::vector<EntityType> nativeSurfs;
	std::vector<EntityType> nativeMnts;
	std::vector<EntityType> nativeTrees;
	std::vector<EntityType> nativeBushes;

	float baseProdPen;

	// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-

	static void InitBlueprints();
	static EBlueprint &GetBlueprint(EntityType pType) { return blueprints[pType]; }

private:

	static EBlueprint blueprints[type_end];
};


#endif // EBLUEPRINT_H
