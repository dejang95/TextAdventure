// TextAdventure.cpp ( main.cpp ) 

#include <iostream>
#include <string>
#include "stdafx.h"
#include "Gameplay.h"

using namespace std;

void intro() {

	cout << " There we go. After so many years of Hollywood projections, one of them has finally come true. " << endl;
	cout << " The third kind has invaded our world, and now we are at the greatest war we have ever been in. " << endl;
	cout << " Many have fought this fight but lost. Do you have what it takes to save the humanity? " << endl;
	cout << endl;
}

int main()
{
	int age = 0;
	string name;
	char answer;

	intro();
	
	cout << " Please enter your name: " << endl;
	cin >> name;

	cout << " Now enter your age: " << endl;
	cin >> age;

	system("cls");

	Gameplay player (name, age);
	
	player.intro();

	cout << " Request further instructions? [ Y/N ]" << endl;
	cin >> answer;

	system("cls");

	if (answer == 'Y' || answer == 'y') {

		cout << " **** OBJECTIVE **** " << endl;
		player.checkpoint_null();

	}

	return 0;
}

