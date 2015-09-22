#pragma once

#ifndef WORLDSERIALIZATOR_H
#define WORLDSERIALIZATOR_H


#include "World.h"


class WorldSerializator
{
public:

	static bool SaveWorld(World &pWorld);
	static bool LoadWorld(World &pWorld, std::string pWorldName);
};


#endif // WORLDSERIALIZATOR_H
