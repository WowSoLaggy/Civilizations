#pragma once

#ifndef GAME_H
#define GAME_H

#include "Constants.h"
#include "RenderDeviceManager.h"
#include "RManager.h"
#include "InputDeviceManager.h"
#include "WorldCreator.h"
#include "WorldUpdater.h"
#include "World.h"
#include "Drawer.h"
#include "GManager.h"
#include "EBlueprint.h"


class Game
{
public:

	static World *world;

	static int selectedTileX;
	static int selectedTileY;

	static Tile * GetSelectedTile();

	static void Initialize();
	static void Dispose();

	static int Start();
	static int MainLoop();

	static void HandleKeyboard();
	static void HandleMouse();

	static bool OnNullRenderDevice();
};


#endif // GAME_H
