#pragma once

#ifndef RENDERDEVICEMANAGER_H
#define RENDERDEVICEMANAGER_H

class RenderDeviceManager
{
public:

	static HINSTANCE hInstance;
	static HWND hWindow;
	static MSG msg;

	static int ScreenWidth;
	static int ScreenHeight;

	const static int ResolutionWidth = 1280;
	const static int ResolutionHeight = 1024;

	const static int WindowCenterX = ResolutionWidth / 2;
	const static int WindowCenterY = ResolutionHeight / 2;

	static bool Created;
	static D3DPRESENT_PARAMETERS PresentPars;
	static IDirect3D9 *Direct3d;
	static IDirect3DDevice9 *RenderDevice;

	static LPDIRECT3DSURFACE9 DefaultRenderTarget;
	static D3DSURFACE_DESC DefaultRenderTargetDesc;

	static void Initialize();
	static void Dispose();

	static void CreateRenderDevice();
};

#endif // RENDERDEVICEMANAGER_H
