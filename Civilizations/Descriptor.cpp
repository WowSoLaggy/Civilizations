#include "stdafx.h"
#include "Descriptor.h"

#include "WorldUpdater.h"


void Descriptor::GetTileDescription(Tile &pTile, std::string &pDesc, int pX, int pY)
{
	Entity *surf = SURF(pTile.surfaceCell);
	Entity *obj = OBJ(pTile.objectCell);


	pDesc = "Surface: ";
	if (surf == nullptr)
		pDesc.append("None ");
	else
		pDesc.append(surf->blueprint->description);

	int afforest = (int)(Weather::afforestation[pX / 3 + pY / 3 * Weather::w3]);

	pDesc.append("(").
		append(std::to_string((int)pTile.humidity)).append("% h, ").
		append(std::to_string((int)pTile.temperature)).append("�C, ").
		append(std::to_string((int)pTile.height)).append("m, ").
		append(std::to_string((int)pTile.productivity)).append(" prod, ").
		append(std::to_string(afforest)).append(" affor)\n");


	pDesc.append("Object: ");
	if (obj == nullptr)
		pDesc.append("None\n");
	else
	{
		int age = AGE(*obj);
		if (age < TREE_ADULTAGE)
			pDesc.append("Sapling ");
		else if (age >= TREE_DIEAGE)
			pDesc.append("Dead ");

		pDesc.append(obj->blueprint->description);
		pDesc.append("(").append(std::to_string(age)).append(" y.o.)\n");
	}
}