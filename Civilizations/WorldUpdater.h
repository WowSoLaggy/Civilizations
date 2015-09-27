#pragma once

#ifndef WORLDUPDATER_H
#define WORLDUPDATER_H


#include "World.h"
#include "TManager.h"
#include "Nature.h"
#include "Flora.h"
#include "Fauna.h"


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
