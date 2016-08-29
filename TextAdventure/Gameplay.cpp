#include <iostream>
#include <string>
#include "stdafx.h"
#include "Gameplay.h"

using namespace std;

Gameplay::Gameplay(string name, int age) : name(name), age(age > 0 ? age : 18), checkpoint(0),  ver(1), hor(0), item_num(0), free_slot(0), money(20), health(100)
{
	for (int i = 0; i < 100; i++) players_items[i] = 0;
}

Gameplay::~Gameplay(){}

void Gameplay::sitrep() {

	cout << endl;
	cout << " Hello, " << name << endl;
	cout << " It is the year 2025 and one of the main philosphical question has been solved. Are we alone in the universe? ";
	cout << " And we didn't like the answer. They are all over the place. They are taking our planet part by part, and it seems they are unstopable. ";
	cout << " We have to fight this battle to the end. It depends on us if we are going to survive.  " << endl;
	cout << endl;

}

void Gameplay::map_items() {
	

	if (ver == 2 && hor == 1) {

		item_num = 1;

		if (!picked()) {		// "picked()" - checks if we already have this item in the inventory

			cout << " You've found an USB flash drive! " << endl;

		}

		else cout << " No Items have been found here. " << endl;
	}

	else if (ver == 1 && hor == 1) {

		item_num = 2;

		if (!picked()) {
		
			cout << " You've found a SIM Card! " << endl;

		}

		else cout << " No Items have been found here. " << endl;

	}

	else if (ver == 1 && hor == 0) {

		item_num = 3;

		if (!picked()) {

			cout << " You've found an SD Card! " << endl;

		}

		else cout << " No Items have been found here. " << endl;

	}

	else if (ver == 0 && hor == 2) {

		item_num = 4;

		if (!picked()) {

			cout << " You've found a Light Torch! " << endl;

		}

		else cout << " No Items have been found here. " << endl;

	}

	else cout << " No Items have been found here. " << endl;

	actions();

}
