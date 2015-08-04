#pragma once

#ifndef WORLDUPDATER_H
#define WORLDUPDATER_H

#include "World.h"
#include "TManager.h"
#include "Forester.h"
#include "Weather.h"


class WorldUpdater
{
public:

	static int currentTurn;

	static void MakeTurn();
	static void MakeTurn(int pTurns);

	static void Load();
	static void Unload();

private:

	static void UpdateWorld();
};


#endif // WORLDUPDATER_H
