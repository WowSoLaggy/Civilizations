#include "stdafx.h"
#include "Game.h"

void Game::HandleKeyboard()
{
	D3DXVECTOR3 moveDir = D3DXVECTOR3(0, 0, 0);

	if (InputDeviceManager::KeyDown(DIK_ESCAPE))
		PostQuitMessage(0);
	if ((InputDeviceManager::KeyDown(DIK_RETURN)) || (InputDeviceManager::KeyDown(DIK_LBRACKET)) || (InputDeviceManager::KeyDown(DIK_RBRACKET)) || (InputDeviceManager::KeyPressed(DIK_P)))
		WorldUpdater::MakeTurn();
	if (InputDeviceManager::KeyDown(DIK_1))
		WorldUpdater::MakeTurn(10);
	if (InputDeviceManager::KeyDown(DIK_2))
		WorldUpdater::MakeTurn(25);
	if (InputDeviceManager::KeyDown(DIK_3))
		WorldUpdater::MakeTurn(50);
	if (InputDeviceManager::KeyDown(DIK_4))
		WorldUpdater::MakeTurn(75);
	if (InputDeviceManager::KeyDown(DIK_5))
		WorldUpdater::MakeTurn(100);
	if (InputDeviceManager::KeyDown(DIK_6))
		WorldUpdater::MakeTurn(125);
	if (InputDeviceManager::KeyDown(DIK_7))
		WorldUpdater::MakeTurn(150);
	if (InputDeviceManager::KeyDown(DIK_G))
		GManager::showGrid = !GManager::showGrid;
	if (InputDeviceManager::KeyDown(DIK_H))
		GManager::showGui = !GManager::showGui;
	if (InputDeviceManager::KeyPressed(DIK_A))
		Drawer::SetCamPosTopLeft((int)(Drawer::camPosX() - SENS_KB_SCROLL_X), Drawer::camPosY());
	if (InputDeviceManager::KeyPressed(DIK_D))
		Drawer::SetCamPosTopLeft((int)(Drawer::camPosX() + SENS_KB_SCROLL_X), Drawer::camPosY());
	if (InputDeviceManager::KeyPressed(DIK_W))
		Drawer::SetCamPosTopLeft(Drawer::camPosX(), (int)(Drawer::camPosY() - SENS_KB_SCROLL_Y));
	if (InputDeviceManager::KeyPressed(DIK_S))
		Drawer::SetCamPosTopLeft(Drawer::camPosX(), (int)(Drawer::camPosY() + SENS_KB_SCROLL_Y));

	if (InputDeviceManager::KeyDown(DIK_LEFT))
	{
		if (selectedTileX > 0)
			--selectedTileX;
	}
	if (InputDeviceManager::KeyDown(DIK_RIGHT))
	{
		if ((selectedTileX != -1) && (selectedTileX < WWIDTH - 1))
			++selectedTileX;
	}
	if (InputDeviceManager::KeyDown(DIK_UP))
	{
		if ((selectedTileX != -1) && (selectedTileY > 0))
			--selectedTileY;
	}
	if (InputDeviceManager::KeyDown(DIK_DOWN))
	{
		if ((selectedTileX != -1) && (selectedTileY < WHEIGHT - 1))
			++selectedTileY;
	}
}
