#include "Util.h"
#include "Tile.h"
#include <vector>

class Map
{
public:
	Map(int length, int width);
	~Map();
	bool isCoordInBound(Coord location);
	Tile *& getTile(Coord input);

private:
	const int length;
	const int width;
	std::vector<std::vector<Tile *>> map;
};