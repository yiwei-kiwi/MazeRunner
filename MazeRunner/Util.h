#pragma once

// A struct containing a x and y variable to represent the coordinate position of an object
struct Coord { 
	int x;
	int y;

	Coord(int _x = 0, int _y = 0);
	friend bool operator==(const Coord &lhs, const Coord &rhs);
	friend bool operator!=(const Coord &lhs, const Coord &rhs);
};