#pragma once

#ifndef RMANAGER_H
#define RMANAGER_H

#include "RenderDeviceManager.h"
#include "ETables.h"


class RManager
{
public:

	static std::vector<LPDIRECT3DTEXTURE9> textures;

	static void LoadResources();
	static void UnloadResources();
};


#endif // RMANAGER_H
