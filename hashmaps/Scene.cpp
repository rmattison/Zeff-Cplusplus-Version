#include "Scene.h"
#include "Enemy.h"
#include "Player.h"
#include "Item.h"
#include <iostream>
#include <string>
#include <chrono>
#include <thread>

using namespace std;
using std::string;

void Scene::buildPaths(string p1, Scene* s1)
{
	screenMap.put(p1, s1);
}

void Scene::buildPaths(string p1, Scene* s1, string p2, Scene* s2)
{
	screenMap.put(p1, s1);
	screenMap.put(p2, s2);
}

void Scene::buildPaths(string p1, Scene* s1, string p2, Scene* s2, string p3, Scene* s3)
{
	screenMap.put(p1, s1);
	screenMap.put(p2, s2);
	screenMap.put(p3, s3);
}

void Scene::buildPaths(string p1, Scene* s1, string p2, Scene* s2, string p3, Scene* s3, string p4, Scene* s4) 
{
	screenMap.put(p1, s1);
	screenMap.put(p2, s2);
	screenMap.put(p3, s3);
	screenMap.put(p4, s4);
}

void Scene::buildEnemy(string name, string desc, int health, int dam)
{
	enemy = new Enemy(name, desc, health, dam);
}

void Scene::buildItem(string name, string desc, int dam)
{
	item = new Item(name, desc, dam);
}

bool Scene::checkpath(string path)
{
	return screenMap.check(path);
}

string Scene::getName()
{
	return roomName;
}

void Scene::printPaths()
{
	cout << endl << paths << endl;
}

void Scene::printDescription()
{
	cout << description;
}

string Scene::getDescription()
{
	return description;
}

void Scene::setDescription(string desc)
{
	description = desc;
}

Scene* Scene::getRoom(string input)
{
	Scene* temp;
	temp = screenMap.get(input);
	return temp;
}

Scene::Scene(string name, string desc, string whereto)
{
	roomName = name;
	description = desc;
	paths = whereto;
	firstTime = true;
}

Scene::~Scene()
{
	if (enemy != nullptr)
		delete enemy;
}


void dotdotdot()
{
	std::this_thread::sleep_for(std::chrono::milliseconds(1000));
	cout << " . ";
	std::this_thread::sleep_for(std::chrono::milliseconds(1000));
	cout << " . ";
	std::this_thread::sleep_for(std::chrono::milliseconds(1000));
	cout << " . ";
	std::this_thread::sleep_for(std::chrono::milliseconds(1000));
	cout << " . ";
	std::this_thread::sleep_for(std::chrono::milliseconds(1000));
	cout << " . " << endl << endl;
	std::this_thread::sleep_for(std::chrono::milliseconds(2000));
}


void Battle(Player &player, Enemy* enemy)
{
	while (player.getHP() > 0 && enemy->getHP() > 0)
	{
		if (player.getHP() > enemy->getHP())
		{
			enemy->loseHP(player.getDamage());
			if (enemy->getHP() > 0)
			{
				player.loseHP(enemy->getDamage());
			}
		}
		else
		{
			player.loseHP(enemy->getDamage());
			enemy->loseHP(player.getDamage());
		}
	}
}


void Scene::enter(Player& playa)
{
	system("CLS");

	if (firstTime == true)
	{
		cout << description;
		firstTime = false;
	}

	else { cout << roomName; }

	if (enemy != nullptr && enemy->getHP() > 0)
	{
		cout << "\nYou come across a " << enemy->getName() << endl;
		cout << enemy->getDescription() << endl;
		cout << "You enter battle with the " << enemy->getName() << endl << endl;

		Battle(playa, enemy);

		dotdotdot();

		if (playa.getHP() > 0)
		{
			cout << "You are victorious!!!" << endl;
			cout << "Your hp is now " << playa.getHP() << "." << endl;
			cout << "---------------------" << endl;
		}
		else
			cout << "You are DEAD." << endl;
	}

	if (item != nullptr && item->getDamage() > playa.getDamage())
	{
		cout << "The " << enemy->getName() << " dropped a " << item->getName() << "." << endl;
		cout << "You pick it up!" << endl;
		cout << item->getDescription() << endl << endl;
		cout << "Your damage increased by " << item->getDamage() - playa.getDamage() << "!" << endl;
		playa.setWeapon(*item);
	}

	//cout << endl << endl << "You may now make a move" << endl << endl;

}