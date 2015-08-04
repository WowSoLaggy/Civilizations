#pragma once

#ifndef ENTITY_H
#define ENTITY_H

#include "ETables.h"


struct Entity
{
	int id;
	EntityType type;
	int feats;			// Features

	int creationTime;

	int posX;
	int posY;

	int ti;				// Texture index

	inline bool operator == (const Entity &pEnt) { return (id == pEnt.id); }
	inline bool operator != (const Entity &pEnt) { return (id != pEnt.id); }
};

#endif // ENTITY_H
