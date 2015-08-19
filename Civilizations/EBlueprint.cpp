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
	nativeTrees.clear();
	nativeBushes.clear();
	baseProdPen = 0;
	affBase = 0;
	affMin = 0;
	ageAdulthood = 0;
	ageOldness = 0;
	ageDecay = 0;
	chanceToGrow = 0;
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
	bp.nativeTrees = {};
	bp.nativeBushes = {};
	bp.baseProdPen = 0;
	bp.affBase = 0;
	bp.affMin = 0;
	bp.ageAdulthood = 0;
	bp.ageOldness = 0;
	bp.ageDecay = 0;
	bp.chanceToGrow = 0;
	blueprints[bp.type] = bp;

	// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-

	bp.type = surf_grass;
	bp.tis = { 2, 0, 0, 0 };
	bp.feats = FEAT_FITFORTREES;
	bp.mmColor = 0xFF3DCE00;
	bp.description = "Grass";
	bp.nativeSurfs = {};
	bp.nativeMnts = { surf_mountain_grass };
	bp.nativeTrees = { obj_oak };
	bp.nativeBushes = { obj_raspberry };
	bp.baseProdPen = 0.99f;
	bp.affBase = 0;
	bp.affMin = 0;
	bp.ageAdulthood = 0;
	bp.ageOldness = 0;
	bp.ageDecay = 0;
	bp.chanceToGrow = 0;
	blueprints[bp.type] = bp;

	// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-

	bp.type = surf_desert;
	bp.tis = { 3, 0, 0, 0 };
	bp.feats = FEAT_FITFORTREES;
	bp.mmColor = 0xFFE68D1F;
	bp.description = "Desert";
	bp.nativeSurfs = {};
	bp.nativeMnts = { surf_mountain_desert };
	bp.nativeTrees = { obj_cactus };
	bp.nativeBushes = { obj_camelthorn };
	bp.baseProdPen = 0.90f;
	bp.affBase = 0;
	bp.affMin = 0;
	bp.ageAdulthood = 0;
	bp.ageOldness = 0;
	bp.ageDecay = 0;
	bp.chanceToGrow = 0;
	blueprints[bp.type] = bp;

	// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-

	bp.type = surf_snow;
	bp.tis = { 13, 0, 0, 0 };
	bp.feats = FEAT_FITFORTREES;
	bp.mmColor = 0xFFEEEEEE;
	bp.description = "Snow";
	bp.nativeSurfs = {};
	bp.nativeMnts = { surf_mountain_snow };
	bp.nativeTrees = { obj_fir };
	bp.nativeBushes = { };
	bp.baseProdPen = 0.80f;
	bp.affBase = 0;
	bp.affMin = 0;
	bp.ageAdulthood = 0;
	bp.ageOldness = 0;
	bp.ageDecay = 0;
	bp.chanceToGrow = 0;
	blueprints[bp.type] = bp;

	// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-

	bp.type = surf_ice;
	bp.tis = { 14, 0, 0, 0 };
	bp.feats = FEAT_WATERTILE;
	bp.mmColor = 0xFF00FFE5;
	bp.description = "Ice";
	bp.nativeSurfs = {};
	bp.nativeMnts = { surf_mountain_reefice };
	bp.nativeTrees = {};
	bp.nativeBushes = {};
	bp.baseProdPen = 0;
	bp.affBase = 0;
	bp.affMin = 0;
	bp.ageAdulthood = 0;
	bp.ageOldness = 0;
	bp.ageDecay = 0;
	bp.chanceToGrow = 0;
	blueprints[bp.type] = bp;

	// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-

	bp.type = surf_mountain_grass;
	bp.tis = { 21, 0, 0, 0 };
	bp.feats = FEAT_MOUNTAIN;
	bp.mmColor = 0xFF000000;
	bp.description = "Mountain";
	bp.nativeSurfs = {};
	bp.nativeMnts = { surf_mountain_grass };
	bp.nativeTrees = {};
	bp.nativeBushes = {};
	bp.baseProdPen = 0.95f;
	bp.affBase = 0;
	bp.affMin = 0;
	bp.ageAdulthood = 0;
	bp.ageOldness = 0;
	bp.ageDecay = 0;
	bp.chanceToGrow = 0;
	blueprints[bp.type] = bp;

	// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-

	bp.type = surf_mountain_snow;
	bp.tis = { 22, 0, 0, 0 };
	bp.feats = FEAT_MOUNTAIN;
	bp.mmColor = 0xFF000000;
	bp.description = "Mountain";
	bp.nativeSurfs = {};
	bp.nativeMnts = { surf_mountain_snow };
	bp.nativeTrees = {};
	bp.nativeBushes = {};
	bp.baseProdPen = 0.80f;
	bp.affBase = 0;
	bp.affMin = 0;
	bp.ageAdulthood = 0;
	bp.ageOldness = 0;
	bp.ageDecay = 0;
	bp.chanceToGrow = 0;
	blueprints[bp.type] = bp;

	// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-

	bp.type = surf_mountain_desert;
	bp.tis = { 23, 0, 0, 0 };
	bp.feats = FEAT_MOUNTAIN;
	bp.mmColor = 0xFF000000;
	bp.description = "Mountain";
	bp.nativeSurfs = {};
	bp.nativeMnts = { surf_mountain_desert };
	bp.nativeTrees = {};
	bp.nativeBushes = {};
	bp.baseProdPen = 0.90f;
	bp.affBase = 0;
	bp.affMin = 0;
	bp.ageAdulthood = 0;
	bp.ageOldness = 0;
	bp.ageDecay = 0;
	bp.chanceToGrow = 0;
	blueprints[bp.type] = bp;

	// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-

	bp.type = surf_mountain_coast;
	bp.tis = { 29, 0, 0, 0 };
	bp.feats = FEAT_MOUNTAIN;
	bp.mmColor = 0xFF000000;
	bp.description = "Mountain";
	bp.nativeSurfs = {};
	bp.nativeMnts = { surf_mountain_coast };
	bp.nativeTrees = {};
	bp.nativeBushes = {};
	bp.baseProdPen = 0.99f;
	bp.affBase = 0;
	bp.affMin = 0;
	bp.ageAdulthood = 0;
	bp.ageOldness = 0;
	bp.ageDecay = 0;
	bp.chanceToGrow = 0;
	blueprints[bp.type] = bp;

	// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-

	bp.type = surf_mountain_oasis;
	bp.tis = { 30, 0, 0, 0 };
	bp.feats = FEAT_MOUNTAIN;
	bp.mmColor = 0xFF000000;
	bp.description = "Mountain";
	bp.nativeSurfs = {};
	bp.nativeMnts = { surf_mountain_oasis };
	bp.nativeTrees = {};
	bp.nativeBushes = {};
	bp.baseProdPen = 0.99f;
	bp.affBase = 0;
	bp.affMin = 0;
	bp.ageAdulthood = 0;
	bp.ageOldness = 0;
	bp.ageDecay = 0;
	bp.chanceToGrow = 0;
	blueprints[bp.type] = bp;

	// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-

	bp.type = surf_mountain_tundra;
	bp.tis = { 34, 0, 0, 0 };
	bp.feats = FEAT_MOUNTAIN;
	bp.mmColor = 0xFF000000;
	bp.description = "Mountain";
	bp.nativeSurfs = {};
	bp.nativeMnts = { surf_mountain_tundra };
	bp.nativeTrees = {};
	bp.nativeBushes = {};
	bp.baseProdPen = 0.80f;
	bp.affBase = 0;
	bp.affMin = 0;
	bp.ageAdulthood = 0;
	bp.ageOldness = 0;
	bp.ageDecay = 0;
	bp.chanceToGrow = 0;
	blueprints[bp.type] = bp;

	// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-

	bp.type = surf_mountain_savanna;
	bp.tis = { 35, 0, 0, 0 };
	bp.feats = FEAT_MOUNTAIN;
	bp.mmColor = 0xFF000000;
	bp.description = "Mountain";
	bp.nativeSurfs = {};
	bp.nativeMnts = { surf_mountain_savanna };
	bp.nativeTrees = {};
	bp.nativeBushes = {};
	bp.baseProdPen = 0.95f;
	bp.affBase = 0;
	bp.affMin = 0;
	bp.ageAdulthood = 0;
	bp.ageOldness = 0;
	bp.ageDecay = 0;
	bp.chanceToGrow = 0;
	blueprints[bp.type] = bp;

	// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-

	bp.type = surf_mountain_tropics;
	bp.tis = { 36, 0, 0, 0 };
	bp.feats = FEAT_MOUNTAIN;
	bp.mmColor = 0xFF000000;
	bp.description = "Mountain";
	bp.nativeSurfs = {};
	bp.nativeMnts = { surf_mountain_tropics };
	bp.nativeTrees = {};
	bp.nativeBushes = {};
	bp.baseProdPen = 0.97f;
	bp.affBase = 0;
	bp.affMin = 0;
	bp.ageAdulthood = 0;
	bp.ageOldness = 0;
	bp.ageDecay = 0;
	bp.chanceToGrow = 0;
	blueprints[bp.type] = bp;

	// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-

	bp.type = surf_coast;
	bp.tis = { 27, 0, 0, 0 };
	bp.feats = FEAT_FITFORTREES;
	bp.mmColor = 0xFFFF9523;
	bp.description = "Coast";
	bp.nativeSurfs = {};
	bp.nativeMnts = { surf_mountain_coast };
	bp.nativeTrees = { obj_oak };
	bp.nativeBushes = { obj_raspberry };
	bp.baseProdPen = 0.99f;
	bp.affBase = 0;
	bp.affMin = 0;
	bp.ageAdulthood = 0;
	bp.ageOldness = 0;
	bp.ageDecay = 0;
	bp.chanceToGrow = 0;
	blueprints[bp.type] = bp;

	// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-

	bp.type = surf_oasis;
	bp.tis = { 28, 0, 0, 0 };
	bp.feats = FEAT_FITFORTREES;
	bp.mmColor = 0xFF007F0E;
	bp.description = "Oasis";
	bp.nativeSurfs = {};
	bp.nativeMnts = { surf_mountain_oasis };
	bp.nativeTrees = { obj_palm };
	bp.nativeBushes = { obj_fern };
	bp.baseProdPen = 0.99f;
	bp.affBase = 0;
	bp.affMin = 0;
	bp.ageAdulthood = 0;
	bp.ageOldness = 0;
	bp.ageDecay = 0;
	bp.chanceToGrow = 0;
	blueprints[bp.type] = bp;

	// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-

	bp.type = surf_tropics;
	bp.tis = { 31, 0, 0, 0 };
	bp.feats = FEAT_FITFORTREES;
	bp.mmColor = 0xFF007F0E;
	bp.description = "Tropics";
	bp.nativeSurfs = {};
	bp.nativeMnts = { surf_mountain_tropics };
	bp.nativeTrees = { obj_palm };
	bp.nativeBushes = { obj_fern };
	bp.baseProdPen = 0.97f;
	bp.affBase = 0;
	bp.affMin = 0;
	bp.ageAdulthood = 0;
	bp.ageOldness = 0;
	bp.ageDecay = 0;
	bp.chanceToGrow = 0;
	blueprints[bp.type] = bp;

	// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-

	bp.type = surf_savanna;
	bp.tis = { 32, 0, 0, 0 };
	bp.feats = FEAT_FITFORTREES;
	bp.mmColor = 0xFFFF9523;
	bp.description = "Savanna";
	bp.nativeSurfs = {};
	bp.nativeMnts = { surf_mountain_savanna };
	bp.nativeTrees = { obj_baobab, obj_acacia };
	bp.nativeBushes = { obj_aloe };
	bp.baseProdPen = 0.95f;
	bp.affBase = 0;
	bp.affMin = 0;
	bp.ageAdulthood = 0;
	bp.ageOldness = 0;
	bp.ageDecay = 0;
	bp.chanceToGrow = 0;
	blueprints[bp.type] = bp;

	// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-

	bp.type = surf_tundra;
	bp.tis = { 33, 0, 0, 0 };
	bp.feats = FEAT_FITFORTREES;
	bp.mmColor = 0xFF636061;
	bp.description = "Tundra";
	bp.nativeSurfs = {};
	bp.nativeMnts = { surf_mountain_tundra };
	bp.nativeTrees = { obj_juniper };
	bp.nativeBushes = { obj_dwarfbirch };
	bp.baseProdPen = 0.80f;
	bp.affBase = 0;
	bp.affMin = 0;
	bp.ageAdulthood = 0;
	bp.ageOldness = 0;
	bp.ageDecay = 0;
	bp.chanceToGrow = 0;
	blueprints[bp.type] = bp;

	// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-

	bp.type = surf_mountain_reef;
	bp.tis = { 43, 0, 0, 0 };
	bp.feats = FEAT_MOUNTAIN | FEAT_WATERTILE;
	bp.mmColor = 0xFF000000;
	bp.description = "Reef";
	bp.nativeSurfs = {};
	bp.nativeMnts = { surf_mountain_reef };
	bp.nativeTrees = {};
	bp.nativeBushes = {};
	bp.baseProdPen = 0;
	bp.affBase = 0;
	bp.affMin = 0;
	bp.ageAdulthood = 0;
	bp.ageOldness = 0;
	bp.ageDecay = 0;
	bp.chanceToGrow = 0;
	blueprints[bp.type] = bp;

	// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-

	bp.type = surf_mountain_reefice;
	bp.tis = { 44, 0, 0, 0 };
	bp.feats = FEAT_MOUNTAIN | FEAT_WATERTILE;
	bp.mmColor = 0xFF000000;
	bp.description = "Ice Reef";
	bp.nativeSurfs = {};
	bp.nativeMnts = { surf_mountain_reefice };
	bp.nativeTrees = {};
	bp.nativeBushes = {};
	bp.baseProdPen = 0;
	bp.affBase = 0;
	bp.affMin = 0;
	bp.ageAdulthood = 0;
	bp.ageOldness = 0;
	bp.ageDecay = 0;
	bp.chanceToGrow = 0;
	blueprints[bp.type] = bp;

	// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-

	bp.type = surf_deepwater;
	bp.tis = { 45, 0, 0, 0 };
	bp.feats = FEAT_WATERTILE;
	bp.mmColor = 0xFF0E35DF;
	bp.description = "Deep Water";
	bp.nativeSurfs = {};
	bp.nativeMnts = { surf_mountain_reef };
	bp.nativeTrees = {};
	bp.nativeBushes = {};
	bp.baseProdPen = 0;
	bp.affBase = 0;
	bp.affMin = 0;
	bp.ageAdulthood = 0;
	bp.ageOldness = 0;
	bp.ageDecay = 0;
	bp.chanceToGrow = 0;
	blueprints[bp.type] = bp;

	// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-

	bp.type = surf_waterfresh;
	bp.tis = { 46, 0, 0, 0 };
	bp.feats = FEAT_WATERTILE | FEAT_FRESHWATER;
	bp.mmColor = 0xFF3F75FF;
	bp.description = "Fresh Water";
	bp.nativeSurfs = {};
	bp.nativeMnts = { surf_mountain_reef };
	bp.nativeTrees = {};
	bp.nativeBushes = {};
	bp.baseProdPen = 0;
	bp.affBase = 0;
	bp.affMin = 0;
	bp.ageAdulthood = 0;
	bp.ageOldness = 0;
	bp.ageDecay = 0;
	bp.chanceToGrow = 0;
	blueprints[bp.type] = bp;

	// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-

	bp.type = surf_waterfreshfrozen;
	bp.tis = { 14, 0, 0, 0 };
	bp.feats = FEAT_WATERTILE | FEAT_FRESHWATER;
	bp.mmColor = 0xFF00FFE5;
	bp.description = "Frozen Fresh Water";
	bp.nativeSurfs = {};
	bp.nativeMnts = { surf_mountain_reefice };
	bp.nativeTrees = {};
	bp.nativeBushes = {};
	bp.baseProdPen = 0;
	bp.affBase = 0;
	bp.affMin = 0;
	bp.ageAdulthood = 0;
	bp.ageOldness = 0;
	bp.ageDecay = 0;
	bp.chanceToGrow = 0;
	blueprints[bp.type] = bp;

	// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-

	bp.type = surf_lake;
	bp.tis = { 46, 0, 0, 0 };
	bp.feats = FEAT_WATERTILE | FEAT_FRESHWATER | FEAT_LAKE;
	bp.mmColor = 0xFF3F75FF;
	bp.description = "Lake";
	bp.nativeSurfs = {};
	bp.nativeMnts = { surf_mountain_reef };
	bp.nativeTrees = {};
	bp.nativeBushes = {};
	bp.baseProdPen = 0;
	bp.affBase = 0;
	bp.affMin = 0;
	bp.ageAdulthood = 0;
	bp.ageOldness = 0;
	bp.ageDecay = 0;
	bp.chanceToGrow = 0;
	blueprints[bp.type] = bp;

	// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-

	bp.type = surf_lakefrozen;
	bp.tis = { 14, 0, 0, 0 };
	bp.feats = FEAT_WATERTILE | FEAT_FRESHWATER | FEAT_LAKE;
	bp.mmColor = 0xFF00FFE5;
	bp.description = "Frozen Lake";
	bp.nativeSurfs = {};
	bp.nativeMnts = { surf_mountain_reefice };
	bp.nativeTrees = {};
	bp.nativeBushes = {};
	bp.baseProdPen = 0;
	bp.affBase = 0;
	bp.affMin = 0;
	bp.ageAdulthood = 0;
	bp.ageOldness = 0;
	bp.ageDecay = 0;
	bp.chanceToGrow = 0;
	blueprints[bp.type] = bp;

	// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
	// OBJECTS
	// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-

	bp.type = obj_oak;
	bp.tis = { 5, 4, 5, 6 };
	bp.feats = FEAT_TREE | FEAT_FLORA;
	bp.mmColor = 0x00000000;
	bp.description = "Oak";
	bp.nativeSurfs = { surf_grass };
	bp.nativeMnts = {};
	bp.nativeTrees = {};
	bp.nativeBushes = {};
	bp.baseProdPen = 0;
	bp.affBase = 1000;
	bp.affMin = 300;
	bp.ageAdulthood = WEEKSFROMYEARS(3);
	bp.ageOldness = WEEKSFROMYEARS(30);
	bp.ageDecay = WEEKSFROMYEARS(35);
	bp.chanceToGrow = 20000;
	blueprints[bp.type] = bp;

	// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-

	bp.type = obj_fir;
	bp.tis = { 16, 15, 16, 17 };
	bp.feats = FEAT_TREE | FEAT_FLORA;
	bp.mmColor = 0x00000000;
	bp.description = "Fir";
	bp.nativeSurfs = { surf_snow };
	bp.nativeMnts = {};
	bp.nativeTrees = {};
	bp.nativeBushes = {};
	bp.baseProdPen = 0;
	bp.affBase = 1000;
	bp.affMin = 0;
	bp.ageAdulthood = WEEKSFROMYEARS(3);
	bp.ageOldness = WEEKSFROMYEARS(40);
	bp.ageDecay = WEEKSFROMYEARS(45);
	bp.chanceToGrow = 80000;
	blueprints[bp.type] = bp;

	// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-

	bp.type = obj_cactus;
	bp.tis = { 19, 18, 19, 20 };
	bp.feats = FEAT_TREE | FEAT_FLORA;
	bp.mmColor = 0x00000000;
	bp.description = "Cactus";
	bp.nativeSurfs = { surf_desert };
	bp.nativeMnts = {};
	bp.nativeTrees = {};
	bp.nativeBushes = {};
	bp.baseProdPen = 0;
	bp.affBase = 1000;
	bp.affMin = 300;
	bp.ageAdulthood = WEEKSFROMYEARS(1);
	bp.ageOldness = WEEKSFROMYEARS(5);
	bp.ageDecay = WEEKSFROMYEARS(6);
	bp.chanceToGrow = 40000;
	blueprints[bp.type] = bp;

	// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-

	bp.type = obj_palm;
	bp.tis = { 25, 24, 25, 26 };
	bp.feats = FEAT_TREE | FEAT_FLORA;
	bp.mmColor = 0x00000000;
	bp.description = "Palm";
	bp.nativeSurfs = { surf_tropics, surf_oasis };
	bp.nativeMnts = {};
	bp.nativeTrees = {};
	bp.nativeBushes = {};
	bp.baseProdPen = 0;
	bp.affBase = 1000;
	bp.affMin = 300;
	bp.ageAdulthood = WEEKSFROMYEARS(3);
	bp.ageOldness = WEEKSFROMYEARS(30);
	bp.ageDecay = WEEKSFROMYEARS(35);
	bp.chanceToGrow = 10000;
	blueprints[bp.type] = bp;

	// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-

	bp.type = obj_juniper;
	bp.tis = { 38, 37, 38, 39 };
	bp.feats = FEAT_TREE | FEAT_FLORA;
	bp.mmColor = 0x00000000;
	bp.description = "Juniper";
	bp.nativeSurfs = { surf_tundra };
	bp.nativeMnts = {};
	bp.nativeTrees = {};
	bp.nativeBushes = {};
	bp.baseProdPen = 0;
	bp.affBase = 1000;
	bp.affMin = 300;
	bp.ageAdulthood = WEEKSFROMYEARS(3);
	bp.ageOldness = WEEKSFROMYEARS(30);
	bp.ageDecay = WEEKSFROMYEARS(35);
	bp.chanceToGrow = 60000;
	blueprints[bp.type] = bp;

	// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-

	bp.type = obj_baobab;
	bp.tis = { 41, 40, 41, 42 };
	bp.feats = FEAT_TREE | FEAT_FLORA;
	bp.mmColor = 0x00000000;
	bp.description = "Baobab";
	bp.nativeSurfs = { surf_savanna };
	bp.nativeMnts = {};
	bp.nativeTrees = {};
	bp.nativeBushes = {};
	bp.baseProdPen = 0;
	bp.affBase = 1000;
	bp.affMin = 300;
	bp.ageAdulthood = WEEKSFROMYEARS(5);
	bp.ageOldness = WEEKSFROMYEARS(100);
	bp.ageDecay = WEEKSFROMYEARS(110);
	bp.chanceToGrow = 200000;
	blueprints[bp.type] = bp;

	// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-

	bp.type = obj_acacia;
	bp.tis = { 55, 54, 55, 56 };
	bp.feats = FEAT_TREE | FEAT_FLORA;
	bp.mmColor = 0x00000000;
	bp.description = "Acacia";
	bp.nativeSurfs = { surf_savanna };
	bp.nativeMnts = {};
	bp.nativeTrees = {};
	bp.nativeBushes = {};
	bp.baseProdPen = 0;
	bp.affBase = 1000;
	bp.affMin = 300;
	bp.ageAdulthood = WEEKSFROMYEARS(3);
	bp.ageOldness = WEEKSFROMYEARS(50);
	bp.ageDecay = WEEKSFROMYEARS(60);
	bp.chanceToGrow = 60000;
	blueprints[bp.type] = bp;

	// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
	// BUSHES
	// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-

	bp.type = obj_raspberry;
	bp.tis = { 49, 49, 49, 49 };
	bp.feats = FEAT_BUSH | FEAT_FLORA;
	bp.mmColor = 0x00000000;
	bp.description = "Raspberry";
	bp.nativeSurfs = { surf_grass };
	bp.nativeMnts = {};
	bp.nativeTrees = {};
	bp.nativeBushes = {};
	bp.baseProdPen = 0;
	bp.affBase = 500;
	bp.affMin = 0;
	bp.ageAdulthood = WEEKSFROMMONTHS(1);
	bp.ageOldness = WEEKSFROMMONTHS(12);
	bp.ageDecay = WEEKSFROMMONTHS(13);
	bp.chanceToGrow = 5000;
	blueprints[bp.type] = bp;

	// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-

	bp.type = obj_camelthorn;
	bp.tis = { 50, 50, 50, 50 };
	bp.feats = FEAT_BUSH | FEAT_FLORA;
	bp.mmColor = 0x00000000;
	bp.description = "Camelthorn";
	bp.nativeSurfs = { surf_desert };
	bp.nativeMnts = {};
	bp.nativeTrees = {};
	bp.nativeBushes = {};
	bp.baseProdPen = 0;
	bp.affBase = 500;
	bp.affMin = 0;
	bp.ageAdulthood = WEEKSFROMMONTHS(1);
	bp.ageOldness = WEEKSFROMMONTHS(36);
	bp.ageDecay = WEEKSFROMMONTHS(39);
	bp.chanceToGrow = 10000;
	blueprints[bp.type] = bp;

	// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-

	bp.type = obj_dwarfbirch;
	bp.tis = { 51, 51, 51, 51 };
	bp.feats = FEAT_BUSH | FEAT_FLORA;
	bp.mmColor = 0x00000000;
	bp.description = "Dwarf birch";
	bp.nativeSurfs = { surf_tundra };
	bp.nativeMnts = {};
	bp.nativeTrees = {};
	bp.nativeBushes = {};
	bp.baseProdPen = 0;
	bp.affBase = 500;
	bp.affMin = 0;
	bp.ageAdulthood = WEEKSFROMMONTHS(1);
	bp.ageOldness = WEEKSFROMMONTHS(24);
	bp.ageDecay = WEEKSFROMMONTHS(26);
	bp.chanceToGrow = 10000;
	blueprints[bp.type] = bp;

	// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-

	bp.type = obj_aloe;
	bp.tis = { 52, 52, 52, 52 };
	bp.feats = FEAT_BUSH | FEAT_FLORA;
	bp.mmColor = 0x00000000;
	bp.description = "Aloe";
	bp.nativeSurfs = { surf_savanna };
	bp.nativeMnts = {};
	bp.nativeTrees = {};
	bp.nativeBushes = {};
	bp.baseProdPen = 0;
	bp.affBase = 500;
	bp.affMin = 0;
	bp.ageAdulthood = WEEKSFROMMONTHS(1);
	bp.ageOldness = WEEKSFROMMONTHS(24);
	bp.ageDecay = WEEKSFROMMONTHS(26);
	bp.chanceToGrow = 7500;
	blueprints[bp.type] = bp;

	// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-

	bp.type = obj_fern;
	bp.tis = { 53, 53, 53, 53 };
	bp.feats = FEAT_BUSH | FEAT_FLORA;
	bp.mmColor = 0x00000000;
	bp.description = "Fern";
	bp.nativeSurfs = { surf_tropics };
	bp.nativeMnts = {};
	bp.nativeTrees = {};
	bp.nativeBushes = {};
	bp.baseProdPen = 0;
	bp.affBase = 500;
	bp.affMin = 0;
	bp.ageAdulthood = WEEKSFROMMONTHS(1);
	bp.ageOldness = WEEKSFROMMONTHS(24);
	bp.ageDecay = WEEKSFROMMONTHS(26);
	bp.chanceToGrow = 2500;
	blueprints[bp.type] = bp;
}
