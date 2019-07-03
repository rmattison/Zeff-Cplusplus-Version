#include "Enemy.h"
#include <iostream>

void Enemy::printName()
{
	std::cout << name;
}

string Enemy::getDescription()
{
	return description;
}

void Enemy::loseHP(int lost)
{
	hp -= lost;
}

string Enemy::getName()
{
	return name;
}

int Enemy::getHP()
{
	return hp;
}

int Enemy::getDamage()
{
	return damage;
}

Enemy::Enemy(string title, string desc, int health, int dam)
{
	name = title;
	description = desc;
	hp = health;
	damage = dam;
}