#pragma once

#ifndef WORLD_H
#define WORLD_H


#include "Tile.h"
#include "EntityLayers.h"
#include "EntityVector.h"


class World
{
public:

	World();

	std::string name;

	int width;
	int height;

	std::vector<Tile> tiles;
	EntityVector entities[lay_end];

private:

	void CountFreeCells();
};


#endif // WORLD_H
