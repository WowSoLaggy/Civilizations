#pragma once

#ifndef INPUTDEVICEMANAGER_H
#define INPUTDEVICEMANAGER_H

#include "Constants.h"
#include "RenderDeviceManager.h"

#define MBUTTON_LEFT	0
#define MBUTTON_RIGHT	1


class InputDeviceManager
{
public:

	static bool created;

	static int cursorPositionX;
	static int cursorPositionY;

	static void CreateInputDevices();
	static void CheckDevices();

	static bool KeyDown(int pIndex);
	static bool KeyUp(int pIndex);
	static bool KeyPressed(int pIndex);

	static bool MouseDown(int pIndex);
	static bool MouseUp(int pIndex);
	static bool MousePressed(int pIndex);

private:

	static IDirectInput8 *DirectInput;
	static IDirectInputDevice8 *Mouse;
	static IDirectInputDevice8 *Keyboard;

	static char KeysPrev[256];
	static char Keys[256];
	static DIMOUSESTATE MouseState;
	static DIMOUSESTATE MouseStatePrev;

	static void Initialize();
	static void Dispose();
	
	static void AcquireKeyboard();
	static void AcquireMouse();
};


#endif // INPUTDEVICEMANAGER_H
