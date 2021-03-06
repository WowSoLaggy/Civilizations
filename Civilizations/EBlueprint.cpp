#include "stdafx.h"
#include "EBlueprint.h"

EBlueprint EBlueprint::blueprints[type_end];


EBlueprint::EBlueprint()
{
	Clear();
}

void EBlueprint::Clear()
{
	type = type_unknown;

	tis.clear();
	feats = 0;
	mmColor = 0x00000000;
	description = "";
	nativeSurfs.clear();
	nativeMnts.clear();
	nativeHills.clear();
	baseProdPen = 0;
	affBase = 0;
	affMin = 0;
	affMax = 0;
	ageAdulthood = 0;
	ageOldness = 0;
	ageDecay = 0;
	chanceToGrow = 0;
	chanceToReproduce = 0;
	faunationBase = 0;
	faunationMin = 0;
	faunationMax = 0;
}


void EBlueprint::InitBlueprints()
{
	EBlueprint bp;

	// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
	// SURFACES
	// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-

	bp.type = surf_water;
	bp.tis = { 1, 0, 0, 0 };
	bp.feats = FEAT_WATERTILE;
	bp.mmColor = 0xFF0F45EF;
	bp.description = "Water";
	bp.nativeSurfs = {};
	bp.nativeMnts = { surf_mountain_reef };
	bp.nativeHills = {};
	bp.baseProdPen = 0;
	bp.affBase = 0;
	bp.affMin = 0;
	bp.affMax = 0;
	bp.ageAdulthood = 0;
	bp.ageOldness = 0;
	bp.ageDecay = 0;
	bp.chanceToGrow = 0;
	bp.chanceToReproduce = 0;
	bp.faunationBase = 0;
	bp.faunationMin = 0;
	bp.faunationMax = 0;
	blueprints[bp.type] = bp;


	bp.type = surf_grass;
	bp.tis = { 2, 0, 0, 0 };
	bp.feats = FEAT_FITFORTREES;
	bp.mmColor = 0xFF3DCE00;
	bp.description = "Grass";
	bp.nativeSurfs = {};
	bp.nativeMnts = { surf_mountain_grass };
	bp.nativeHills = { surf_hill_grass };
	bp.baseProdPen = 0.99f;
	bp.affBase = 0;
	bp.affMin = 0;
	bp.affMax = 0;
	bp.ageAdulthood = 0;
	bp.ageOldness = 0;
	bp.ageDecay = 0;
	bp.chanceToGrow = 0;
	bp.chanceToReproduce = 0;
	bp.faunationBase = 0;
	bp.faunationMin = 0;
	bp.faunationMax = 0;
	blueprints[bp.type] = bp;


	bp.type = surf_desert;
	bp.tis = { 3, 0, 0, 0 };
	bp.feats = FEAT_FITFORTREES;
	bp.mmColor = 0xFFE68D1F;
	bp.description = "Desert";
	bp.nativeSurfs = {};
	bp.nativeMnts = { surf_mountain_desert };
	bp.nativeHills = { surf_hill_desert };
	bp.baseProdPen = 0.90f;
	bp.affBase = 0;
	bp.affMin = 0;
	bp.affMax = 0;
	bp.ageAdulthood = 0;
	bp.ageOldness = 0;
	bp.ageDecay = 0;
	bp.chanceToGrow = 0;
	bp.chanceToReproduce = 0;
	bp.faunationBase = 0;
	bp.faunationMin = 0;
	bp.faunationMax = 0;
	blueprints[bp.type] = bp;


	bp.type = surf_snow;
	bp.tis = { 13, 0, 0, 0 };
	bp.feats = FEAT_FITFORTREES;
	bp.mmColor = 0xFFEEEEEE;
	bp.description = "Snow";
	bp.nativeSurfs = {};
	bp.nativeMnts = { surf_mountain_snow };
	bp.nativeHills = { surf_hill_snow };
	bp.baseProdPen = 0.80f;
	bp.affBase = 0;
	bp.affMin = 0;
	bp.affMax = 0;
	bp.ageAdulthood = 0;
	bp.ageOldness = 0;
	bp.ageDecay = 0;
	bp.chanceToGrow = 0;
	bp.chanceToReproduce = 0;
	bp.faunationBase = 0;
	bp.faunationMin = 0;
	bp.faunationMax = 0;
	blueprints[bp.type] = bp;


	bp.type = surf_ice;
	bp.tis = { 14, 0, 0, 0 };
	bp.feats = FEAT_WATERTILE;
	bp.mmColor = 0xFF00FFE5;
	bp.description = "Ice";
	bp.nativeSurfs = {};
	bp.nativeMnts = { surf_mountain_reefice };
	bp.nativeHills = {};
	bp.baseProdPen = 0;
	bp.affBase = 0;
	bp.affMin = 0;
	bp.affMax = 0;
	bp.ageAdulthood = 0;
	bp.ageOldness = 0;
	bp.ageDecay = 0;
	bp.chanceToGrow = 0;
	bp.chanceToReproduce = 0;
	bp.faunationBase = 0;
	bp.faunationMin = 0;
	bp.faunationMax = 0;
	blueprints[bp.type] = bp;


	bp.type = surf_mountain_grass;
	bp.tis = { 21, 0, 0, 0 };
	bp.feats = FEAT_MOUNTAIN;
	bp.mmColor = 0xFF000000;
	bp.description = "Grass Mountain";
	bp.nativeSurfs = {};
	bp.nativeMnts = { surf_mountain_grass };
	bp.nativeHills = { surf_hill_grass };
	bp.baseProdPen = 0.95f;
	bp.affBase = 0;
	bp.affMin = 0;
	bp.affMax = 0;
	bp.ageAdulthood = 0;
	bp.ageOldness = 0;
	bp.ageDecay = 0;
	bp.chanceToGrow = 0;
	bp.chanceToReproduce = 0;
	bp.faunationBase = 0;
	bp.faunationMin = 0;
	bp.faunationMax = 0;
	blueprints[bp.type] = bp;


	bp.type = surf_mountain_snow;
	bp.tis = { 22, 0, 0, 0 };
	bp.feats = FEAT_MOUNTAIN;
	bp.mmColor = 0xFF000000;
	bp.description = "Snow Mountain";
	bp.nativeSurfs = {};
	bp.nativeMnts = { surf_mountain_snow };
	bp.nativeHills = { surf_hill_snow };
	bp.baseProdPen = 0.80f;
	bp.affBase = 0;
	bp.affMin = 0;
	bp.affMax = 0;
	bp.ageAdulthood = 0;
	bp.ageOldness = 0;
	bp.ageDecay = 0;
	bp.chanceToGrow = 0;
	bp.chanceToReproduce = 0;
	bp.faunationBase = 0;
	bp.faunationMin = 0;
	bp.faunationMax = 0;
	blueprints[bp.type] = bp;


	bp.type = surf_mountain_desert;
	bp.tis = { 23, 0, 0, 0 };
	bp.feats = FEAT_MOUNTAIN;
	bp.mmColor = 0xFF000000;
	bp.description = "Desert Mountain";
	bp.nativeSurfs = {};
	bp.nativeMnts = { surf_mountain_desert };
	bp.nativeHills = { surf_hill_desert };
	bp.baseProdPen = 0.90f;
	bp.affBase = 0;
	bp.affMin = 0;
	bp.affMax = 0;
	bp.ageAdulthood = 0;
	bp.ageOldness = 0;
	bp.ageDecay = 0;
	bp.chanceToGrow = 0;
	bp.chanceToReproduce = 0;
	bp.faunationBase = 0;
	bp.faunationMin = 0;
	bp.faunationMax = 0;
	blueprints[bp.type] = bp;


	bp.type = surf_mountain_coast;
	bp.tis = { 29, 0, 0, 0 };
	bp.feats = FEAT_MOUNTAIN;
	bp.mmColor = 0xFF000000;
	bp.description = "Cliff";
	bp.nativeSurfs = {};
	bp.nativeMnts = { surf_mountain_coast };
	bp.nativeHills = { surf_hill_coast };
	bp.baseProdPen = 0.99f;
	bp.affBase = 0;
	bp.affMin = 0;
	bp.affMax = 0;
	bp.ageAdulthood = 0;
	bp.ageOldness = 0;
	bp.ageDecay = 0;
	bp.chanceToGrow = 0;
	bp.chanceToReproduce = 0;
	bp.faunationBase = 0;
	bp.faunationMin = 0;
	bp.faunationMax = 0;
	blueprints[bp.type] = bp;


	bp.type = surf_mountain_oasis;
	bp.tis = { 30, 0, 0, 0 };
	bp.feats = FEAT_MOUNTAIN;
	bp.mmColor = 0xFF000000;
	bp.description = "Oasis Mountain";
	bp.nativeSurfs = {};
	bp.nativeMnts = { surf_mountain_oasis };
	bp.nativeHills = { surf_hill_oasis };
	bp.baseProdPen = 0.99f;
	bp.affBase = 0;
	bp.affMin = 0;
	bp.affMax = 0;
	bp.ageAdulthood = 0;
	bp.ageOldness = 0;
	bp.ageDecay = 0;
	bp.chanceToGrow = 0;
	bp.chanceToReproduce = 0;
	bp.faunationBase = 0;
	bp.faunationMin = 0;
	bp.faunationMax = 0;
	blueprints[bp.type] = bp;


	bp.type = surf_mountain_tundra;
	bp.tis = { 34, 0, 0, 0 };
	bp.feats = FEAT_MOUNTAIN;
	bp.mmColor = 0xFF000000;
	bp.description = "Tundra Mountain";
	bp.nativeSurfs = {};
	bp.nativeMnts = { surf_mountain_tundra };
	bp.nativeHills = { surf_hill_tundra };
	bp.baseProdPen = 0.80f;
	bp.affBase = 0;
	bp.affMin = 0;
	bp.affMax = 0;
	bp.ageAdulthood = 0;
	bp.ageOldness = 0;
	bp.ageDecay = 0;
	bp.chanceToGrow = 0;
	bp.chanceToReproduce = 0;
	bp.faunationBase = 0;
	bp.faunationMin = 0;
	bp.faunationMax = 0;
	blueprints[bp.type] = bp;


	bp.type = surf_mountain_savanna;
	bp.tis = { 35, 0, 0, 0 };
	bp.feats = FEAT_MOUNTAIN;
	bp.mmColor = 0xFF000000;
	bp.description = "Savanna Mountain";
	bp.nativeSurfs = {};
	bp.nativeMnts = { surf_mountain_savanna };
	bp.nativeHills = { surf_hill_savanna };
	bp.baseProdPen = 0.95f;
	bp.affBase = 0;
	bp.affMin = 0;
	bp.affMax = 0;
	bp.ageAdulthood = 0;
	bp.ageOldness = 0;
	bp.ageDecay = 0;
	bp.chanceToGrow = 0;
	bp.chanceToReproduce = 0;
	bp.faunationBase = 0;
	bp.faunationMin = 0;
	bp.faunationMax = 0;
	blueprints[bp.type] = bp;


	bp.type = surf_mountain_tropics;
	bp.tis = { 36, 0, 0, 0 };
	bp.feats = FEAT_MOUNTAIN;
	bp.mmColor = 0xFF000000;
	bp.description = "Tropics Mountain";
	bp.nativeSurfs = {};
	bp.nativeMnts = { surf_mountain_tropics };
	bp.nativeHills = { surf_hill_tropics };
	bp.baseProdPen = 0.97f;
	bp.affBase = 0;
	bp.affMin = 0;
	bp.affMax = 0;
	bp.ageAdulthood = 0;
	bp.ageOldness = 0;
	bp.ageDecay = 0;
	bp.chanceToGrow = 0;
	bp.chanceToReproduce = 0;
	bp.faunationBase = 0;
	bp.faunationMin = 0;
	bp.faunationMax = 0;
	blueprints[bp.type] = bp;


	bp.type = surf_coast;
	bp.tis = { 27, 0, 0, 0 };
	bp.feats = FEAT_FITFORTREES;
	bp.mmColor = 0xFFFF9523;
	bp.description = "Coast";
	bp.nativeSurfs = {};
	bp.nativeMnts = { surf_mountain_coast };
	bp.nativeHills = { surf_hill_coast };
	bp.baseProdPen = 0.99f;
	bp.affBase = 0;
	bp.affMin = 0;
	bp.affMax = 0;
	bp.ageAdulthood = 0;
	bp.ageOldness = 0;
	bp.ageDecay = 0;
	bp.chanceToGrow = 0;
	bp.chanceToReproduce = 0;
	bp.faunationBase = 0;
	bp.faunationMin = 0;
	bp.faunationMax = 0;
	blueprints[bp.type] = bp;


	bp.type = surf_oasis;
	bp.tis = { 28, 0, 0, 0 };
	bp.feats = FEAT_FITFORTREES;
	bp.mmColor = 0xFF007F0E;
	bp.description = "Oasis";
	bp.nativeSurfs = {};
	bp.nativeMnts = { surf_mountain_oasis };
	bp.nativeHills = { surf_hill_oasis };
	bp.baseProdPen = 0.99f;
	bp.affBase = 0;
	bp.affMin = 0;
	bp.affMax = 0;
	bp.ageAdulthood = 0;
	bp.ageOldness = 0;
	bp.ageDecay = 0;
	bp.chanceToGrow = 0;
	bp.chanceToReproduce = 0;
	bp.faunationBase = 0;
	bp.faunationMin = 0;
	bp.faunationMax = 0;
	blueprints[bp.type] = bp;


	bp.type = surf_tropics;
	bp.tis = { 31, 0, 0, 0 };
	bp.feats = FEAT_FITFORTREES;
	bp.mmColor = 0xFF007F0E;
	bp.description = "Tropics";
	bp.nativeSurfs = {};
	bp.nativeMnts = { surf_mountain_tropics };
	bp.nativeHills = { surf_hill_tropics };
	bp.baseProdPen = 0.97f;
	bp.affBase = 0;
	bp.affMin = 0;
	bp.affMax = 0;
	bp.ageAdulthood = 0;
	bp.ageOldness = 0;
	bp.ageDecay = 0;
	bp.chanceToGrow = 0;
	bp.chanceToReproduce = 0;
	bp.faunationBase = 0;
	bp.faunationMin = 0;
	bp.faunationMax = 0;
	blueprints[bp.type] = bp;


	bp.type = surf_savanna;
	bp.tis = { 32, 0, 0, 0 };
	bp.feats = FEAT_FITFORTREES;
	bp.mmColor = 0xFFFF9523;
	bp.description = "Savanna";
	bp.nativeSurfs = {};
	bp.nativeMnts = { surf_mountain_savanna };
	bp.nativeHills = { surf_hill_savanna };
	bp.baseProdPen = 0.95f;
	bp.affBase = 0;
	bp.affMin = 0;
	bp.affMax = 0;
	bp.ageAdulthood = 0;
	bp.ageOldness = 0;
	bp.ageDecay = 0;
	bp.chanceToGrow = 0;
	bp.chanceToReproduce = 0;
	bp.faunationBase = 0;
	bp.faunationMin = 0;
	bp.faunationMax = 0;
	blueprints[bp.type] = bp;


	bp.type = surf_tundra;
	bp.tis = { 33, 0, 0, 0 };
	bp.feats = FEAT_FITFORTREES;
	bp.mmColor = 0xFF636061;
	bp.description = "Tundra";
	bp.nativeSurfs = {};
	bp.nativeMnts = { surf_mountain_tundra };
	bp.nativeHills = { surf_hill_tundra };
	bp.baseProdPen = 0.80f;
	bp.affBase = 0;
	bp.affMin = 0;
	bp.affMax = 0;
	bp.ageAdulthood = 0;
	bp.ageOldness = 0;
	bp.ageDecay = 0;
	bp.chanceToGrow = 0;
	bp.chanceToReproduce = 0;
	bp.faunationBase = 0;
	bp.faunationMin = 0;
	bp.faunationMax = 0;
	blueprints[bp.type] = bp;


	bp.type = surf_mountain_reef;
	bp.tis = { 43, 0, 0, 0 };
	bp.feats = FEAT_MOUNTAIN | FEAT_WATERTILE;
	bp.mmColor = 0xFF000000;
	bp.description = "Reef";
	bp.nativeSurfs = {};
	bp.nativeMnts = { surf_mountain_reef };
	bp.nativeHills = {};
	bp.baseProdPen = 0;
	bp.affBase = 0;
	bp.affMin = 0;
	bp.affMax = 0;
	bp.ageAdulthood = 0;
	bp.ageOldness = 0;
	bp.ageDecay = 0;
	bp.chanceToGrow = 0;
	bp.chanceToReproduce = 0;
	bp.faunationBase = 0;
	bp.faunationMin = 0;
	bp.faunationMax = 0;
	blueprints[bp.type] = bp;


	bp.type = surf_mountain_reefice;
	bp.tis = { 44, 0, 0, 0 };
	bp.feats = FEAT_MOUNTAIN | FEAT_WATERTILE;
	bp.mmColor = 0xFF000000;
	bp.description = "Ice Reef";
	bp.nativeSurfs = {};
	bp.nativeMnts = { surf_mountain_reefice };
	bp.nativeHills = {};
	bp.baseProdPen = 0;
	bp.affBase = 0;
	bp.affMin = 0;
	bp.affMax = 0;
	bp.ageAdulthood = 0;
	bp.ageOldness = 0;
	bp.ageDecay = 0;
	bp.chanceToGrow = 0;
	bp.chanceToReproduce = 0;
	bp.faunationBase = 0;
	bp.faunationMin = 0;
	bp.faunationMax = 0;
	blueprints[bp.type] = bp;


	bp.type = surf_deepwater;
	bp.tis = { 45, 0, 0, 0 };
	bp.feats = FEAT_WATERTILE;
	bp.mmColor = 0xFF0E35DF;
	bp.description = "Deep Water";
	bp.nativeSurfs = {};
	bp.nativeMnts = { surf_mountain_reef };
	bp.nativeHills = {};
	bp.baseProdPen = 0;
	bp.affBase = 0;
	bp.affMin = 0;
	bp.affMax = 0;
	bp.ageAdulthood = 0;
	bp.ageOldness = 0;
	bp.ageDecay = 0;
	bp.chanceToGrow = 0;
	bp.chanceToReproduce = 0;
	bp.faunationBase = 0;
	bp.faunationMin = 0;
	bp.faunationMax = 0;
	blueprints[bp.type] = bp;


	bp.type = surf_waterfresh;
	bp.tis = { 46, 0, 0, 0 };
	bp.feats = FEAT_WATERTILE | FEAT_FRESHWATER;
	bp.mmColor = 0xFF3F75FF;
	bp.description = "Fresh Water";
	bp.nativeSurfs = {};
	bp.nativeMnts = { surf_mountain_reef };
	bp.nativeHills = {};
	bp.baseProdPen = 0;
	bp.affBase = 0;
	bp.affMin = 0;
	bp.affMax = 0;
	bp.ageAdulthood = 0;
	bp.ageOldness = 0;
	bp.ageDecay = 0;
	bp.chanceToGrow = 0;
	bp.chanceToReproduce = 0;
	bp.faunationBase = 0;
	bp.faunationMin = 0;
	bp.faunationMax = 0;
	blueprints[bp.type] = bp;


	bp.type = surf_waterfreshfrozen;
	bp.tis = { 14, 0, 0, 0 };
	bp.feats = FEAT_WATERTILE | FEAT_FRESHWATER;
	bp.mmColor = 0xFF00FFE5;
	bp.description = "Frozen Fresh Water";
	bp.nativeSurfs = {};
	bp.nativeMnts = { surf_mountain_reefice };
	bp.nativeHills = {};
	bp.baseProdPen = 0;
	bp.affBase = 0;
	bp.affMin = 0;
	bp.affMax = 0;
	bp.ageAdulthood = 0;
	bp.ageOldness = 0;
	bp.ageDecay = 0;
	bp.chanceToGrow = 0;
	bp.chanceToReproduce = 0;
	bp.faunationBase = 0;
	bp.faunationMin = 0;
	bp.faunationMax = 0;
	blueprints[bp.type] = bp;


	bp.type = surf_lake;
	bp.tis = { 46, 0, 0, 0 };
	bp.feats = FEAT_WATERTILE | FEAT_FRESHWATER | FEAT_LAKE;
	bp.mmColor = 0xFF3F75FF;
	bp.description = "Lake";
	bp.nativeSurfs = {};
	bp.nativeMnts = { surf_mountain_reef };
	bp.nativeHills = {};
	bp.baseProdPen = 0;
	bp.affBase = 0;
	bp.affMin = 0;
	bp.affMax = 0;
	bp.ageAdulthood = 0;
	bp.ageOldness = 0;
	bp.ageDecay = 0;
	bp.chanceToGrow = 0;
	bp.chanceToReproduce = 0;
	bp.faunationBase = 0;
	bp.faunationMin = 0;
	bp.faunationMax = 0;
	blueprints[bp.type] = bp;


	bp.type = surf_lakefrozen;
	bp.tis = { 14, 0, 0, 0 };
	bp.feats = FEAT_WATERTILE | FEAT_FRESHWATER | FEAT_LAKE;
	bp.mmColor = 0xFF00FFE5;
	bp.description = "Frozen Lake";
	bp.nativeSurfs = {};
	bp.nativeMnts = { surf_mountain_reefice };
	bp.nativeHills = {};
	bp.baseProdPen = 0;
	bp.affBase = 0;
	bp.affMin = 0;
	bp.affMax = 0;
	bp.ageAdulthood = 0;
	bp.ageOldness = 0;
	bp.ageDecay = 0;
	bp.chanceToGrow = 0;
	bp.chanceToReproduce = 0;
	bp.faunationBase = 0;
	bp.faunationMin = 0;
	bp.faunationMax = 0;
	blueprints[bp.type] = bp;


	bp.type = surf_hill_grass;
	bp.tis = { 59, 0, 0, 0 };
	bp.feats = FEAT_HILL | FEAT_FITFORTREES;
	bp.mmColor = 0xFF3DCE00;
	bp.description = "Grass Hill";
	bp.nativeSurfs = {};
	bp.nativeMnts = { surf_mountain_grass };
	bp.nativeHills = { surf_hill_grass };
	bp.baseProdPen = 0.99f;
	bp.affBase = 0;
	bp.affMin = 0;
	bp.affMax = 0;
	bp.ageAdulthood = 0;
	bp.ageOldness = 0;
	bp.ageDecay = 0;
	bp.chanceToGrow = 0;
	bp.chanceToReproduce = 0;
	bp.faunationBase = 0;
	bp.faunationMin = 0;
	bp.faunationMax = 0;
	blueprints[bp.type] = bp;


	bp.type = surf_hill_snow;
	bp.tis = { 62, 0, 0, 0 };
	bp.feats = FEAT_HILL | FEAT_FITFORTREES;
	bp.mmColor = 0xFFEEEEEE;
	bp.description = "Snow Hill";
	bp.nativeSurfs = {};
	bp.nativeMnts = { surf_mountain_reefice };
	bp.nativeHills = { surf_hill_snow };
	bp.baseProdPen = 0.80f;
	bp.affBase = 0;
	bp.affMin = 0;
	bp.affMax = 0;
	bp.ageAdulthood = 0;
	bp.ageOldness = 0;
	bp.ageDecay = 0;
	bp.chanceToGrow = 0;
	bp.chanceToReproduce = 0;
	bp.faunationBase = 0;
	bp.faunationMin = 0;
	bp.faunationMax = 0;
	blueprints[bp.type] = bp;


	bp.type = surf_hill_desert;
	bp.tis = { 58, 0, 0, 0 };
	bp.feats = FEAT_HILL | FEAT_FITFORTREES;
	bp.mmColor = 0xFFE68D1F;
	bp.description = "Barkhan";
	bp.nativeSurfs = {};
	bp.nativeMnts = { surf_mountain_reefice };
	bp.nativeHills = { surf_hill_desert };
	bp.baseProdPen = 0.90f;
	bp.affBase = 0;
	bp.affMin = 0;
	bp.affMax = 0;
	bp.ageAdulthood = 0;
	bp.ageOldness = 0;
	bp.ageDecay = 0;
	bp.chanceToGrow = 0;
	bp.chanceToReproduce = 0;
	bp.faunationBase = 0;
	bp.faunationMin = 0;
	bp.faunationMax = 0;
	blueprints[bp.type] = bp;


	bp.type = surf_hill_coast;
	bp.tis = { 57, 0, 0, 0 };
	bp.feats = FEAT_HILL | FEAT_FITFORTREES;
	bp.mmColor = 0xFFFF9523;
	bp.description = "Coast Hill";
	bp.nativeSurfs = {};
	bp.nativeMnts = { surf_mountain_reefice };
	bp.nativeHills = { surf_hill_coast };
	bp.baseProdPen = 0.99f;
	bp.affBase = 0;
	bp.affMin = 0;
	bp.affMax = 0;
	bp.ageAdulthood = 0;
	bp.ageOldness = 0;
	bp.ageDecay = 0;
	bp.chanceToGrow = 0;
	bp.chanceToReproduce = 0;
	bp.faunationBase = 0;
	bp.faunationMin = 0;
	bp.faunationMax = 0;
	blueprints[bp.type] = bp;


	bp.type = surf_hill_oasis;
	bp.tis = { 60, 0, 0, 0 };
	bp.feats = FEAT_HILL | FEAT_FITFORTREES;
	bp.mmColor = 0xFF007F0E;
	bp.description = "Oasis Hill";
	bp.nativeSurfs = {};
	bp.nativeMnts = { surf_mountain_reefice };
	bp.nativeHills = { surf_hill_oasis };
	bp.baseProdPen = 0.99f;
	bp.affBase = 0;
	bp.affMin = 0;
	bp.affMax = 0;
	bp.ageAdulthood = 0;
	bp.ageOldness = 0;
	bp.ageDecay = 0;
	bp.chanceToGrow = 0;
	bp.chanceToReproduce = 0;
	bp.faunationBase = 0;
	bp.faunationMin = 0;
	bp.faunationMax = 0;
	blueprints[bp.type] = bp;


	bp.type = surf_hill_tundra;
	bp.tis = { 64, 0, 0, 0 };
	bp.feats = FEAT_HILL | FEAT_FITFORTREES;
	bp.mmColor = 0xFF636061;
	bp.description = "Tundra Hill";
	bp.nativeSurfs = {};
	bp.nativeMnts = { surf_mountain_reefice };
	bp.nativeHills = { surf_hill_tundra };
	bp.baseProdPen = 0.80f;
	bp.affBase = 0;
	bp.affMin = 0;
	bp.affMax = 0;
	bp.ageAdulthood = 0;
	bp.ageOldness = 0;
	bp.ageDecay = 0;
	bp.chanceToGrow = 0;
	bp.chanceToReproduce = 0;
	bp.faunationBase = 0;
	bp.faunationMin = 0;
	bp.faunationMax = 0;
	blueprints[bp.type] = bp;


	bp.type = surf_hill_savanna;
	bp.tis = { 61, 0, 0, 0 };
	bp.feats = FEAT_HILL | FEAT_FITFORTREES;
	bp.mmColor = 0xFFFF9523;
	bp.description = "Savanna Hill";
	bp.nativeSurfs = {};
	bp.nativeMnts = { surf_mountain_reefice };
	bp.nativeHills = { surf_hill_savanna };
	bp.baseProdPen = 0.95f;
	bp.affBase = 0;
	bp.affMin = 0;
	bp.affMax = 0;
	bp.ageAdulthood = 0;
	bp.ageOldness = 0;
	bp.ageDecay = 0;
	bp.chanceToGrow = 0;
	bp.chanceToReproduce = 0;
	bp.faunationBase = 0;
	bp.faunationMin = 0;
	bp.faunationMax = 0;
	blueprints[bp.type] = bp;


	bp.type = surf_hill_tropics;
	bp.tis = { 63, 0, 0, 0 };
	bp.feats = FEAT_HILL | FEAT_FITFORTREES;
	bp.mmColor = 0xFF007F0E;
	bp.description = "Tropics Hill";
	bp.nativeSurfs = {};
	bp.nativeMnts = { surf_mountain_reefice };
	bp.nativeHills = { surf_hill_tropics };
	bp.baseProdPen = 0.97f;
	bp.affBase = 0;
	bp.affMin = 0;
	bp.affMax = 0;
	bp.ageAdulthood = 0;
	bp.ageOldness = 0;
	bp.ageDecay = 0;
	bp.chanceToGrow = 0;
	bp.chanceToReproduce = 0;
	bp.faunationBase = 0;
	bp.faunationMin = 0;
	bp.faunationMax = 0;
	blueprints[bp.type] = bp;

	// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
	// OBJECTS
	// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-

	bp.type = obj_oak;
	bp.tis = { 5, 4, 5, 6 };
	bp.feats = FEAT_TREE | FEAT_FLORA;
	bp.mmColor = 0x00000000;
	bp.description = "Oak";
	bp.nativeSurfs = { surf_grass, surf_hill_grass, surf_coast };
	bp.nativeMnts = {};
	bp.nativeHills = {};
	bp.baseProdPen = 0;
	bp.affBase = 1000;
	bp.affMin = 300;
	bp.affMax = std::numeric_limits<short>::max();
	bp.ageAdulthood = WEEKSFROMYEARS(3);
	bp.ageOldness = WEEKSFROMYEARS(30);
	bp.ageDecay = WEEKSFROMYEARS(35);
	bp.chanceToGrow = 100000;
	bp.chanceToReproduce = 450;
	bp.faunationBase = 0;
	bp.faunationMin = 0;
	bp.faunationMax = 0;
	blueprints[bp.type] = bp;


	bp.type = obj_fir;
	bp.tis = { 16, 15, 16, 17 };
	bp.feats = FEAT_TREE | FEAT_FLORA;
	bp.mmColor = 0x00000000;
	bp.description = "Fir";
	bp.nativeSurfs = { surf_grass, surf_hill_grass };
	bp.nativeMnts = {};
	bp.nativeHills = {};
	bp.baseProdPen = 0;
	bp.affBase = 1000;
	bp.affMin = 300;
	bp.affMax = std::numeric_limits<short>::max();
	bp.ageAdulthood = WEEKSFROMYEARS(3);
	bp.ageOldness = WEEKSFROMYEARS(40);
	bp.ageDecay = WEEKSFROMYEARS(45);
	bp.chanceToGrow = 200000;
	bp.chanceToReproduce = 1000;
	bp.faunationBase = 0;
	bp.faunationMin = 0;
	bp.faunationMax = 0;
	blueprints[bp.type] = bp;


	bp.type = obj_cactus;
	bp.tis = { 19, 18, 19, 20 };
	bp.feats = FEAT_TREE | FEAT_FLORA;
	bp.mmColor = 0x00000000;
	bp.description = "Cactus";
	bp.nativeSurfs = { surf_desert, surf_hill_desert };
	bp.nativeMnts = {};
	bp.nativeHills = {};
	bp.baseProdPen = 0;
	bp.affBase = 1000;
	bp.affMin = 300;
	bp.affMax = std::numeric_limits<short>::max();
	bp.ageAdulthood = WEEKSFROMYEARS(1);
	bp.ageOldness = WEEKSFROMYEARS(5);
	bp.ageDecay = WEEKSFROMYEARS(6);
	bp.chanceToGrow = 200000;
	bp.chanceToReproduce = 600;
	bp.faunationBase = 0;
	bp.faunationMin = 0;
	bp.faunationMax = 0;
	blueprints[bp.type] = bp;


	bp.type = obj_palm;
	bp.tis = { 25, 24, 25, 26 };
	bp.feats = FEAT_TREE | FEAT_FLORA;
	bp.mmColor = 0x00000000;
	bp.description = "Palm";
	bp.nativeSurfs = { surf_tropics, surf_oasis, surf_hill_tropics, surf_hill_oasis };
	bp.nativeMnts = {};
	bp.nativeHills = {};
	bp.baseProdPen = 0;
	bp.affBase = 1000;
	bp.affMin = 300;
	bp.affMax = std::numeric_limits<short>::max();
	bp.ageAdulthood = WEEKSFROMYEARS(3);
	bp.ageOldness = WEEKSFROMYEARS(30);
	bp.ageDecay = WEEKSFROMYEARS(35);
	bp.chanceToGrow = 50000;
	bp.chanceToReproduce = 200;
	bp.faunationBase = 0;
	bp.faunationMin = 0;
	bp.faunationMax = 0;
	blueprints[bp.type] = bp;


	bp.type = obj_juniper;
	bp.tis = { 38, 37, 38, 39 };
	bp.feats = FEAT_TREE | FEAT_FLORA;
	bp.mmColor = 0x00000000;
	bp.description = "Juniper";
	bp.nativeSurfs = { surf_tundra, surf_hill_tundra };
	bp.nativeMnts = {};
	bp.nativeHills = {};
	bp.baseProdPen = 0;
	bp.affBase = 1000;
	bp.affMin = 300;
	bp.affMax = std::numeric_limits<short>::max();
	bp.ageAdulthood = WEEKSFROMYEARS(3);
	bp.ageOldness = WEEKSFROMYEARS(30);
	bp.ageDecay = WEEKSFROMYEARS(35);
	bp.chanceToGrow = 200000;
	bp.chanceToReproduce = 1200;
	bp.faunationBase = 0;
	bp.faunationMin = 0;
	bp.faunationMax = 0;
	blueprints[bp.type] = bp;


	bp.type = obj_baobab;
	bp.tis = { 41, 40, 41, 42 };
	bp.feats = FEAT_TREE | FEAT_FLORA;
	bp.mmColor = 0x00000000;
	bp.description = "Baobab";
	bp.nativeSurfs = { surf_savanna, surf_hill_savanna };
	bp.nativeMnts = {};
	bp.nativeHills = {};
	bp.baseProdPen = 0;
	bp.affBase = 1000;
	bp.affMin = 300;
	bp.affMax = std::numeric_limits<short>::max();
	bp.ageAdulthood = WEEKSFROMYEARS(5);
	bp.ageOldness = WEEKSFROMYEARS(100);
	bp.ageDecay = WEEKSFROMYEARS(110);
	bp.chanceToGrow = 1000000;
	bp.chanceToReproduce = 3000;
	bp.faunationBase = 0;
	bp.faunationMin = 0;
	bp.faunationMax = 0;
	blueprints[bp.type] = bp;


	bp.type = obj_acacia;
	bp.tis = { 55, 54, 55, 56 };
	bp.feats = FEAT_TREE | FEAT_FLORA;
	bp.mmColor = 0x00000000;
	bp.description = "Acacia";
	bp.nativeSurfs = { surf_savanna, surf_hill_savanna };
	bp.nativeMnts = {};
	bp.nativeHills = {};
	bp.baseProdPen = 0;
	bp.affBase = 1000;
	bp.affMin = 300;
	bp.affMax = std::numeric_limits<short>::max();
	bp.ageAdulthood = WEEKSFROMYEARS(3);
	bp.ageOldness = WEEKSFROMYEARS(50);
	bp.ageDecay = WEEKSFROMYEARS(60);
	bp.chanceToGrow = 250000;
	bp.chanceToReproduce = 800;
	bp.faunationBase = 0;
	bp.faunationMin = 0;
	bp.faunationMax = 0;
	blueprints[bp.type] = bp;

	// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
	// BUSHES
	// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-

	bp.type = obj_raspberry;
	bp.tis = { 49, 49, 49, 49 };
	bp.feats = FEAT_BUSH | FEAT_FLORA;
	bp.mmColor = 0x00000000;
	bp.description = "Raspberry";
	bp.nativeSurfs = { surf_grass, surf_coast, surf_hill_grass, surf_hill_coast };
	bp.nativeMnts = {};
	bp.nativeHills = {};
	bp.baseProdPen = 0;
	bp.affBase = 500;
	bp.affMin = 0;
	bp.affMax = std::numeric_limits<short>::max();
	bp.ageAdulthood = WEEKSFROMMONTHS(3);
	bp.ageOldness = WEEKSFROMMONTHS(24);
	bp.ageDecay = WEEKSFROMMONTHS(26);
	bp.chanceToGrow = 25000;
	bp.chanceToReproduce = 100;
	bp.faunationBase = 0;
	bp.faunationMin = 0;
	bp.faunationMax = 0;
	blueprints[bp.type] = bp;


	bp.type = obj_camelthorn;
	bp.tis = { 50, 50, 50, 50 };
	bp.feats = FEAT_BUSH | FEAT_FLORA;
	bp.mmColor = 0x00000000;
	bp.description = "Camelthorn";
	bp.nativeSurfs = { surf_desert, surf_hill_desert };
	bp.nativeMnts = {};
	bp.nativeHills = {};
	bp.baseProdPen = 0;
	bp.affBase = 500;
	bp.affMin = 0;
	bp.affMax = std::numeric_limits<short>::max();
	bp.ageAdulthood = WEEKSFROMMONTHS(3);
	bp.ageOldness = WEEKSFROMMONTHS(36);
	bp.ageDecay = WEEKSFROMMONTHS(39);
	bp.chanceToGrow = 50000;
	bp.chanceToReproduce = 150;
	bp.faunationBase = 0;
	bp.faunationMin = 0;
	bp.faunationMax = 0;
	blueprints[bp.type] = bp;


	bp.type = obj_dwarfbirch;
	bp.tis = { 51, 51, 51, 51 };
	bp.feats = FEAT_BUSH | FEAT_FLORA;
	bp.mmColor = 0x00000000;
	bp.description = "Dwarf birch";
	bp.nativeSurfs = { surf_tundra, surf_hill_tundra };
	bp.nativeMnts = {};
	bp.nativeHills = {};
	bp.baseProdPen = 0;
	bp.affBase = 500;
	bp.affMin = 0;
	bp.affMax = std::numeric_limits<short>::max();
	bp.ageAdulthood = WEEKSFROMMONTHS(3);
	bp.ageOldness = WEEKSFROMMONTHS(36);
	bp.ageDecay = WEEKSFROMMONTHS(38);
	bp.chanceToGrow = 50000;
	bp.chanceToReproduce = 150;
	bp.faunationBase = 0;
	bp.faunationMin = 0;
	bp.faunationMax = 0;
	blueprints[bp.type] = bp;


	bp.type = obj_aloe;
	bp.tis = { 52, 52, 52, 52 };
	bp.feats = FEAT_BUSH | FEAT_FLORA;
	bp.mmColor = 0x00000000;
	bp.description = "Aloe";
	bp.nativeSurfs = { surf_savanna, surf_hill_savanna };
	bp.nativeMnts = {};
	bp.nativeHills = {};
	bp.baseProdPen = 0;
	bp.affBase = 500;
	bp.affMin = 0;
	bp.affMax = std::numeric_limits<short>::max();
	bp.ageAdulthood = WEEKSFROMMONTHS(3);
	bp.ageOldness = WEEKSFROMMONTHS(36);
	bp.ageDecay = WEEKSFROMMONTHS(38);
	bp.chanceToGrow = 37500;
	bp.chanceToReproduce = 125;
	bp.faunationBase = 0;
	bp.faunationMin = 0;
	bp.faunationMax = 0;
	blueprints[bp.type] = bp;


	bp.type = obj_fern;
	bp.tis = { 53, 53, 53, 53 };
	bp.feats = FEAT_BUSH | FEAT_FLORA;
	bp.mmColor = 0x00000000;
	bp.description = "Fern";
	bp.nativeSurfs = { surf_tropics, surf_hill_tropics };
	bp.nativeMnts = {};
	bp.nativeHills = {};
	bp.baseProdPen = 0;
	bp.affBase = 500;
	bp.affMin = 0;
	bp.affMax = std::numeric_limits<short>::max();
	bp.ageAdulthood = WEEKSFROMMONTHS(3);
	bp.ageOldness = WEEKSFROMMONTHS(24);
	bp.ageDecay = WEEKSFROMMONTHS(26);
	bp.chanceToGrow = 12500;
	bp.chanceToReproduce = 100;
	bp.faunationBase = 0;
	bp.faunationMin = 0;
	bp.faunationMax = 0;
	blueprints[bp.type] = bp;

	// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
	// FAUNA
	// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-

	bp.type = obj_hare;
	bp.tis = { 65, 0, 0, 0 };
	bp.feats = FEAT_FAUNA;
	bp.mmColor = 0x00000000;
	bp.description = "Hare";
	bp.nativeSurfs = { surf_grass, surf_hill_grass, surf_tundra, surf_hill_tundra };
	bp.nativeMnts = {};
	bp.nativeHills = {};
	bp.baseProdPen = 0;
	bp.affBase = 0;
	bp.affMin = 800;
	bp.affMax = std::numeric_limits<short>::max();
	bp.ageAdulthood = WEEKSFROMMONTHS(0);
	bp.ageOldness = WEEKSFROMMONTHS(0);
	bp.ageDecay = WEEKSFROMMONTHS(0);
	bp.chanceToGrow = 2500;
	bp.chanceToReproduce = 0;
	bp.faunationBase = 500;
	bp.faunationMin = 0;
	bp.faunationMax = 30;
	blueprints[bp.type] = bp;


	bp.type = obj_fox;
	bp.tis = { 66, 0, 0, 0 };
	bp.feats = FEAT_FAUNA;
	bp.mmColor = 0x00000000;
	bp.description = "Fox";
	bp.nativeSurfs = { surf_grass, surf_hill_grass, surf_tundra, surf_hill_tundra };
	bp.nativeMnts = {};
	bp.nativeHills = {};
	bp.baseProdPen = 0;
	bp.affBase = 0;
	bp.affMin = 800;
	bp.affMax = std::numeric_limits<short>::max();
	bp.ageAdulthood = WEEKSFROMMONTHS(0);
	bp.ageOldness = WEEKSFROMMONTHS(0);
	bp.ageDecay = WEEKSFROMMONTHS(0);
	bp.chanceToGrow = 2500;
	bp.chanceToReproduce = 0;
	bp.faunationBase = 500;
	bp.faunationMin = 0;
	bp.faunationMax = 30;
	blueprints[bp.type] = bp;

	bp.type = obj_monkey;
	bp.tis = { 67, 0, 0, 0 };
	bp.feats = FEAT_FAUNA;
	bp.mmColor = 0x00000000;
	bp.description = "Monkey";
	bp.nativeSurfs = { surf_savanna, surf_hill_savanna, surf_tropics, surf_hill_tropics };
	bp.nativeMnts = {};
	bp.nativeHills = {};
	bp.baseProdPen = 0;
	bp.affBase = 0;
	bp.affMin = 800;
	bp.affMax = std::numeric_limits<short>::max();
	bp.ageAdulthood = WEEKSFROMMONTHS(0);
	bp.ageOldness = WEEKSFROMMONTHS(0);
	bp.ageDecay = WEEKSFROMMONTHS(0);
	bp.chanceToGrow = 2500;
	bp.chanceToReproduce = 0;
	bp.faunationBase = 500;
	bp.faunationMin = 0;
	bp.faunationMax = 30;
	blueprints[bp.type] = bp;

	bp.type = obj_fish;
	bp.tis = { 68, 0, 0, 0 };
	bp.feats = FEAT_FAUNA;
	bp.mmColor = 0x00000000;
	bp.description = "Fish";
	bp.nativeSurfs = { surf_water, surf_deepwater, surf_waterfresh, surf_lake };
	bp.nativeMnts = {};
	bp.nativeHills = {};
	bp.baseProdPen = 0;
	bp.affBase = 0;
	bp.affMin = 0;
	bp.affMax = std::numeric_limits<short>::max();
	bp.ageAdulthood = WEEKSFROMMONTHS(0);
	bp.ageOldness = WEEKSFROMMONTHS(0);
	bp.ageDecay = WEEKSFROMMONTHS(0);
	bp.chanceToGrow = 50000;
	bp.chanceToReproduce = 0;
	bp.faunationBase = 500;
	bp.faunationMin = 0;
	bp.faunationMax = 20;
	blueprints[bp.type] = bp;

	bp.type = obj_horse;
	bp.tis = { 69, 0, 0, 0 };
	bp.feats = FEAT_FAUNA;
	bp.mmColor = 0x00000000;
	bp.description = "Horse";
	bp.nativeSurfs = { surf_grass };
	bp.nativeMnts = {};
	bp.nativeHills = {};
	bp.baseProdPen = 0;
	bp.affBase = 0;
	bp.affMin = 0;
	bp.affMax = 300;
	bp.ageAdulthood = WEEKSFROMMONTHS(0);
	bp.ageOldness = WEEKSFROMMONTHS(0);
	bp.ageDecay = WEEKSFROMMONTHS(0);
	bp.chanceToGrow = 50000;
	bp.chanceToReproduce = 0;
	bp.faunationBase = 500;
	bp.faunationMin = 0;
	bp.faunationMax = 20;
	blueprints[bp.type] = bp;

	bp.type = obj_crocodile;
	bp.tis = { 70, 0, 0, 0 };
	bp.feats = FEAT_FAUNA;
	bp.mmColor = 0x00000000;
	bp.description = "Crocodile";
	bp.nativeSurfs = { surf_oasis, surf_tropics, surf_coast };
	bp.nativeMnts = {};
	bp.nativeHills = {};
	bp.baseProdPen = 0;
	bp.affBase = 0;
	bp.affMin = 100;
	bp.affMax = std::numeric_limits<short>::max();
	bp.ageAdulthood = WEEKSFROMMONTHS(0);
	bp.ageOldness = WEEKSFROMMONTHS(0);
	bp.ageDecay = WEEKSFROMMONTHS(0);
	bp.chanceToGrow = 50000;
	bp.chanceToReproduce = 0;
	bp.faunationBase = 500;
	bp.faunationMin = 0;
	bp.faunationMax = 30;
	blueprints[bp.type] = bp;

	bp.type = obj_whale;
	bp.tis = { 71, 0, 0, 0 };
	bp.feats = FEAT_FAUNA;
	bp.mmColor = 0x00000000;
	bp.description = "Whale";
	bp.nativeSurfs = { surf_deepwater };
	bp.nativeMnts = {};
	bp.nativeHills = {};
	bp.baseProdPen = 0;
	bp.affBase = 0;
	bp.affMin = 0;
	bp.affMax = std::numeric_limits<short>::max();
	bp.ageAdulthood = WEEKSFROMMONTHS(0);
	bp.ageOldness = WEEKSFROMMONTHS(0);
	bp.ageDecay = WEEKSFROMMONTHS(0);
	bp.chanceToGrow = 100000;
	bp.chanceToReproduce = 0;
	bp.faunationBase = 500;
	bp.faunationMin = 0;
	bp.faunationMax = 10;
	blueprints[bp.type] = bp;

	bp.type = obj_bear_polar;
	bp.tis = { 72, 0, 0, 0 };
	bp.feats = FEAT_FAUNA;
	bp.mmColor = 0x00000000;
	bp.description = "Polar bear";
	bp.nativeSurfs = { surf_snow };
	bp.nativeMnts = {};
	bp.nativeHills = {};
	bp.baseProdPen = 0;
	bp.affBase = 0;
	bp.affMin = 0;
	bp.affMax = std::numeric_limits<short>::max();
	bp.ageAdulthood = WEEKSFROMMONTHS(0);
	bp.ageOldness = WEEKSFROMMONTHS(0);
	bp.ageDecay = WEEKSFROMMONTHS(0);
	bp.chanceToGrow = 100000;
	bp.chanceToReproduce = 0;
	bp.faunationBase = 500;
	bp.faunationMin = 0;
	bp.faunationMax = 10;
	blueprints[bp.type] = bp;

	bp.type = obj_pinguin;
	bp.tis = { 73, 0, 0, 0 };
	bp.feats = FEAT_FAUNA;
	bp.mmColor = 0x00000000;
	bp.description = "Pinguin";
	bp.nativeSurfs = { surf_snow };
	bp.nativeMnts = {};
	bp.nativeHills = {};
	bp.baseProdPen = 0;
	bp.affBase = 0;
	bp.affMin = 0;
	bp.affMax = std::numeric_limits<short>::max();
	bp.ageAdulthood = WEEKSFROMMONTHS(0);
	bp.ageOldness = WEEKSFROMMONTHS(0);
	bp.ageDecay = WEEKSFROMMONTHS(0);
	bp.chanceToGrow = 50000;
	bp.chanceToReproduce = 0;
	bp.faunationBase = 500;
	bp.faunationMin = 0;
	bp.faunationMax = 40;
	blueprints[bp.type] = bp;

	bp.type = obj_seal;
	bp.tis = { 74, 0, 0, 0 };
	bp.feats = FEAT_FAUNA;
	bp.mmColor = 0x00000000;
	bp.description = "Seal";
	bp.nativeSurfs = { surf_snow };
	bp.nativeMnts = {};
	bp.nativeHills = {};
	bp.baseProdPen = 0;
	bp.affBase = 0;
	bp.affMin = 0;
	bp.affMax = std::numeric_limits<short>::max();
	bp.ageAdulthood = WEEKSFROMMONTHS(0);
	bp.ageOldness = WEEKSFROMMONTHS(0);
	bp.ageDecay = WEEKSFROMMONTHS(0);
	bp.chanceToGrow = 100000;
	bp.chanceToReproduce = 0;
	bp.faunationBase = 500;
	bp.faunationMin = 0;
	bp.faunationMax = 20;
	blueprints[bp.type] = bp;

	bp.type = obj_deer;
	bp.tis = { 75, 0, 0, 0 };
	bp.feats = FEAT_FAUNA;
	bp.mmColor = 0x00000000;
	bp.description = "Deer";
	bp.nativeSurfs = { surf_tundra, surf_hill_tundra };
	bp.nativeMnts = {};
	bp.nativeHills = {};
	bp.baseProdPen = 0;
	bp.affBase = 0;
	bp.affMin = 300;
	bp.affMax = std::numeric_limits<short>::max();
	bp.ageAdulthood = WEEKSFROMMONTHS(0);
	bp.ageOldness = WEEKSFROMMONTHS(0);
	bp.ageDecay = WEEKSFROMMONTHS(0);
	bp.chanceToGrow = 25000;
	bp.chanceToReproduce = 0;
	bp.faunationBase = 1000;
	bp.faunationMin = 0;
	bp.faunationMax = 100;
	blueprints[bp.type] = bp;

	bp.type = obj_bear;
	bp.tis = { 76, 0, 0, 0 };
	bp.feats = FEAT_FAUNA;
	bp.mmColor = 0x00000000;
	bp.description = "Bear";
	bp.nativeSurfs = { surf_grass, surf_hill_grass };
	bp.nativeMnts = {};
	bp.nativeHills = {};
	bp.baseProdPen = 0;
	bp.affBase = 0;
	bp.affMin = 950;
	bp.affMax = std::numeric_limits<short>::max();
	bp.ageAdulthood = WEEKSFROMMONTHS(0);
	bp.ageOldness = WEEKSFROMMONTHS(0);
	bp.ageDecay = WEEKSFROMMONTHS(0);
	bp.chanceToGrow = 50000;
	bp.chanceToReproduce = 0;
	bp.faunationBase = 5000;
	bp.faunationMin = 0;
	bp.faunationMax = 300;
	blueprints[bp.type] = bp;
}
