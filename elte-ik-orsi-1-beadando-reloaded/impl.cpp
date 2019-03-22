#include "types.hpp"
#include <iostream>


FIELD field_from_int(const int i)
{
	return static_cast<FIELD>(i);
}

int field_value(const FIELD& f)
{
	switch (f)
	{
		case FIELD::CANNIBALS	: return -2;	break;
		case FIELD::DESERT		: return 0;		break;
		case FIELD::FOREST		: return 3;		break;
		case FIELD::GOLD_MINE	: return 5;		break;
		case FIELD::GRASSLAND	: return 2;		break;
		case FIELD::IRON		: return 2;		break;
		case FIELD::LAKE		: return 3;		break;
		case FIELD::SEA			: return 1;		break;
		case FIELD::SWAMP		: return 1;		break;
		case FIELD::VILLAGE		: return 6;		break;
		case FIELD::WHEAT		: return 3;		break;
	}
}

int tile_value(const Tile& f)
{
	return 0;
}

bool operator<(const Coordinate& a, const Coordinate& b)
{
	if (a.x == b.x) return a.y < b.y;
	return a.x < b.x;
}


std::ostream& operator<<(std::ostream& s, const FIELD& f)
{
	switch (f)
	{
		case FIELD::CANNIBALS	: s << "CANNIBALS";		break;
		case FIELD::DESERT		: s << "DESERT";		break;
		case FIELD::FOREST		: s << "FOREST";		break;
		case FIELD::GOLD_MINE	: s << "GOLD_MINE";		break;
		case FIELD::GRASSLAND	: s << "GRASSLAND";		break;
		case FIELD::IRON		: s << "IRON";			break;
		case FIELD::LAKE		: s << "LAKE";			break;
		case FIELD::SEA			: s << "SEA";			break;
		case FIELD::SWAMP		: s << "SWAMP";			break;
		case FIELD::VILLAGE		: s << "VILLAGE";		break;
		case FIELD::WHEAT		: s << "WHEAT";			break;
	}
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
