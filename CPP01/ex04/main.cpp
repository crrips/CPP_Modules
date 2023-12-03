#include <iostream>
#include <fstream>

int main(int argc, char **argv)
{
	std::ifstream	ifs;
	std::ofstream	ofs;
	std::string		filename;
	std::string		s1;
	std::string		s2;

	if (argc != 4)
	{
		std::cout << "Usage: ./replacer <filename> <string to replace> <string to replace with>" << std::endl;
		return 1;
	}
	filename = argv[1];
	s1 = argv[2];
	s2 = argv[3];
	if (s1.empty() || s2.empty())
	{
		std::cout << "Error: empty string" << std::endl;
		return 1;
	}
	ifs.open(filename);
	if (!ifs.is_open())
	{
		std::cout << "Error: could not open file" << std::endl;
		return 1;
	}
	
    return 0;
}
