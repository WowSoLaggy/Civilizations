#pragma once

#ifndef GMANAGER_H
#define GMANAGER_H

#include "RenderDeviceManager.h"
#include "InputDeviceManager.h"


class GManager
{
public:

	static bool showGrid;
	static bool showGui;

	static RECT guiTurnRect;
	static RECT guiDescRect;

	static void Load();
	static void UnLoad();

	static bool CheckGuiClick(int pButton);
};


#endif // GMANAGER_H
