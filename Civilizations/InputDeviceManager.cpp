#include "stdafx.h"
#include "InputDeviceManager.h"

bool InputDeviceManager::created;

int InputDeviceManager::cursorPositionX;
int InputDeviceManager::cursorPositionY;

IDirectInput8 *InputDeviceManager::DirectInput;
IDirectInputDevice8 *InputDeviceManager::Mouse;
IDirectInputDevice8 *InputDeviceManager::Keyboard;

char InputDeviceManager::KeysPrev[256];
char InputDeviceManager::Keys[256];
DIMOUSESTATE InputDeviceManager::MouseState;
DIMOUSESTATE InputDeviceManager::MouseStatePrev;

void InputDeviceManager::Initialize()
{
	DirectInput = nullptr;
	Mouse = nullptr;
	Keyboard = nullptr;

	created = false;
}

void InputDeviceManager::Dispose()
{
	created = false;

	if (Mouse != nullptr)
	{
		Mouse->Unacquire();
		Mouse->Release();
		Mouse = nullptr;
	}

	if (Keyboard != nullptr)
	{
		Keyboard->Unacquire();
		Keyboard->Release();
		Keyboard = nullptr;
	}

	if (DirectInput != nullptr)
	{
		DirectInput->Release();
		DirectInput = nullptr;
	}
}

void InputDeviceManager::CreateInputDevices()
{
	int res = 0;
	created = false;

	res = DirectInput8Create(RenderDeviceManager::hInstance, DIRECTINPUT_VERSION,
	                   IID_IDirectInput8, (void **)&DirectInput, NULL);
	if ((res != DI_OK) || (DirectInput == nullptr))
		return;

	res = DirectInput->CreateDevice(GUID_SysMouse, &Mouse, NULL);
	if ((res != DI_OK) || (Mouse == nullptr))
		return;
	Mouse->SetDataFormat(&c_dfDIMouse);
	Mouse->SetCooperativeLevel(RenderDeviceManager::hWindow, DISCL_FOREGROUND | DISCL_EXCLUSIVE);
	AcquireMouse();

	res = DirectInput->CreateDevice(GUID_SysKeyboard, &Keyboard,NULL);
	if ((res != DI_OK) || (Keyboard == nullptr))
		return;
	Keyboard->SetDataFormat(&c_dfDIKeyboard);
	Keyboard->SetCooperativeLevel(RenderDeviceManager::hWindow, DISCL_FOREGROUND | DISCL_NONEXCLUSIVE);
	AcquireKeyboard();

	cursorPositionX = RenderDeviceManager::WindowCenterX;
	cursorPositionY = RenderDeviceManager::WindowCenterY;

	created = true;
}

void InputDeviceManager::AcquireKeyboard()
{
	Keyboard->Acquire();
	ZeroMemory(Keys, sizeof(Keys));
}

void InputDeviceManager::AcquireMouse()
{
	Mouse->Acquire();
	ZeroMemory(&MouseState, sizeof(MouseState));
	ZeroMemory(&MouseStatePrev, sizeof(MouseStatePrev));
}

void InputDeviceManager::CheckDevices()
{
	HRESULT hRes = 0;

	memcpy(KeysPrev, Keys, sizeof(Keys));
	memcpy(&MouseStatePrev, &MouseState, sizeof(MouseStatePrev));

	hRes = Keyboard->GetDeviceState(sizeof(Keys), Keys);
	if (hRes != DI_OK) 
		AcquireKeyboard();

	hRes = Mouse->GetDeviceState(sizeof(DIMOUSESTATE), &MouseState);
	if (hRes != DI_OK)
		AcquireMouse();

	cursorPositionX += (int)(MouseState.lX * SENS_MOUSE_X);
	cursorPositionY += (int)(MouseState.lY * SENS_MOUSE_Y);

	cursorPositionX = cursorPositionX < 0 ? 0 : cursorPositionX > RenderDeviceManager::ResolutionWidth - 1 ? RenderDeviceManager::ResolutionWidth - 1 : cursorPositionX;
	cursorPositionY = cursorPositionY < 0 ? 0 : cursorPositionY > RenderDeviceManager::ResolutionHeight - 1 ? RenderDeviceManager::ResolutionHeight - 1 : cursorPositionY;
}

bool InputDeviceManager::KeyDown(int pIndex)
{
	return (!(KeysPrev[pIndex] & 0x80) && (Keys[pIndex] & 0x80));
}

bool InputDeviceManager::KeyUp(int pIndex)
{
	return ((KeysPrev[pIndex] & 0x80) && !(Keys[pIndex] & 0x80));
}

bool InputDeviceManager::KeyPressed(int pIndex)
{
	return ((Keys[pIndex] & 0x80) != 0);
}

bool InputDeviceManager::MouseDown(int pIndex)
{
	return (!(MouseStatePrev.rgbButtons[pIndex] & 0x80) && (MouseState.rgbButtons[pIndex] & 0x80));
}

bool InputDeviceManager::MouseUp(int pIndex)
{
	return ((MouseStatePrev.rgbButtons[pIndex] & 0x80) && !(MouseState.rgbButtons[pIndex] & 0x80));
}

bool InputDeviceManager::MousePressed(int pIndex)
{
	return ((MouseState.rgbButtons[pIndex] & 0x80) != 0);
}
