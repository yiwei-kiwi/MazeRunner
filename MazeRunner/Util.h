#pragma once

struct Coord { //because this is a struct, it can be simply represented by {x,y}, kinda copied over from my chess game
	int x;
	int y;

	Coord(int _x = 0, int _y = 0);
	friend bool operator==(const Coord &lhs, const Coord &rhs);
	friend bool operator!=(const Coord &lhs, const Coord &rhs);
};