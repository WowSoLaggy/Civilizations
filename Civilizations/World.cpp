#include "stdafx.h"
#include "World.h"

World::World()
{
	name = "New World";
	width = -1;
	height = -1;

	entities = EntityMap({
		{ lay_surf, EntityVector() },
		{ lay_flora, EntityVector() }
	});

	CountFreeCells();
}

void World::CountFreeCells()
{
	for (EntityMap::iterator it = entities.begin(); it != entities.end(); ++it)
		it->second.CountFreeCells();
}
