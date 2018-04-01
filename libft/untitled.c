
#include <stdio.h>
#include "libft.h"

int	main(int ac, char **av)
{
	int tab[1] = {17};

	ft_bzero(tab, 1);
	printf("%d\n", tab[0]);
}