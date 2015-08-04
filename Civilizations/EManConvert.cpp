#include "stdafx.h"
#include "EManager.h"

void EManager::ConvertTreeToType(Entity &pTree, EntityType pType)
{
	pTree.type = pType;

	int age = AGE(pTree);
	if (age < TREE_ADULTAGE)
		pTree.ti = ETables::GetTiTreeYoung(pType);
	else if (age < TREE_DIEAGE)
		pTree.ti = ETables::GetTiTreeAdult(pType);
	else
		pTree.ti = ETables::GetTiTreeDead(pType);
}
