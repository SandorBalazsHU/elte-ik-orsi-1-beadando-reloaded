//Run Kara Run
#include <iostream>
#include <fstream>
#include <thread>
#include "types.hpp"

class Mission {
	private:
		Map map;
		int civilisations_number;
		int scanning_radius;
		std::vector<Coordinate> civilisations;
		std::vector<int> counted_values;
		void counting(Coordinate c);
	public:
		Mission(std::string input_file);
		void compute();
		void write_out(std::string input_file);
};

int main()
{
	Mission mission("world.map");
	mission.compute();
	mission.write_out("output.txt");
}

Mission::Mission(std::string input_file)
{
	std::fstream file(input_file);
	if (!file.good()) std::cout << "The input file dosen't exist!" << std::endl;

	int n, m;
	file >> n >> m;
	map = Map(n, m);
	file >> map;

	file >> civilisations_number >> scanning_radius;
	for (int i = 0; i < civilisations_number; i++)
	{
		int x, y;
		file >> x >> y;
		civilisations.push_back(Coordinate(x, y));
	}
}

void Mission::counting(Coordinate c)
{
	std::set<Tile> s = map.get_tiles_in_radius(c, scanning_radius);
	int sum = 0;
	for (Tile t : s)
	{
		sum += tile_value(t);
	}
	counted_values.push_back(sum);
}

void Mission::compute()
{
	std::vector<std::thread> threads;
	for (size_t i = 0; i < civilisations.size(); i++)
	{
		threads.push_back(std::thread(&counting, civilisations[i]));
	}

	for (size_t i = 0; i < civilisations.size(); i++)
	{
		counting(civilisations[i]);
	}

	for (size_t i = 0; i < civilisations.size(); i++) threads[i].join();
}


void Mission::write_out(std::string input_file)
{
	std::ofstream myfile;
	myfile.open(input_file);
	for (size_t i = 0; i < counted_values.size(); i++)
	{
		myfile << counted_values[i] << std::endl;
	}
	myfile.close();
}