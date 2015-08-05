#pragma once

#ifndef ETABLE_H
#define ETABLE_H

#include "Features.h"


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
};


// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=


const std::string resourcesNames[] = {
	"Data\\Grass.png",				/* 0 */
	"Data\\Water.png",				/* 1 */
	"Data\\Desert.png",				/* 2 */
	
	"Data\\Oak_adult.png",			/* 3 */
	"Data\\Oak_dead.png",			/* 4 */
	"Data\\Oak_young.png",			/* 5 */
	
	"Data\\Cursor.png",				/* 6 */
	"Data\\Grid.png",				/* 7 */
	"Data\\Gui_top_1024.png",		/* 8 */
	"Data\\Gui_bottom_1024.png",	/* 9 */
	"Data\\Gui_minimap.png",		/* 10 */
	"Data\\Gui_minimapFrame.png",	/* 11 */
	
	"Data\\Snow.png",				/* 12 */
	"Data\\Ice.png",				/* 13 */
	
	"Data\\Fir_adult.png",			/* 14 */
	"Data\\Fir_dead.png",			/* 15 */
	"Data\\Fir_young.png",			/* 16 */
	
	"Data\\Cactus_adult.png",		/* 17 */
	"Data\\Cactus_dead.png",		/* 18 */
	"Data\\Cactus_young.png",		/* 19 */
	
	"Data\\Mountain_Grass.png",		/* 20 */
	"Data\\Mountain_Snow.png",		/* 21 */
	"Data\\Mountain_Desert.png",	/* 22 */
	
	"Data\\Coast.png",				/* 23 */
	"Data\\Palm_adult.png",			/* 24 */
	"Data\\Palm_dead.png",			/* 25 */
	"Data\\Palm_young.png",			/* 26 */
	"Data\\Oasis.png",				/* 27 */
	"Data\\Mountain_coast.png",		/* 28 */
	"Data\\Mountain_oasis.png",		/* 29 */
	
	"Data\\Tropics.png",			/* 30 */
	"Data\\Savanna.png",			/* 31 */
	"Data\\Tundra.png",				/* 32 */
	"Data\\Mountain_Tundra.png",	/* 33 */
	"Data\\Mountain_Savanna.png",	/* 34 */
	"Data\\Mountain_Tropics.png",	/* 35 */
	
	"Data\\Juniper_adult.png",		/* 36 */
	"Data\\Juniper_dead.png",		/* 37 */
	"Data\\Juniper_young.png",		/* 38 */
	
	"Data\\Baobab_adult.png",		/* 39 */
	"Data\\Baobab_dead.png",		/* 40 */
	"Data\\Baobab_young.png",		/* 41 */

	"Data\\Mountain_Reef.png",		/* 42 */
	"Data\\Mountain_ReefIce.png",	/* 43 */

	"Data\\DeepWater.png",			/* 44 */
	"Data\\Water_fresh.png",		/* 45 */
	"Data\\Gui_top_2048.png",		/* 46 */
	"Data\\Gui_bottom_2048.png",	/* 47 */
};


// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=


const int tiSurface[] = {
	0,	// unknown
	1,	// water
	0,	// grass
	2,	// desert
	12,	// snow
	13,	// ice
	20,	// mnt grass
	21,	// mnt snow
	22,	// mnt desert
	28,	// mnt coast
	29,	// mnt oasis
	33,	// mnt tundra
	34,	// mnt savanna
	35,	// mnt tropics
	23,	// coast
	27,	// oasis
	30,	// tropics
	31,	// savanna
	32,	// tundra
	42,	// mnt reef
	43,	// mnt reef ice
	44,	// deep water
	45,	// water fresh
	13,	// water fresh frozen
	45, // lake
	13, // lake frozen
};


const int mmColors[] = {
	0xFF000000,	// unknown
	0xFF0F45EF,	// water
	0xFF3DCE00,	// grass
	0xFFE68D1F,	// desert
	0xFFEEEEEE,	// snow
	0xFF00FFE5,	// ice
	0xFF000000,	// mnt grass
	0xFF000000,	// mnt snow
	0xFF000000,	// mnt desert
	0xFF000000,	// mnt coast
	0xFF000000,	// mnt oasis
	0xFF000000,	// mnt tundra
	0xFF000000,	// mnt savanna
	0xFF000000,	// mnt tropics
	0xFFFF9523,	// coast
	0xFF007F0E,	// oasis
	0xFF007F0E,	// tropics
	0xFFFF9523,	// savanna
	0xFF636061,	// tundra
	0xFF000000,	// mnt reef
	0xFF000000,	// mnt reef ice
	0xFF0E35DF,	// deep water
	0xFF3F75FF,	// water fresh
	0xFF00FFE5,	// water fresh frozen
	0xFF3F75FF,	// lake
	0xFF00FFE5,	// lake frozen
};


const int featsSurface[] = {
	FEAT_NONE,										// unknown
	FEAT_WATERTILE,									// water
	FEAT_FITFORTREES,								// grass
	FEAT_FITFORTREES,								// desert
	FEAT_FITFORTREES,								// snow
	FEAT_WATERTILE,									// ice
	FEAT_MOUNTAIN,									// mnt grass
	FEAT_MOUNTAIN,									// mnt snow
	FEAT_MOUNTAIN,									// mnt desert
	FEAT_MOUNTAIN,									// mnt coast
	FEAT_MOUNTAIN,									// mnt oasis
	FEAT_MOUNTAIN,									// mnt tundra
	FEAT_MOUNTAIN,									// mnt savanna
	FEAT_MOUNTAIN,									// mnt tropics
	FEAT_FITFORTREES,								// coast
	FEAT_FITFORTREES,								// oasis
	FEAT_FITFORTREES,								// tropics
	FEAT_FITFORTREES,								// savanna
	FEAT_FITFORTREES,								// tundra
	FEAT_MOUNTAIN | FEAT_WATERTILE,					// mnt reef
	FEAT_MOUNTAIN | FEAT_WATERTILE,					// mnt reef ice
	FEAT_WATERTILE,									// deep water
	FEAT_WATERTILE | FEAT_FRESHWATER,				// water fresh
	FEAT_WATERTILE | FEAT_FRESHWATER,				// water fresh frozen
	FEAT_WATERTILE | FEAT_FRESHWATER | FEAT_LAKE,	// lake
	FEAT_WATERTILE | FEAT_FRESHWATER | FEAT_LAKE,	// lake frozen
};

const int tiTrees[] = {
	5,	// Unknown
	5,
	5,
	5,	// Oak
	3,
	4,
	16,	// Fir
	14,
	15,
	19,	// Cactus
	17,
	18,
	26,	// Palm
	24,
	25,
	38,	// Juniper
	36,
	37,
	41,	// Baobab
	39,
	40,
};

const EntityType mntsForSurfaces[] = {
	surf_mountain_grass,	// unknown
	surf_mountain_reef,		// water
	surf_mountain_grass,	// grass
	surf_mountain_desert,	// desert
	surf_mountain_snow,		// snow
	surf_mountain_reefice,	// ice
	surf_mountain_grass,	// mnt grass
	surf_mountain_snow,		// mnt snow
	surf_mountain_desert,	// mnt desert
	surf_mountain_coast,	// mnt coast
	surf_mountain_oasis,	// mnt oasis
	surf_mountain_tundra,	// mnt tundra
	surf_mountain_savanna,	// mnt savanna
	surf_mountain_tropics,	// mnt tropics
	surf_mountain_coast,	// coast
	surf_mountain_oasis,	// oasis
	surf_mountain_tropics,	// tropics
	surf_mountain_savanna,	// savanna
	surf_mountain_tundra,	// tundra
	surf_mountain_reef,		// mnt reef
	surf_mountain_reefice,	// mnt reef ice
	surf_mountain_reef,		// deep water
	surf_mountain_reef,		// water fresh
	surf_mountain_reefice,	// water fresh frozen
	surf_mountain_reef,		// lake
	surf_mountain_reefice,	// lake frozen
};

const std::string descSurfaces[] = {
	"Unknown",				// unknown
	"Water",				// water
	"Grass",				// grass
	"Desert",				// desert
	"Snow",					// snow
	"Ice",					// ice
	"Mountain",				// mnt grass
	"Mountain",				// mnt snow
	"Mountain",				// mnt desert
	"Mountain",				// mnt coast
	"Mountain",				// mnt oasis
	"Mountain",				// mnt tundra
	"Mountain",				// mnt savanna
	"Mountain",				// mnt tropics
	"Coast",				// coast
	"Oasis",				// oasis
	"Tropics",				// tropics
	"Savanna",				// savanna
	"Tundra",				// tundra
	"Reef",					// mnt reef
	"Ice Reef",				// mnt reef ice
	"Deep Water",			// deep water
	"Fresh Water",			// water fresh
	"Frozen Fresh Water",	// water fresh frozen
	"Lake",					// lake
	"Frozen Lake",			// lake frozen
};

const std::string descObjects[] = {
	"Unknown",	// Unknown
	"Oak",		// Oak
	"Fir",		// Fir
	"Cactus",	// Cactus
	"Palm",		// Palm
	"Juniper",	// Juniper
	"Baobab",	// Baobab
};

const float baseSurfProdPen[] = {
	0.00f,	// unknown
	0.00f,	// water
	0.99f,	// grass
	0.90f,	// desert
	0.80f,	// snow
	0.00f,	// ice
	0.95f,	// mnt grass
	0.80f,	// mnt snow
	0.90f,	// mnt desert
	0.99f,	// mnt coast
	0.99f,	// mnt oasis
	0.80f,	// mnt tundra
	0.95f,	// mnt savanna
	0.97f,	// mnt tropics
	0.99f,	// coast
	0.99f,	// oasis
	0.97f,	// tropics
	0.95f,	// savanna
	0.80f,	// tundra
	0.00f,	// mnt reef
	0.00f,	// mnt reef ice
	0.00f,	// deep water
	0.00f,	// water fresh
	0.00f,	// water fresh frozen
	0.00f,	// lake
	0.00f,	// lake frozen
};


class ETables
{
public:

	inline static int GetMmColor(EntityType pType)				{ return mmColors[pType]; }
	inline static int GetTiSurface(EntityType pType)			{ return tiSurface[pType]; }
	inline static int GetFeatsSurface(EntityType pType)			{ return featsSurface[pType]; }
	inline static int GetTiTreeYoung(EntityType pType)			{ return tiTrees[(pType - 100) * 3 + 0]; }
	inline static int GetTiTreeAdult(EntityType pType)			{ return tiTrees[(pType - 100) * 3 + 1]; }
	inline static int GetTiTreeDead(EntityType pType)			{ return tiTrees[(pType - 100) * 3 + 2]; }
	inline static EntityType GetMntForSurface(EntityType pType)	{ return mntsForSurfaces[pType]; }
	inline static std::string GetDescSurface(EntityType pType)	{ return descSurfaces[pType]; }
	inline static std::string GetDescObject(EntityType pType)	{ return descObjects[pType - 100]; }
	inline static float GetBaseSurfProdPen(EntityType pType)	{ return baseSurfProdPen[pType]; }
};

#endif // ETABLE_H
