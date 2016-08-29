#pragma once
#include <iostream>
#include <string>
using namespace std;

class Gameplay
{
	string name;
	int age, money, health;	
	int checkpoint;		// tracks the checkpoints that the user have passed
	
	const int map_max = 100;	// the possible value of "hor" or "ver" cannot be greater than "map_max"
	int ver, hor;	

	int item_num;
	int players_items[100];	// inventory
	int free_slot;	// tracks the next free slot in the inventory

public:

	void sitrep();		// situation report

	void players_data();	// reads players data like: name, age, money, health

	void actions();		// prompts the user to enter the next action

	void move();	// makes it possible for the user to move in wanted direction

	bool wall(int vertically, int horizontally);	// sets walls on the map for the user

	void map_items();	// checks if on the user's position there is a certain item

	void help();	// gives a list of commands that the user can enter in order to play the game

	void list_invetory();	// gives a list of items in the inventory

	void pick();	// if the item have been found, makes it possible to save an item in the inventory

	void use ();	// makes the use of the items stored in the inventory

	void location();	// reads the users exact location on the map

	bool picked();	// checks if the item was already picked and stored in the inventory

	void checkpoints();	// checks if on the user's position there is a checkpoint

	void checkpoint_null();	// first objective

	void checkpoint_one();	// second objective

	void checkpoint_two();	// third objective

	Gameplay(string name = "player", int age = 18 );	// default construcor
	
	~Gameplay();	// default deconstructor
};

