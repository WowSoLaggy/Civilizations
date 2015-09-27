#pragma once

#ifndef TILE_H
#define TILE_H

#include "Entity.h"
#include "EntityLayers.h"


class Tile
{
public:

	Tile()
	{
		for (int i = 0; i < lay_end; ++i)
			cells[i] = -1;
	}

	int cells[lay_end];

	float humidity;
	float temperature;
	float height;
	float productivity;
	short aff;
	short faunaLand;
	short faunaWater;
};


#endif // TILE_H
