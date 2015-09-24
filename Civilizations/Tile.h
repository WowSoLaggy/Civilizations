#pragma once

#ifndef TILE_H
#define TILE_H

#include "Entity.h"
#include "EntityLayers.h"


typedef std::map<EntityLayer, int> CellMap;


class Tile
{
public:

	Tile()
	{
		for (int i = 0; i != (int)lay_end; ++i)
			cells.insert( { (EntityLayer)i, -1 } );
	}

	CellMap cells;

	float humidity;
	float temperature;
	float height;
	float productivity;
	short aff;
};


#endif // TILE_H
