#include "stdafx.h"
#include "Game.h"


World *Game::world;
int Game::selectedTileX;
int Game::selectedTileY;


void Game::Initialize()
{
	initRand();
	selectedTileX = -1;
	selectedTileY = -1;

	EBlueprint::InitBlueprints();
}

int Game::Start()
{
	world = new World();
	int size = 1024;
	WorldCreator::GenerateWorld(*world, size, size);
	return 0;
}

void Game::Dispose()
{
	WorldCreator::DisposeWorld(*world);
	delete world;
}

bool Game::OnNullRenderDevice()
{
	RenderDeviceManager::CreateRenderDevice();
	if (!RenderDeviceManager::Created)
		return false;

	RManager::LoadResources();
	GManager::Load();
	Drawer::Load();
	WorldUpdater::Load();

	return true;
}

Tile * Game::GetSelectedTile()
{
	if ((world == nullptr) || (selectedTileX == -1))
		return nullptr;
	return &TILES[selectedTileX + selectedTileY * world->width];
}
