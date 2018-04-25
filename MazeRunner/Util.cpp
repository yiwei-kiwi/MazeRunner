#include "Util.h"

Coord::Coord(int _x, int _y) : x(_x), y(_y) {}

bool operator==(const Coord & lhs, const Coord & rhs)
{
	return ((lhs.x == rhs.x) && (rhs.y == rhs.y));
}

bool operator!=(const Coord & lhs, const Coord & rhs)
{
	return !(lhs == rhs);
}