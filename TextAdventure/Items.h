#pragma once
#include <iostream>
using namespace std;

class Items
{
	int axis_X, axis_Y;
	int checkpoint;

	int item_num;
	int players_items[100];	// inventory
	int free_slot;	// tracks the next free slot in the inventory

	bool item;

public:

	Items(int axis_Y = 1, int axis_X = 0, int checkpoint = 0);
	~Items();

	int locate();	// checks if the user is on the position of an item
	void read_located_item();	// if on user's position there is an item, it reads what item it is
	void toss();	//throws an item on the ground. Couldn't use "throw()" because that word has a meaning in C++. 
	void save(); // saves item in the inventory
	void read_inventory();	// reads inventory
	bool check_if_picked();	// checks if the item has already been picked
	void update_values(int axis_Y, int axis_X, int checkpoint); // updates location and checkpoint values from function "Gameplay::move() and Gameplay::actions()

};

