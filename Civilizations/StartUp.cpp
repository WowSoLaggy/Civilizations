#include "stdafx.h"

#include "Game.h"
#include "RenderDeviceManager.h"
#include "RManager.h"


LRESULT __stdcall WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);


int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	// Register win class

	WNDCLASS wc;
	wc.style = CS_OWNDC;
	wc.lpfnWndProc = WndProc;
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.hbrBackground = (HBRUSH)(6);
	wc.hCursor = LoadCursor(hInstance, IDC_ARROW);
	wc.hIcon = LoadIcon(hInstance, IDI_APPLICATION);
	wc.hInstance = hInstance;
	wc.lpszClassName = "Ships";
	wc.lpszMenuName = nullptr;
	RegisterClass(&wc);

	Game::Initialize();
	RenderDeviceManager::Initialize();
	RenderDeviceManager::hInstance = hInstance;

	RenderDeviceManager::hWindow = CreateWindowEx(0, "Ships", "Ships", WS_VISIBLE | WS_POPUP,
		(RenderDeviceManager::ScreenWidth - RenderDeviceManager::ResolutionWidth) / 2, (RenderDeviceManager::ScreenHeight - RenderDeviceManager::ResolutionHeight) / 2,
		RenderDeviceManager::ResolutionWidth, RenderDeviceManager::ResolutionHeight,
		nullptr, nullptr, hInstance, nullptr);
	ShowWindow(RenderDeviceManager::hWindow, nCmdShow);
	UpdateWindow(RenderDeviceManager::hWindow);

	int res = Game::Start();
	res = Game::MainLoop();
	Game::Dispose();

	Drawer::Unload();
	WorldUpdater::Unload();
	GManager::UnLoad();
	RManager::UnloadResources();
	RenderDeviceManager::Dispose();

	UnregisterClass("Ships", hInstance);

	return res;
}

LRESULT __stdcall WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	switch (msg)
	{
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	}
	return DefWindowProc(hWnd,msg,wParam,lParam);
}
