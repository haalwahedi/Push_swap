#include "libft.h"

void	ft_putnbr(int n)
{
	unsigned int	num;

	if (n < 0)
	{
		ft_putchar('-');
		num = n * -1;
	}
	else
		num = n;
	if ((num / 10) > 0)
		ft_putnbr(num / 10);
	ft_putchar((num % 10) + '0');
}
