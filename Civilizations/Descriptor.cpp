#include "stdafx.h"
#include "Descriptor.h"

#include "WorldUpdater.h"


void Descriptor::GetTileDescription(Tile &pTile, std::string &pDesc, int pX, int pY)
{
	Entity *surf = SURF(pTile.surfaceCell);
	Entity *obj = OBJ(pTile.floraCell);


	pDesc = "Surface: ";
	if (surf == nullptr)
		pDesc.append("None ");
	else
		pDesc.append(surf->eblueprint().description);


	pDesc.append("(").
		append(std::to_string((int)pTile.humidity)).append("% h, ").
		append(std::to_string((int)pTile.temperature)).append("°C, ").
		append(std::to_string((int)pTile.height)).append("m, ").
		append(std::to_string((int)pTile.productivity)).append(" prod, ").
		append(std::to_string((int)pTile.aff)).append(" affor)\n");


	pDesc.append("Object: ");
	if (obj == nullptr)
		pDesc.append("None\n");
	else
	{
		if (EManager::IsFlora(*obj))
		{
			if (obj->state == state_young)
				pDesc.append("Young ");
			else if (obj->state == state_dead)
				pDesc.append("Dead ");
		}

		pDesc.append(obj->eblueprint().description);
		pDesc.append("(").append(std::to_string(AGE(*obj) / WEEKSINYEAR)).append(" y.o.)\n");
	}
}
