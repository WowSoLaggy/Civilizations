#pragma once

#ifndef WORLDCONSTANTS_H
#define WORLDCONSTANTS_H


static int TREE_DIE_CHANCE			= 10;
static int TREE_REPRODUCT_RAD		= 5;

static float HUMIDITY_PENALTY		= 0.99f;
static float HUMIDITY_BORDER		= 50;
static float PRODUCTIVITY_PENALTY	= 0.999f;

static float TEMPERATURE_PENALTY	= 0.98f;
static float TEMPERATURE_MIN		= (-30.0f);
static float TEMPERATURE_MAX		= (50.0f);
static float TEMPERATURE_RANGE		= (abs(TEMPERATURE_MIN) + abs(TEMPERATURE_MAX));

static double DEEPWATER_DEPTH		= 200;
static double MOUNTAIN_HEIGHT_KOEF	= 0.5;
static double HILL_HEIGHT_KOEF		= 0.3;


#endif // WORLDCONSTANTS_H
