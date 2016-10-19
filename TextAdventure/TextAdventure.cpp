// TextAdventure.cpp ( main.cpp ) 

#include <iostream>
#include <string>
#include "stdafx.h"
#include "Gameplay.h"

using namespace std;

int main()
{
	int age = 0;
	string name;
	
	cout << " Please enter your name: " << endl;
	getline(cin, name);

	cout << " Now enter your age: " << endl;
	cin >> age;

	system("cls");

	Gameplay player (name, age);

	player.intro();

	cout << " **** OBJECTIVE **** " << endl;
	player.checkpoint_null();

	return 0;
}

