#include "Item.h"
#include <iostream>

string Item::getName()
{
	return name;
}

string Item::getDescription()
{
	return description;
}

int Item::getDamage()
{
	return damage;
}

Item::Item()
{
	name = "";
	description = "";
	damage = 0;
}

Item::Item(string title, string desc, int dam)
{
	name = title;
	description = desc;
	damage = dam;
}