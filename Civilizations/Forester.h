#pragma once

#ifndef FORESTER_H
#define FORESTER_H

#include "Game.h"
#include "Utils.h"


class Forester
{
public:

	static void UpdateTrees();
	static bool TryToPlant(EntityType pType, int pX, int pY);
	static void TryToReproduce(Entity &pTree, int pX, int pY);
};


#endif // FORESTER_H
