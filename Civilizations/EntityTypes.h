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

	// Objects

	obj_oak					= 101,
	obj_fir					= 102,
	obj_cactus				= 103,
	obj_palm				= 104,
	obj_juniper				= 105,
	obj_baobab				= 106,
	obj_raspberry			= 107,

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
