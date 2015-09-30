#include "stdafx.h"
#include "Flora.h"

void Flora::CheckTile(int pX, int pY)
{
	Entity *ent = FLORAAT(pX, pY);
	if (ent != nullptr)
	{
		// Process an existing object
		

		// Check whether the surface fits flora

		if (!EManager::IsNativeSurfForObj(ent->type, SURFAT(pX, pY)->type))
		{
			if (RAND0EQ0(FLORA_EXTINGUISH_CHANCE))
			{
				EManager::DeleteEntityAt(lay_flora, pX, pY);
				return;
			}
		}

		// Check it's age

		int age = AGE(*ent);

		if (EManager::IsYoungTree(*ent))
		{
			if (age >= ent->eblueprint().ageAdulthood)
				ent->state = state_adult;
		}
		else if (EManager::IsAdultTree(*ent))
		{
			if (age >= ent->eblueprint().ageOldness)
				ent->state = state_dead;
			else
				TryToReproduce(*ent, pX, pY);
		}
		else
		{
			if (age >= ent->eblueprint().ageDecay)
			{
				if (RAND0EQ0(TREE_DIE_CHANCE))
					EManager::DeleteEntityAt(lay_flora, pX, pY);
			}
		}

		return;
	}

	// No tree here

	if (!EManager::IsFitForTrees(*SURFAT(pX, pY)))
		return;

	// Check if something wants to grow here

	EntityType eType = RANDVECT(SURFAT(pX, pY)->cblueprint().nativeFlora);
	if (eType != type_unknown)
	{
		if (TryToPlant(eType, pX, pY))
			return;
	}
}

bool Flora::TryToPlant(EntityType pType, int pX, int pY)
{
	if (TILE(pX, pY)->aff < EBlueprint::GetBlueprint(pType).affMin)			// not enough afforestation
		return false;
	if (!EManager::IsNativeSurfForObj(pType, SURFAT(pX, pY)->type))			// not native surface
		return false;
	if (RAND0NEQ0(EBlueprint::GetBlueprint(pType).chanceToGrow))			// sorry but no
		return false;

	// Planting here
	Entity *ent = EManager::CreateEntity(lay_flora, pType, pX, pY);
	ent->state = state_young;
	TILE(pX, pY)->aff = std::max(TILE(pX, pY)->aff, ent->eblueprint().affBase);

	return true;
}

bool Flora::TryToReproduce(Entity &pEnt, int pX, int pY)
{
	if (RAND0NEQ0(pEnt.eblueprint().chanceToReproduce))						// it is not your day
		return false;

	int newX = RAND(TREE_REPRODUCT_RAD * 2 + 1, pX - TREE_REPRODUCT_RAD);
	int newY = RAND(TREE_REPRODUCT_RAD * 2 + 1, pY - TREE_REPRODUCT_RAD);

	if (FLORAAT(newX, newY) != nullptr)										// tile is occupied
		return false;
	if (!EManager::IsFitForTrees(*SURFAT(newX, newY)))						// trees can't grow here
		return false;
	if (!EManager::IsNativeSurfForObj(pEnt.type, SURFAT(newX, newY)->type))	// not native surface
		return false;

	// Reproduce!

	Entity *ent = EManager::CreateEntity(lay_flora, pEnt.type, newX, newY);
	ent->state = state_young;
	TILE(pX, pY)->aff = std::max(TILE(pX, pY)->aff, ent->eblueprint().affBase);

	return true;
}
