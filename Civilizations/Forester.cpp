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
					if (age == TREE_ADULTAGE)
						ent->ti = ETables::GetTiObject(ent->type, state_adult);

					if (EManager::IsAdultTree(*ent))
					{
						// Roll for tree reproduction
						if (RAND0(TREE_REPRODUCT_CHANCE))
							Forester::ReproduceTree(*ent);
					}

					if (age == TREE_DIEAGE)
						ent->ti = ETables::GetTiObject(ent->type, state_dead);
					else if (age >= TREE_DISAPPEARAGE)
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

			if (!EManager::IsFitForTrees(*SURFAT(x, y)))
				continue;

			// Check if something wants to grow here

			float afforest = Weather::afforestation[x / 3 + y / 3 * Weather::w3];

			EntityType entType = ETables::GetNativeTree(SURFAT(x, y)->type);
			if (afforest >= ETables::GetReqAfforestation(entType))
			{
				// Tree can be planted here
				if (RAND(TREE_GROW_CHANCE, 0) == 0)
				{
					// Planting tree here
					EManager::CreateObject(entType, x, y, state_young);
					continue;
				}
			}

			entType = ETables::GetNativeBush(SURFAT(x, y)->type);
			if (afforest >= ETables::GetReqAfforestation(entType))
			{
				// Bush can be planted here
				if (RAND(BUSH_GROW_CHANCE, 0) == 0)
				{
					// Planting bush here
					EManager::CreateObject(entType, x, y, state_young);
					continue;
				}
			}
		}
	}

	//for (int i = Game::world->occupiedObjectCells.size() - 1; i >= 0; --i)
	//{
	//	int cell = Game::world->occupiedObjectCells[i];

	//	if (EManager::IsTree(*OBJ(cell)))
	//	{
	//		int age = AGE(*OBJ(cell));

	//		if (age == TREE_ADULTAGE)
	//			OBJ(cell)->ti = ETables::GetTiObject(OBJ(cell)->type, state_adult);

	//		if (EManager::IsAdultTree(*OBJ(cell)))
	//		{
	//			// Roll for tree reproduction
	//			if (rand() % TREE_REPRODUCT_KOEF == 0)
	//				Forester::ReproduceTree(*OBJ(cell));
	//		}

	//		if (age == TREE_DIEAGE)
	//			OBJ(cell)->ti = ETables::GetTiObject(OBJ(cell)->type, state_dead);
	//		else if (age >= TREE_DISAPPEARAGE)
	//		{
	//			if ((rand() % TREE_DIE_KOEF) == 0)
	//				EManager::DeleteObjectAt(OBJ(cell)->posX, OBJ(cell)->posY);
	//		}
	//	}
	//}
}

void Forester::ReproduceTree(Entity &pTree)
{
	/*int tries = 0;
	while (tries++ < TREE_REPRODUCT_TRIES)
	{
		int newX = rand() % TREE_REPRODUCT_DIAM + pTree.posX - TREE_REPRODUCT_RAD;
		int newY = rand() % TREE_REPRODUCT_DIAM + pTree.posY - TREE_REPRODUCT_RAD;

		if ((newX == pTree.posX) && (newY == pTree.posY))
			continue;
		if ((newX < 0) || (newX >= WWIDTH) || (newY < 0) || (newY >= WHEIGHT))
			continue;
		if (!EManager::IsNativeSurface(pTree, *SURFAT(newX, newY)))
			continue;
		if (TILE(newX, newY)->objectCell != -1)
			continue;

		EManager::CreateTree(pTree.type, newX, newY, 0);

		break;
	}*/
}
