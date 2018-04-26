/*
Programmers: Darshil Shah, Yi Wei, Joy Dang
Date Last Modified: 4/25/18
Project: PA 9, Cpts 122
Name: MazeRunner
*/

#pragma once

// A struct containing a x and y variable to represent the coordinate position of an object
struct Coord { 
	int x;
	int y;
	// Constructor for the Coord
	Coord(int _x = 0, int _y = 0);
	// Friend functions for the Coord struct
	friend bool operator==(const Coord &lhs, const Coord &rhs);
	friend bool operator!=(const Coord &lhs, const Coord &rhs);
};