#include "stdafx.h"
#include "WorldCreator.h"

void WorldCreator::GenerateWorld(World &pWorld, int pSizeX, int pSizeY)
{
	pWorld.width = pSizeX;
	pWorld.height = pSizeY;

	int w = pWorld.width;
	int h = pWorld.height;
	int w2 = pWorld.width / 2;
	int h2 = pWorld.height / 2;

	pWorld.ResizeSurfaces(w * h);
	pWorld.ResizeObjects(w * h / 100);

	int count = 0;
	EntityType *tiles = new EntityType[w * h];

	// Generate heightmap
	float *heights = new float[w * h];
	for (int y = 0; y < h; ++y)
	{
		for (int x = 0; x < w; ++x)
		{
			heights[x + y * w] = -10;

			if (x < 32)
				heights[x + y * w] -= (32 - x) * 100;
			if (y < 32)
				heights[x + y * w] -= (32 - y) * 100;
			if (x > pWorld.width - 32)
				heights[x + y * w] -= (x - (pWorld.width - 32)) * 100;
			if (y > pWorld.height - 32)
				heights[x + y * w] -= (y - (pWorld.height - 32)) * 100;
		}
	}

	// Create random height map
	for (int hr = ((w + h) / 2) / 10; hr >= 3; --hr)
	{
		for (int i = 0; i < hr; ++i)
		{
			int hx = RAND(w - hr * 4, (int)(hr * 2));
			int hy = RAND(h - hr * 4, (int)(hr * 2));
			int h = RAND(103, -50);

			for (int y = hy - hr; y < hy + hr; ++y)
			{
				for (int x = hx - hr; x < hx + hr; ++x)
				{
					if (DIST(x - hx, y - hy) < SQR(hr))
						heights[x + y * w] += h;
				}
			}
		}
	}

	// Make smooth
	float *tmp = new float[w * h];
	for (int n = 0; n < 3; ++n)
	{
		for (int y = 1; y < h - 1; ++y)
		{
			for (int x = 1; x < w - 1; ++x)
			{
				tmp[x + y * w] =
					heights[(x - 1) + (y - 1) * w] + heights[(x + 0) + (y - 1) * w] + heights[(x + 1) + (y - 1) * w] +
					heights[(x - 1) + (y + 0) * w] + heights[(x + 0) + (y + 0) * w] + heights[(x + 1) + (y + 0) * w] +
					heights[(x - 1) + (y + 1) * w] + heights[(x + 0) + (y + 1) * w] + heights[(x + 1) + (y + 1) * w];
				tmp[x + y * w] /= 9;
			}

			tmp[0 + y * w] = tmp[1 + y * w];
			tmp[(w - 1) + y * w] = tmp[(w - 2) + y * w];
		}
		memcpy(tmp, tmp + w, w * sizeof(float));
		memcpy(tmp + (h - 1) * w, tmp + (h - 2) * w, w * sizeof(float));
		memcpy(heights, tmp, w * h * sizeof(float));
	}
	delete[] tmp;

	// Find min and max values
	pWorld.heightMin = 10e5;
	pWorld.heightMax = -10e5;
	for (int i = 0; i < w * h; ++i)
	{
		if (heights[i] > pWorld.heightMax)
			pWorld.heightMax = heights[i];
		if (heights[i] < pWorld.heightMin)
			pWorld.heightMin = heights[i];
	}

	// Place water-grass-mountains
	for (int y = 0; y < h; ++y)
	{
		for (int x = 0; x < w; ++x)
		{
			if (heights[x + y * w] >= pWorld.heightMax * 0.5)
				tiles[x + y * w] = surf_mountain_grass;
			else if (heights[x + y * w] >= 0)
				tiles[x + y * w] = surf_grass;
			else if (heights[x + y * w] >= -DEEPWATER_DEPTH)
				tiles[x + y * w] = surf_water;
			else
				tiles[x + y * w] = surf_deepwater;
		}
	}

	// Remove lonely water or grass tiles
	for (int y = 1; y < h; ++y)
	{
		for (int x = 1; x < w; ++x)
		{
			EntityType t = tiles[x + y * w];
			if ((t == surf_water) || (t == surf_grass))
			{
				if (t == surf_water)
				{
					if ((tiles[(x - 1) + (y + 0) * w] == surf_grass) && (tiles[(x + 1) + (y + 0) * w] == surf_grass) &&
						(tiles[(x + 0) + (y - 1) * w] == surf_grass) && (tiles[(x + 0) + (y + 1) * w] == surf_grass))
						tiles[x + y * w] = surf_grass;

					// And place some reef in the water by the way
					if ((heights[x + y * w] >= -DEEPWATER_DEPTH) && (RAND(100, 0) == 0))
						tiles[x + y * w] = surf_mountain_reef;
				}
				else
				{
					if ((tiles[(x - 1) + (y + 0) * w] == surf_water) && (tiles[(x + 1) + (y + 0) * w] == surf_water) &&
						(tiles[(x + 0) + (y - 1) * w] == surf_water) && (tiles[(x + 0) + (y + 1) * w] == surf_water))
						tiles[x + y * w] = surf_mountain_reef;
				}
			}
		}
	}

	bool *seas = new bool[w * h];
	ZeroMemory(seas, w * h * sizeof(bool));
	memset(seas, 1, w * sizeof(bool));
	memset(seas + w * h - w, 1, w * sizeof(bool));
	int errs = 1;
	while (errs != 0)
	{
		errs = 0;

		for (int y = 1; y < h - 1; ++y)
		{
			seas[0 + y * w] = true;

			for (int x = 1; x < w - 1; ++x)
			{
				if ((seas[x + y * w]) || (!EManager::IsWaterTile(tiles[x + y * w])))
					continue;

				if ((seas[(x + 1) + (y + 0) * w]) ||
					(seas[(x - 1) + (y + 0) * w]) ||
					(seas[(x + 0) + (y + 1) * w]) ||
					(seas[(x + 0) + (y - 1) * w]))
				{
					seas[x + y * w] = true;
					errs++;
				}
			}

			seas[w - 1 + y * w] = true;
		}
	}

	for (int i = 0; i < w * h; ++i)
	{
		if ((!seas[i]) && (EManager::IsWaterTile(tiles[i])))
			tiles[i] = surf_lake;
	}

	// Rivers
	bool flag = false;
	count = (int)((w + h) / 2 / 10);
	for (int i = 0; i < count; ++i)
	{
		flag = false;

		int x = RAND(w - 20 * 2, 20);
		int y = RAND(h - 20 * 2, 20);

		if (heights[x + y * w] < 5)
		{
			// Bad position for a river
			--i;
			continue;
		}

		CheckRiverTile(x, y, tiles, heights, w);
	}

	// Widen rivers
	EntityType *tilesTmp = new EntityType[w * h];
	memcpy(tilesTmp, tiles, w * h * sizeof (EntityType));
	int r = 3;
	for (int y = r; y < h - r; ++y)
	{
		for (int x = r; x < w - r; ++x)
		{
			if (tilesTmp[x + y * w] == surf_waterfresh)
			{
				for (int yy = -r; yy < r + 1; ++yy)
				{
					for (int xx = -r; xx < r + 1; ++xx)
					{
						if (DIST(xx, yy) <= SQR(r))
							tiles[(x + xx) + (y + yy) * w] = surf_waterfresh;
					}
				}
			}
		}
	}
	delete[] tilesTmp;

	// World tiles
	pWorld.tiles = new Tile[w * h];
	for (int y = 0; y < h; ++y)
	{
		for (int x = 0; x < w; ++x)
		{
			EManager::CreateSurface(tiles[x + y * w], x, y);
			pWorld.tiles[x + y * w].humidity = 0;
			pWorld.tiles[x + y * w].temperature = 23;
			pWorld.tiles[x + y * w].height = heights[x + y * w];
			pWorld.tiles[x + y * w].productivity = 0;
		}
	}

	delete[] tiles;
	delete[] heights;

	// Randomly seed some trees
	/*int treeCount = 0;
	int attempts = 0;
	while ((treeCount < (w * h / 100)) && (attempts < (w * h / 300 * 20)))
	{
		++attempts;

		int x = rand() % w;
		int y = rand() % h;

		if (!EManager::IsFitForTrees(*SURF(pWorld.tiles[x + y * w].surfaceCell)))
			continue;
		if (pWorld.tiles[x + y * w].objectCell != -1)
			continue;

		int age = (rand() % 30) + 5;

		if (EManager::IsEntityType(*SURF(pWorld.tiles[x + y * w].surfaceCell), surf_grass))
			EManager::CreateTree(obj_tree, x, y, age);
		
		++treeCount;
	}*/
}

void WorldCreator::DisposeWorld(World &pWorld)
{
	delete[] pWorld.lsurfaces;
	delete[] pWorld.lobjects;
	delete[] pWorld.tiles;

	pWorld.lsurfaces = nullptr;
	pWorld.lobjects = nullptr;
	pWorld.tiles = nullptr;
}

void WorldCreator::CheckRiverTile(int pX, int pY, EntityType *pTiles, float *pHeights, int pW)
{
	int minX;
	int minY;
	int lastX = pX - 1;
	int lastY = pY;
	int xx;
	int yy;

	while (true)
	{
		pTiles[pX + pY * pW] = surf_waterfresh;

		float minH = std::numeric_limits<float>::max();

		xx = pX;
		yy = pY - 1;
		if ((pTiles[xx + yy * pW] != surf_waterfresh) && (pHeights[xx + yy * pW] < minH))
		{
			minH = pHeights[xx + yy * pW];
			minX = xx;
			minY = yy;
		}

		xx = pX;
		yy = pY + 1;
		if ((pTiles[xx + yy * pW] != surf_waterfresh) && (pHeights[xx + yy * pW] < minH))
		{
			minH = pHeights[xx + yy * pW];
			minX = xx;
			minY = yy;
		}

		xx = pX - 1;
		yy = pY;
		if ((pTiles[xx + yy * pW] != surf_waterfresh) && (pHeights[xx + yy * pW] < minH))
		{
			minH = pHeights[xx + yy * pW];
			minX = xx;
			minY = yy;
		}

		xx = pX + 1;
		yy = pY;
		if ((pTiles[xx + yy * pW] != surf_waterfresh) && (pHeights[xx + yy * pW] < minH))
		{
			minH = pHeights[xx + yy * pW];
			minX = xx;
			minY = yy;
		}

		// Sea
		if (minH < 0)
			return;

		// Surrounded by river
		if (minH == std::numeric_limits<float>::max())
		{
			int dx = pX - lastX;
			int dy = pY - lastY;
			while (pTiles[pX + pY * pW] == surf_waterfresh)
			{
				pX += dx;
				pY += dy;
				lastX += dx;
				lastY += dy;
			}

			continue;
			//return;
		}

		// Local minima
		if (minH > pHeights[pX + pY * pW])
		{
			pHeights[minX + minY * pW] -= 5;
			if (pHeights[minX + minY * pW] < 0)
				pHeights[minX + minY * pW] = 0;
		}
		else
		{
			lastX = pX;
			lastY = pY;
			pX = minX;
			pY = minY;
		}
	}
}
