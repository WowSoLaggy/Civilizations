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

void EManager::DeleteEntityAt(EntityLayer pLayer, int pX, int pY)
{
	WORLD->entities[pLayer].DeleteEntity(TILE(pX, pY)->cells[pLayer]);
	TILE(pX, pY)->cells[pLayer] = -1;
}

// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
// Entities
// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=

Entity *EManager::CreateEntity(EntityLayer pLayer, EntityType pType, int pX, int pY)
{
	if (TILE(pX, pY)->cells[pLayer] != -1)
		WORLD->entities[pLayer].DeleteEntity(TILE(pX, pY)->cells[pLayer]);

	int cell;
	Entity *ent = WORLD->entities[pLayer].GetFreeCell(cell);
	TILE(pX, pY)->cells[pLayer] = cell;

	InitializeEntity(*ent);
	ent->type = pType;

	return ent;
}
