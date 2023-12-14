#include "MapLoader.h"
#include <fstream>
#include <string>

void MapLoader::Load(std::string filename)
{
	std::string line;
	std::ifstream file(filename);

	bool isMapValid = false;

	if (file.is_open())
	{
		while (std::getline(file, line))
		{
			if (!isMapValid)
			{
				if (line == "[MAP]")
				{
					isMapValid = true;
					continue;
				}
				else
				{
					std::cout << "aha66 file is not valid" << std::endl;
					break;
				}
			}

			if (isMapValid)
			{
				int count = line.find('=');

				std::string variable = line.substr(0, count);
				std::string value = line.substr(count+1, line.length() - count -1);

				std::cout << variable << std::endl;
				std::cout << value << std::endl;
				break;
			}
			
		}
		file.close();
	}
	else
	{
		std::cout << "Unable to open: " << filename << std::endl;
	}
}

void MapLoader::Save(std::string filename)
{
	std::ofstream file;

	file.open(filename);
	file << "This is my map" <<std::endl;
	file << "124, 125, 126, 144, 145, 146" << std::endl;
	file.close();
}
