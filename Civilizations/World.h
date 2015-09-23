#pragma once

#ifndef WORLD_H
#define WORLD_H


#include "Tile.h"


class World
{
public:

	World();

	std::string name;

	int width;
	int height;

	std::vector<Tile> tiles;

	std::vector<int> freeSurfaceCells;
	std::vector<int> freeFloraCells;

	std::vector<int> occupiedSurfaceCells;
	std::vector<int> occupiedFloraCells;

	Entity *lSurfaces;
	Entity *lFloras;

	Entity *GetFreeSurfaceCell();
	Entity *GetFreeSurfaceCell(int &pId);

	Entity *GetFreeFloraCell();
	Entity *GetFreeFloraCell(int &pId);

	void ResizeSurfaces(int pCount);
	void ResizeFloras(int pCount);

	void DeleteSurface(int pCell);
	void DeleteFlora(int pCell);

private:

	int m_curSurfacesSize;
	int m_curFloraSize;

	void CountFreeCells();
	void CountFreeSurfaceCells();
	void CountFreeFloraCells();
};


#endif // WORLD_H
