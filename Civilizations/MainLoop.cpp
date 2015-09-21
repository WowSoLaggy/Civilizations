#include "stdafx.h"
#include "Game.h"

int Game::MainLoop()
{
	HRESULT hRes = 0;
	int res = 0;

	RECT rect;
	SetRect(&rect, 10, 10, 200, 50);

	int fps = 0;
	int frameCount = 0;

	double dt = 0;
	double dtAcc = 0;

	LARGE_INTEGER accTimePrecStart;
	LARGE_INTEGER accTimePrecEnd;
	LARGE_INTEGER accTimePrecFreq;
	QueryPerformanceFrequency(&accTimePrecFreq);

	while (true)
	{
		QueryPerformanceCounter(&accTimePrecStart);

		if (PeekMessage(&RenderDeviceManager::msg, NULL, 0, 0, PM_REMOVE))
		{
			if (RenderDeviceManager::msg.message == WM_QUIT)
				break;
			TranslateMessage(&RenderDeviceManager::msg);
			DispatchMessage(&RenderDeviceManager::msg);
		}

		// Check render device
		if (!RenderDeviceManager::Created)
		{
			if (!OnNullRenderDevice())
				break;
		}

		// Check input device
		if (!InputDeviceManager::created)
		{
			InputDeviceManager::CreateInputDevices();
			if (!InputDeviceManager::created)
				break;
		}

		// Check inputs
		InputDeviceManager::CheckDevices();
		HandleKeyboard();
		HandleMouse();

		// Start scene drawing
		EnterCriticalSection(&worldLocker);
		RenderDeviceManager::RenderDevice->SetRenderTarget(0, RenderDeviceManager::DefaultRenderTarget);
		hRes = RenderDeviceManager::RenderDevice->Clear(0, NULL, D3DCLEAR_TARGET | D3DCLEAR_ZBUFFER, D3DCOLOR_ARGB(255, 0, 0, 0), 1.0f, 0);
		hRes = RenderDeviceManager::RenderDevice->BeginScene();

		if (WORLD != nullptr)
			Drawer::DrawWorld();

		// End scene drawing
		hRes = RenderDeviceManager::RenderDevice->EndScene();
		hRes = RenderDeviceManager::RenderDevice->Present(NULL, NULL, NULL, NULL);
		LeaveCriticalSection(&worldLocker);

		QueryPerformanceCounter(&accTimePrecEnd);
		dt = (double)(accTimePrecEnd.QuadPart - accTimePrecStart.QuadPart);
		dt /= accTimePrecFreq.QuadPart;

		frameCount++;
		dtAcc += dt;
		if (dtAcc > 1)
		{
			fps = frameCount;
			dtAcc -= 1;
			frameCount = 0;
		}
	}

	return RenderDeviceManager::msg.wParam;
}
