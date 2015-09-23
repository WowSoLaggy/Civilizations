#pragma once

#ifndef TILE_H
#define TILE_H

#include "Entity.h"


class Tile
{
public:

	Tile() { surfaceCell = -1; floraCell = -1; }

	int surfaceCell;
	int floraCell;

	float humidity;
	float temperature;
	float height;
	float productivity;
	short aff;
};


#endif // TILE_H
