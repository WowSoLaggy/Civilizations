#include "stdafx.h"
#include "WorldUpdater.h"

int WorldUpdater::currentTurn = 0;

void WorldUpdater::MakeTurn()
{
	currentTurn++;
	UpdateWorld();
	Drawer::UpdateMiniMap();
}

void WorldUpdater::MakeTurn(int pTurns)
{
	while (pTurns > 0)
	{
		currentTurn++;
		UpdateWorld();
		pTurns--;
	}

	Drawer::UpdateMiniMap();
}

void WorldUpdater::UpdateWorld()
{
	Weather::UpdateGroundHumidity();
	Weather::UpdateAirTemperature();
	Weather::UpdateGroundProductivity();
	TManager::CheckTilesClimate();

	Forester::UpdateTrees();
}


void WorldUpdater::Load()
{
	Weather::Load();
}

void WorldUpdater::Unload()
{
	Weather::UnLoad();
}
