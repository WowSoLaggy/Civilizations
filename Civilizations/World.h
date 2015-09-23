#pragma once

#ifndef WORLD_H
#define WORLD_H


#include "Tile.h"
#include "EntityLayers.h"
#include "EntityVector.h"


typedef std::map<EntityLayer, EntityVector> EntityMap;


class World
{
public:

	World();

	std::string name;

	int width;
	int height;

	std::vector<Tile> tiles;

	EntityMap entities;

private:

	void CountFreeCells();
};


#endif // WORLD_H
