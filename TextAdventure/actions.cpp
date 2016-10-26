#include <iostream>
#include <string>
#include "stdafx.h"
#include "Gameplay.h"
#include "Items.h"
#include "Print.h"
#include "Walls.h"
using namespace std;

void Gameplay::enter_command() {

	string action;
	string direction;

	while (true) {

		item.update_values(axis_Y, axis_X, checkpoint);
		print.update_values(axis_Y, axis_X, name, age, health, money);

		cout << " What would you like to do next? [ Hint: If you wish to see the list of avaliable commands, type in ''help''.] " << endl;
		cin >> action;

		if (action == "go" || action == "g") { getline(cin, direction);  move_player(direction); }
		else if (action == "help" || action == "h") print.commands();
		else if (action == "pick" || action == "p") item.save();
		else if (action == "inventory" || action == "i") item.read_inventory();
		else if (action == "location" || action == "l") print.location();
		else if (action == "stats" || action == "s") print.players_data();
		//else if (action == "use") item.use();
		else if (action == "clear" || action == "c") system("cls");
		else cout << " Please enter an existing command! " << endl;

	}
}

string Gameplay::identify_direction(string direction)
{
	if (direction == " north" || direction == " N" || direction == " North" || direction == " n") return "n";
	else if (direction == " north east" || direction == " NE" || direction == " ne" || direction == " North East") return "ne";
	else if (direction == " north west" || direction == " NW" || direction == " nw" || direction == " North West") return "nw";
	else if (direction == " south" || direction == " S" || direction == " South" || direction == " s") return "s";
	else if (direction == " SE" || direction == " se" || direction == " South East" || direction == " south east") return "se";
	else if (direction == " SW" || direction == " sw" || direction == " South West" || direction == " south west") return "sw";
	else if (direction == " east" || direction == " E" || direction == " East" || direction == " e") return "e";
	else if (direction == " west" || direction == " W" || direction == " West" || direction == " w") return "w";
	else return "0";
}

void Gameplay::move_player(string direction) {

	int old_axis_X = axis_X;		//saves current position of ver and hor before moving
	int old_axis_Y = axis_Y;

	if (!wall.check_for_walls(axis_X, axis_Y, identify_direction(direction)) ) {

		if (identify_direction(direction) == "n") ++axis_Y;
		else if (identify_direction(direction) == "ne") { ++axis_Y; ++axis_X; }
		else if (identify_direction(direction) == "nw") { ++axis_Y; --axis_X; }
		else if (identify_direction(direction) == "s") --axis_Y;
		else if (identify_direction(direction) == "se") { --axis_Y; ++axis_X; }
		else if (identify_direction(direction) == "sw") { --axis_Y; --axis_X; }
		else if (identify_direction(direction) == "e") ++axis_X;
		else if (identify_direction(direction) == "w") --axis_X;
		else cout << " This direction doesn't exist! " << endl;
	}

	else cout << " This direction is blocked, you cannot go there! " << endl;

	if (old_axis_Y != axis_Y || old_axis_X != axis_X) {
		item.update_values(axis_Y, axis_X, checkpoint);
		item.read_located_item();
		checkpoints_position();
	}
}