#include "stdafx.h"
#include "World.h"

World::World()
{
	lSurfaces = nullptr;
	lFloras = nullptr;

	name = "New World";
	width = -1;
	height = -1;

	CountFreeCells();
}

void World::ResizeSurfaces(int pCount)
{
	if (lSurfaces == nullptr)
	{
		lSurfaces = new Entity[pCount];
		m_curSurfacesSize = pCount;
		ZeroMemory(lSurfaces, pCount * sizeof(Entity));

		CountFreeSurfaceCells();
		return;
	}

	if (pCount <= m_curSurfacesSize)
		return;

	Entity *tmp = lSurfaces;
	lSurfaces = new Entity[pCount];
	ZeroMemory(lSurfaces, pCount * sizeof(Entity));
	memcpy(lSurfaces, tmp, m_curSurfacesSize * sizeof(Entity));
	m_curSurfacesSize = pCount;
	delete[] tmp;

	CountFreeSurfaceCells();
}

void World::ResizeFloras(int pCount)
{
	if (lFloras == nullptr)
	{
		lFloras = new Entity[pCount];
		m_curFloraSize = pCount;
		ZeroMemory(lFloras, pCount * sizeof(Entity));

		CountFreeFloraCells();
		return;
	}

	if (pCount <= m_curFloraSize)
		return;

	Entity *tmp = lFloras;
	lFloras = new Entity[pCount];
	ZeroMemory(lFloras, pCount * sizeof(Entity));
	memcpy(lFloras, tmp, m_curFloraSize * sizeof(Entity));
	m_curFloraSize = pCount;
	delete[] tmp;

	CountFreeFloraCells();
}

Entity *World::GetFreeSurfaceCell()
{
	if (freeSurfaceCells.size() == 0)
		ResizeSurfaces(m_curSurfacesSize * 2);

	int cell = freeSurfaceCells[freeSurfaceCells.size() - 1];
	freeSurfaceCells.pop_back();
	occupiedSurfaceCells.push_back(cell);

	return &lSurfaces[cell];
}

Entity *World::GetFreeSurfaceCell(int &pId)
{
	if (freeSurfaceCells.size() == 0)
		ResizeSurfaces(m_curSurfacesSize * 2);

	pId = freeSurfaceCells[freeSurfaceCells.size() - 1];
	freeSurfaceCells.pop_back();
	occupiedSurfaceCells.push_back(pId);

	return &lSurfaces[pId];
}

Entity *World::GetFreeFloraCell()
{
	if (freeFloraCells.size() == 0)
		ResizeFloras(m_curFloraSize * 2);

	int cell = freeFloraCells[freeFloraCells.size() - 1];
	freeFloraCells.pop_back();
	occupiedFloraCells.push_back(cell);

	return &lFloras[cell];
}

Entity *World::GetFreeFloraCell(int &pId)
{
	if (freeFloraCells.size() == 0)
		ResizeFloras(m_curFloraSize * 2);

	pId = freeFloraCells[freeFloraCells.size() - 1];
	freeFloraCells.pop_back();
	occupiedFloraCells.push_back(pId);

	return &lFloras[pId];
}

void World::CountFreeCells()
{
	CountFreeSurfaceCells();
	CountFreeFloraCells();
}

void World::CountFreeSurfaceCells()
{
	freeSurfaceCells.clear();
	occupiedSurfaceCells.clear();

	for (int i = 0; i < m_curSurfacesSize; ++i)
	{
		if (lSurfaces[i].id == 0)
			freeSurfaceCells.push_back(i);
		else
			occupiedSurfaceCells.push_back(i);
	}
}

void World::CountFreeFloraCells()
{
	freeFloraCells.clear();
	occupiedFloraCells.clear();

	for (int i = 0; i < m_curFloraSize; ++i)
	{
		if (lFloras[i].id == 0)
			freeFloraCells.push_back(i);
		else
			occupiedFloraCells.push_back(i);
	}
}

void World::DeleteSurface(int pCell)
{
	if (pCell < 0)
		return;

	lSurfaces[pCell].id = 0;
	freeSurfaceCells.push_back(pCell);

	std::vector<int>::iterator it = std::find(occupiedSurfaceCells.begin(), occupiedSurfaceCells.end(), pCell);
	if (it != occupiedSurfaceCells.end())
		occupiedSurfaceCells.erase(it);
}

void World::DeleteFlora(int pCell)
{
	if (pCell < 0)
		return;

	lFloras[pCell].id = 0;
	freeFloraCells.push_back(pCell);

	std::vector<int>::iterator it = std::find(occupiedFloraCells.begin(), occupiedFloraCells.end(), pCell);
	if (it != occupiedFloraCells.end())
		occupiedFloraCells.erase(it);
}
