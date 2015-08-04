#pragma once

#ifndef WORLDCREATOR_H
#define WORLDCREATOR_H

#include "World.h"
#include "EManager.h"


class WorldCreator
{
public:

	static void GenerateWorld(World &pWorld, int pSizeX, int pSizeY);
	static void DisposeWorld(World &pWorld);

private:

	static void CheckRiverTile(int pX, int pY, EntityType *pTiles, float *pHeights, int pW);
};


#endif // WORLDCREATOR_H
