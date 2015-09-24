#include "stdafx.h"
#include "World.h"

World::World()
{
	name = "New World";
	width = -1;
	height = -1;

	entities.clear();
	entities.resize(lay_end, EntityVector());

	CountFreeCells();
}

void World::CountFreeCells()
{
	for (auto it = entities.begin(); it != entities.end(); ++it)
		it->CountFreeCells();
}
