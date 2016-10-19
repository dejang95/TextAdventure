#include <iostream>
#include <string>
#include "stdafx.h"
#include "Gameplay.h"
#include "Print.h"
#include "Items.h"
using namespace std;

Gameplay::Gameplay(string name, int age) : name(name), age(age > 0 ? age : 18), checkpoint(0), axis_X(0), axis_Y(1), money(20), health(100), item(axis_Y, axis_X, checkpoint), print(axis_Y, axis_X, this->name, this->age, health, money) {}

Gameplay::~Gameplay(){}

void Gameplay::intro() {

	cout << endl;
	cout << " Hello, " << name << endl;
	cout << " It is the year 2025 and one of the main philosphical question has been solved. Are we alone in the universe? ";
	cout << " And we didn't like the answer. They are all over the place. They are taking our planet part by part, and it seems they are unstopable. ";
	cout << " We have to fight this battle to the end. It depends on us if we are going to survive.  " << endl;
	cout << endl;

}
