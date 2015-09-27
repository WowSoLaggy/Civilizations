#include "stdafx.h"
#include "Fauna.h"

void Fauna::CheckTile(int pX, int pY)
{
	Entity *ent = FAUNAAT(pX, pY);
	if (ent != nullptr)
	{
		// Process an existing object

		return;
	}

	// No fauna here

	EntityType eType = RANDVECT(SURFAT(pX, pY)->cblueprint().nativeFaunaSmall);
	if (eType != type_unknown)
	{
		if (TryToGrow(eType, pX, pY))
			return;
	}
}

bool Fauna::TryToGrow(EntityType pType, int pX, int pY)
{
	if (EManager::IsWaterTile(SURFAT(pX, pY)->type))
	{
		if ((TILE(pX, pY)->faunaWater < EBlueprint::GetBlueprint(pType).faunationMin) || (TILE(pX, pY)->faunaWater > EBlueprint::GetBlueprint(pType).faunationMax))	// Not enough fishiness
			return false;
	}
	else
	{
		if ((TILE(pX, pY)->faunaLand < EBlueprint::GetBlueprint(pType).faunationMin) || (TILE(pX, pY)->faunaLand > EBlueprint::GetBlueprint(pType).faunationMax))	// Not enough faunation
			return false;
		if (TILE(pX, pY)->aff < EBlueprint::GetBlueprint(pType).affMin)	// not enough afforestation
			return false;
	}

	if (!EManager::IsNativeSurfForObj(pType, SURFAT(pX, pY)->type))
		return false;
	if (RAND0NEQ0(EBlueprint::GetBlueprint(pType).chanceToGrow))		// sorry but no
		return false;

	// Planting here
	Entity *ent = EManager::CreateEntity(lay_fauna, pType, pX, pY);

	if (EManager::IsWaterTile(SURFAT(pX, pY)->type))
		TILE(pX, pY)->faunaWater = ent->eblueprint().affBase;
	else
		TILE(pX, pY)->faunaLand = ent->eblueprint().affBase;

	return true;
}
