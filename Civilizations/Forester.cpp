#include "stdafx.h"
#include "Forester.h"

void Forester::UpdateTrees()
{
	for (int i = Game::world->occupiedObjectCells.size() - 1; i >= 0; --i)
	{
		int cell = Game::world->occupiedObjectCells[i];

		if (EManager::IsTreeLike(*OBJ(cell)))
		{
			int age = AGE(*OBJ(cell));

			if (age == TREE_ADULTAGE)
				MakeTreeAdult(*OBJ(cell));

			if (EManager::IsAdultTree(*OBJ(cell)))
			{
				// Roll for tree reproduction
				if (rand() % TREE_REPRODUCT_KOEF == 0)
					Forester::ReproduceTree(*OBJ(cell));
			}

			if (age == TREE_DIEAGE)
				MakeTreeDead(*OBJ(cell));
			else if (age >= TREE_DISAPPEARAGE)
			{
				if ((rand() % TREE_DIE_KOEF) == 0)
					EManager::DeleteObjectAt(OBJ(cell)->posX, OBJ(cell)->posY);
			}
		}
	}
}

void Forester::ReproduceTree(Entity &pTree)
{
	int tries = 0;
	while (tries++ < TREE_REPRODUCT_TRIES)
	{
		int newX = rand() % TREE_REPRODUCT_DIAM + pTree.posX - TREE_REPRODUCT_RAD;
		int newY = rand() % TREE_REPRODUCT_DIAM + pTree.posY - TREE_REPRODUCT_RAD;

		if ((newX == pTree.posX) && (newY == pTree.posY))
			continue;
		if ((newX < 0) || (newX >= Game::world->width) || (newY < 0) || (newY >= Game::world->height))
			continue;
		if (!EManager::IsNativeSurface(pTree, *SURFAT(newX, newY)))
			continue;
		if (TILE(newX, newY)->objectCell != -1)
			continue;

		EManager::CreateTree(pTree.type, newX, newY, 0);

		break;
	}
}

void Forester::MakeTreeAdult(Entity &pTree)
{
	if (EManager::IsEntityType(pTree, obj_tree))
		pTree.ti = 3;
	else if (EManager::IsEntityType(pTree, obj_fir))
		pTree.ti = 14;
	else if (EManager::IsEntityType(pTree, obj_cactus))
		pTree.ti = 17;
	else if (EManager::IsEntityType(pTree, obj_palm))
		pTree.ti = 24;
	else if (EManager::IsEntityType(pTree, obj_juniper))
		pTree.ti = 36;
	else if (EManager::IsEntityType(pTree, obj_baobab))
		pTree.ti = 39;
}

void Forester::MakeTreeDead(Entity &pTree)
{
	if (EManager::IsEntityType(pTree, obj_tree))
		pTree.ti = 4;
	else if (EManager::IsEntityType(pTree, obj_fir))
		pTree.ti = 15;
	else if (EManager::IsEntityType(pTree, obj_cactus))
		pTree.ti = 18;
	else if (EManager::IsEntityType(pTree, obj_palm))
		pTree.ti = 25;
	else if (EManager::IsEntityType(pTree, obj_juniper))
		pTree.ti = 37;
	else if (EManager::IsEntityType(pTree, obj_baobab))
		pTree.ti = 40;
}
