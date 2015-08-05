#include "stdafx.h"
#include "EManager.h"

void EManager::ConvertTreeToType(Entity &pTree, EntityType pType)
{
	pTree.type = pType;

	int age = AGE(pTree);
	if (age < TREE_ADULTAGE)
		pTree.ti = ETables::GetTiObject(pType, state_young);
	else if (age < TREE_DIEAGE)
		pTree.ti = ETables::GetTiObject(pType, state_adult);
	else
		pTree.ti = ETables::GetTiObject(pType, state_dead);
}
