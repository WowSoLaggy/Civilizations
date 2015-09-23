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
	pEntity.climtype = clim_unknown;
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
	Game::world->DeleteFlora(TILE(pX, pY)->floraCell);
	TILE(pX, pY)->floraCell = -1;
}

// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
// Entities
// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=

Entity *EManager::CreateSurface(EntityType pType, int pX, int pY)
{
	if (TILE(pX, pY)->surfaceCell != -1)
		Game::world->DeleteSurface(TILE(pX, pY)->surfaceCell);

	int cell;
	Entity *ent = Game::world->GetFreeSurfaceCell(cell);
	TILE(pX, pY)->surfaceCell = cell;

	InitializeEntity(*ent);
	ent->type = pType;

	return ent;
}

Entity *EManager::CreateObject(EntityType pType, int pX, int pY)
{
	if (TILE(pX, pY)->floraCell != -1)
		Game::world->DeleteFlora(TILE(pX, pY)->floraCell);

	int cell;
	Entity *ent = Game::world->GetFreeFloraCell(cell);
	TILE(pX, pY)->floraCell = cell;

	InitializeEntity(*ent);
	ent->type = pType;

	return ent;
}
