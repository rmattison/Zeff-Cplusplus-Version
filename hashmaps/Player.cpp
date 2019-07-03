#include "Player.h"
#include "Item.h"
#include "Scene.h"
#include <iostream>

void Player::printName()
{
	std::cout << name;
}

void Player::printDescription()
{
	std::cout << description;
}

void Player::loseHP(int lost)
{
	hp -= lost;
}

void Player::setWeapon(Item weapon)
{
	damage = weapon.getDamage();
}

int Player::getHP()
{
	return hp;
}

int Player::getDamage()
{
	return damage;
}

void Player::setCurrent(Scene* scene)
{
	current = scene;
}

Scene*  Player::getCurrent()
{
	return current;
}

Player::Player(string title, string desc, int health, int dam)
{
	name = title;
	description = desc;
	hp = health;
	damage = dam;
}