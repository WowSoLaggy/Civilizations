#pragma once

#ifndef DRAWER_H
#define DRAWER_H

#include "Utils.h"
#include "Constants.h"
#include "RenderDeviceManager.h"
#include "InputDeviceManager.h"
#include "World.h"
#include "Descriptor.h"
#include "ETables.h"
#include "GManager.h"


class Drawer
{
public:

	static int tilesOnScreenX;
	static int tilesOnScreenY;

	static int camPosX() { return m_camPosX; }
	static int camPosY() { return m_camPosY; }

	static void Load();
	static void Unload();
	static void DrawWorld();

	static void UpdateMiniMap();

	static void SetCamPosTopLeft(int pCamPosX, int pCamPosY);
	static void SetCamPosCenter(int pCamPosX, int pCamPosY);
	static void GetSelectedTile(int &pX, int &pY);
	static inline void GetSelectedTileCoord(D3DXVECTOR2 &pV);
	static inline void GetSelectedTileCoord(D3DXVECTOR3 &pV);

private:

	static int m_camPosX;
	static int m_camPosY;

	static int m_camPosXMin;
	static int m_camPosXMax;
	static int m_camPosYMin;
	static int m_camPosYMax;

	static LPD3DXSPRITE m_sprite;
	static LPD3DXLINE m_line;
	static LPD3DXFONT m_font;

	static int m_verticesCount;
	static D3DXVECTOR2 *m_vertices;

	static int m_cursorTIndex;
	static int m_gridTIndex;
	static int m_guiTopTIndex;
	static int m_guiBottomTIndex;
	static int m_guiMinimapTIndex;
	static int m_guiMinimapFrameTIndex;

	static void PrepareGridVertices();
	static void PrepareMinimapFrame();
};


#endif // DRAWER_H
