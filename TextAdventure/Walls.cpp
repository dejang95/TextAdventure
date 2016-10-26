#include "stdafx.h"
#include <iostream>
#include <string>
#include "Walls.h"
using namespace std;


Walls::Walls()
{
}


Walls::~Walls()
{
}

bool Walls::check_for_walls(int x_axis, int y_axis,string direction) {
	// first we define base case as follows:
	if (y_axis == 2 && direction == "n") return true;
	else if ((y_axis == 2 || x_axis == 0) && direction == "nw") return true;
	else if ((y_axis == 2 || x_axis == 100) && direction == "ne") return true;
	else if (y_axis == 0 && direction == "s") return true;
	else if ((y_axis == 0 || x_axis == 0) && direction == "sw") return true;
	else if ((y_axis == 0 || x_axis == 100) && direction == "se") return true;
	else if (x_axis == 0 && direction == "w") return true;
	else if (x_axis == 100 && direction == "e") return true;
	else return false;
}