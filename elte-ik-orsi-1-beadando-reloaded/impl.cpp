#include "types.hpp"
#include <iostream>


FIELD field_from_int(const int i)
{
	return FIELD::SEA;
}

int field_value(const FIELD& f)
{
	return 0;
}

int tile_value(const Tile& f)
{
	return 0;
}

bool operator<(const Coordinate& a, const Coordinate& b)
{
	return true;
}

/*
std::ostream& operator<<(std::ostream& s, const FIELD& f)
{
	return s;
}

std::ostream& operator<<(std::ostream& s, const DIRECTION& d)
{
	return s;
}

std::ostream& operator<<(std::ostream& s, const Coordinate& p)
{
	return s;
}
std::istream& operator>>(std::istream& s, Coordinate& p)
{
	return s;
}

std::ostream& operator<<(std::ostream& s, const Tile& t)
{
	return s;
}
*/
std::istream& operator>>(std::istream& s, Map& m)
{
	return s;
}

Map::Map()
{

}

Map::Map(const int r, const int c)
{

}

int Map::rows() const
{
	return 0;
}

int Map::cols() const
{
	return 0;
}

bool Map::in_range(const int x, const int y) const
{
	return false;
}

Tile Map::tile_at(const int i, const int j) const
{
	return std::make_pair(Coordinate(-1, -1), FIELD::SEA);
}

void Map::set_tile(const int i, const int j, const FIELD f)
{

}

Tile Map::tile_in_direction(int x, int y, const DIRECTION d) const
{
	return tile_at(0, 0);
}

std::set<Tile> Map::get_tiles_in_radius(const int i, const int j, const int r) const
{
	std::set<Tile> s;
	return s;
}
