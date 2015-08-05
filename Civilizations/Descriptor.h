#pragma once

#ifndef DESCRIPTOR_H
#define DESCRIPTOR_H

#include "Tile.h"
#include "Utils.h"
#include "WorldConstants.h"

class Descriptor
{
public:

	static void GetTileDescription(Tile &pTile, std::string &pDesc, int pX, int pY);
};


#endif // DESCRIPTOR_H
