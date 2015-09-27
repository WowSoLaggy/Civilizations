#pragma once

#ifndef FLORA_H
#define FLORA_H


#include "Game.h"


class Flora
{
public:

	static void CheckTile(int pX, int pY);

private:

	static bool TryToPlant(EntityType pType, int pX, int pY);
	static bool TryToReproduce(Entity &pTree, int pX, int pY);
};


#endif // FLORA_H
