#pragma once

#ifndef WORLD_H
#define WORLD_H

#include "Tile.h"

class World
{
public:

	World();

	int width;
	int height;

	std::vector<Tile> tiles;

	Entity *lsurfaces;
	Entity *lobjects;

	Entity *GetFreeSurfaceCell();
	Entity *GetFreeSurfaceCell(int &pId);

	Entity *GetFreeObjectCell();
	Entity *GetFreeObjectCell(int &pId);

	void ResizeSurfaces(int pCount);
	void ResizeObjects(int pCount);

	void DeleteSurface(int pCell);
	void DeleteObject(int pCell);

	std::vector<int> freeSurfaceCells;
	std::vector<int> freeObjectCells;

	std::vector<int> occupiedSurfaceCells;
	std::vector<int> occupiedObjectCells;

	float heightMax;
	float heightMin;

private:

	int m_curSurfacesSize;
	int m_curObjectsSize;

	void CountFreeCells();
	void CountFreeSurfaceCells();
	void CountFreeObjectCells();
};

#endif // WORLD_H
