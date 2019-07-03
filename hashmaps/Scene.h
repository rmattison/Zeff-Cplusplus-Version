#pragma once
#include <string>
#include "Paths.h"

using std::string;

class Player;
class Enemy;
class Item;

class Scene
{
public:
	Scene(string, string, string);
	~Scene();

	void buildPaths(string p1, Scene* s1);
	void buildPaths(string p1, Scene* s1, string p2, Scene* s2);
	void buildPaths(string p1, Scene* s1, string p2, Scene* s2, string p3, Scene* s3);
	void buildPaths(string p1, Scene* s1, string p2, Scene* s2, string p3, Scene* s3, string p4, Scene* s4);

	void buildEnemy(string, string, int, int);

	void buildItem(string, string, int);

	string getName();
	string getDescription();
	Scene* getRoom(string);
	bool checkpath(string path);
	void printPaths();
	void printDescription();
	void setDescription(string);
	void enter(Player&);
private:
	Paths screenMap;
	string roomName;
	string description;
	string paths;
	Enemy* enemy = nullptr;
	Item* item = nullptr;
	bool firstTime;
};