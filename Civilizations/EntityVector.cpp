#include "stdafx.h"
#include "EntityVector.h"

EntityVector::EntityVector()
{
	lEntities = nullptr;
	m_curSize = 0;
}

void EntityVector::Resize(int pCount)
{
	if (lEntities == nullptr)
	{
		lEntities = new Entity[pCount];
		m_curSize = pCount;
		ZeroMemory(lEntities, pCount * sizeof(Entity));

		CountFreeCells();
		return;
	}

	if (pCount <= m_curSize)
		return;

	Entity *tmp = lEntities;
	lEntities = new Entity[pCount];
	ZeroMemory(lEntities, pCount * sizeof(Entity));
	memcpy(lEntities, tmp, m_curSize * sizeof(Entity));
	m_curSize = pCount;
	delete[] tmp;

	CountFreeCells();
}

Entity *EntityVector::GetFreeCell()
{
	if (m_curSize == 0)
		Resize(1024);
	else if (freeCells.size() == 0)
		Resize(m_curSize * 2);

	int cell = freeCells[freeCells.size() - 1];
	freeCells.pop_back();
	occupiedCells.push_back(cell);

	return &lEntities[cell];
}

Entity *EntityVector::GetFreeCell(int &pId)
{
	if (m_curSize == 0)
		Resize(1024);
	else if (freeCells.size() == 0)
		Resize(m_curSize * 2);

	pId = freeCells[freeCells.size() - 1];
	freeCells.pop_back();
	occupiedCells.push_back(pId);

	return &lEntities[pId];
}

void EntityVector::CountFreeCells()
{
	freeCells.clear();
	occupiedCells.clear();

	for (int i = 0; i < m_curSize; ++i)
	{
		if (lEntities[i].id == 0)
			freeCells.push_back(i);
		else
			occupiedCells.push_back(i);
	}
}

void EntityVector::DeleteEntity(int pCell)
{
	if (pCell < 0)
		return;

	lEntities[pCell].id = 0;
	freeCells.push_back(pCell);

	std::vector<int>::iterator it = std::find(occupiedCells.begin(), occupiedCells.end(), pCell);
	if (it != occupiedCells.end())
		occupiedCells.erase(it);
}

void EntityVector::Dispose()
{
	delete[] lEntities;
	lEntities = nullptr;
}
