#include <iostream>
#include <string>
#include "stdafx.h"
#include "Gameplay.h"
#include "Print.h"
#include "Items.h"
#include "Walls.h"
using namespace std;

Gameplay::Gameplay(string name, int age) : name(name), age(age > 0 ? age : 18), checkpoint(0), axis_X(0), axis_Y(1), money(20), health(100), item(axis_Y, axis_X, checkpoint), print(axis_Y, axis_X, this->name, this->age, health, money) {}

Gameplay::~Gameplay(){}

void Gameplay::intro() {

	cout << endl;
	cout << " Hello, " << name << endl;
	cout << endl;
	cout << " Welcome to the Dejan's first Text Adventure game. You are about to embark on a rich adventure of saving a human race from this new threat." << endl;
	cout << " The story takes place in New York, the year is 2045 and after so many years of Hollywood projections, one of them has finally come true. " << endl;
	cout << " The third kind has invaded our world. Many lives have been already lost and the number will not end there. These creatures seem to be unstoppable. " << endl;
	cout << " We have to fight this battle untill the very end. History will be written after this, the only question is, who'll have the privilege to tell it? " << endl;
	cout << " Godspeed young soldier, may the luck be on your side! " << endl;
	cout << endl;

}