#include "stdafx.h"
#include "World.h"

World::World()
{
	name = "New World";
	width = -1;
	height = -1;

	entities.clear();

	for (int i = 0; i != (int)lay_end; ++i)
		entities.insert({ (EntityLayer)i, EntityVector() });

	CountFreeCells();
}

void World::CountFreeCells()
{
	for (EntityMap::iterator it = entities.begin(); it != entities.end(); ++it)
		it->second.CountFreeCells();
}
