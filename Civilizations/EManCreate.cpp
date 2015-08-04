#include "stdafx.h"
#include "EManager.h"

int EManager::m_nextId = 1;


// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
// General
// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=

void EManager::InitializeEntity(Entity &pEntity)
{
	pEntity.id = m_nextId++;
	pEntity.ti = 0;
	pEntity.type = type_unknown;
	pEntity.feats = 0x00000000;

	pEntity.creationTime = WorldUpdater::currentTurn;
}

Entity &EManager::CreateObject(int pX, int pY)
{
	int cell;
	Entity *ent = Game::world->GetFreeObjectCell(cell);

	InitializeEntity(*ent);
	TILE(pX, pY)->objectCell = cell;
	ent->posX = pX;
	ent->posY = pY;

	AddFeature(*ent, FEAT_OBJECT);

	return *ent;
}

void EManager::DeleteSurfaceAt(int pX, int pY)
{
	Game::world->DeleteSurface(TILE(pX, pY)->surfaceCell);
	TILE(pX, pY)->surfaceCell = -1;
}

void EManager::DeleteObjectAt(int pX, int pY)
{
	Game::world->DeleteObject(TILE(pX, pY)->objectCell);
	TILE(pX, pY)->objectCell = -1;
}

// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
// Surfaces
// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=

Entity &EManager::CreateSurface(EntityType pType, int pX, int pY)
{
	if (TILE(pX, pY)->surfaceCell != -1)
		Game::world->DeleteSurface(TILE(pX, pY)->surfaceCell);

	int cell;
	Entity *ent = Game::world->GetFreeSurfaceCell(cell);

	InitializeEntity(*ent);
	TILE(pX, pY)->surfaceCell = cell;
	ent->posX = pX;
	ent->posY = pY;

	ent->type = pType;
	ent->ti = ETables::GetTiSurface(pType);

	AddFeature(*ent, ETables::GetFeatsSurface(pType));

	return *ent;
}

// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
// Objects
// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=

Entity &EManager::CreateTree(EntityType pType, int pX, int pY, int pAge)
{
	Entity *ent = &CreateObject(pX, pY);

	ent->type = pType;

	if (pAge >= TREE_DISAPPEARAGE)
		pAge = TREE_DISAPPEARAGE - 1;
	ent->creationTime = WorldUpdater::currentTurn - pAge;

	if (pAge < TREE_ADULTAGE)
		ent->ti = ETables::GetTiTreeYoung(pType);
	else if (pAge < TREE_DIEAGE)
		ent->ti = ETables::GetTiTreeAdult(pType);
	else
		ent->ti = ETables::GetTiTreeDead(pType);

	AddFeature(*ent, FEAT_TREELIKE);

	return *ent;
}
