#include "stdafx.h"
#include "World.h"

World::World()
{
	name = "New World";
	width = -1;
	height = -1;

	CountFreeCells();
}

void World::CountFreeCells()
{
	for (auto entVector : entities)
		entVector.CountFreeCells();
}
