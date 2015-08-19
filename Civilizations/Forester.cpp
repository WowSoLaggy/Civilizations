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
					{
						// TODO: tree reproduction
					}
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
			EntityType entType = RANDVECT(SURFAT(x, y)->eblueprint().nativeTrees);
			if (entType != type_unknown)
			{
				if (TryToPlant(entType, x, y))
					continue;
			}

			// Check bushes
			entType = RANDVECT(SURFAT(x, y)->eblueprint().nativeBushes);
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
	if (TILE(pX, pY)->aff >= EBlueprint::GetBlueprint(pType).affMin)
	{
		// Tree can be planted here. Let's dice

		if (RAND0EQ0(EBlueprint::GetBlueprint(pType).chanceToGrow))
		{
			// Planting here
			Entity *ent = EManager::CreateObject(pType, pX, pY);
			ent->state = state_young;
			TILE(pX, pY)->aff = ent->eblueprint().affBase;

			return true;
		}
	}

	return false;
}

void Forester::ReproduceTree(Entity &pEnt)
{
	// TODO:
}
