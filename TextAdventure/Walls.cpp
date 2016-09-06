#include <iostream>
#include <string>
#include "stdafx.h"
#include "Gameplay.h"

using namespace std;

bool Gameplay::check_for_wall(int vertically, int horizontally) {

	bool wall = false;

	if ((vertically > 2 || horizontally > 5) && checkpoint < 2) return true;

	return wall;
}