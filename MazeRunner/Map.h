#pragma once
#include "Util.h"
#include "Tile.h"
#include <vector>
#include <array>
#define MAPSIZE 25

class Map
{
public:
	// Constructor for the map class
	Map(unsigned seed = 0);
	// Destructor for the map class
	~Map();
	// Checks to see if the current coordinates are within the boundaries of the map
	bool isCoordInBound(Coord location);
	// Grabs the tile at the current coordinates
	Tile *& getTile(Coord input);
	// Creates the game map
	void generateMap();
private:
	// Dimensions of the map
	unsigned seed;
	const int length;
	const int width;
	// Functions for genrating random map
	bool isPathTileValid(Coord newTile, std::vector<Coord> &path);
	void generatePath(std::vector<Coord> &path);
	bool addToPath(std::vector<Coord> &path, int direction);
	void replaceTile(Coord tile, Tile* newTile);
	bool isInPath(std::vector<Coord> &path, Coord location);
	// Defines the size of the map
	std::array<std::array<Tile *,MAPSIZE>, MAPSIZE> map;
};