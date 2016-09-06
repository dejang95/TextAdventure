#include <iostream>
#include "stdafx.h"
#include "Items.h"	
using namespace std;

Items::Items(int axis_Y, int axis_X, int checkpoint) : axis_Y (axis_Y), axis_X(axis_X),item_num(0), free_slot(0), checkpoint(checkpoint) {for (int i = 0; i < 100; i++) players_items[i] = 0;}

Items::~Items(){}

int Items::locate() {

	if (axis_Y == 2 && axis_X == 1) item_num = 1; 
	else if (axis_Y == 2 && axis_X == 0) item_num = 2; 
	else if (axis_Y == 1 && axis_X == 1) item_num = 3; 
	else item_num = 0;

	return item_num;
}

void Items::read_located_item() {

	if (!check_if_picked()) {

		switch (locate()) {

		case 1: cout << " On the ground is an USB drive. "<< endl;
			break;

		case 2: cout << " On the ground is a SIM Card. " << endl;
			break;

		case 3: cout << " On the ground is an SD card. " << endl;
			break;

		default:
			break;
		}

	}
}

void Items::toss() {}

void Items::save() {

	if (locate() && !check_if_picked()) {
		players_items[free_slot++] = item_num;
		cout << " The item has been saved! " << endl;
	}

	else cout << " There is no item at this location to save! " << endl;
}

void Items::read_inventory() {

	cout << endl;
	cout << " ****INVENTORY****" << endl;
	cout << endl;

	if (!free_slot) cout << " Your Inventory is empty! " << endl;

	else {

		cout << " In your Inventory there is: " << endl;

		for (int i = 0; players_items[i] != 0; i++) {

			cout << endl;
			cout << " " << players_items[i] << ". ";

			switch (players_items[i]) {

			case 1: cout << "  USB Drive. " << endl;
				break;

			case 2: cout << "  SIM Card. " << endl;
				break;

			case 3: cout << "  SD Card. " << endl;
				break;

			}
			cout << endl;
		}	

	}
}

void Items::update_values(int axis_Y, int axis_X, int checkpoint) {
	this->axis_Y = axis_Y;
	this->axis_X = axis_X;
	this->checkpoint = checkpoint;
}

bool Items::check_if_picked() {

	for (int i = 0; players_items[i] != 0; i++) {if (locate() == players_items[i]) return true;}
    return false;
}
