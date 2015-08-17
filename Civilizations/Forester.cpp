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

				int age = AGE(*ent);

				if (EManager::IsTree(*ent))
				{
					if (EManager::IsAdultTree(*ent))
					{
						// Roll for tree reproduction
						if (RAND0(TREE_REPRODUCT_CHANCE))
							Forester::ReproduceTree(*ent);
					}

					if (age >= TREE_DISAPPEARAGE)
					{
						if (RAND0(TREE_DIE_CHANCE))
							EManager::DeleteObjectAt(x, y);
					}
				}
				else if (EManager::IsBush(*ent))
				{
					if (age >= BUSH_DIEAGE)
					{
						if (RAND0(BUSH_DIE_CHANCE))
							EManager::DeleteObjectAt(x, y);
					}
				}

				continue;
			}

			// No tree here

			if (!EManager::IsFitForTrees(*SURFAT(x, y)))
				continue;

			// Check if something wants to grow here

			float afforest = Weather::afforestation[x / 3 + y / 3 * Weather::w3];

			EntityType entType = SURFAT(x, y)->blueprint->nativeTrees[0];
			if (afforest >= 0)
			{
				// Tree can be planted here
				if (RAND(TREE_GROW_CHANCE, 0) == 0)
				{
					// Planting tree here
					Entity ent = EManager::CreateObject(entType, x, y);
					ent.state = state_young;
					continue;
				}
			}

			entType = SURFAT(x, y)->blueprint->nativeBushes[0];
			if (afforest >= 0)
			{
				// Bush can be planted here
				if (RAND(BUSH_GROW_CHANCE, 0) == 0)
				{
					// Planting bush here
					Entity ent = EManager::CreateObject(entType, x, y);
					continue;
				}
			}
		}
	}
}

void Forester::ReproduceTree(Entity &pEnt)
{
	// TODO:
}
