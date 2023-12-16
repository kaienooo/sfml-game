#include "MapLoader.h"
#include "MapData.h"
#include <fstream>

void MapLoader::Load(std::string filename, MapData& data)
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
				std::string value = line.substr(count + 1, line.length() - count-1);

				try
				{
					if (variable == "tilesheet")
						data.tilesheet = value;

					else if (variable == "name")
						data.name = value;

					else if (variable == "tile-width")
						data.tileWidth = std::stoi(value);

					else if (variable == "tile-height")
						data.tileHeight = std::stoi(value);

					else if (variable == "scale-x")
						data.scaleX = std::stoi(value);

					else if (variable == "scale-y")
						data.scaleY = std::stoi(value);

					else if (variable == "data-length")
						data.dataLength = std::stoi(value);

					else if (variable == "data")
					{
						data.data = new int[data.dataLength];
						int i = 0;
						int j = 0;
						std::string podTresc;
						while (i < value.length())
						{
							podTresc = "";
							while (value[i] != ',')
							{
								if (value[i] == ' ')
								{
									i++;
								}
								else
								{
									podTresc += value[i++];
								}

								if (i == value.length())
									break;
							}
							i++;
							if (j < data.dataLength)
							{
								data.data[j++] = std::stoi(podTresc);
							}
						}
					}
					else if (variable == "data-x")
						data.mapWidth = std::stoi(value);
				}
				catch (const std::exception&)
				{
					std::cout << "Error! "<< filename << std::endl;
				}
				
			}

		}
		file.close();

		for (int i = 0; i < data.dataLength; i++) {
			std::cout << data.data[i] << ",";
		}
		std::cout << "\n";
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
