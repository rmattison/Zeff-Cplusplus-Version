//2ND WINDOW ADDS ENENY WHEN IN BATTLE
//CREATE A FUNCTION TO DO THIS
//FINISH LATER MAP
//HAVE INVENTORY TO READ THE NOTE.
//ADD HEALING AT BOTTOM OF CAVE AND A WIZARD TO DO IT.
///THE DARK ESSENCE DOES IT
//MAKE IT SO A SECOND ROOM DESCIPTION PRINTS WHEN A ROOM HAS BEEN VISITED BEFORE
//MAKE SECOND WINDOW TO POPULATE THE MAP AS THE PLAYER TRAVELS

#include "World.h"
#include "Player.h"
#include "Item.h"
#include "Enemy.h"
#include "Paths.h"
#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;
using std::string;

//load stuff
Player player("Robby", "The Author.", 100, 2);

Item noItem("none", "none", 0);
Item potion("Potion", "A blue potion", 5);

Enemy noEnemy("none", "none", 0, 0);
Enemy troll("Troll!", "A big troll.", 2, 1);

//for user input
string val;


//---------------------------------------------------------

int main()
{
	constructWorld();

	player.setCurrent(scenes[Start]);
	player.getCurrent()->enter(player);

	while (player.getHP() > 0)
	{
		cout << "\nWhich way do you go?\n" << ">>> ";
		cin >> val;

		if (player.getCurrent()->checkpath(val))
		{
			player.setCurrent(player.getCurrent()->getRoom(val));
			player.getCurrent()->enter(player);
		}
		else
		{
			player.getCurrent()->printPaths();
		}
	}

	player.setCurrent(scenes[End]);
	player.getCurrent()->enter(player);
	cout << "\n\nType 'quit' to exit. \n>>>";
	//THIS DOESN'T WORK
	//cin.get();
	cin >> val;
}

//--------------------------------------------------------