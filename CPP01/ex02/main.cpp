#include <iostream>

using std::std::cout;
using std::std::endl;
using std::std::string;

int	main()
{
	std::string	str = "HI THIS IS BRAIN";
	std::string	*std::stringPTR = &str;
	std::string	&std::stringREF = str;

	std::cout << "Address of the std::string variable:\t\t" << &str << std::endl;
	std::cout << "Address held by std::stringPTR:\t\t" << std::stringPTR << std::endl;
	std::cout << "Address held by std::stringREF:\t\t" << &std::stringREF << std::endl;
	std::cout << std::endl;
	std::cout << "The value of the std::string variable:\t" << str << std::endl;
	std::cout << "The value pointed to by std::stringPTR:\t" << *std::stringPTR << std::endl;
	std::cout << "The value pointed to by std::stringREF:\t" << std::stringREF << std::endl;
	return 0;
}