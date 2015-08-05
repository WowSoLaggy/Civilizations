#include "stdafx.h"
#include "Descriptor.h"

#include "WorldUpdater.h"


void Descriptor::GetTileDescription(Tile &pTile, std::string &pDesc)
{
	Entity *surf = SURF(pTile.surfaceCell);
	Entity *obj = OBJ(pTile.objectCell);


	pDesc = "Surface: ";
	if (surf == nullptr)
		pDesc.append("None ");
	else
		pDesc.append(ETables::GetDescSurface(surf->type));

	pDesc.append("(").
		append(std::to_string((int)pTile.humidity)).append("% h, ").
		append(std::to_string((int)pTile.temperature)).append("°C, ").
		append(std::to_string((int)pTile.height)).append("m, ").
		append(std::to_string((int)pTile.productivity)).append(" prod)\n");


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

		pDesc.append(ETables::GetDescObject(obj->type));
		pDesc.append("(").append(std::to_string(age)).append(" y.o.)\n");
	}
}
