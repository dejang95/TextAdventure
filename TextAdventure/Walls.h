#pragma once
#include <iostream>
#include <string>
using namespace std;

class Walls
{
public:

	Walls();
	~Walls();

	bool check_for_walls(int x_axis,int y_axis,string direction);
};