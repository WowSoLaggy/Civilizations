#include "stdafx.h"
#include "EManager.h"


bool EManager::IsEntityType(Entity &pEntity, EntityType pType)
{
	return (pEntity.type == pType);
}


// =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-


bool EManager::IsSurface(Entity &pEntity)
{
	return ((pEntity.eblueprint().feats & FEAT_OBJECT) != 0);
}

bool EManager::IsObject(Entity &pEntity)
{
	return ((pEntity.eblueprint().feats & FEAT_OBJECT) != 0);
}

bool EManager::IsWaterTile(Entity &pEntity)
{
	return ((pEntity.eblueprint().feats & FEAT_WATERTILE) != 0);
}

bool EManager::IsWaterTile(EntityType &pEntType)
{
	return ((EBlueprint::GetBlueprint(pEntType).feats & FEAT_WATERTILE) != 0);
}

bool EManager::IsTree(Entity &pEntity)
{
	return ((pEntity.eblueprint().feats & FEAT_TREE) != 0);
}

bool EManager::IsTree(EntityType &pEntType)
{
	return ((EBlueprint::GetBlueprint(pEntType).feats & FEAT_TREE) != 0);
}

bool EManager::IsBush(Entity &pEntity)
{
	return ((pEntity.eblueprint().feats & FEAT_BUSH) != 0);
}

bool EManager::IsBush(EntityType &pEntType)
{
	return ((EBlueprint::GetBlueprint(pEntType).feats & FEAT_BUSH) != 0);
}

bool EManager::IsFlora(Entity &pEntity)
{
	return ((pEntity.eblueprint().feats & FEAT_FLORA) != 0);
}

bool EManager::IsFitForTrees(Entity &pSurface)
{
	return ((pSurface.eblueprint().feats & FEAT_FITFORTREES) != 0);
}

bool EManager::IsMountain(Entity &pSurface)
{
	return ((pSurface.eblueprint().feats & FEAT_MOUNTAIN) != 0);
}

bool EManager::IsHill(Entity &pSurface)
{
	return ((pSurface.eblueprint().feats & FEAT_HILL) != 0);
}

bool EManager::IsFreshWaterTile(Entity &pSurface)
{
	return ((pSurface.eblueprint().feats & FEAT_FRESHWATER) != 0);
}

bool EManager::IsLakeTile(Entity &pSurface)
{
	return ((pSurface.eblueprint().feats & FEAT_LAKE) != 0);
}

bool EManager::IsNativeSurfForObj(EntityType pObjType, EntityType pSurfType)
{
	return (std::find(EBlueprint::GetBlueprint(pObjType).nativeSurfs.begin(), EBlueprint::GetBlueprint(pObjType).nativeSurfs.end(), pSurfType) != EBlueprint::GetBlueprint(pObjType).nativeSurfs.end());
}

// =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-


bool EManager::IsYoungTree(Entity &pEntity)
{
	return (pEntity.state == state_young);
}

bool EManager::IsAdultTree(Entity &pEntity)
{
	return (pEntity.state == state_adult);
}

bool EManager::IsDeadTree(Entity &pEntity)
{
	return (pEntity.state == state_dead);
}
