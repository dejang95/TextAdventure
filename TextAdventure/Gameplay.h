#pragma once
#include <iostream>
#include <string>
using namespace std;

class Gameplay
{
	string name;
	int age, money, health;
	int checkpoint;
	
	const int map_max = 100;
	bool position[100][100];
	int ver, hor;

	int item_num;
	int players_items[100];
	int free_slot;

public:

	void intro();

	void players_data();

	void actions();

	void move();

	bool wall(int vertically, int horizontally);

	void map_items();

	void help();

	void list_invetory();

	void pick();

	void use ();

	void location();

	bool picked();

	void checkpoints();

	void checkpoint_null();

	void checkpoint_one();

	void checkpoint_two();

	Gameplay(string name = "player", int age = 18 );
	
	~Gameplay();
};

