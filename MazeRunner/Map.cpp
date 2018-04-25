#include "Map.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <thread>

Map::Map(unsigned seed) : length(MAPSIZE), width(MAPSIZE), seed(seed)
{
	int count = 0;
	for (int x = 0; x < this->length; ++x) {
		for (int y = 0; y < this->width; ++y) {
			map[x][y] = new Tile;
		}
	}
	this->generateMap();
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

void Map::generateMap()
{
	std::vector<Coord> path;
	if (seed != 0) {
		this->generatePath(path);
	}
	else {
		while (path.size() < (MAPSIZE * 2)) {
			path.clear();
			this->generatePath(path);
		}
	}
	
	this->replaceTile(path.back(), new VictoryTile);

	for (int x = 0; x < this->length; ++x) {
		for (int y = 0; y < this->width; ++y) {
			if (!this->isInPath(path, { x, y })){
				int chance = std::rand() % 100;
				if (chance < 70) {
					if (chance < 60) {
						this->replaceTile({ x,y }, new WallTile);
					}
					else if (chance < 65) {
						this->replaceTile({ x,y }, new ResetTrap);
					}
					else {
						this->replaceTile({ x,y }, new PauseTrap);
					}
				}
			}
		}
	}
}

bool Map::isPathTileValid(Coord newTile, std::vector<Coord> &path)
{
	if (this->isCoordInBound(newTile)) {
		for (auto t : path) {
			if (t == newTile) {
				return false;
			}
		}
		return true;
	}
	return false;
}

void Map::generatePath(std::vector<Coord>& path)
{
	seed = std::time(NULL);
	std::srand(seed);
	
	std::vector<Coord>viableTiles;
	path.reserve(MAPSIZE * 4);
	path.push_back({ 0,0 });
	for (int i = 0; i < (MAPSIZE * 4); ++i) {
		viableTiles.clear();
		auto potentialTile = path.back();
		if (this->isPathTileValid({ potentialTile.x + 1, potentialTile.y }, path))
			viableTiles.push_back({ potentialTile.x + 1, potentialTile.y });
		if (this->isPathTileValid({ potentialTile.x - 1, potentialTile.y }, path))
			viableTiles.push_back({ potentialTile.x - 1, potentialTile.y });
		if (this->isPathTileValid({ potentialTile.x, potentialTile.y + 1 }, path))
			viableTiles.push_back({ potentialTile.x, potentialTile.y + 1 });
		if (this->isPathTileValid({ potentialTile.x, potentialTile.y - 1 }, path))
			viableTiles.push_back({ potentialTile.x, potentialTile.y - 1 });
		if (viableTiles.empty())
			break;
		int direction = (std::rand() % viableTiles.size());
		path.push_back(viableTiles[direction]);
	}
}

bool Map::addToPath(std::vector<Coord>& path, int direction)
{
	Coord nextTile;
	switch (direction) {
	case 0:
		nextTile = path.back();
		--nextTile.y;
		if (this->isPathTileValid(nextTile, path)) {
			path.push_back(nextTile);
			return true;
		}
		break;
	case 1:
		nextTile = path.back();
		++nextTile.x;
		if (this->isPathTileValid(nextTile, path)) {
			path.push_back(nextTile);
			return true;
		}
		break;
	case 2:
		nextTile = path.back();
		++nextTile.y;
		if (this->isPathTileValid(nextTile, path)) {
			path.push_back(nextTile);
			return true;
		}
		break;
	case 3:
		nextTile = path.back();
		--nextTile.x;
		if (this->isPathTileValid(nextTile, path)) {
			path.push_back(nextTile);
			return true;
		}
		break;
	}
	return false;
}

void Map::replaceTile(Coord tile, Tile * newTile)
{
	delete this->getTile(tile);
	this->map[tile.x][tile.y] = newTile;
}

bool Map::isInPath(std::vector<Coord>& path, Coord location)
{
	for (auto t : path) {
		if (t == location) {
			return true;
		}
	}
	return false;
}
