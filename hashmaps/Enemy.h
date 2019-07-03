#pragma once
#include <string>

using std::string;

class Enemy
{
public:
	void printName();
	void loseHP(int);
	string getName();
	string getDescription();
	int getHP();
	int getDamage();

	Enemy(string, string, int, int);

private:
	string name;
	string description;
	int hp;
	int damage;
};