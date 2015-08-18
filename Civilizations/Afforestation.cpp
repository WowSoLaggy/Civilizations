#include "stdafx.h"
#include "Weather.h"

void Weather::UpdateAfforestation()
{
	/*for (int i = 0; i < WWIDTH * WHEIGHT; ++i)
	{
		Entity *ent = OBJATP(i);
		if (ent == nullptr)
			TILEP(i)->aff = 0;
		else
			TILEP(i)->aff = ent->blueprint->affBase;
	}*/

	for (int y = 1; y < WHEIGHT - 1; ++y)
	{
		for (int x = 1; x < WWIDTH - 1; ++x)
		{
			tmps[x + y * WWIDTH] = (
				TILE(x - 1, y - 1)->aff + TILE(x + 0, y - 1)->aff + TILE(x + 1, y - 1)->aff +
				TILE(x - 1, y + 0)->aff + TILE(x + 0, y + 0)->aff + TILE(x + 1, y + 0)->aff +
				TILE(x - 1, y + 1)->aff + TILE(x + 0, y + 1)->aff + TILE(x + 1, y + 1)->aff) / 9;
		}
	}

	for (int i = 0; i < WWIDTH * WHEIGHT; ++i)
		TILEP(i)->aff = (OBJATP(i) == nullptr) ? tmps[i] : OBJATP(i)->blueprint->affBase;
}
