#include "stdafx.h"
#include "EManager.h"

void EManager::AddFeature(Entity &pEntity, int pFeature)
{
	pEntity.feats |= pFeature;
}

void EManager::RemoveFeature(Entity &pEntity, int pFeature)
{
	pEntity.feats &= ~pFeature;
}


// =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-


bool EManager::IsEntityType(Entity &pEntity, EntityType pType)
{
	return (pEntity.type == pType);
}


// =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-


bool EManager::IsSurface(Entity &pEntity)
{
	return ((pEntity.feats & FEAT_OBJECT) != 0);
}

bool EManager::IsObject(Entity &pEntity)
{
	return ((pEntity.feats & FEAT_OBJECT) != 0);
}

bool EManager::IsWaterTile(Entity &pEntity)
{
	return ((pEntity.feats & FEAT_WATERTILE) != 0);
}

bool EManager::IsWaterTile(EntityType &pEntType)
{
	return ((ETables::GetFeatsSurface(pEntType) & FEAT_WATERTILE) != 0);
}

bool EManager::IsTree(Entity &pEntity)
{
	return ((pEntity.feats & FEAT_TREE) != 0);
}

bool EManager::IsTree(EntityType &pEntType)
{
	return ((ETables::GetFeatsObject(pEntType) & FEAT_TREE) != 0);
}

bool EManager::IsBush(Entity &pEntity)
{
	return ((pEntity.feats & FEAT_BUSH) != 0);
}

bool EManager::IsBush(EntityType &pEntType)
{
	return ((ETables::GetFeatsObject(pEntType) & FEAT_BUSH) != 0);
}

bool EManager::IsFlora(Entity &pEntity)
{
	return ((IsTree(pEntity)) || (IsBush(pEntity)));
}

bool EManager::IsFitForTrees(Entity &pSurface)
{
	return ((pSurface.feats & FEAT_FITFORTREES) != 0);
}

bool EManager::IsMountain(Entity &pSurface)
{
	return ((pSurface.feats & FEAT_MOUNTAIN) != 0);
}

bool EManager::IsFreshWaterTile(Entity &pSurface)
{
	return ((pSurface.feats & FEAT_FRESHWATER) != 0);
}

bool EManager::IsLakeTile(Entity &pSurface)
{
	return ((pSurface.feats & FEAT_LAKE) != 0);
}

// =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-


bool EManager::IsSaplingTree(Entity &pEntity)
{
	return ((IsTree(pEntity)) && (AGE(pEntity) < TREE_ADULTAGE));
}

bool EManager::IsAdultTree(Entity &pEntity)
{
	return ((IsTree(pEntity)) && (AGE(pEntity) >= TREE_ADULTAGE) && (AGE(pEntity) < TREE_DIEAGE));
}

bool EManager::IsDeadTree(Entity &pEntity)
{
	return ((IsTree(pEntity)) && (AGE(pEntity) >= TREE_DIEAGE));
}


// =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-


bool EManager::IsNativeSurface(Entity &pEntity, Entity &pSurface)
{
	return (
			((pSurface.type == surf_grass) && (pEntity.type == obj_oak)) ||
			((pSurface.type == surf_snow) && (pEntity.type == obj_fir)) ||
			((pSurface.type == surf_desert) && (pEntity.type == obj_cactus)) ||
			((pSurface.type == surf_coast) && (pEntity.type == obj_palm)) ||
			((pSurface.type == surf_oasis) && (pEntity.type == obj_palm)) ||
			((pSurface.type == surf_tundra) && (pEntity.type == obj_juniper)) ||
			((pSurface.type == surf_savanna) && (pEntity.type == obj_baobab)) ||
			((pSurface.type == surf_tropics) && (pEntity.type == obj_palm))
			);
}
