#include "Util.h"

Coord::Coord(int _x, int _y) : x(_x), y(_y) {}

bool operator==(const Coord & lhs, const Coord & rhs)
{
	// Checks to see if two sets of coordinates are equal
	if (lhs.x == rhs.x) {
		if (lhs.y == rhs.y) {
			return true;
		}
	}
	return false;
}

bool operator!=(const Coord & lhs, const Coord & rhs)
{
	return !(lhs == rhs);
}