#include "stdafx.h"
#include "Weather.h"

#include "Game.h"

float *Weather::tmp = nullptr;


void Weather::Load()
{
	tmp = new float[Game::world->width * Game::world->height];
}

void Weather::UnLoad()
{
	delete[] tmp;
}
