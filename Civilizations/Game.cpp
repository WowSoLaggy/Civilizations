#include "stdafx.h"
#include "Game.h"


World *Game::world;
int Game::selectedTileX;
int Game::selectedTileY;
CRITICAL_SECTION Game::worldLocker;

void Game::Initialize()
{
	InitRand();
	selectedTileX = -1;
	selectedTileY = -1;

	EBlueprint::InitBlueprints();
	CBlueprint::InitBlueprints();
}

int Game::Start()
{
	InitializeCriticalSection(&worldLocker);

	EnterCriticalSection(&worldLocker);
	world = new World();
	int size = 1024;
	std::string worldName = "New World";
	WorldCreator::GenerateWorld(*world, worldName, size, size);
	LeaveCriticalSection(&worldLocker);

	return 0;
}

void Game::Dispose()
{
	EnterCriticalSection(&worldLocker);
	WorldCreator::DisposeWorld(*world);
	delete world;
	world = nullptr;
	LeaveCriticalSection(&worldLocker);

	DeleteCriticalSection(&worldLocker);
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
