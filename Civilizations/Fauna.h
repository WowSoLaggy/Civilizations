#pragma once

#ifndef FAUNA_H
#define FAUNA_H


#include "Game.h"


class Fauna
{
public:

	static void CheckTile(int pX, int pY);

private:

	static bool TryToGrow(EntityType pType, int pX, int pY);
};


#endif // FAUNA_H
