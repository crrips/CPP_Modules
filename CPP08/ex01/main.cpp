#include "Span.hpp"

int main()
{
	Span sp = Span(5);

	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);

	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;

	std::vector<int> v;
	for (int i = 0; i < 10001; ++i)
		v.push_back(i * 42);

	Span	big(10001);
	big.addNumber(v.begin(), v.end());

	std::cout << std::endl;
	std::cout << big.shortestSpan() << std::endl;
	std::cout << big.longestSpan() << std::endl;
	
	return 0;
}
