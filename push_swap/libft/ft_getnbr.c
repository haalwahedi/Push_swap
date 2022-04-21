#include "libft.h"

int	ft_getnbr(char const *str)
{
	int		nbr;
	int		neg;

	nbr = 0;
	neg = 0;
	if (*str == '-')
	{
		str++;
		neg++;
	}
	while (*str)
	{
		nbr *= 10;
		nbr = (*str - 48) + nbr;
		str++;
	}
	if (neg)
		nbr *= -1;
	return (nbr);
}
