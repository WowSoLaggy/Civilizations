#include "stdafx.h"
#include "WorldSerializator.h"

#include "Game.h"

bool WorldSerializator::SaveWorld(World &pWorld)
{
	// Generate the file name and open the file

	std::string fileName = "Data\\Worlds\\" + pWorld.name + ".wrld";

	std::ofstream fout(fileName, std::ios::trunc | std::ios::binary);
	if (!fout.is_open())
		return false;

	// Serialization start

	// Name
	unsigned int nameLength = pWorld.name.size();
	fout.write((char *)&nameLength, sizeof(unsigned int));
	fout.write(pWorld.name.c_str(), nameLength);

	// Turn
	fout.write((char *)&WorldUpdater::currentTurn, sizeof(int));

	// Cam pos
	int camPosX = Drawer::camPosX();
	int camPosY = Drawer::camPosY();
	fout.write((char *)&camPosX, sizeof(int));
	fout.write((char *)&camPosY, sizeof(int));

	// Size
	fout.write((char *)&pWorld.width, sizeof(int));
	fout.write((char *)&pWorld.height, sizeof(int));

	// Tiles
	for (int y = 0; y < pWorld.height; ++y)
	{
		for (int x = 0; x < pWorld.width; ++x)
		{
			fout.write((char *)TILE(x, y), sizeof(Tile));
			if (TILE(x, y)->surfaceCell != -1)
				fout.write((char *)SURFAT(x, y), sizeof(Entity));
			if (TILE(x, y)->floraCell != -1)
				fout.write((char *)OBJAT(x, y), sizeof(Entity));
		}
	}

	// Serialization end

	fout.close();
	return true;
}

bool WorldSerializator::LoadWorld(World &pWorld, std::string pWorldName)
{
	// Generate the file name and open the file

	std::string fileName = "Data\\Worlds\\" + pWorldName + ".wrld";

	std::ifstream fin(fileName, std::ios::binary);
	if (!fin.is_open())
		return false;

	// Deserialization start

	// Name
	unsigned int nameLength = 0;
	fin.read((char *)&nameLength, sizeof(unsigned int));
	char *buf = new char[nameLength];
	fin.read(buf, nameLength);
	pWorld.name = std::string(buf, nameLength);
	delete[] buf;

	// Turn
	fin.read((char *)&WorldUpdater::currentTurn, sizeof(int));

	// Cam pos
	int camPosX = 0;
	int camPosY = 0;
	fin.read((char *)&camPosX, sizeof(int));
	fin.read((char *)&camPosY, sizeof(int));
	Drawer::SetCamPosTopLeft(camPosX, camPosY);

	// Size
	fin.read((char *)&pWorld.width, sizeof(int));
	fin.read((char *)&pWorld.height, sizeof(int));

	// Tiles
	pWorld.tiles.clear();
	pWorld.tiles.resize(pWorld.width * pWorld.height);
	pWorld.ResizeSurfaces(pWorld.width * pWorld.height);
	pWorld.ResizeFloras(pWorld.width * pWorld.height / 100);
	Tile tileTmp;
	Entity entTmp;
	for (int y = 0; y < pWorld.height; ++y)
	{
		for (int x = 0; x < pWorld.width; ++x)
		{
			fin.read((char *)&tileTmp, sizeof(Tile));
			pWorld.tiles[x + y * pWorld.width] = tileTmp;
			pWorld.tiles[x + y * pWorld.width].surfaceCell = -1;
			pWorld.tiles[x + y * pWorld.width].floraCell = -1;

			if (tileTmp.surfaceCell != -1)
			{
				fin.read((char *)&entTmp, sizeof(Entity));
				EManager::CreateSurface(entTmp.type, x, y);
				*SURFAT(x, y) = entTmp;
			}

			if (tileTmp.floraCell != -1)
			{
				fin.read((char *)&entTmp, sizeof(Entity));
				EManager::CreateObject(entTmp.type, x, y);
				*OBJAT(x, y) = entTmp;
			}
		}
	}

	// Deserialization end

	fin.close();

	Drawer::UpdateMiniMap();

	return true;
}
