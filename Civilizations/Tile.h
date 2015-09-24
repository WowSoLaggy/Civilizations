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
		cells.resize(lay_end, -1);
	}

	std::vector<int> cells;

	float humidity;
	float temperature;
	float height;
	float productivity;
	short aff;
};


#endif // TILE_H
