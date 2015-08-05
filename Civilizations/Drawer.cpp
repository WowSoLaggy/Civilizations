#include "stdafx.h"
#include "Drawer.h"

#include "Game.h"

int Drawer::m_camPosX;
int Drawer::m_camPosY;

int Drawer::m_camPosXMin;
int Drawer::m_camPosXMax;
int Drawer::m_camPosYMin;
int Drawer::m_camPosYMax;

int Drawer::tilesOnScreenX;
int Drawer::tilesOnScreenY;

LPD3DXSPRITE Drawer::m_sprite = nullptr;
LPD3DXLINE Drawer::m_line = nullptr;
LPD3DXFONT Drawer::m_font = nullptr;

int Drawer::m_verticesCount;
D3DXVECTOR2 *Drawer::m_vertices;

int Drawer::m_cursorTIndex = 6;
int Drawer::m_gridTIndex = 7;
int Drawer::m_guiTopTIndex = 46;
int Drawer::m_guiBottomTIndex = 47;
int Drawer::m_guiMinimapTIndex = 10;
int Drawer::m_guiMinimapFrameTIndex = 11;


void Drawer::DrawWorld()
{
	D3DXVECTOR3 pos(0, 0, 0);
	
	// Draw game world if any
	if (Game::world != nullptr)
	{
		m_sprite->Begin(0);

		// Tiles

		int startX = m_camPosX / TILESIZE;
		int startY = m_camPosY / TILESIZE;

		for (int y = startY; y < startY + tilesOnScreenY + 2; ++y)
		{
			for (int x = startX; x < startX + tilesOnScreenX + 1; ++x)
			{
				pos.x = (float)((x - startX) * TILESIZE - m_camPosX % TILESIZE);
				pos.y = (float)((y - startY) * TILESIZE - m_camPosY % TILESIZE);

				if ((x < 0) || (y < 0) || (x >= WWIDTH) || (y >= WHEIGHT))
					continue;

				if (TILE(x, y)->surfaceCell != -1)
					m_sprite->Draw(RManager::textures[SURFAT(x, y)->ti], 0, 0, &pos, D3DCOLOR_ARGB(255, 255, 255, 255));
				if (TILE(x, y)->objectCell != -1)
					m_sprite->Draw(RManager::textures[OBJAT(x, y)->ti], 0, 0, &pos, D3DCOLOR_ARGB(255, 255, 255, 255));
			}
		}

		// Tile under cursor
		GetSelectedTileCoord(pos);
		m_sprite->Draw(RManager::textures[m_gridTIndex], 0, 0, &pos, D3DCOLOR_ARGB(75, 255, 255, 255));

		// Selected tile
		if (Game::selectedTileX != -1)
		{
			pos.x = (float)(Game::selectedTileX * TILESIZE - m_camPosX);
			pos.y = (float)(Game::selectedTileY * TILESIZE - m_camPosY);
			m_sprite->Draw(RManager::textures[m_gridTIndex], 0, 0, &pos, D3DCOLOR_ARGB(150, 255, 255, 255));
		}

		m_sprite->End();

		// Grid
		if (GManager::showGrid)
		{
			PrepareGridVertices();

			m_line->Begin();
			m_line->Draw(m_vertices, m_verticesCount, D3DCOLOR_ARGB(100, 0, 0, 0));
			m_line->End();
		}
	}

	// GUI
	if (GManager::showGui)
	{
		m_sprite->Begin(0);

		pos.x = 0;
		pos.y = 0;
		m_sprite->Draw(RManager::textures[m_guiTopTIndex], 0, 0, &pos, D3DCOLOR_ARGB(255, 255, 255, 255));
		pos.x = 4;
		pos.y = RenderDeviceManager::ResolutionHeight - 118;
		m_sprite->Draw(RManager::textures[m_guiMinimapTIndex], 0, 0, &pos, D3DCOLOR_ARGB(255, 255, 255, 255));
		pos.x = (float)(4 + m_camPosX * MINIMAPTEXTURESIZE / (WWIDTH * TILESIZE));
		pos.y = (float)(RenderDeviceManager::ResolutionHeight - 118 + m_camPosY * MINIMAPTEXTURESIZE / (WHEIGHT * TILESIZE));
		m_sprite->Draw(RManager::textures[m_guiMinimapFrameTIndex], 0, 0, &pos, D3DCOLOR_ARGB(255, 255, 255, 255));
		pos.x = 0;
		pos.y = RenderDeviceManager::ResolutionHeight - 128;
		m_sprite->Draw(RManager::textures[m_guiBottomTIndex], 0, 0, &pos, D3DCOLOR_ARGB(255, 255, 255, 255));

		m_sprite->End();

		// Fonts
		if (Game::world != nullptr)
		{
			// Current turn
			std::string str = "Turn: ";
			str = str.append(std::to_string(WorldUpdater::currentTurn));
			m_font->DrawText(0, str.c_str(), -1, &GManager::guiTurnRect, 0, D3DCOLOR_ARGB(255, 255, 255, 255));

			// Object description
			Tile *selTile = Game::GetSelectedTile();
			if (selTile != nullptr)
			{
				Descriptor::GetTileDescription(*selTile, str, Game::selectedTileX, Game::selectedTileY);
				m_font->DrawText(0, str.c_str(), -1, &GManager::guiDescRect, 0, D3DCOLOR_ARGB(255, 255, 255, 255));
			}
		}
	}

	m_sprite->Begin(0);

	// Cursor
	pos.x = (float)InputDeviceManager::cursorPositionX;
	pos.y = (float)InputDeviceManager::cursorPositionY;
	m_sprite->Draw(RManager::textures[m_cursorTIndex], 0, 0, &pos, D3DCOLOR_ARGB(255, 255, 255, 255));

	m_sprite->End();
}

void Drawer::SetCamPosTopLeft(int pCamPosX, int pCamPosY)
{
	m_camPosX = SATURATE(pCamPosX, m_camPosXMin, m_camPosXMax);
	m_camPosY = SATURATE(pCamPosY, m_camPosYMin, m_camPosYMax);
}

void Drawer::SetCamPosCenter(int pCamPosX, int pCamPosY)
{
	pCamPosX -= tilesOnScreenX * TILESIZE / 2;
	pCamPosY -= tilesOnScreenY * TILESIZE / 2;

	m_camPosX = SATURATE(pCamPosX, m_camPosXMin, m_camPosXMax);
	m_camPosY = SATURATE(pCamPosY, m_camPosYMin, m_camPosYMax);
}

void Drawer::GetSelectedTile(int &pX, int &pY)
{
	pX = (m_camPosX + InputDeviceManager::cursorPositionX) / TILESIZE;
	pY = (m_camPosY + InputDeviceManager::cursorPositionY) / TILESIZE;
}

void Drawer::GetSelectedTileCoord(D3DXVECTOR2 &pV)
{
	pV.x = (float)((InputDeviceManager::cursorPositionX / TILESIZE) * TILESIZE - m_camPosX % TILESIZE);
	pV.y = (float)((InputDeviceManager::cursorPositionY / TILESIZE) * TILESIZE - m_camPosY % TILESIZE);
}

void Drawer::GetSelectedTileCoord(D3DXVECTOR3 &pV)
{
	int shiftX = m_camPosX % TILESIZE;
	int shiftY = m_camPosY % TILESIZE;

	pV.x = (float)((InputDeviceManager::cursorPositionX + shiftX) / TILESIZE * TILESIZE - shiftX);
	pV.y = (float)((InputDeviceManager::cursorPositionY + shiftY) / TILESIZE * TILESIZE - shiftY);
}

void Drawer::PrepareGridVertices()
{
	m_verticesCount = 0;

	int shiftX = m_camPosX % TILESIZE;
	int shiftY = m_camPosY % TILESIZE;

	// Vertical grid lines
	for (int i = 0; i < RenderDeviceManager::ResolutionWidth + 2 * TILESIZE; i += TILESIZE)
	{
		if (m_verticesCount % 4 == 0)
		{
			m_vertices[m_verticesCount] = D3DXVECTOR2((float)(i - shiftX), -1);
			m_vertices[m_verticesCount + 1] = D3DXVECTOR2((float)(i - shiftX), (float)RenderDeviceManager::ResolutionHeight);
		}
		else
		{
			m_vertices[m_verticesCount + 1] = D3DXVECTOR2((float)(i - shiftX), -1);
			m_vertices[m_verticesCount] = D3DXVECTOR2((float)(i - shiftX), (float)RenderDeviceManager::ResolutionHeight);
		}
		m_verticesCount += 2;
	}
	// Horizontal grid lines
	for (int i = 0; i < RenderDeviceManager::ResolutionHeight +  2 * TILESIZE; i += TILESIZE)
	{
		if (m_verticesCount % 4 == 0)
		{
			m_vertices[m_verticesCount] = D3DXVECTOR2(-1, (float)(i - shiftY));
			m_vertices[m_verticesCount + 1] = D3DXVECTOR2((float)RenderDeviceManager::ResolutionWidth, (float)(i - shiftY));
		}
		else
		{
			m_vertices[m_verticesCount + 1] = D3DXVECTOR2(-1, (float)(i - shiftY));
			m_vertices[m_verticesCount] = D3DXVECTOR2((float)RenderDeviceManager::ResolutionWidth, (float)(i - shiftY));
		}
		m_verticesCount += 2;
	}
}

void Drawer::Load()
{
	m_vertices = new D3DXVECTOR2[(RenderDeviceManager::ResolutionWidth / TILESIZE + 2) * 2 + (RenderDeviceManager::ResolutionHeight / TILESIZE + 2) * 2];
	PrepareGridVertices();

	HRESULT hRes;
	hRes = D3DXCreateSprite(RenderDeviceManager::RenderDevice, &m_sprite);
	hRes = D3DXCreateLine(RenderDeviceManager::RenderDevice, &m_line);

	tilesOnScreenX = RenderDeviceManager::ResolutionWidth / TILESIZE;
	tilesOnScreenY = RenderDeviceManager::ResolutionHeight / TILESIZE;

	m_camPosXMin = 0;
	m_camPosYMin = -TILESIZE;
	m_camPosXMax = m_camPosXMin + WWIDTH * TILESIZE - RenderDeviceManager::ResolutionWidth;
	m_camPosYMax = m_camPosYMin + WHEIGHT * TILESIZE - RenderDeviceManager::ResolutionHeight + TILESIZE * 4;

	SetCamPosCenter(WWIDTH * TILESIZE / 2, WHEIGHT * TILESIZE / 2);

	// Font
	D3DXCreateFont(RenderDeviceManager::RenderDevice, 20, 0, FW_BOLD, 1, FALSE, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, 
		ANTIALIASED_QUALITY, DEFAULT_PITCH | FF_DONTCARE, "Verdana", &m_font);

	UpdateMiniMap();
	PrepareMinimapFrame();
}

void Drawer::Unload()
{
	m_font->Release();
	m_line->Release();
	m_sprite->Release();

	if (m_vertices != nullptr)
		delete[] m_vertices;
}

void Drawer::UpdateMiniMap()
{
	D3DLOCKED_RECT rect;
	HRESULT hRes = RManager::textures[m_guiMinimapTIndex]->LockRect(0, &rect, 0, 0);

	int *mmScan0 = (int *)rect.pBits;
	for (int j = 0; j < MINIMAPTEXTURESIZE; ++j)
	{
		for (int i = 0; i < MINIMAPTEXTURESIZE; ++i)
		{
			int x = i * WWIDTH / MINIMAPTEXTURESIZE;
			int y = j * WHEIGHT / MINIMAPTEXTURESIZE;

			mmScan0[i] = ETables::GetMmColor(SURFAT(x, y)->type);
		}

		mmScan0 += rect.Pitch / sizeof(int);
	}

	RManager::textures[m_guiMinimapTIndex]->UnlockRect(0);
}

void Drawer::PrepareMinimapFrame()
{
	int frameWidth = tilesOnScreenX * MINIMAPTEXTURESIZE / WWIDTH;
	int frameHeight = tilesOnScreenY * MINIMAPTEXTURESIZE / WHEIGHT;

	if (frameWidth > MINIMAPTEXTURESIZE)
		frameWidth = MINIMAPTEXTURESIZE;
	if (frameHeight > MINIMAPTEXTURESIZE)
		frameHeight = MINIMAPTEXTURESIZE;

	D3DLOCKED_RECT rect;
	RManager::textures[m_guiMinimapFrameTIndex]->LockRect(0, &rect, 0, 0);

	int *mmfStart = (int *)rect.pBits;

	memset(mmfStart, MINIMAP_COLOR_FRAME, frameWidth * sizeof(int));
	memset(mmfStart + frameHeight * rect.Pitch / sizeof(int), MINIMAP_COLOR_FRAME, frameWidth * sizeof(int));

	for (int i = 0; i < frameHeight + 1; ++i)
	{
		*(mmfStart + i * rect.Pitch / sizeof(int)) = MINIMAP_COLOR_FRAME;
		*(mmfStart + frameWidth + i * rect.Pitch / sizeof(int)) = MINIMAP_COLOR_FRAME;
	}

	RManager::textures[m_guiMinimapFrameTIndex]->UnlockRect(0);
}
