#include "stdafx.h"
#include "GManager.h"

#include "Drawer.h"
#include "Game.h"


bool GManager::showGrid = false;
bool GManager::showGui = true;

RECT GManager::guiTurnRect;
RECT GManager::guiDescRect;

void GManager::Load()
{
	guiTurnRect.left = 10;
	guiTurnRect.top = 3;
	guiTurnRect.right = 1000;
	guiTurnRect.bottom = 50;
	
	guiDescRect.left = 133;
	guiDescRect.top = RenderDeviceManager::ResolutionHeight - 85;
	guiDescRect.right = guiDescRect.left + 1000;
	guiDescRect.bottom = guiDescRect.top + 100;
}

void GManager::UnLoad()
{
}

bool GManager::CheckGuiClick(int pButton)
{
	if (!showGui)
		return false;

	int x = InputDeviceManager::cursorPositionX;
	int y = InputDeviceManager::cursorPositionY;

	if ((y < 32) || ((y > RenderDeviceManager::ResolutionHeight - 96) && (x >= 128)))
		return true;
	
	// Check for click on the minimap
	if ((pButton == MBUTTON_LEFT) && (3 < x) && (x < 118) && (RenderDeviceManager::ResolutionHeight - 119 < y) && (y < RenderDeviceManager::ResolutionHeight - 3))
	{
		x = (int)((float)(x - 4) / 114 * (WWIDTH * TILESIZE));
		y = (int)((float)(y - (RenderDeviceManager::ResolutionHeight - 119)) / 114 * (WHEIGHT * TILESIZE));

		Drawer::SetCamPosCenter(x, y);

		return true;
	}

	if ((x < 128) && (y > RenderDeviceManager::ResolutionHeight - 128))
		return true;

	return false;
}
