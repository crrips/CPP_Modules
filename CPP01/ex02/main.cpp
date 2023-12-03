#include <iostream>

int	main()
{
	std::string	str = "HI THIS IS BRAIN";
	std::string	*stringPTR = &str;
	std::string	&stringREF = str;

	std::cout << "Address of the std::string variable:\t\t" << &str << std::endl;
	std::cout << "Address held by stringPTR:\t\t" << stringPTR << std::endl;
	std::cout << "Address held by stringREF:\t\t" << &stringREF << std::endl;
	std::cout << std::endl;
	std::cout << "The value of the std::string variable:\t" << str << std::endl;
	std::cout << "The value pointed to by stringPTR:\t" << *stringPTR << std::endl;
	std::cout << "The value pointed to by stringREF:\t" << stringREF << std::endl;
	return 0;
}
