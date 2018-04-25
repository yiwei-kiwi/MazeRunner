#include "Map.h"

Map::Map(int length, int width) : length(length), width(width)
{
	map.reserve(this->length * 2);
	for (int x = 0; x < this->length; ++x) {
		map.at(x).reserve(this->width * 2);
		for (int y = 0; y < this->width; ++y) {
			map[x].push_back(new Tile);
		}
	}
}

Map::~Map()
{
	for (int x = 0; x < this->length; ++x)
	{
		for (int y = 0; y < this->width; ++y)
		{
			auto tile = this->map[x][y];
			if (tile != nullptr)
				delete tile;
		}
	}
}

bool Map::isCoordInBound(Coord location)
{
	if ((location.x < length) && (location.x >= 0)) {
		if ((location.y < width) && (location.y >= 0))
			return true;
	}
	return false;
}

Tile *& Map::getTile(Coord input)
{
	return map[input.x][input.y];
}