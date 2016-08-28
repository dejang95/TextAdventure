#include <iostream>
#include <string>
#include "stdafx.h"
#include "Gameplay.h"

using namespace std;

void Gameplay::actions() {

	string action;

	while (true) {

		cout << " What would you like to do next? [ Hint: If you wish to see the list of avaliable commands, type in ''help''.] " << endl;
		cin >> action;

		if (action == "move") move();
		else if (action == "help") help();
		else if (action == "pick") pick();
		else if (action == "inventory") list_invetory();
		else if (action == "location") location();
		else if (action == "stats") players_data();
		else if (action == "use") use();
		else if (action == "clear") system("cls");
		else cout << " Please enter an existing command! " << endl;

	}
}

void Gameplay::move() {

	string move;

	cout << " In what direction would you like to move?" << endl;
	cin >> move;

	if (move == "north" || move == "N" || move == "North") {

		if (ver < map_max && (!wall(ver+1,hor)) ) {

			position[ver][hor] = false;

			position[++ver][hor] = true;

			map_items();

		}

		else cout << " Street is blocked, you cannot go there! " << endl;
	}

	else if (move == "north-east" || move == "NE" || move == "ne" || move == "North-East") {

		if (ver < map_max && hor > 0) {

			position[ver][hor] = false;

			position[++ver][--hor] = true;

			map_items();

		}

		else cout << " Street is blocked, you cannot go there! " << endl;
	}

	else if (move == "north-west" || move == "NW" || move == "nw" || move == "North-West") {

		if (ver < map_max && hor < map_max) {

			position[ver][hor] = false;

			position[++ver][++hor] = true;

			map_items();

		}

		else cout << " Street is blocked, you cannot go there! " << endl;

	}

	else if (move == "south" || move == "S" || move == "South") {

		if (ver > 0) {

			position[ver][hor] = false;

			position[--ver][hor] = true;

			map_items();

		}

		else cout << " This street is blocked, you cannot go there! " << endl;

	}

	else if (move == "SE" || move == "se" || move == "South-East" || move == "south-east") {

		if (ver > 0 && hor > 0) {

			position[ver][hor] = false;

			position[--ver][--hor] = true;

			map_items();

		}

		else cout << " This street is blocked, you cannot go there! " << endl;

	}

	else if (move == "SW" || move == "sw" || move == "South-West" || move == "south-west") {

		if (ver > 0 && hor < map_max) {

			position[ver][hor] = false;

			position[--ver][++hor] = true;

			map_items();

		}

		else cout << " This street is blocked, you cannot go there! " << endl;

	}

	else if (move == "east" || move == "E" || move == "East") {

		if (hor > 0) {

			position[ver][hor] = false;

			--hor;

			position[ver][hor] = true;

			map_items();

		}

		else cout << " This street is blocked, you cannot go there! " << endl;
	}

	else if (move == "west" || move == "W" || move == "West") {

		if (hor < map_max) {

			position[ver][hor] = false;

			++hor;

			position[ver][hor] = true;

			map_items();

		}

		else cout << " This street is blocked, you cannot go there! " << endl;

	}

	else cout << " This direction doesn't exist! " << endl;

	checkpoints();

}

void Gameplay::help() {

	cout << endl;
	cout << " **** LIST OF AVALIABLE COMMANDS **** " << endl;
	cout << endl;
	cout << " ''move'' - gives you an option to move in wanted direction" << endl;
	cout << " ''help'' - helps you with commands" << endl;
	cout << " ''stats'' - gives you your current stats ( e.d Money, Health etc.. ) " << endl;
	cout << " ''pick'' - picks up an item and stores it in an inventory " << endl;
	cout << " ''use'' - uses a specific item you have in inventory or you've just picked up " << endl;
	cout << " ''inventory'' - gives you an overview of your Inventory " << endl;
	cout << " ''location'' - gives you your exact current location on the map " << endl;
	cout << " ''clear'' - clears the screen " << endl;
	cout << endl;

}

void Gameplay::list_invetory() {					// ***** LIST INVENTORY *****
	
	cout << endl;
	cout << " ****** INVENTORY ******" << endl;
	cout << endl;

	if (!free_slot) cout << " Your inventory is empty! " << endl;

	for (int i = 0; players_items[i] != 0; i++) {

		switch (players_items[i]) {

		case 1: cout << " 1. You have an USB Flash drive. " << endl;
			break;

		case 2: cout << " 2. You've have an Mobile Sim Card. " << endl;
			break;

		case 3: cout << " 3. You've have an SD Card. " << endl;
			break;

		case 4: cout << " 4. You've have a light torch. " << endl;
			break;

		}

	}

	cout << endl;

}

void Gameplay::use() {							// ****** USE ****** ( Not finished yet ) 

	if (!free_slot) {

		cout << " Your inventory is empty. There is nothing to use! " << endl;

	}

	else {

		int answer;

		cout << " In your Invetory: " << endl;
		cout << endl;
		list_invetory();

		cout << endl;
		cout << " What Item do you wish to use? ( Choose a number ) " << endl;
		cin >> answer;

		item_num = answer;

		if (picked()) {

			switch (answer) {

			case 1: cout << "You've chosen the USB!" << endl;				// replace cout statements with real functions
				break;

			case 2: cout << " You've chosen the SIM Card!" << endl;
				break;

			case 3: cout << " You've chosen the SD Card! " << endl;
				break;

			case 4: cout << " You've chosen the Light Torch! " << endl;
				break;
			
			}

		}

		else {

			cout << " You don't have an item under number " << answer << " in your inventory! Please, try again. " << endl;
			cout << endl;
			use();
		}
	}

	actions();

}

void Gameplay::location() {

	cout << endl;
	cout << " Your current location is " << ver << " vertically and " << hor << " horizontally. " << endl;
	cout << endl;

}

void Gameplay::players_data() {

	cout << endl;
	cout << " Players name: " << name << endl;
	cout << " Player age: " << age << endl;
	cout << " Money: " << money << " $" << endl;
	cout << " Health: " << health << " hp" << endl;
	cout << endl;
}


void Gameplay::pick() {

	if (item_num == 0) {

		cout << " There is no item at this location to pick! " << endl;

	}

	else {

		players_items[free_slot++] = item_num;
		cout << " This Item has now been saved to your Inventory!" << endl;

	}
}

bool Gameplay::picked() {

	for (int i = 0; players_items[i] != 0; i++) {

		if ( players_items[i] == item_num) {

			return true;

		}

	}

	return false;

}

void Gameplay::checkpoints() {

	if (position[1][2]) {

		cout << endl;
		cout << "MESSAGE: Success! You found the terminal! " << endl;
		cout << endl;

		cout << " ***OBJECTIVE*** " << endl;
		checkpoint_one();

	}

	if (position[4][6]) {

		cout << endl;
		cout << "MESSAGE: Success! You made it to your second checkpoint! " << endl;
		cout << endl;

		cout << " ***OBJECTIVE*** " << endl;
		checkpoint_two();

	}

}