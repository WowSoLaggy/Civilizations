#include "stdafx.h"
#include "Forester.h"

void Forester::UpdateTrees()
{
	for (int y = 0; y < WHEIGHT; ++y)
	{
		for (int x = 0; x < WHEIGHT; ++x)
		{
			Entity *ent = OBJAT(x, y);
			if (ent != nullptr)
			{
				// Process an existing object

				if (!EManager::IsFlora(*ent))
					continue;

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
						TryToReproduce(*ent, x, y);
				}
				else
				{
					if (age >= ent->eblueprint().ageDecay)
					{
						if (RAND0EQ0(TREE_DIE_CHANCE))
							EManager::DeleteObjectAt(x, y);
					}
				}

				continue;
			}

			// No tree here

			if (!EManager::IsFitForTrees(*SURFAT(x, y)))
				continue;

			// Check if something wants to grow here

			// Check trees
			EntityType entType = RANDVECT(SURFAT(x, y)->cblueprint().nativeTrees);
			if (entType != type_unknown)
			{
				if (TryToPlant(entType, x, y))
					continue;
			}

			// Check bushes
			entType = RANDVECT(SURFAT(x, y)->cblueprint().nativeBushes);
			if (entType != type_unknown)
			{
				if (TryToPlant(entType, x, y))
					continue;
			}
		}
	}
}

bool Forester::TryToPlant(EntityType pType, int pX, int pY)
{
	if (TILE(pX, pY)->aff < EBlueprint::GetBlueprint(pType).affMin)			// not enough afforestation
		return false;
	if (!EManager::IsNativeSurfForObj(pType, SURFAT(pX, pY)->type))			// not native surface
		return false;
	if (RAND0NEQ0(EBlueprint::GetBlueprint(pType).chanceToGrow))			// sorry but no
		return false;

	// Planting here
	Entity *ent = EManager::CreateObject(pType, pX, pY);
	ent->state = state_young;
	TILE(pX, pY)->aff = ent->eblueprint().affBase;

	return true;
}

bool Forester::TryToReproduce(Entity &pEnt, int pX, int pY)
{
	if (RAND0NEQ0(pEnt.eblueprint().chanceToReproduce))						// it is not your day
		return false;

	int newX = RAND(TREE_REPRODUCT_RAD * 2 + 1, pX - TREE_REPRODUCT_RAD);
	int newY = RAND(TREE_REPRODUCT_RAD * 2 + 1, pY - TREE_REPRODUCT_RAD);

	if (OBJAT(newX, newY) != nullptr)										// tile is occupied
		return false;
	if (!EManager::IsFitForTrees(*SURFAT(newX, newY)))						// trees can't grow here
		return false;
	if (!EManager::IsNativeSurfForObj(pEnt.type, SURFAT(newX, newY)->type))	// not native surface
		return false;

	// Reproduce!

	Entity *ent = EManager::CreateObject(pEnt.type, newX, newY);
	ent->state = state_young;
	TILE(pX, pY)->aff = ent->eblueprint().affBase;

	return true;
}
