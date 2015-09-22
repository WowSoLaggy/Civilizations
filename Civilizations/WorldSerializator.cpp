#include "stdafx.h"
#include "WorldSerializator.h"

#include "Game.h"

bool WorldSerializator::SaveWorld(World &pWorld)
{
	// Generate file name

	std::string fileName = "Data\\Worlds\\" + pWorld.name + ".wrld";

	FILE *pFile;
	errno_t err = fopen_s(&pFile, fileName.c_str(), "wb");
	if (err != 0)
		return false;

	// Serialization start

	// Name
	unsigned int nameLength = pWorld.name.size();
	fwrite(&nameLength, sizeof(unsigned int), 1, pFile);
	fwrite(pWorld.name.c_str(), sizeof(char), pWorld.name.size(), pFile);

	// Turn
	fwrite(&WorldUpdater::currentTurn, sizeof(int), 1, pFile);

	// Size
	fwrite(&pWorld.width, sizeof(int), 1, pFile);
	fwrite(&pWorld.height, sizeof(int), 1, pFile);

	// Tiles
	for (int y = 0; y < pWorld.height; ++y)
	{
		for (int x = 0; x < pWorld.width; ++x)
		{
			fwrite(TILE(x, y), sizeof(Tile), 1, pFile);
			if (TILE(x, y)->surfaceCell != -1)
				fwrite(SURFAT(x, y), sizeof(Entity), 1, pFile);
			if (TILE(x, y)->objectCell != -1)
				fwrite(OBJAT(x, y), sizeof(Entity), 1, pFile);
		}
	}

	// Serialization end

	fclose(pFile);
	return true;
}

bool WorldSerializator::LoadWorld(World &pWorld, std::string pWorldName)
{
	// Generate file name

	std::string fileName = "Data\\Worlds\\" + pWorldName + ".wrld";

	FILE *pFile;
	errno_t err = fopen_s(&pFile, fileName.c_str(), "rb");
	if (err != 0)
		return false;

	// Deserialization start

	// Name
	unsigned int nameLength = 0;
	fread(&nameLength, sizeof(unsigned int), 1, pFile);
	char *buf = new char[nameLength];
	fread(buf, sizeof(char), nameLength, pFile);
	pWorld.name = std::string(buf, nameLength);
	delete[] buf;

	// Turn
	fread(&WorldUpdater::currentTurn, sizeof(int), 1, pFile);

	// Size
	fread(&pWorld.width, sizeof(int), 1, pFile);
	fread(&pWorld.height, sizeof(int), 1, pFile);

	// Tiles
	pWorld.tiles.clear();
	pWorld.tiles.resize(pWorld.width * pWorld.height);
	pWorld.ResizeSurfaces(pWorld.width * pWorld.height);
	pWorld.ResizeObjects(pWorld.width * pWorld.height / 100);
	Tile tileTmp;
	Entity entTmp;
	for (int y = 0; y < pWorld.height; ++y)
	{
		for (int x = 0; x < pWorld.width; ++x)
		{
			fread(&tileTmp, sizeof(Tile), 1, pFile);
			pWorld.tiles[x + y * pWorld.width].aff = tileTmp.aff;
			pWorld.tiles[x + y * pWorld.width].height = tileTmp.height;
			pWorld.tiles[x + y * pWorld.width].humidity = tileTmp.humidity;
			pWorld.tiles[x + y * pWorld.width].productivity = tileTmp.productivity;
			pWorld.tiles[x + y * pWorld.width].temperature = tileTmp.temperature;
			pWorld.tiles[x + y * pWorld.width].surfaceCell = -1;
			pWorld.tiles[x + y * pWorld.width].objectCell = -1;

			if (tileTmp.surfaceCell != -1)
			{
				fread(&entTmp, sizeof(Entity), 1, pFile);
				EManager::CreateSurface(entTmp.type, x, y);
				*SURFAT(x, y) = entTmp;
			}

			if (tileTmp.objectCell != -1)
			{
				fread(&entTmp, sizeof(Entity), 1, pFile);
				EManager::CreateObject(entTmp.type, x, y);
				*OBJAT(x, y) = entTmp;
			}
		}
	}

	// Deserialization end

	fclose(pFile);

	Drawer::UpdateMiniMap();

	return true;
}
