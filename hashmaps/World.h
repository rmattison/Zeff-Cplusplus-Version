#pragma once
#include "Scene.h"
#include "Lines.h"

enum Rooms { Start, North, TrollDen, KillerTroll, South, FishingHut, Oven, East, Barn, BarnDown, West, CaveMain, CaveWest, CaveDown, End };

Scene *scenes[14];

//-----------------------------------------------

Scene* startScreen = new Scene("Start", intro, "You can go North, South, East, and West.");
Scene* lastScreen = new Scene("End", "YOU DIED", "None");

Scene* north = new Scene("North", north_line, "You can go North and South.");
Scene* trollDen = new Scene("Troll Den", trollDen_line, "You can go South and West.");
Scene* killerTroll = new Scene("Killer Troll", killerTroll_line, "You can go East.");

Scene* south = new Scene("South", south_line, "You can go North and West.");
Scene* fishingHut = new Scene("Fishing Hut", fishingHut_line, "You can go East.");
Scene* oven = new Scene("Oven", oven_line, "You can go East.");

Scene* east = new Scene("East", east_line, "You can go East and West.");
Scene* barn = new Scene("Barn", barn_line, "You can go West and Down.");
Scene* barnDown = new Scene("Barn Basement", barnDown_line, "You can go Up.");

Scene* west = new Scene("West", west_line, "You can go North and East.");
Scene* caveMain = new Scene("Cave", caveMain_line, "You can go South and West.");
Scene* caveWest = new Scene("Inner Cave", caveWest_line, "You can go East and Down.");
Scene* caveDown = new Scene("Lower Cave", caveDown_line, "You can go Up.");

//-----------------------------------------------

void constructWorld()
{
	scenes[Start] = startScreen;
	scenes[End] = lastScreen;

	scenes[North] = north;
	scenes[TrollDen] = trollDen;
	scenes[KillerTroll] = killerTroll;

	scenes[South] = south;
	scenes[FishingHut] = fishingHut;
	scenes[Oven] = oven;

	scenes[East] = east;
	scenes[Barn] = barn;
	scenes[BarnDown] = barnDown;

	scenes[West] = west;
	scenes[CaveMain] = caveMain;
	scenes[CaveWest] = caveWest;
	scenes[CaveDown] = caveDown;


	//-----PATHS-----//
	scenes[Start]->buildPaths("north", scenes[North], "south", scenes[South], "west", scenes[West], "east", scenes[East]);
	scenes[End]->buildPaths("north", scenes[North]);

	//North
	scenes[North]->buildPaths("north", scenes[TrollDen], "south", scenes[Start]);
	scenes[North]->buildEnemy("Troll", "It's a huge beast.", 10, 5);
	scenes[North]->buildItem("Club", "A giant piece of wood.", 10);

	scenes[TrollDen]->buildPaths("south", scenes[North], "west", scenes[KillerTroll]);

	scenes[KillerTroll]->buildPaths("east", scenes[TrollDen]);
	scenes[KillerTroll]->buildEnemy("Big Troll", "This Troll is even bigger than the last one!", 20, 12);
	scenes[KillerTroll]->buildItem("Battle-Axe", "A hulking axe with blades on both ends.", 25);

	//South
	scenes[South]->buildPaths("north", scenes[North], "west", scenes[FishingHut]);
	scenes[FishingHut]->buildPaths("oven", scenes[Oven]);
	scenes[Oven]->buildPaths("east", scenes[South]);

	//East
	scenes[East]->buildPaths("east", scenes[Barn], "west", scenes[Start]);
	scenes[Barn]->buildPaths("down", scenes[BarnDown], "west", scenes[East]);

	scenes[BarnDown]->buildPaths("up", scenes[Barn]);
	scenes[BarnDown]->buildEnemy("Dark Beast", "No light illuminates this beast.", 25, 10);
	scenes[BarnDown]->buildItem("Dark Essence", "A formless black smoke.", 30);

	//West
	scenes[West]->buildPaths("north", scenes[CaveMain], "east", scenes[Start]);
	scenes[CaveMain]->buildPaths("south", scenes[West], "west", scenes[CaveWest]);
	scenes[CaveWest]->buildPaths("down", scenes[CaveDown], "east", scenes[CaveMain]);
	scenes[CaveDown]->buildPaths("up", scenes[CaveMain]);
}