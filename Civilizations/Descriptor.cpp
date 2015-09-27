#include "stdafx.h"
#include "Descriptor.h"

#include "WorldUpdater.h"


void Descriptor::GetTileDescription(Tile &pTile, std::string &pDesc, int pX, int pY)
{
	Entity *surf = SURF(pTile.cells[lay_surf]);
	Entity *flora = FLORA(pTile.cells[lay_flora]);
	Entity *fauna = FAUNA(pTile.cells[lay_fauna]);


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
		append(std::to_string((int)pTile.aff)).append(" affor, ").
		append(std::to_string((int)pTile.faunaLand)).append(" fauna, ").
		append(std::to_string((int)pTile.faunaWater)).append(" fish)\n");


	pDesc.append("Flora: ");
	if (flora == nullptr)
		pDesc.append("None\n");
	else
	{
		if (flora->state == state_young)
			pDesc.append("Young ");
		else if (flora->state == state_dead)
			pDesc.append("Dead ");

		pDesc.append(flora->eblueprint().description);
		pDesc.append("(").append(std::to_string(AGE(*flora) / WEEKSINYEAR)).append(" y.o.)\n");
	}

	pDesc.append("Fauna: ");
	if (fauna == nullptr)
		pDesc.append("None\n");
	else
		pDesc.append(fauna->eblueprint().description);
}
