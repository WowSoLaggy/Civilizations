#include "stdafx.h"
#include "EManager.h"

int EManager::m_nextId = 1;


// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
// General
// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=

void EManager::InitializeEntity(Entity &pEntity)
{
	pEntity.id = m_nextId++;
	pEntity.type = type_unknown;
	pEntity.state = state_unknown;

	pEntity.creationTime = WorldUpdater::currentTurn;
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
// Entities
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
	ent->UpdateBlueprint();

	return *ent;
}

Entity &EManager::CreateObject(EntityType pType, int pX, int pY)
{
	if (TILE(pX, pY)->objectCell != -1)
		Game::world->DeleteObject(TILE(pX, pY)->objectCell);

	int cell;
	Entity *ent = Game::world->GetFreeObjectCell(cell);

	InitializeEntity(*ent);
	TILE(pX, pY)->objectCell = cell;
	ent->posX = pX;
	ent->posY = pY;

	ent->type = pType;
	ent->UpdateBlueprint();

	return *ent;
}
