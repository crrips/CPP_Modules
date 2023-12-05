#include <iostream>
#include <fstream>

void my_string_iterator_replacer(std::string &str, std::string const &s1, std::string const &s2)
{
	size_t pos = 0;
	size_t len = s1.length();

	while ((pos = str.find(s1, pos)) != std::string::npos)
	{
		str.erase(pos, len);
		str.insert(pos, s2);
		pos += s2.length();
	}
}

int main(int argc, char **argv)
{
	std::ifstream	ifs;
	std::ofstream	ofs;
	std::string		file;
	std::string		s1;
	std::string		s2;

	if (argc != 4)
	{
		std::cout << "Usage: ./replacer <filename> <string to replace> <string to replace with>" << std::endl;
		return 1;
	}
	file = argv[1];
	s1 = argv[2];
	s2 = argv[3];
	if (s1.empty() || s2.empty())
	{
		std::cout << "Error: empty string" << std::endl;
		return 1;
	}
	ifs.open(file);
	if (!ifs.is_open())
	{
		std::cout << "Error: could not open file" << std::endl;
		return 1;
	}
	std::string fileContent((std::istreambuf_iterator<char>(ifs)), std::istreambuf_iterator<char>());
	ifs.close();
	my_string_iterator_replacer(fileContent, s1, s2);
	ofs.open(file + ".replace");
	ofs << fileContent;
	ofs.close();
    return 0;
}
