#include "parse.h"

int main(int ac, char **av)
{
	if (ac != 2)
		return (0);
	t_input *input = parse(av[1]);

	(void)input;
}