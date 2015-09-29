#pragma once

#ifndef ENTITYTYPES_H
#define ENTITYTYPES_H


enum EntityType : unsigned char
{
	// General

	type_unknown			= 0,
	surf_unknown			= 0,
	obj_unknown				= 0,

	// Surfaces

	surf_water				= 1,
	surf_grass				= 2,
	surf_desert				= 3,
	surf_snow				= 4,
	surf_ice				= 5,
	surf_mountain_grass		= 6,
	surf_mountain_snow		= 7,
	surf_mountain_desert	= 8,
	surf_mountain_coast		= 9,
	surf_mountain_oasis		= 10,
	surf_mountain_tundra	= 11,
	surf_mountain_savanna	= 12,
	surf_mountain_tropics	= 13,
	surf_coast				= 14,
	surf_oasis				= 15,
	surf_tropics			= 16,
	surf_savanna			= 17,
	surf_tundra				= 18,
	surf_mountain_reef		= 19,
	surf_mountain_reefice	= 20,
	surf_deepwater			= 21,
	surf_waterfresh			= 22,
	surf_waterfreshfrozen	= 23,
	surf_lake				= 24,
	surf_lakefrozen			= 25,
	surf_hill_grass			= 26,
	surf_hill_snow			= 27,
	surf_hill_desert		= 28,
	surf_hill_coast			= 29,
	surf_hill_oasis			= 30,
	surf_hill_tundra		= 31,
	surf_hill_savanna		= 32,
	surf_hill_tropics		= 33,

	// Flora

	obj_oak					= 51,
	obj_fir					= 52,
	obj_cactus				= 53,
	obj_palm				= 54,
	obj_juniper				= 55,
	obj_baobab				= 56,
	obj_acacia				= 57,

	obj_raspberry			= 58,
	obj_camelthorn			= 59,
	obj_dwarfbirch			= 60,
	obj_aloe				= 61,
	obj_fern				= 62,

	// Fauna

	obj_hare				= 151,
	obj_fox					= 152,
	obj_monkey				= 153,
	obj_fish				= 154,
	obj_horse				= 155,
	obj_crocodile			= 156,
	obj_whale				= 157,
	obj_bear_polar			= 158,
	obj_pinguin				= 159,
	obj_seal				= 160,
	obj_deer				= 161,
	obj_bear				= 162,

	type_end
};


enum EntityState : unsigned char
{
	// General

	state_unknown			= 0,
	state_usual				= 0,

	// Trees

	state_young				= 1,
	state_adult				= 2,
	state_dead				= 3,
};


#endif // ENTITYTYPES_H
