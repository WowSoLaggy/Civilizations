#pragma once

#ifndef ENTITYVECTOR_H
#define ENTITYVECTOR_H


#include "Entity.h"


class EntityVector
{
public:

	EntityVector();

	std::vector<int> freeCells;
	std::vector<int> occupiedCells;

	Entity *lEntities;

	Entity *GetFreeCell();
	Entity *GetFreeCell(int &pId);

	void Resize(int pCount);
	void DeleteEntity(int pCell);
	void Dispose();

	void CountFreeCells();

	Entity & operator [] (int pIndex) const { return lEntities[pIndex]; }

private:

	int m_curSize;
};


#endif // ENTITYVECTOR_H
