#include "libft.h"

int	ft_intlen(int n)
{
	int	i;

	i = 1;
	while (n > 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}
