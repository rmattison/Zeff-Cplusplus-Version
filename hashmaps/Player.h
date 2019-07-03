#pragma once
#include <string>
#include <vector>
#include "Scene.h"

using std::string;

class Item;

class Player
{
public:
	Player(string, string, int, int);

	Scene* getCurrent();
	void setCurrent(Scene*);
	void printName();
	void printDescription();
	void loseHP(int);
	void setWeapon(Item);
	int getHP();
	int getDamage();
private:
	Scene *current;
	string name;
	string description;
	int hp;
	int damage;
};