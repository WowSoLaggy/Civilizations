#include "stdafx.h"
#include "ETables.h"

#include "EManager.h"


int ETables::GetTiObject(EntityType pType, EntityState pState)
{
	if (EManager::IsTree(pType))
	{
		if (pState == state_young)
			return tiTrees[(pType - 100) * 3 + 0];
		else if (pState == state_adult)
			return tiTrees[(pType - 100) * 3 + 1];
		else if (pState == state_dead)
			return tiTrees[(pType - 100) * 3 + 2];
	}
	else
		return tiObjects[pType - 107];

	return 0;
}
