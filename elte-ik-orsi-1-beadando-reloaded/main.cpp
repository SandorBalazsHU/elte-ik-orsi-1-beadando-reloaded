//run Kara run
#include <iostream>
#include "types.hpp"

// TODO: Tényleges implementáció
int main()
{
    std::cout << "Teszt:" << std::endl;
	Map m;
	std::set<Tile> s = m.get_tiles_in_radius(2, 2, 2);
	for (Tile t : s)
	{
		std::cout << t << std::endl;
	}
}
