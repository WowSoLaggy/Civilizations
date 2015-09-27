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
	Nature::UpdateGroundHumidity();
	Nature::UpdateAirTemperature();
	Nature::UpdateGroundProductivity();
	Nature::UpdateAfforestation();
	Nature::UpdateFaunation();
	TManager::CheckTilesClimate();


	for (int y = 0; y < WHEIGHT; ++y)
	{
		for (int x = 0; x < WWIDTH; ++x)
		{
			Flora::CheckTile(x, y);
			Fauna::CheckTile(x, y);
		}
	}
}


void WorldUpdater::Load()
{
	Nature::Load();
}

void WorldUpdater::Unload()
{
	Nature::UnLoad();
}
