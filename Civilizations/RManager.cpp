#include "stdafx.h"
#include "RManager.h"


std::vector<LPDIRECT3DTEXTURE9> RManager::textures;


void RManager::LoadResources()
{
	HRESULT hRes;

	std::vector<std::string> resNamesVector(begin(resourcesNames), end(resourcesNames));

	textures.resize(resNamesVector.size());

	for (unsigned int i = 0; i < resNamesVector.size(); ++i)
		hRes = D3DXCreateTextureFromFile(RenderDeviceManager::RenderDevice, resNamesVector[i].c_str(), &textures[i]);
}

void RManager::UnloadResources()
{
	for (unsigned int i = 0; i < textures.size(); ++i)
	{
		if (textures[i] != nullptr)
			textures[i]->Release();
	}

	textures.clear();
}
