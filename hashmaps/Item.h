#pragma once
#include <string>

using std::string;

class Item
{
public:
	string getName();
	string getDescription();
	int getDamage();

	Item();
	Item(string, string, int);
private:
	string name;
	string description;
	int damage;
};