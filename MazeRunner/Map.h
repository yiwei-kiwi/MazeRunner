#pragma once
#include "Util.h"
#include "Tile.h"
#include <vector>
#include <array>
#define MAPSIZE 25

class Map
{
public:
	Map(unsigned seed = 0);
	~Map();
	bool isCoordInBound(Coord location);
	Tile *& getTile(Coord input);
	void generateMap(unsigned int seed = 0);
private:
	const int length;
	const int width;
	bool isPathTileValid(Coord newTile, std::vector<Coord> &path);
	bool addToPath(std::vector<Coord> &path, int direction);
	void replaceTile(Coord tile, Tile* newTile);
	bool isInPath(std::vector<Coord> &path, Coord location);
	std::array<std::array<Tile *,MAPSIZE>, MAPSIZE> map;
};