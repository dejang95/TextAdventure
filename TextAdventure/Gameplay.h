#pragma once
#include <iostream>
#include <string>
#include "Print.h"
#include "Items.h"
using namespace std;

class Gameplay
{
	string name;
	int age, money, health;	
	int checkpoint;		// tracks the checkpoints that the user have passed
	
	const int map_max = 100;	// the possible value of "hor" or "ver" cannot be greater than "map_max"
	int	axis_X, axis_Y;

	Items item;
	Print print;

public:

	Gameplay(string name = "Player", int age = 18);	// default construcor

	~Gameplay();	// default deconstructor

	void intro();		// situation report

	void enter_command();		// prompts the user to enter the next action

	void move_player(string direction);	// makes it possible for the user to move in wanted direction

	bool check_for_wall(int vertically, int horizontally);	// sets walls on the map for the user

	void checkpoints_position();	// checks if on the user's position there is a checkpoint

	void checkpoint_null();	// first objective

	void checkpoint_one();	// second objective

	void checkpoint_two();	// third objective

};

