#include <iostream>
#include <string>
#include "stdafx.h"
#include "Gameplay.h"

void Gameplay::checkpoint_null() {

	cout << " Your first objective will be to find out the exact location of the remaining team of humans in New York. " << endl;
	cout << " The terminal is not too far from here. Move around to find it, and find out the exact location of the remaining humans. " << endl;
	cout << endl;

	checkpoint = 0;

	actions();
}

void Gameplay::checkpoint_one() {

	cout << " The exact location of the other humans in New York is: 4 verticaclly and 6 horizontally. " << endl;
	cout << " [ Hint: Type in '' location '' to see your exact location. ] " << endl;
	cout << endl;

	checkpoint = 1;

	actions();

}

void Gameplay::checkpoint_two() {

	cout << endl;
	cout << " THIS IS CHECKPOINT 2 " << endl;
	cout << endl;

	checkpoint = 2;

	actions();
}