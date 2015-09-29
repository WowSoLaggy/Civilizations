#include "stdafx.h"
#include "Fauna.h"

void Fauna::CheckTile(int pX, int pY)
{
	Entity *ent = FAUNAAT(pX, pY);
	if (ent != nullptr)
	{
		// Process an existing object


		// Check whether the climate conditions fits flora

		if (
			(!EManager::IsNativeSurfForObj(ent->type, SURFAT(pX, pY)->type)) ||
			((TILE(pX, pY)->aff < ent->eblueprint().affMin) || (TILE(pX, pY)->aff > ent->eblueprint().affMax))
			)
		{
			if (RAND0EQ0(FAUNA_EXTINGUISH_CHANCE))
			{
				EManager::DeleteEntityAt(lay_fauna, pX, pY);
				return;
			}
		}

		return;
	}

	// No fauna here

	EntityType eType = RANDVECT(SURFAT(pX, pY)->cblueprint().nativeFauna);
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
		if ((TILE(pX, pY)->faunaWater < EBlueprint::GetBlueprint(pType).faunationMin) || (TILE(pX, pY)->faunaWater > EBlueprint::GetBlueprint(pType).faunationMax))	// Fishiness doesn't fit
			return false;
	}
	else
	{
		if ((TILE(pX, pY)->faunaLand < EBlueprint::GetBlueprint(pType).faunationMin) || (TILE(pX, pY)->faunaLand > EBlueprint::GetBlueprint(pType).faunationMax))	// Faunation doesn't fit
			return false;
		if ((TILE(pX, pY)->aff < EBlueprint::GetBlueprint(pType).affMin) || (TILE(pX, pY)->aff > EBlueprint::GetBlueprint(pType).affMax))	// Afforestation doesn't fit
			return false;
	}

	if (!EManager::IsNativeSurfForObj(pType, SURFAT(pX, pY)->type))		// Not native surface
		return false;
	if (RAND0NEQ0(EBlueprint::GetBlueprint(pType).chanceToGrow))		// Sorry but no
		return false;

	// Planting here
	Entity *ent = EManager::CreateEntity(lay_fauna, pType, pX, pY);

	if (EManager::IsWaterTile(SURFAT(pX, pY)->type))
		TILE(pX, pY)->faunaWater = ent->eblueprint().affBase;
	else
		TILE(pX, pY)->faunaLand = ent->eblueprint().affBase;

	return true;
}
