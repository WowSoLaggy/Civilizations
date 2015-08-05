#pragma once

#ifndef EMANAGER_H
#define EMANAGER_H

#include "RManager.h"
#include "WorldUpdater.h"
#include "Game.h"
#include "WorldConstants.h"
#include "Features.h"


class EManager
{
public:

	// General
	
	static void DeleteSurfaceAt(int pX, int pY);
	static void DeleteObjectAt(int pX, int pY);

	// Entities

	static Entity &CreateSurface(EntityType pType, int pX, int pY);
	static Entity &CreateObject(EntityType pType, int pX, int pY, EntityState pState);
	static void ConvertTreeToType(Entity &pTree, EntityType pType);

	// Features

	static void AddFeature(Entity &pEntity, int pFeature);
	static void RemoveFeature(Entity &pEntity, int pFeature);

	static bool IsEntityType(Entity &pEntity, EntityType pType);

	static bool IsSurface(Entity &pEntity);
	static bool IsObject(Entity &pEntity);
	static bool IsWaterTile(Entity &pEntity);
	static bool IsWaterTile(EntityType &pEntType);
	static bool IsTree(Entity &pEntity);
	static bool IsTree(EntityType &pEntType);
	static bool IsBush(Entity &pEntity);
	static bool IsBush(EntityType &pEntType);
	static bool IsFlora(Entity &pEntity);
	static bool IsFitForTrees(Entity &pSurface);
	static bool IsMountain(Entity &pSurface);
	static bool IsFreshWaterTile(Entity &pSurface);
	static bool IsLakeTile(Entity &pSurface);

	static bool IsSaplingTree(Entity &pEntity);
	static bool IsAdultTree(Entity &pEntity);
	static bool IsDeadTree(Entity &pEntity);

	static bool IsNativeSurface(Entity &pEntity, Entity &pSurface);

private:

	static int m_nextId;

	static void InitializeEntity(Entity &pEntity);
};

#endif // EMANAGER_H
