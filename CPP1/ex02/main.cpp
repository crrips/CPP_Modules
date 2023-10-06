#include <iostream>

using std::cout;
using std::endl;
using std::string;

int	main()
{
	string	str = "HI THIS IS BRAIN";
	string	*stringPTR = &str;
	string	&stringREF = str;

	cout << "Address of the string variable:\t\t" << &str << endl;
	cout << "Address held by stringPTR:\t\t" << stringPTR << endl;
	cout << "Address held by stringREF:\t\t" << &stringREF << endl;
	cout << endl;
	cout << "The value of the string variable:\t" << str << endl;
	cout << "The value pointed to by stringPTR:\t" << *stringPTR << endl;
	cout << "The value pointed to by stringREF:\t" << stringREF << endl;
	return 0;
}