#include "easyfind.hpp"
#include <vector>
#include <list>
#include <deque>

int main()
{
	std::vector<int> v;
	std::list<int> l;
	std::deque<int> d;

	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
		l.push_back(i);
		d.push_back(i);
	}

	std::cout << "Vector: ";
	for (std::vector<int>::iterator it = v.begin(); it != v.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;

	std::cout << "List: ";
	for (std::list<int>::iterator it = l.begin(); it != l.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;

	std::cout << "Deque: ";
	for (std::deque<int>::iterator it = d.begin(); it != d.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;

	std::cout << "easyfind(v, 5): " << *easyfind(v, 5) << std::endl;
	std::cout << "easyfind(l, 5): " << *easyfind(l, 5) << std::endl;
	std::cout << "easyfind(d, 5): " << *easyfind(d, 5) << std::endl;

	std::cout << "easyfind(v, 42): ";
	try
	{
		std::cout << *easyfind(v, 42) << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Not found" << std::endl;
	}

	std::cout << "easyfind(l, 42): ";
	try
	{
		std::cout << *easyfind(l, 42) << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Not found" << std::endl;
	}

	std::cout << "easyfind(d, 42): ";
	try
	{
		std::cout << *easyfind(d, 42) << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Not found" << std::endl;
	}
	return 0;
}
