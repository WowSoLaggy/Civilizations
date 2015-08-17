#pragma once

#ifndef RMANAGER_H
#define RMANAGER_H

#include "ResourcesNames.h"
#include "RenderDeviceManager.h"


class RManager
{
public:

	static std::vector<LPDIRECT3DTEXTURE9> textures;

	static void LoadResources();
	static void UnloadResources();
};


#endif // RMANAGER_H
