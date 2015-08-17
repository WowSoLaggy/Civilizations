#pragma once

#ifndef ENTITY_H
#define ENTITY_H

#include "EBlueprint.h"


struct Entity
{
	EBlueprint *blueprint;

	int id;
	EntityType type;
	EntityState state;

	int posX;
	int posY;

	int creationTime;

	inline void UpdateBlueprint() { blueprint = &EBlueprint::GetBlueprint(type); }

	inline bool operator == (const Entity &pEnt) { return (id == pEnt.id); }
	inline bool operator != (const Entity &pEnt) { return (id != pEnt.id); }
};

#endif // ENTITY_H
