#include "stdafx.h"
#include "Weather.h"

void Weather::UpdateAfforestation()
{
	ZeroMemory(afforestation, w3 * h3 * sizeof(float));

	for (int y = 0; y < WHEIGHT; ++y)
	{
		for (int x = 0; x < WWIDTH; ++x)
		{
			Entity *ent = OBJAT(x, y);
			if (ent == nullptr)
				continue;

			if (EManager::IsBush(*ent))
				afforestation[(x / 3) + (y / 3) * w3] += AFFORESTCOST_BUSH;
			else if (EManager::IsTree(*ent))
				afforestation[(x / 3) + (y / 3) * w3] += AFFORESTCOST_TREE;
		}
	}

	int count = 0;
	for (int y = 1; y < h3 - 1; ++y)
	{
		for (int x = 1; x < w3 - 1; ++x)
		{
			tmp[count] = (
				afforestation[(x - 1) + (y - 1) * w3] + afforestation[(x + 0) + (y - 1) * w3] + afforestation[(x + 1) + (y - 1) * w3] +
				afforestation[(x - 1) + (y + 0) * w3] + afforestation[(x + 0) + (y + 0) * w3] + afforestation[(x + 1) + (y + 0) * w3] +
				afforestation[(x - 1) + (y + 1) * w3] + afforestation[(x + 0) + (y + 1) * w3] + afforestation[(x + 1) + (y + 1) * w3]) / 9;
			++count;
		}
	}

	memcpy(afforestation, tmp, w3 * h3 * sizeof(float));
}
