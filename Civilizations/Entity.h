#pragma once

#ifndef ENTITY_H
#define ENTITY_H

#include "EBlueprint.h"
#include "CBlueprint.h"


struct Entity
{
	int id;

	EntityType type;
	ClimateType climtype;

	inline EBlueprint &eblueprint() const { return EBlueprint::GetBlueprint(type); }
	inline CBlueprint &cblueprint() const { return CBlueprint::GetBlueprint(climtype); }

	EntityState state;

	int creationTime;

	inline bool operator == (const Entity &pEnt) { return (id == pEnt.id); }
	inline bool operator != (const Entity &pEnt) { return (id != pEnt.id); }
};

#endif // ENTITY_H
