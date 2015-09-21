#include "stdafx.h"
#include "World.h"

World::World()
{
	lsurfaces = nullptr;
	lobjects = nullptr;

	name = "New World";
	width = -1;
	height = -1;

	CountFreeCells();
}

void World::ResizeSurfaces(int pCount)
{
	if (lsurfaces == nullptr)
	{
		lsurfaces = new Entity[pCount];
		m_curSurfacesSize = pCount;
		ZeroMemory(lsurfaces, pCount * sizeof(Entity));

		CountFreeSurfaceCells();
		return;
	}

	if (pCount <= m_curSurfacesSize)
		return;

	Entity *tmp = lsurfaces;
	lsurfaces = new Entity[pCount];
	ZeroMemory(lsurfaces, pCount * sizeof(Entity));
	memcpy(lsurfaces, tmp, m_curSurfacesSize * sizeof(Entity));
	m_curSurfacesSize = pCount;
	delete[] tmp;

	CountFreeSurfaceCells();
}

void World::ResizeObjects(int pCount)
{
	if (lobjects == nullptr)
	{
		lobjects = new Entity[pCount];
		m_curObjectsSize = pCount;
		ZeroMemory(lobjects, pCount * sizeof(Entity));

		CountFreeObjectCells();
		return;
	}

	if (pCount <= m_curObjectsSize)
		return;

	Entity *tmp = lobjects;
	lobjects = new Entity[pCount];
	ZeroMemory(lobjects, pCount * sizeof(Entity));
	memcpy(lobjects, tmp, m_curObjectsSize * sizeof(Entity));
	m_curObjectsSize = pCount;
	delete[] tmp;

	CountFreeObjectCells();
}

Entity *World::GetFreeSurfaceCell()
{
	if (freeSurfaceCells.size() == 0)
		ResizeSurfaces(m_curSurfacesSize * 2);

	int cell = freeSurfaceCells[freeSurfaceCells.size() - 1];
	freeSurfaceCells.pop_back();
	occupiedSurfaceCells.push_back(cell);

	return &lsurfaces[cell];
}

Entity *World::GetFreeSurfaceCell(int &pId)
{
	if (freeSurfaceCells.size() == 0)
		ResizeSurfaces(m_curSurfacesSize * 2);

	pId = freeSurfaceCells[freeSurfaceCells.size() - 1];
	freeSurfaceCells.pop_back();
	occupiedSurfaceCells.push_back(pId);

	return &lsurfaces[pId];
}

Entity *World::GetFreeObjectCell()
{
	if (freeObjectCells.size() == 0)
		ResizeObjects(m_curObjectsSize * 2);

	int cell = freeObjectCells[freeObjectCells.size() - 1];
	freeObjectCells.pop_back();
	occupiedObjectCells.push_back(cell);

	return &lobjects[cell];
}

Entity *World::GetFreeObjectCell(int &pId)
{
	if (freeObjectCells.size() == 0)
		ResizeObjects(m_curObjectsSize * 2);

	pId = freeObjectCells[freeObjectCells.size() - 1];
	freeObjectCells.pop_back();
	occupiedObjectCells.push_back(pId);

	return &lobjects[pId];
}

void World::CountFreeCells()
{
	CountFreeSurfaceCells();
	CountFreeObjectCells();
}

void World::CountFreeSurfaceCells()
{
	freeSurfaceCells.clear();
	occupiedSurfaceCells.clear();

	for (int i = 0; i < m_curSurfacesSize; ++i)
	{
		if (lsurfaces[i].id == 0)
			freeSurfaceCells.push_back(i);
		else
			occupiedSurfaceCells.push_back(i);
	}
}

void World::CountFreeObjectCells()
{
	freeObjectCells.clear();
	occupiedObjectCells.clear();

	for (int i = 0; i < m_curObjectsSize; ++i)
	{
		if (lobjects[i].id == 0)
			freeObjectCells.push_back(i);
		else
			occupiedObjectCells.push_back(i);
	}
}

void World::DeleteSurface(int pCell)
{
	if (pCell < 0)
		return;

	lsurfaces[pCell].id = 0;
	freeSurfaceCells.push_back(pCell);

	std::vector<int>::iterator it = std::find(occupiedSurfaceCells.begin(), occupiedSurfaceCells.end(), pCell);
	if (it != occupiedSurfaceCells.end())
		occupiedSurfaceCells.erase(it);
}

void World::DeleteObject(int pCell)
{
	if (pCell < 0)
		return;

	lobjects[pCell].id = 0;
	freeObjectCells.push_back(pCell);

	std::vector<int>::iterator it = std::find(occupiedObjectCells.begin(), occupiedObjectCells.end(), pCell);
	if (it != occupiedObjectCells.end())
		occupiedObjectCells.erase(it);
}
