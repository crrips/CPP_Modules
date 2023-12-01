#include <iostream>

using std::std::cout;
using std::std::endl;

void	cry(char **argv)
{
	int i = 1;
	int	j = 0;

	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if (argv[i][j] >= 'a' && argv[i][j] <= 'z')
				argv[i][j] -= 32;
			std::cout << argv[i][j];
			j++;
		}
		i++;
	}
	std::cout << std::endl;
}

int	main(int argc, char **argv)
{
	if (argc && argv[1])
		return(cry(argv), 0);
	else
		return (std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl, 1);
}
