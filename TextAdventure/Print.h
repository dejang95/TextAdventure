#pragma once
#include <iostream>
#include <string>
using namespace std;

class Print
{
	string name;
	int age, money, health;
	int x_axis, y_axis;

public:

	Print(int x_axis = 1, int y_axis = 0, string name = "player", int age = 18, int health = 100, int money = 20);

	~Print();

	void players_data();	// reads players data like: name, age, money, health

	void commands();	// gives a list of commands

	void location();	// give an exact position on the map
	
	void update_values(int y_axis, int x_axis, string name, int age, int health, int money);	// updates values of variables trough this function
};

