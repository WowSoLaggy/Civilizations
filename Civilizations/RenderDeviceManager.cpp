#include "stdafx.h"
#include "RenderDeviceManager.h"

HINSTANCE RenderDeviceManager::hInstance;
HWND RenderDeviceManager::hWindow;
MSG RenderDeviceManager::msg;

int RenderDeviceManager::ScreenWidth;
int RenderDeviceManager::ScreenHeight;

bool RenderDeviceManager::Created;
D3DPRESENT_PARAMETERS RenderDeviceManager::PresentPars;
IDirect3D9 *RenderDeviceManager::Direct3d;
IDirect3DDevice9 *RenderDeviceManager::RenderDevice;

LPDIRECT3DSURFACE9 RenderDeviceManager::DefaultRenderTarget;
D3DSURFACE_DESC RenderDeviceManager::DefaultRenderTargetDesc;

void RenderDeviceManager::Initialize()
{
	RECT desktop;
	const HWND hDesktop = GetDesktopWindow();
	GetWindowRect(hDesktop, &desktop);
	ScreenWidth = desktop.right;
	ScreenHeight = desktop.bottom;

	Direct3d = nullptr;
	RenderDevice = nullptr;

	Created = false;
}

void RenderDeviceManager::Dispose()
{
	Created = false;

	if (RenderDevice != nullptr)
	{
		RenderDevice->Release();
		RenderDevice = nullptr;
	}

	if (Direct3d != nullptr)
	{
		Direct3d->Release();
		Direct3d = nullptr;
	}
}

void RenderDeviceManager::CreateRenderDevice()
{
	int res = 0;

	Created = false;

	Direct3d = Direct3DCreate9(D3D_SDK_VERSION);
	if (Direct3d == nullptr)
		return;

	ZeroMemory(&PresentPars, sizeof(PresentPars));
	PresentPars.EnableAutoDepthStencil = true;
	PresentPars.AutoDepthStencilFormat = D3DFMT_D24X8;
	PresentPars.BackBufferWidth = ResolutionWidth;
	PresentPars.BackBufferHeight = ResolutionHeight;
	PresentPars.BackBufferFormat = D3DFMT_A8R8G8B8;
	PresentPars.BackBufferCount = 1;
	PresentPars.SwapEffect = D3DSWAPEFFECT_DISCARD;
	//PresentPars.PresentationInterval = D3DPRESENT_INTERVAL_IMMEDIATE;
	PresentPars.PresentationInterval = D3DPRESENT_INTERVAL_ONE;
	//PresentPars.FullScreen_RefreshRateInHz = 60;
	PresentPars.hDeviceWindow = hWindow;
	PresentPars.Windowed = true;

	res = Direct3d->CreateDevice(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, hWindow,
	                  D3DCREATE_HARDWARE_VERTEXPROCESSING | D3DCREATE_PUREDEVICE,
	                  &PresentPars, &RenderDevice);
	if ((res != D3D_OK) || (RenderDevice == nullptr))
		return;

	RenderDevice->SetRenderState(D3DRS_LIGHTING, FALSE);
	RenderDevice->SetRenderState(D3DRS_ALPHABLENDENABLE, true);
	RenderDevice->SetRenderState(D3DRS_SRCBLEND , D3DBLEND_SRCALPHA);
	RenderDevice->SetRenderState(D3DRS_DESTBLEND, D3DBLEND_INVSRCALPHA);

	RenderDevice->GetRenderTarget(0, &DefaultRenderTarget);
	DefaultRenderTarget->GetDesc(&DefaultRenderTargetDesc);

	Created = true;
}
