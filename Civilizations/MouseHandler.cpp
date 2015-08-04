#include "stdafx.h"
#include "Game.h"

void Game::HandleMouse()
{
	if (InputDeviceManager::cursorPositionX == 0)
		Drawer::SetCamPosTopLeft((int)(Drawer::camPosX() - SENS_MOUSE_SCROLL_X), Drawer::camPosY());
	else if (InputDeviceManager::cursorPositionX == RenderDeviceManager::ResolutionWidth - 1)
		Drawer::SetCamPosTopLeft((int)(Drawer::camPosX() + SENS_MOUSE_SCROLL_X), Drawer::camPosY());

	if (InputDeviceManager::cursorPositionY == 0)
		Drawer::SetCamPosTopLeft(Drawer::camPosX(), (int)(Drawer::camPosY() - SENS_MOUSE_SCROLL_Y));
	else if (InputDeviceManager::cursorPositionY == RenderDeviceManager::ResolutionHeight - 1)
		Drawer::SetCamPosTopLeft(Drawer::camPosX(), (int)(Drawer::camPosY() + SENS_MOUSE_SCROLL_Y));

	if (InputDeviceManager::MouseDown(MBUTTON_LEFT))
	{
		if (!GManager::CheckGuiClick(MBUTTON_LEFT))
			Drawer::GetSelectedTile(selectedTileX, selectedTileY);
	}
	if (InputDeviceManager::MouseDown(MBUTTON_RIGHT))
	{
		if (!GManager::CheckGuiClick(MBUTTON_RIGHT))
			selectedTileX = -1;
	}
}
