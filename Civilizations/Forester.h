#pragma once

#ifndef FORESTER_H
#define FORESTER_H

#include "Game.h"
#include "Utils.h"


class Forester
{
public:

	static void UpdateTrees();
	static void ReproduceTree(Entity &pTree);

	static void MakeTreeAdult(Entity &pTree);
	static void MakeTreeDead(Entity &pTree);
};


#endif // FORESTER_H
