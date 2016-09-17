#include <iostream>
#include <string>
#include "stdafx.h"
#include "Gameplay.h"
#include "Items.h"
#include "Print.h"
using namespace std;

void Gameplay::enter_command() {

	string action;
	string direction;

	while (true) {

		item.update_values(axis_Y, axis_X, checkpoint);
		print.update_values(axis_Y, axis_X, name, age, health, money);

		cout << " What would you like to do next? [ Hint: If you wish to see the list of avaliable commands, type in ''help''.] " << endl;
		cin >> action;

		if (action == "go") { cin >> direction;  move_player(direction); }
		else if (action == "help") print.commands();
		else if (action == "pick") item.save();
		else if (action == "inventory") item.read_inventory();
		else if (action == "location") print.location();
		else if (action == "stats") print.players_data();
		//else if (action == "use") item.use();
		else if (action == "clear") system("cls");
		else cout << " Please enter an existing command! " << endl;

	}
}

void Gameplay::move_player(string direction) {	

	int old_axis_X = axis_X;		//saves current position of ver and hor before moving
	int old_axis_Y = axis_Y;

	if (direction == "north" || direction == "N" || direction == "North") {

		if (axis_Y < map_max && (!check_for_wall(axis_Y+1,axis_X)) ) ++axis_Y;		// wall function yet to be implemented

		else cout << " Street is blocked, you cannot go there! " << endl;
	}

	else if (direction == "north-east" || direction == "NE" || direction == "ne" || direction == "North-East") {

		if (axis_Y < map_max && axis_X > 0) {

			++axis_Y;
			--axis_X;
		}

		else cout << " Street is blocked, you cannot go there! " << endl;
	}

	else if ( direction == "north-west" || direction == "NW" || direction == "nw" || direction == "North-West") {

		if (axis_Y < map_max && axis_X < map_max) {

			++axis_Y;
			++axis_X;
		}

		else cout << " Street is blocked, you cannot go there! " << endl;

	}

	else if (direction == "south" || direction == "S" || direction == "South") {

		if (axis_Y > 0) --axis_Y;

		else cout << " This street is blocked, you cannot go there! " << endl;

	}

	else if (direction == "SE" || direction == "se" || direction == "South-East" || direction == "south-east") {

		if (axis_Y > 0 && axis_X > 0) {

			--axis_Y;
			--axis_X;

		}

		else cout << " This street is blocked, you cannot go there! " << endl;

	}

	else if (direction == "SW" || direction == "sw" || direction == "South-West" || direction == "south-west") {

		if (axis_Y > 0 && axis_X < map_max) {

			--axis_Y;
			++axis_X;
		}

		else cout << " This street is blocked, you cannot go there! " << endl;

	}

	else if (direction == "east" || direction == "E" || direction == "East") {

		if (axis_X > 0) --axis_X;

		else cout << " This street is blocked, you cannot go there! " << endl;
	}

	else if (direction == "west" || direction == "W" || direction == "West") {

		if (axis_X < map_max) ++axis_X;

		else cout << " This street is blocked, you cannot go there! " << endl;

	}

	else cout << " This direction doesn't exist! " << endl;

	if (old_axis_Y != axis_Y || old_axis_X != axis_X) {

		item.update_values(axis_Y, axis_X, checkpoint);
		item.read_located_item();
		checkpoints_position();
	
	}
}