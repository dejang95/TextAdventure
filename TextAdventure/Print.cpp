#include "stdafx.h"
#include <iostream>
#include "Print.h"
using namespace std;


Print::Print(int x_axis, int y_axis, string name, int age, int health, int money) : x_axis(x_axis), y_axis(y_axis), name(name), age(age), health(health), money(money) {}

Print::~Print() {}

void Print::commands() {

	cout << endl;
	cout << " **** LIST OF AVALIABLE COMMANDS **** " << endl;
	cout << endl;
	cout << " ''go [direction]'' - moves a player to a wanted position | Abbreviation: 'g' " << endl;
	cout << " ''help'' - helps you with commands | Abbreviation: 'h' " << endl;
	cout << " ''stats'' - gives you your current stats ( e.d Money, Health etc.. ) | Abbreviation: 's' " << endl;
	cout << " ''pick'' - picks up an item and stores it in an inventory | Abbreviation: 'p' " << endl;
	cout << " ''use'' - uses a specific item you have in inventory or you've just picked up | Abbreviation: 'u' " << endl;
	cout << " ''inventory'' - gives you an overview of your Inventory | Abbreviation: 'i' " << endl;
	cout << " ''location'' - gives you your exact current location on the map | Abbreviation: 'l' " << endl;
	cout << " ''clear'' - clears the screen | Abbrevation: 'c' " << endl;
	cout << endl;

}

void Print::location() {

	cout << endl;
	cout << " Your current location is "  << y_axis << " on Y Axis and " << x_axis << " on X Axis. " << endl;
	cout << endl;

}

void Print::players_data() {

	cout << endl;
	cout << " Players name: " << name << endl;
	cout << " Player age: " << age << endl;
	cout << " Money: " << money << " $" << endl;
	cout << " Health: " << health << " hp" << endl;
	cout << endl;
}

void Print::update_values(int y_axis, int x_axis, string name, int age, int health, int money) {
	
	this->y_axis = y_axis;
	this->x_axis = x_axis;
	this->name = name;
	this->age = age;
	this->health = health;
	this->money = money;

}