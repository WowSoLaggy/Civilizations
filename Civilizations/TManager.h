#pragma once

#ifndef TMANAGER_H
#define TMANAGER_H

#include "Utils.h"
#include "WorldConstants.h"
#include "Tile.h"
#include "EManager.h"


class TManager
{
public:

	static void CheckTilesClimate();

private:

	static void ConvertSurfaceToType(Tile &pTile, EntityType pType);
};

#endif // TMANAGER_H
